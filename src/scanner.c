#include "tree_sitter/parser.h"
#include <stdbool.h>
#include <stdint.h>

// === External tokens (#40, #40-boneyard) ===
//
// Two tokens live here: `underline` and `boneyard`. Everything else in
// this grammar stays on the GLR + dynamic-precedence approach the file
// header describes; these exist solely to give each token a correctly
// bounded span when preceded by whitespace — see the notes above
// `underline` and `boneyard` in grammar.js for the full story of why the
// internal (non-external) lexer can't do this: token selection there is
// resolved once, deterministically, before GLR ever gets a chance to
// fork, so no in-grammar trick can make a whitespace token conditional on
// "a delimiter actually follows" without also winning at every OTHER
// position where it's reachable.
//
// `lexer->advance(lexer, true)` marks a character as skipped ("skip"):
// consumed, but excluded from the span of whatever token eventually gets
// returned. Using it for the leading run of spaces/tabs, then switching to
// `advance(lexer, false)` once the real delimiter starts, is the standard
// idiom for exactly this ("trim leading trivia from a token's span") —
// documented in tree-sitter's own external-scanner guide, and used the
// same way in tree-sitter-php, tree-sitter-lua and tree-sitter-nix.
//
// The leading whitespace-skip is hoisted into the dispatcher (`scan`)
// rather than duplicated in each sub-scanner: once a lexer has been
// advanced, there is no way to rewind it from within scanner code, so if
// one sub-scanner speculatively consumed characters before failing, a
// second sub-scanner attempted afterward in the same call would start
// from the wrong position. Peeking one character after the shared
// whitespace-skip to decide which (if either) delimiter is even a
// candidate avoids that entirely — `_` and `/` never overlap, so at most
// one sub-scanner is ever invoked per call.

enum TokenType { UNDERLINE, BONEYARD };

// No state to carry between calls (no serialize/deserialize needed), so
// every hook below is a no-op except `scan` itself — the (void) casts
// just silence unused-parameter warnings on an otherwise-fixed signature.
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
//   PROSE_CHAR   = [^ \t\r\n*_\\/] | /[^*\r\n]
//   ESCAPED_DELIM = \\[*_]
// Returns true and advances past exactly one piece (1 or 2 codepoints) on
// success. Returns false on any dead end; the caller aborts the whole
// match in that case, so it is safe to have already advanced here.
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

// Assumes the caller has already confirmed lexer->lookahead == '_' and
// that any leading whitespace has already been skipped.
static bool scan_underline(TSLexer *lexer) {
  lexer->advance(lexer, false); // opening delimiter

  bool consumed_any_piece = false;
  bool trailing_ws_pending = false;

  while (true) {
    int32_t c = lexer->lookahead;
    if (c == '_') break; // the only possible closing delimiter position
    if (c == ' ' || c == '\t') {
      // FLANKING_SAFE allows interior whitespace, but never before the
      // first piece (a bare "_ word_" must not match).
      if (!consumed_any_piece) return false;
      lexer->advance(lexer, false);
      trailing_ws_pending = true;
      continue;
    }
    if (!consume_prose_piece(lexer)) return false;
    consumed_any_piece = true;
    trailing_ws_pending = false;
  }

  // The flanking rule: the closing delimiter must immediately follow a
  // PROSE_PIECE, never trailing whitespace ("_word _" does not close).
  if (!consumed_any_piece || trailing_ws_pending) return false;

  lexer->advance(lexer, false); // closing delimiter
  lexer->mark_end(lexer);
  lexer->result_symbol = UNDERLINE;
  return true;
}

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
      lexer->mark_end(lexer);
      lexer->result_symbol = BONEYARD;
      return true;
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

bool tree_sitter_fountain_external_scanner_scan(
    void *payload, TSLexer *lexer, const bool *valid_symbols) {
  (void)payload;
  if (!valid_symbols[UNDERLINE] && !valid_symbols[BONEYARD]) return false;

  // Leading whitespace: skipped, never part of the reported span. Shared
  // across both sub-scanners — see the header note on why.
  while (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
    lexer->advance(lexer, true);
  }

  if (valid_symbols[BONEYARD] && lexer->lookahead == '/') {
    return scan_boneyard(lexer);
  }
  if (valid_symbols[UNDERLINE] && lexer->lookahead == '_') {
    return scan_underline(lexer);
  }
  return false;
}
