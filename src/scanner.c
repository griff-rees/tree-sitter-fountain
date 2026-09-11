#include "tree_sitter/parser.h"
#include <stdbool.h>
#include <stdint.h>

// === External tokens (#40, #9-span-fix, #38) ===
//
// `boneyard` and `note` are here for the same reason:
//   - Each's reported span, as a plain JS-level regex token, starts
//     from wherever the lexer began searching rather than from the
//     token's own first real character — so leading whitespace skipped
//     as an `extra` on the way there gets folded into the following
//     token's span instead of staying a separate, correctly-bounded
//     sibling.
//   - `boneyard` was fixed this way in #40; `note` had the identical
//     bug (confirmed empirically while working on #38 —
//     `He drinks.   [[note]]` reported the note's span starting three
//     columns before the `[`) but nobody had caught it, because the bug
//     is only visually obvious for a highlight attribute that paints
//     something over blank cells (`underline`'s span bug was the one
//     that surfaced it, per #40) — `note` typically renders as a plain
//     foreground colour, so the bled columns were invisible in
//     practice.
//   - Fixed here alongside #38 since this file's externals/scan
//     dispatch was already being restructured.
//
// The six OPEN/CLOSE pairs (`italic`, `bold`, `underline`) exist for a
// different reason (#38): same-line nesting of one emphasis type inside
// another, e.g. `**bold *and italic* text**`.
//   - An earlier spike tried this as a pure multi-token grammar rule
//     (open delimiter, recursive content, close delimiter) with no
//     external scanner, and hit a real, unresolved problem: once the
//     opening delimiter is shifted, tree-sitter's default shift/reduce
//     resolution commits to building the structured node via its
//     normal (non-GLR) path.
//   - When a valid closing delimiter turns out not to exist several
//     tokens later, the failure surfaces as generic error recovery
//     rather than backtracking to a live sibling parse (the line should
//     instead fall back to plain text, as it does today when nothing
//     pairs up).
//
// The fix implemented here:
//   - Before an OPEN token is ever emitted (i.e. before the parser ever
//     shifts it and commits to the structured reading),
//     `validate_content_and_close` walks the *entire* remainder of the
//     prospective span — including any nested spans it would contain —
//     purely to answer "does a legal close exist".
//   - Only if that succeeds does the scanner emit the OPEN token;
//     otherwise it returns false, so tree-sitter falls through to the
//     ordinary literal-character tokens (`_star`/`_star2`/`_underscore`
//     in grammar.js) and the structured rule is never entered at all.
//   - This costs nothing on failure: whatever the validation pass
//     advanced through is transparently rewound by the tree-sitter
//     runtime whenever `scan` returns false — the same guarantee
//     `scan_boneyard` below already relies on when it advances
//     speculatively and bails out partway through.
//
// Once an OPEN token has been validated and emitted, the *real* parse
// walks the same content a second time, one grammar token at a time
// (nested OPEN/CLOSE tokens, and the plain `_emphasis_content_run`
// token in grammar.js for everything in between).
//   - This retracing reaches the same decisions as the validation pass,
//     because both are pure functions of the remaining input — nothing
//     here is order-dependent or cached across calls.
//   - That also means this scanner, despite driving a
//     recursive/"stateful-feeling" decision procedure, has no state to
//     actually carry between `scan` calls: every decision is re-derived
//     fresh each time from the lexer's current position, so
//     `serialize`/`deserialize` below stay trivial no-ops — there is no
//     stack that GLR forking/backtracking could ever observe
//     half-built.
//
// Scope, deliberately:
//   - Same-*type* re-nesting is excluded (an `italic` span's content
//     may contain `bold`/`underline`/`bold_italic` but not another
//     `italic`), which is what makes the star-run length (1, 2, or 3
//     stars) or the presence of `_` an unambiguous, non-backtracking
//     decision at every position — see `Kind`/`NESTABLE_IN_*` below.
//   - `bold_italic` (`***...***`) is deliberately NOT restructured — it
//     stays the same flat, atomic token it already was (see
//     grammar.js): it may appear as a nested *child* inside
//     `italic`/`bold`/`underline`, but its own content does not itself
//     recurse.
//   - A nestable span whose content contains an unpaired delimiter of a
//     nestable type (e.g. an `_` inside `italic` content with no
//     matching close anywhere on the line) fails validation entirely —
//     the WHOLE outer span falls back to literal characters, rather
//     than partially matching. That is a deliberate simplification
//     (matches this grammar's existing philosophy of "fall back to
//     literal rather than guess"), not a bug.
//
// `lexer->advance(lexer, true)` marks a character as skipped ("skip"):
// consumed, but excluded from the span of whatever token eventually
// gets returned.
//   - Used below for the leading whitespace before `boneyard`, `note`,
//     or an emphasis/`parenthetical`/`centered` OPEN token.
//   - CLOSE tokens never have pending leading whitespace to skip,
//     because `validate_content_and_close` already refuses to treat a
//     position as a legal close when whitespace immediately precedes it
//     (the flanking rule), so real parsing never reaches a CLOSE scan
//     in that state.
//
// `PAREN_OPEN`/`CENTERED_OPEN` exist for the same core reason as the
// emphasis OPEN tokens above — confirmed the hard way: an early attempt
// left `_centered_open`/`_paren_open` as plain (non-external) tokens,
// and "> Burn to White." (a forced transition with no closing '<') hit
// exactly the failure mode #38's own header describes: the parser
// committed to a `centered` reading via ordinary shift/reduce, found no
// '<' before end of line, and surfaced a genuine parse ERROR instead of
// falling back to `_forced_transition_line`.
//   - Much simpler than italic/bold/underline's validators, though:
//     neither `parenthetical` nor `centered` nests (their own content
//     never contains another instance of themselves), and
//     PAREN_PIECE/CENTERED_PIECE (grammar.js) already exclude their own
//     delimiter characters from ordinary content — including inside a
//     NESTED emphasis span, which still uses the plain, unmodified
//     `_emphasis_content_run` token, unaware of the outer container's
//     delimiters.
//   - So a simple linear scan for the first occurrence of the close
//     character, with no nesting-awareness needed at all, is exactly
//     equivalent to what the real grammar walk does afterward — see
//     `validate_simple_close` below.
//
// Order here must match `externals` in grammar.js exactly — external
// token identity is positional.

typedef enum {
  BONEYARD,
  NOTE,
  ITALIC_OPEN,
  ITALIC_CLOSE,
  BOLD_OPEN,
  BOLD_CLOSE,
  UNDERLINE_OPEN,
  UNDERLINE_CLOSE,
  CENTERED_OPEN,
  PAREN_OPEN,
} TokenType;

void *tree_sitter_fountain_external_scanner_create(void) { return NULL; }

void tree_sitter_fountain_external_scanner_destroy(void *payload) {
  (void)payload;
}

unsigned tree_sitter_fountain_external_scanner_serialize(void *payload, char *buffer) {
  (void)payload;
  (void)buffer;
  return 0;
}

void tree_sitter_fountain_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
  (void)payload;
  (void)buffer;
  (void)length;
}

// One PROSE_PIECE: mirrors PROSE_CHAR|ESCAPED_DELIM from grammar.js.
//   PROSE_CHAR    = [^ \t\r\n*_\\/] | /[^*\r\n]
//   ESCAPED_DELIM = \\[*_]  (this function's own scope: see the note
//                            below on why `\/`/`\[` don't apply here)
// Returns true and advances past exactly one piece (1 or 2 codepoints) on
// success. Returns false on any dead end; the caller aborts the whole
// match in that case, so it is safe to have already advanced here.
//
// This deliberately only escapes `\*`/`\_`, not the grammar-level
// `\/`/`\[` extension:
//   - Those exist purely to defuse `_prose_text`'s "first refusal"
//     lookahead for `/*` and `[[` (so a real boneyard/note still gets
//     first shot at those two characters) — a concern specific to
//     competing token *length* at the top `_prose_line` level.
//   - Nothing here competes with `note`/`boneyard` the same way: every
//     token this file's scanners produce is short and
//     delimiter-bounded, so a bare `/` or `[` inside emphasis content
//     is already unambiguous, unescaped.
static bool consume_prose_piece(TSLexer *lexer) {
  int32_t c = lexer->lookahead;
  if (c == 0 || c == '\n' || c == '\r' || c == '*' || c == '_' ||
      c == ' ' || c == '\t') {
    return false;
  }
  if (c == '\\') {
    lexer->advance(lexer, false);
    int32_t next = lexer->lookahead;
    if (next != '*' && next != '_') return false;
    lexer->advance(lexer, false);
    return true;
  }
  if (c == '/') {
    lexer->advance(lexer, false);
    int32_t next = lexer->lookahead;
    if (next == 0 || next == '*' || next == '\n' || next == '\r') return false;
    lexer->advance(lexer, false);
    return true;
  }
  lexer->advance(lexer, false);
  return true;
}

// === #38: nested emphasis validation ===

typedef enum {
  KIND_ITALIC = 1 << 0,
  KIND_BOLD = 1 << 1,
  KIND_UNDERLINE = 1 << 2,
  KIND_BOLD_ITALIC = 1 << 3,
} Kind;

// What may legally nest inside each kind's content: everything except
// the kind itself (same-type re-nesting is out of scope — see the file
// header) and `bold_italic`'s own content (a leaf, handled by
// `validate_bold_italic_content_and_close` instead of recursing).
#define NESTABLE_IN_ITALIC (KIND_BOLD | KIND_UNDERLINE | KIND_BOLD_ITALIC)
#define NESTABLE_IN_BOLD (KIND_ITALIC | KIND_UNDERLINE | KIND_BOLD_ITALIC)
#define NESTABLE_IN_UNDERLINE (KIND_ITALIC | KIND_BOLD | KIND_BOLD_ITALIC)

// `bold_italic`'s content, unchanged from its existing flat-token shape:
// PROSE_PIECEs and interior whitespace, sandwiched (must start and end
// on a real piece), closing on exactly three consecutive '*'. Assumes
// the three opening '*' have already been consumed by the caller.
static bool validate_bold_italic_content_and_close(TSLexer *lexer) {
  bool consumed_any = false;
  bool trailing_ws = false;

  while (true) {
    int32_t c = lexer->lookahead;
    if (c == 0 || c == '\n' || c == '\r') return false;

    if (c == ' ' || c == '\t') {
      if (!consumed_any) return false;
      lexer->advance(lexer, false);
      trailing_ws = true;
      continue;
    }

    if (c == '*') {
      int run = 0;
      while (lexer->lookahead == '*') {
        lexer->advance(lexer, false);
        run++;
      }
      // bold_italic's own content excludes '*' entirely (like the
      // existing flat token), so any run here can only be the close —
      // and only a run of exactly three counts as one.
      if (run == 3) {
        if (!consumed_any || trailing_ws) return false;
        return true;
      }
      return false;
    }

    if (!consume_prose_piece(lexer)) return false;
    consumed_any = true;
    trailing_ws = false;
  }
}

// Forward decl: mutually recursive with the '*'/'_' branches below.
static bool validate_content_and_close(TSLexer *lexer, Kind kind, unsigned allowed);

// Validates a nested span of whichever kind is indicated by the
// delimiter just found (already known live in `allowed`), including its
// own recursive content-and-close.
//   - Returns false (letting tree-sitter's automatic rewind-on-false
//     undo any advancing) if that nested span turns out not to
//     validate — per the file header, an unpaired nested delimiter
//     fails the WHOLE outer span, not just the nested one.
//   - Assumes the nested delimiter itself has ALREADY been consumed by
//     the caller — every call site below advances past it while first
//     discovering its length (the run-counting loop for '*', the
//     single check for '_'), so this only ever dispatches to the
//     appropriate content validator, never touches the delimiter
//     itself.
static bool validate_nested_open(TSLexer *lexer, Kind nested_kind) {
  if (nested_kind == KIND_UNDERLINE) {
    return validate_content_and_close(lexer, KIND_UNDERLINE, NESTABLE_IN_UNDERLINE);
  }
  if (nested_kind == KIND_ITALIC) {
    return validate_content_and_close(lexer, KIND_ITALIC, NESTABLE_IN_ITALIC);
  }
  if (nested_kind == KIND_BOLD) {
    return validate_content_and_close(lexer, KIND_BOLD, NESTABLE_IN_BOLD);
  }
  // KIND_BOLD_ITALIC
  return validate_bold_italic_content_and_close(lexer);
}

// The general case (italic/bold/underline). Assumes the caller has
// already consumed `kind`'s own opening delimiter.
//   - Walks forward, treating each '*'-run or '_' either as `kind`'s
//     own close (the only possible reading when nesting that type is
//     excluded from `allowed`, which is always true for `kind` itself
//     — see NESTABLE_IN_*), as the start of a nested span of a type
//     present in `allowed`, or — for anything else — as ordinary
//     content via `consume_prose_piece`.
//   - Because content excludes '*'/'_' from ordinary pieces entirely
//     (same as the pre-#38 flat tokens), there is at most one candidate
//     reading at each delimiter position: no backtracking across
//     multiple occurrences is ever needed, only a single forward walk.
static bool validate_content_and_close(TSLexer *lexer, Kind kind, unsigned allowed) {
  bool consumed_any = false;
  bool trailing_ws = false;

  while (true) {
    int32_t c = lexer->lookahead;
    if (c == 0 || c == '\n' || c == '\r') return false; // no close on this line

    if (c == ' ' || c == '\t') {
      if (!consumed_any) return false; // flanking: nothing before first piece
      lexer->advance(lexer, false);
      trailing_ws = true;
      continue;
    }

    if (c == '_') {
      if (kind == KIND_UNDERLINE) {
        if (!consumed_any || trailing_ws) return false; // flanking
        lexer->advance(lexer, false); // consume the close
        return true;
      }
      if (!(allowed & KIND_UNDERLINE)) return false;
      lexer->advance(lexer, false); // consume the nested open delimiter
      if (!validate_nested_open(lexer, KIND_UNDERLINE)) return false;
      consumed_any = true;
      trailing_ws = false;
      continue;
    }

    if (c == '*') {
      int run = 0;
      while (lexer->lookahead == '*' && run < 3) {
        lexer->advance(lexer, false);
        run++;
      }

      if (run == 1) {
        if (kind == KIND_ITALIC) {
          if (!consumed_any || trailing_ws) return false;
          return true;
        }
        if (!(allowed & KIND_ITALIC)) return false;
        if (!validate_nested_open(lexer, KIND_ITALIC)) return false;
      } else if (run == 2) {
        if (kind == KIND_BOLD) {
          if (!consumed_any || trailing_ws) return false;
          return true;
        }
        if (!(allowed & KIND_BOLD)) return false;
        if (!validate_nested_open(lexer, KIND_BOLD)) return false;
      } else { // run == 3
        if (!(allowed & KIND_BOLD_ITALIC)) return false;
        if (!validate_nested_open(lexer, KIND_BOLD_ITALIC)) return false;
      }
      consumed_any = true;
      trailing_ws = false;
      continue;
    }

    if (!consume_prose_piece(lexer)) return false;
    consumed_any = true;
    trailing_ws = false;
  }
}

// === Shared OPEN/CLOSE/whole-token emission ===
//
// `result_symbol = symbol; return true;` is the common tail of every
// scanner function in this file that succeeds — factored into
// `emit_symbol` below. `mark_end()` is deliberately NOT part of that
// shared tail, even though it precedes it everywhere: it has to run at
// a different LOGICAL moment for each caller —
//   - `emit_token` (used by `scan_boneyard`/`scan_note`/every CLOSE
//     token below): the whole match is already complete, so it marks
//     the end itself, immediately before the shared tail.
//   - `emit_open_if_valid` (used by every OPEN token except
//     bold_italic, not independently reachable as its own OPEN symbol —
//     see the file header): must mark the end BEFORE validating the
//     rest of the prospective span, locking the token's reported span
//     to just the delimiter regardless of how much further validation
//     advances beyond it (the standard "lookahead past the end" idiom)
//     — calling `emit_token` afterward would re-mark at validation's
//     end position instead, corrupting the span.
static bool emit_symbol(TSLexer *lexer, TokenType symbol) {
  lexer->result_symbol = symbol;
  return true;
}

static bool emit_token(TSLexer *lexer, TokenType symbol) {
  lexer->mark_end(lexer);
  return emit_symbol(lexer, symbol);
}

static bool emit_open_if_valid(TSLexer *lexer, Kind kind, unsigned allowed, TokenType symbol) {
  lexer->mark_end(lexer);
  if (!validate_content_and_close(lexer, kind, allowed)) return false;
  return emit_symbol(lexer, symbol);
}

// === Boneyard ===
//
// Assumes the caller has already confirmed lexer->lookahead == '/' and
// that any leading whitespace has already been skipped. Mirrors the JS
// regex `/\*([^*]|\*+[^*/])*\*+/`: the classic "find the first valid
// closing */" technique — a run of one or more '*' immediately followed
// by '/' always closes; a run followed by anything else (including
// another '*' — impossible, since the run is maximal — or a plain
// character) is content, along with that one following character.
// Content chars include '\n'/'\r' (no [^*] exclusion for them), which is
// what lets a boneyard span blank lines per the spec.
static bool scan_boneyard(TSLexer *lexer) {
  lexer->advance(lexer, false); // '/'
  if (lexer->lookahead != '*') return false;
  lexer->advance(lexer, false); // opening "/*"

  while (true) {
    if (lexer->lookahead == 0) return false; // EOF: unterminated

    if (lexer->lookahead != '*') {
      lexer->advance(lexer, false);
      continue;
    }

    while (lexer->lookahead == '*') {
      lexer->advance(lexer, false);
    }

    if (lexer->lookahead == '/') {
      lexer->advance(lexer, false); // closing "*/"
      return emit_token(lexer, BONEYARD);
    }
    if (lexer->lookahead == 0) return false; // EOF right after '*'+: unterminated

    // The star run wasn't a close; it and the one character after it
    // (already confirmed not '*' or EOF, but any other char including
    // '/' is fine here since it's not immediately following '*' anymore
    // — that '/' would only close a NEW run, handled by the next
    // iteration) are content together.
    lexer->advance(lexer, false);
  }
}

// === Note ===
//
// Assumes the caller has already confirmed lexer->lookahead == '[' and
// that any leading whitespace has already been skipped. Mirrors the JS
// regex this replaces:
//   \[\[NOTE_PIECE*(NL NOTE_NONWS_PIECE NOTE_PIECE*)*\]\]
//   - i.e. a first line of content, then zero or more further lines
//     each REQUIRED to start with a non-whitespace, non-']' piece — the
//     "no blank line inside a note" rule, enforced by rejecting a
//     continuation line that opens on whitespace, a newline (a truly
//     blank line), or ']' (which would otherwise let an empty
//     continuation close the note), all without needing lookahead.
//   - `\]` is a recognised escape (a literal ']' that doesn't end the
//     note); an unpaired backslash is not an error here — unlike
//     `consume_prose_piece`'s escaping of `*`/`_`, NOTE_CHAR itself
//     doesn't exclude '\', so a backslash not forming a valid `\]`
//     escape is simply one ordinary content character, exactly as the
//     regex it replaces would match it (NOTE_CHAR's char class has no
//     reason to exclude '\').
static bool scan_note(TSLexer *lexer) {
  lexer->advance(lexer, false); // first '['
  if (lexer->lookahead != '[') return false;
  lexer->advance(lexer, false); // second '['

  bool at_line_start = false;

  while (true) {
    int32_t c = lexer->lookahead;
    if (c == 0) return false; // EOF: unterminated

    if (at_line_start) {
      if (c == ' ' || c == '\t' || c == ']' || c == '\n' || c == '\r') {
        return false;
      }
      at_line_start = false;
      // falls through to handle this character as ordinary content below
    }

    if (c == ']') {
      lexer->advance(lexer, false);
      if (lexer->lookahead == ']') {
        lexer->advance(lexer, false);
        return emit_token(lexer, NOTE);
      }
      return false; // a lone ']' is not valid note content
    }

    if (c == '\n' || c == '\r') {
      if (c == '\r') {
        lexer->advance(lexer, false);
        if (lexer->lookahead != '\n') return false; // NL = \r?\n, not bare \r
      }
      lexer->advance(lexer, false); // consume '\n'
      at_line_start = true;
      continue;
    }

    if (c == '\\') {
      lexer->advance(lexer, false);
      if (lexer->lookahead == ']') {
        lexer->advance(lexer, false); // the escaped ']'
      }
      // else: the backslash itself was already one ordinary NOTE_CHAR;
      // whatever follows is handled fresh on the next iteration.
      continue;
    }

    lexer->advance(lexer, false); // ordinary NOTE_CHAR
  }
}

// === OPEN token scanner (underline only) ===
//
// Italic's and bold's OPEN scanning is inlined into the dispatcher's
// '*' branch instead of living here, because distinguishing them
// requires counting the star run first (see the dispatcher) — by the
// time that count is known, the delimiter is already consumed, so a
// separate "fresh from lookahead == '*'" function isn't reusable there.
// Underline has no such ambiguity ('_' is always exactly one
// character), so it keeps the simpler shape: confirm the delimiter,
// then hand off to `emit_open_if_valid` above.

static bool scan_underline_open(TSLexer *lexer) {
  lexer->advance(lexer, false); // '_'
  return emit_open_if_valid(lexer, KIND_UNDERLINE, NESTABLE_IN_UNDERLINE, UNDERLINE_OPEN);
}

// === OPEN token scanners (centered, parenthetical) ===
//
// Same "don't commit until a close is confirmed" idea as the emphasis
// OPEN scanners above, but much simpler: neither `centered` nor
// `parenthetical` nests (their own content never contains another
// instance of themselves), and grammar.js's CENTERED_PIECE/PAREN_PIECE
// already exclude their own delimiter characters from ordinary content
// — including inside a nested emphasis span, which still uses the
// plain, unmodified `_emphasis_content_run` token, unaware of the
// outer container's delimiters. So there's no recursive
// validate-and-dispatch needed: a single linear scan for the first
// occurrence of the close character is exactly equivalent to what the
// real grammar walk does afterward.
static bool validate_simple_close(TSLexer *lexer, int32_t close_char) {
  while (true) {
    int32_t c = lexer->lookahead;
    if (c == 0 || c == '\n' || c == '\r') return false; // no close on this line
    if (c == close_char) return true;
    lexer->advance(lexer, false);
  }
}

// `scan_centered_open`/`scan_paren_open` differ only in which close
// character to look for and which symbol to report on success — real
// work shared here rather than duplicated between two near-identical
// bodies.
static bool scan_simple_open(TSLexer *lexer, int32_t close_char, TokenType symbol) {
  lexer->advance(lexer, false); // the opening delimiter
  lexer->mark_end(lexer);
  if (!validate_simple_close(lexer, close_char)) return false;
  return emit_symbol(lexer, symbol);
}

static bool scan_centered_open(TSLexer *lexer) {
  return scan_simple_open(lexer, '<', CENTERED_OPEN);
}

static bool scan_paren_open(TSLexer *lexer) {
  return scan_simple_open(lexer, ')', PAREN_OPEN);
}

// === Dispatcher ===

bool tree_sitter_fountain_external_scanner_scan(
    void *payload, TSLexer *lexer, const bool *valid_symbols) {
  (void)payload;

  bool want_boneyard = valid_symbols[BONEYARD];
  bool want_note = valid_symbols[NOTE];
  bool want_italic_open = valid_symbols[ITALIC_OPEN];
  bool want_italic_close = valid_symbols[ITALIC_CLOSE];
  bool want_bold_open = valid_symbols[BOLD_OPEN];
  bool want_bold_close = valid_symbols[BOLD_CLOSE];
  bool want_underline_open = valid_symbols[UNDERLINE_OPEN];
  bool want_underline_close = valid_symbols[UNDERLINE_CLOSE];
  bool want_centered_open = valid_symbols[CENTERED_OPEN];
  bool want_paren_open = valid_symbols[PAREN_OPEN];

  if (!want_boneyard && !want_note && !want_italic_open && !want_italic_close &&
      !want_bold_open && !want_bold_close && !want_underline_open &&
      !want_underline_close && !want_centered_open && !want_paren_open) {
    return false;
  }

  // Leading whitespace: skipped, never part of the reported span. Not
  // relevant to CLOSE tokens — see the file header on why real parsing
  // never reaches a CLOSE scan with pending leading whitespace.
  while (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
    lexer->advance(lexer, true);
  }

  if (want_boneyard && lexer->lookahead == '/') {
    return scan_boneyard(lexer);
  }

  if (want_note && lexer->lookahead == '[') {
    return scan_note(lexer);
  }

  if (want_centered_open && lexer->lookahead == '>') {
    return scan_centered_open(lexer);
  }

  if (want_paren_open && lexer->lookahead == '(') {
    return scan_paren_open(lexer);
  }

  if (lexer->lookahead == '_') {
    // CLOSE and OPEN for the same kind are never simultaneously valid
    // at one parser state:
    //   - Same-type re-nesting is excluded, so `underline`'s own
    //     content never offers `underline` as a further alternative —
    //     see the file header.
    //   - Order between the two checks below therefore never matters in
    //     practice; CLOSE is checked first only because it is the more
    //     specific of the two.
    if (want_underline_close) {
      lexer->advance(lexer, false);
      return emit_token(lexer, UNDERLINE_CLOSE);
    }
    if (want_underline_open) return scan_underline_open(lexer);
    return false;
  }

  if (lexer->lookahead == '*') {
    if (!want_italic_open && !want_italic_close && !want_bold_open && !want_bold_close) {
      return false;
    }

    // Unlike '_', '*' needs its run length counted before any decision
    // can be made:
    //   - ITALIC_CLOSE and BOLD_OPEN (for a nested bold starting right
    //     where italic's content could also legally end) CAN be
    //     simultaneously valid at one shared "which repeat alternative
    //     comes next" parser state, and only the actual character count
    //     on the line (1 star vs 2) distinguishes them.
    //   - Advancing here is safe regardless of how this resolves: the
    //     tree-sitter runtime discards any advancing from a `scan` call
    //     that ultimately returns false.
    lexer->advance(lexer, false);
    if (lexer->lookahead != '*') {
      // Exactly one '*': italic's territory only.
      if (want_italic_close) return emit_token(lexer, ITALIC_CLOSE);
      if (want_italic_open) {
        return emit_open_if_valid(lexer, KIND_ITALIC, NESTABLE_IN_ITALIC, ITALIC_OPEN);
      }
      return false;
    }

    lexer->advance(lexer, false);
    if (lexer->lookahead == '*') return false; // '***': bold_italic's territory, not ours

    // Exactly two '*': bold's territory only.
    if (want_bold_close) return emit_token(lexer, BOLD_CLOSE);
    if (want_bold_open) {
      return emit_open_if_valid(lexer, KIND_BOLD, NESTABLE_IN_BOLD, BOLD_OPEN);
    }
    return false;
  }

  return false;
}
