/**
 * @file Tree-sitter grammar for Fountain (https://fountain.io), a plain-text
 * screenplay markup format.
 * @author Dr Griffith Rees <info@box3spool5.org>
 * @license MIT
 *
 * The element definitions and disambiguation rules implemented here follow
 * the Fountain syntax specification: https://fountain.io/syntax
 *
 * Approach: in Fountain, the meaning of each line of text in the file is
 * determined by its content and by the blank lines around it — for example,
 * an uppercase line is a character cue only when the line below it is not
 * blank; otherwise it is action. This grammar therefore treats each
 * text line as a single token that includes its trailing newline, and
 * treats a blank line as its own `_blank` token separating blocks.
 * (Scene headings are the one exception: they are split into smaller
 * tokens so their prefix, location and time appear as separate nodes —
 * see the scene heading rules below.)
 *
 * Where deciding a line's meaning needs a peek at the NEXT line (the
 * character cue vs. action case above), the grammar declares a conflict,
 * which makes tree-sitter parse that stretch with GLR parsing [1]: the
 * parser follows the possible readings of the line in parallel and
 * drops each one as soon as a later token rules it out. If more than
 * one reading survives, the one whose rules carry the most dynamic
 * precedence (`prec.dynamic`) wins. This is what lets the grammar avoid
 * an external C scanner.
 *
 * [1] GLR ("generalized left-to-right, rightmost-derivation") parsing:
 *     an ordinary LR parser must commit to a single reading at every
 *     step; the generalized form may pursue several at once. See the
 *     Glossary section of README.md for a fuller definition and links
 *     to tree-sitter's implementation.
 *
 * Earlier drafts of this grammar (preserved in `grammar-old.js`) drew on
 * UserNobody14's tree-sitter-fountain:
 * https://github.com/UserNobody14/tree-sitter-fountain
 * This rewrite takes a different approach, but that project's work is
 * gratefully acknowledged.
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

'use strict';

const NL = '\\r?\\n';
// Line end that also accepts end-of-file (no trailing newline). Only safe
// for tokens whose leading marker is distinctive; the character cue and
// transition tokens must require a real newline, since matching a mere
// prefix of a line would misclassify it.
const EOL = `(${NL})?`;

/** Case-insensitive pattern for a literal word. */
function ci(word) {
  return word
    .split('')
    .map((c) => (/[a-z]/i.test(c) ? `[${c.toUpperCase()}${c.toLowerCase()}]` : c))
    .join('');
}

const SCENE_PREFIX =
  `(${ci('INT')}\\.?/${ci('EXT')}` +
  `|${ci('EXT')}` +
  `|${ci('EST')}` +
  `|${ci('INT')}` +
  `|${ci('I')}/${ci('E')})`;

const TITLE_KEYS = [
  'draft date',
  'title',
  'credit',
  'authors',
  'author',
  'source',
  'contact',
  'notes',
  'copyright',
  'revision',
  'date',
]
  .map(ci)
  .join('|');

// A character cue's bare name (#56): at least one uppercase letter, no
// lowercase; digits, spaces and simple punctuation allowed. Matched by
// `$._character_name` — an EXTERNAL token, not a plain regex here (see
// src/scanner.c's `scan_character_name` for why). Extensions
// ("(V.O.)"/"(CONT'D)") and the "^" dual-dialogue marker are separate
// tokens below, sequenced after it.
const CHARACTER_EXTENSION = `\\([^()\\r\\n]*\\)`;

// Any non-blank line's content. Shared by `_any_line` and
// `_indented_line` below — same alphabet, only the leading indentation
// requirement differs between them.
//   - Stops before "/*", so a boneyard that opens mid-line — even one
//     closing on a later line — is picked up by the `boneyard` extra
//     instead of being swallowed by the line (#31).
//   - The lone "/" alternative keeps a slash at the end of a line, or
//     an unclosed "/*", lexing as plain text rather than an error.
//   - Token regular expressions cannot peek ahead, so "not containing
//     /*" is spelled out as "runs of either a non-slash character or a
//     slash followed by a non-star".
//   - A trailing /? on the main alternative would be wrong: longest-
//     match would then swallow the opening slash of a real boneyard.
const ANY_LINE_BODY = `(([^/\\r\\n]|/[^*\\r\\n])+|/)`;

// A single marker character ('~'/'='/'!') followed by prose content to
// end of line — the shared shape behind `_lyric_line`, `_synopsis_line`
// and `_forced_action_line` (#38 cheap tier).
//   - Factored out rather than repeated three times with only the
//     marker rule differing.
//   - `marker` must be a `$.`-referenced rule (not an inline token),
//     since each caller needs its own distinctly-named marker for the
//     lexer precedence reasoning documented at each call site.
//   - `piece` defaults to the ordinary `_prose_piece`; `_forced_action_line`
//     (#19) passes `_action_prose_piece` instead, so forced action gets
//     the same all-caps treatment as ordinary action — see that rule's
//     own comment.
function markedProseLine($, marker, piece) {
  return seq(marker, repeat(piece ?? $._prose_piece), optional($._scene_eol));
}

// A dialogue block's own shape: a character cue followed by one or more
// lines of content.
//   - Factored out (#11) so `dual_dialogue` can build its SECOND member
//     from the mandatory-marker `_dual_character` cue.
//   - Still produces the exact same node shape ordinary `dialogue`
//     does — see `dual_dialogue`'s own comment for why that matters.
function dialogueBody($, character) {
  return seq(
    field('character', character),
    repeat1(choice($.parenthetical, $.lyric, alias($._prose_line, $.dialogue_line)))
  );
}

// A structured character cue: name (bare or forced "@NAME"), zero-or-
// more extensions, and the '^' dual-dialogue marker.
//   - Shared by `character` and `_dual_character` (#11) — they differ
//     only in whether the marker is optional or required.
//   - `markerRequired: false` (`character`):
//     - Bare-name branch has no fallback of its own — name, extensions
//       and marker are all pre-validated by the external
//       `_character_name` token (see its own comment).
//     - Forced-name branch keeps its flat `_forced_character_line`
//       fallback for a malformed extension.
//   - `markerRequired: true` (`_dual_character`): drops that flat
//     fallback entirely — it has no marker field to offer, so it could
//     never satisfy "marker required"; keeping it would be dead grammar.
function characterCue($, markerRequired) {
  const marker = field('marker', alias($._character_marker, $.character_marker));
  const bareName = seq(
    field('name', alias($._character_name, $.character_name)),
    repeat(field('extension', alias($._character_extension, $.character_extension))),
    markerRequired ? marker : optional(marker),
    $._character_eol
  );
  const forcedName = seq(
    field('name', alias($._forced_character_name, $.character_name)),
    repeat(field('extension', alias($._character_extension, $.character_extension))),
    markerRequired ? marker : optional(marker),
    $._character_eol
  );
  return markerRequired
    ? choice(bareName, forcedName)
    : choice(bareName, choice(forcedName, $._forced_character_line));
}

// A container's own open/close delimiter pair, wrapping content that
// may include ANY of the four emphasis types (`centered`/
// `parenthetical`, #38 Tier 2) plus a plain content-run token specific
// to that container. Unlike `italic`/`bold`/`underline` (which each
// exclude THEMSELVES from their own nestable set, since they mutually
// recurse — see the "Inline emphasis" comment below), `centered` and
// `parenthetical` aren't part of that recursive set at all, so both
// always offer the same unfiltered choice of all four — genuinely
// identical between the two, not just similar, which is what makes
// this worth sharing rather than writing out twice.
function containerLine($, open, contentRun, close) {
  return seq(
    open,
    repeat(choice($.italic, $.bold, $.bold_italic, $.underline, contentRun)),
    close,
    optional($._scene_eol)
  );
}

// === Inline emphasis (#8) ===
//
// One character of plain inline prose content: excludes the emphasis
// delimiters ('*', '_') and a backslash (reserved for escaping). Two
// characters additionally need "first refusal" for a longer delimiter
// that might start with them, so a longer match wins the lexer's
// longest-match tie-break instead of `_prose_text` swallowing it whole:
//   - '/' immediately followed by '*' — mirrors the boneyard fix (#31),
//     so a boneyard opening mid-line still gets recognised.
//   - '[' immediately followed by another '[' — the same fix for notes
//     (#9): `note`'s own token is otherwise shorter than the rest of
//     the line and would simply lose the tie-break.
// A lone '[' not forming "[[" (including one at the very end of a
// line, with nothing valid to pair it with) still falls through to the
// `_lbracket` token below, the same pattern `_slash` uses for a lone
// '/'.
// One character of plain content, parameterized by an extra set of
// excluded characters on top of the base alphabet (space/tab/CR/LF/
// '*'/'_'/'\\'/'[' — see the paragraph above for why each of those is
// there). `PROSE_CHAR` below is this called with no extra exclusions;
// `parenthetical`/`centered` (#38 Tier 2) call it with their own
// closing delimiter (')'/'<') added, so a content run stops before it
// instead of swallowing it — the same "first refusal" concern as
// '/*'/'[[' above, just for a different container.
//   - A function, not per-variant constants: the THREE alternatives
//     here (base class, '/'-lookahead, '['-lookahead) are one piece of
//     shared logic, not just shared text — a future change to how a
//     character class is built (not just which characters it excludes)
//     only needs editing this one function body, not three near-
//     duplicate regex strings kept in sync by hand.
//   - The two-character lookahead alternatives get the extra exclusions
//     in their SECOND character slot too: without that, e.g. a '/'
//     immediately followed by a container's own ')' would be wrongly
//     swallowed together as one piece, hiding the close.
function proseChar(extraExcluded = '') {
  return `([^ \\t\\r\\n*_\\\\/\\[${extraExcluded}]` +
    `|/[^*\\r\\n${extraExcluded}]` +
    `|\\[[^\\[\\r\\n${extraExcluded}])`;
}

const PROSE_CHAR = proseChar();

// A backslash-escaped delimiter is safe content too — writes a literal
// delimiter character without triggering its special meaning:
//   - '\*' / '\_' escape emphasis, per spec (e.g. "\*9765\*" shows
//     literal asterisks).
//   - '\/' and '\[' are this grammar's own extension (not in the spec,
//     which has no note/boneyard escape syntax): each defuses one side
//     of the two-character "/*" or "[[" lookahead above (#9), which is
//     enough to stop it opening — a boneyard or note needs both
//     characters live to open.
const ESCAPED_DELIM = `\\\\[*_/\\[]`;

// Same pairing as proseChar/PROSE_CHAR: a function (piece = char OR
// escaped delimiter, parameterized) plus the unparameterized default as
// a constant.
function prosePiece(extraExcluded = '') {
  return `(${proseChar(extraExcluded)}|${ESCAPED_DELIM})`;
}

const PROSE_PIECE = prosePiece();

// Parenthetical/centered content (#38 Tier 2) — see proseChar's own
// comment for why these exist. Both exclude BOTH of their construct's
// delimiter characters, symmetrically ('()' / '><') — stricter than the
// flat token `centered` replaces, which excluded only '<' and let a
// stray '>' appear as ordinary content. Centered has two genuinely
// distinct delimiter characters (unlike e.g. `~`'s single marker), so
// treating both as reserved is the more consistent choice: a stray '>'
// mid-content now fails the parse (falls back to literal, the same
// "fail closed" pattern unclosed emphasis already uses) instead of
// being silently absorbed.
const PAREN_PIECE = prosePiece('()');
const CENTERED_PIECE = prosePiece('><');

// A run of content that itself starts and ends on a PROSE_PIECE
// (interior spaces/tabs are fine). This "sandwich" shape is what makes
// the spec's flanking rule enforceable without lookahead, which token
// regular expressions cannot do ("*69 and then *23" does not
// italicize — spaces around emphasis markers are meaningful, "as with
// Markdown"): the token can never absorb a disqualifying trailing
// space as though it were harmless interior content, so wherever no
// valid pairing exists, the surrounding regex engine's own (ordinary,
// non-lookaround) backtracking fails the whole match rather than
// partially matching.
const FLANKING_SAFE = `${PROSE_PIECE}((${PROSE_PIECE}|[ \\t])*${PROSE_PIECE})?`;

// === All-caps words in action (#19) ===
//
// A character usable inside an all-caps "word": BASE, or a hyphen
// followed by another BASE character.
//   - BASE excludes a lowercase letter, whitespace, one of the inline-
//     emphasis/note/boneyard delimiter characters PROSE_CHAR already
//     treats as reserved ('*'/'_'/'\\'/'/'/'['), or one of ','/'.'/':'/
//     ';'/'!'/'?'/'"' — clause/sentence punctuation (English-specific;
//     Unicode/other-language punctuation is out of scope, same as #22
//     generally), not part of the word itself.
//     - The delimiter exclusions give a caps run first refusal against
//       a directly-adjacent emphasis/note/boneyard opener, same idea as
//       PROSE_CHAR's own two-character lookaheads (just via outright
//       exclusion here, since nothing needs to stay literal content the
//       way an unpaired '/' or '[' does): "GUN*bang*" stops before '*'.
//     - The punctuation exclusions mean "BAND,"/"JACK."/"TIME:"/
//       "STOP!"/"WHAT?" highlight as "BAND"/"JACK"/"TIME"/"STOP"/"WHAT",
//       leaving the punctuation as ordinary trailing content — the same
//       way a sentence's own final period is never highlighted along
//       with the last word before it.
//     - There's no single Unicode/regex "punctuation" class that fits
//       here: some punctuation (apostrophe, parentheses) stays INCLUDED
//       on purpose, so "CONT'D"-style contractions still form one word
//       — this has to be a curated exclusion list, not a blanket class.
//     - `&` needs no exclusion of its own: it's not a letter or digit,
//       so it can never form a word on its own (CAP_WORD's own
//       requirements already fail it), and it isn't in this class
//       either — "BRICK & STEEL" already comes out as two separate caps
//       words with the "&" as plain text between them, nothing to fix.
//     - A double quote is excluded even though the SAME character often
//       opens a quotation too ("STOP" she said" vs a closing one) —
//       this grammar has no way to tell which, so it's treated
//       uniformly as a boundary; a single quote/apostrophe is NOT
//       excluded for the opposite reason (excluding it would break
//       "CONT'D"), leaving one narrow, accepted overlap: a single-
//       quoted word like 'STOP' still keeps its closing quote.
//   - A lone hyphen stays part of the word (so "T-1000"/"DEAD-END" still
//     form one word), but the SAME character immediately followed by
//     ANOTHER hyphen does not: "--" is a dash used as a separator, not a
//     compound-word joiner, so "LANDSCAPE--STRIKING" splits into two
//     words. Written as its own alternative (a hyphen, then a BASE
//     character) rather than folded into BASE itself, since BASE's own
//     job is "one ordinary character" — pairing a hyphen with what
//     follows it needs the same two-character technique PROSE_CHAR uses
//     for '/*'/'[[', just checking the OPPOSITE thing (that what
//     follows ISN'T disqualifying, rather than that it IS).
//   - Deliberately ASCII-only, like the rest of this grammar (Unicode
//     support is tracked separately as #22) — a future case-folding fix
//     belongs there, not duplicated here.
const CAPS_CHAR =
  `([^a-z \\t\\r\\n*_\\\\/\\[,.:;!?"\\-]` +
  `|-[^a-z \\t\\r\\n*_\\\\/\\[,.:;!?"\\-])`;

// One "word": 2+ characters built from CAPS_CHAR, with at least one
// uppercase letter somewhere in it.
//   - A run of pure punctuation/digits doesn't qualify, and neither
//     does a single stray capital ("A"/"I") — otherwise every sentence-
//     initial article or pronoun in ordinary action prose would fire.
//   - The leading character is deliberately restricted to [A-Z0-9]
//     rather than the full CAPS_CHAR class (which also contains e.g.
//     '~'/'='/'!'/'#'/'>', this grammar's OWN block-marker characters,
//     each only meaningful as a line's very first character).
//     - An earlier, more permissive version let a marker combine with
//       the very next uppercase letter into what looked like a legal
//       2-character word (e.g. "~A" in "~A *lyric* line") — since that
//       starts at the same lexer position as the marker token itself,
//       and `caps`/`_lyric_marker` share the same `prec(3)`, the LONGER
//       match won the tie and silently turned an entire `lyric` block
//       into `action` instead.
//     - Restricting the leading character removes the collision at its
//       source: none of those marker characters can ever start a
//       `caps` word, so they never compete with it for a token starting
//       in the same place.
//   - Two alternatives, not one pattern plus a lookahead (the Rust regex
//     crate tree-sitter compiles against — see the Development section
//     of README.md — has no lookaround support):
//     - A letter-first word needs only 1+ more CAPS_CHAR to reach the
//       2-character minimum (the leading letter already satisfies "has
//       an uppercase letter").
//     - A digit-first word additionally needs a real [A-Z] somewhere in
//       its own tail, or a lone number like "2016" would wrongly
//       qualify.
const CAP_WORD = `([A-Z]${CAPS_CHAR}+|[0-9]${CAPS_CHAR}*[A-Z]${CAPS_CHAR}*)`;

// A run of one or more such words joined by a single literal space.
//   - E.g. "JOHN SMITH" or "CAPTION (V.O.)" stay one combined `caps`
//     node, matching the convention's own "character's first
//     introduction" case (#19's issue text).
//   - Exactly one space, not `[ \t]+`: two-or-more spaces (or a tab)
//     between otherwise-qualifying words is treated as a real break
//     instead — an accepted simplification, see `caps`'s own comment
//     below for the fuller design discussion.
const CAP_RUN = `${CAP_WORD}( ${CAP_WORD})*`;

// `_action_prose_text`'s own alphabet (#19): like PROSE_CHAR (see its
// own comment above), plus one more exclusion.
//   - Refuses to fold an uppercase letter together with a FOLLOWING
//     all-caps-compatible character into ordinary content — giving
//     `caps` below the same kind of two-character "first refusal"
//     PROSE_CHAR already grants '/*' and '[[', just for a different
//     rival, and in the opposite direction (excluding an unsafe
//     pairing, rather than permitting a safe one).
//   - Why this is needed at all:
//     - `_action_prose_text`'s greedy FLANKING_SAFE-based match has no
//       natural stopping point partway through a line — it doesn't
//       distinguish letters by case, so e.g. "A GUN gleams." would be
//       swallowed as ONE token, "GUN" included, since nothing before it
//       hints a caps word is coming.
//     - Precedence alone (as `_lyric_marker`/`_synopsis_marker`/
//       `_forced_action_marker` use against plain `_prose_text`) only
//       decides which of two tokens STARTING AT THE SAME POSITION wins
//       — it can't make a token stop partway through a match it's
//       already committed to, which is exactly what's needed here.
//   - The exclusion itself: an uppercase letter is only ordinary
//     content when followed by a LOWERCASE letter (an ordinary word
//     like "The").
//     - Anything else that could extend a caps word (another uppercase
//       letter, a digit, or one of CAP_WORD's own CAPS_CHAR punctuation
//       characters) is refused, opening a token boundary for `caps` to
//       claim instead.
//     - A solo uppercase letter with nothing safe to pair with (line-
//       final, or directly against a delimiter) falls to `_caps_letter`
//       below — same "structured token failed, one literal character
//       instead" idiom `_star`/`_underscore` already use.
//   - Deliberately letter-led only, not digit-led:
//     - A digit-led caps word (e.g. "9MM") needs to confirm a real
//       letter appears somewhere LATER in the run, which a fixed
//       2-character lookahead can't determine in general — an accepted
//       scope limit.
//     - Still fully recognised when it starts a fresh piece already
//       (right after a marker, an emphasis span, or at the very start
//       of a line, where `caps`'s own longer match simply wins on
//       length).
//     - Mid-run, preceded by ordinary prose with no boundary in
//       between, only its trailing letters are recognised — its own
//       leading digits fall to the ordinary base class instead, one
//       boundary earlier than ideal but never a parse error.
const ACTION_PROSE_CHAR =
  `([^ \\t\\r\\n*_\\\\/\\[A-Z]` +
  `|/[^*\\r\\n]` +
  `|\\[[^\\[\\r\\n]` +
  `|[A-Z][a-z])`;

function actionProsePiece() {
  return `(${ACTION_PROSE_CHAR}|${ESCAPED_DELIM})`;
}

const ACTION_PROSE_PIECE = actionProsePiece();

// Same "sandwich" shape as FLANKING_SAFE above, built on
// ACTION_PROSE_PIECE instead of PROSE_PIECE.
const ACTION_FLANKING_SAFE =
  `${ACTION_PROSE_PIECE}((${ACTION_PROSE_PIECE}|[ \\t])*${ACTION_PROSE_PIECE})?`;

// === Notes (#9, #38-span-fix) ===
//
// `note`'s matching now lives in src/scanner.c's `scan_note`, alongside
// `boneyard`:
//   - Content excludes ']' (reserved for the closing "]]") and any
//     newline except a backslash-escaped ']'; continuation lines after
//     the first may not start with whitespace — the "no blank lines
//     inside a note" rule.
//   - Like `boneyard`, `note` needs `advance(lexer, skip)` to keep
//     leading whitespace out of its reported span, a bug that existed
//     unnoticed since #9 (a plain regex token can't do this — see the
//     fuller explanation above `italic` below) until it was caught and
//     fixed alongside #38's scanner work.
//   - Declared only in `externals` above — an external token needs no
//     `rules` entry here.

module.exports = grammar({
  name: 'fountain',

  // The grammar's deliberate exception to "no external C scanner" (see
  // the file header). Two different problems land here:
  //   - `boneyard` and `note` need to consume leading whitespace without
  //     that whitespace counting toward their reported span, which is
  //     what `advance(lexer, skip)` exists for (#40, and the identical
  //     bug in `note` fixed alongside #38 — see src/scanner.c).
  //   - `italic`/`bold`/`underline`/`centered`/`parenthetical`'s OPEN
  //     tokens need to validate, before ever committing to a structured
  //     reading, that a legal nested/closing match exists later in the
  //     line — the fix for a real GLR limitation that ruled out a
  //     pure-grammar version of same-line nested emphasis (#38), and
  //     confirmed necessary again for `centered`/`parenthetical` when a
  //     plain-token attempt hit the identical failure mode against an
  //     unclosed forced transition (#38 Tier 2 — see src/scanner.c for
  //     the full rationale on both).
  //   - `caps` (#19) was tried as a THIRD external-scanner candidate too
  //     (same leading-whitespace span bug as `boneyard`/`note`), but
  //     reverted:
  //     - `caps` and `CHARACTER_NAME` alphabets genuinely overlap
  //       ([A-Z0-9]), and unlike a grammar-level conflict, the LEXER can
  //       only return ONE token for a given position — there is no
  //       external-scanner equivalent of "try A, and if it fails, try B
  //       from the same start" once `scan_character_name` has advanced.
  //     - Worse, confirmed empirically: an external token wins
  //       UNCONDITIONALLY over ANY internal one on success, with no
  //       visibility into which internal tokens are also live at that
  //       position.
  //     - `caps` firing externally silently ate `transition`'s own
  //       `_transition_line` token whenever a transition directly
  //       followed action with no blank line (`_block`'s one exception
  //       to needing a blank between siblings) — that position has
  //       `_transition_line` internally competing but no
  //       `CHARACTER_NAME` to guard against it.
  //     - `caps` stays a plain, internal token below instead (see its
  //       own comment) — the leading-whitespace span inaccuracy is a
  //       known, accepted limitation, not worth this amount of
  //       collision risk with every other internal token in the grammar
  //       to fix.
  // Order here must match `enum TokenType` in src/scanner.c exactly —
  // external token identity is positional.
  externals: ($) => [
    $.boneyard,
    $.note,
    $._italic_open,
    $._italic_close,
    $._bold_open,
    $._bold_close,
    $._underline_open,
    $._underline_close,
    $._centered_open,
    $._paren_open,
    $._character_name,
    $._forced_character_name,
  ],

  extras: ($) => [/[ \t]+/, $.note, $.boneyard],

  conflicts: ($) => [
    // Same fork as scene_heading/_scene_start_line below (#56): while
    // the parser is still deciding character vs. action, both readings
    // share the same small token sequence — see `_character_cue_line`
    // below. This supersedes a plain `[$.character, $.action]` entry
    // (tree-sitter 0.26 flags that one "unnecessary" once this more
    // specific entry exists; kept as just this one to stay warning-free).
    [$.character, $._character_cue_line],
    // The heading-or-action fork: a heading-shaped line may instead be
    // the first line of an action paragraph (decided by whether a blank
    // line follows). While both readings are alive, each part of the
    // structured heading is also, in the action reading, just another
    // token absorbed by the hidden `_scene_start_line` rule.
    [$.scene_heading, $._scene_start_line],
    [$.location, $._scene_start_line],
    [$.transition, $.action],
    // Inside a scene heading, a dash can either extend the location
    // (locations may contain hyphens, as in "DEAD-END STREET") or
    // introduce the time-of-day ("... - DAY"). The parser follows both
    // readings (GLR parsing; see the header comment). `time` carries
    // extra dynamic precedence, so the reading that splits at the LAST
    // dash wins: a split at any earlier dash cannot parse the rest of
    // the line and dies off.
    [$.location],
    // The dual-dialogue fork (#11): after a `dialogue` block and its
    // trailing blank(s), still deciding whether it stands alone as its
    // own `_block` or is the `first` half of a `dual_dialogue`.
    //   - Resolved by `dual_dialogue`'s own `prec.dynamic`.
    //   - Both readings need declaring here first, so the parser follows
    //     each long enough to find out.
    [$._block, $.dual_dialogue],
  ],

  rules: {
    // #38 regression fix (see `title_entry`'s own comment for the full
    // mechanism): when `title_page` is present, at least one real blank
    // line is now REQUIRED before the first `_block` — closing the
    // "title_page ends here, with zero blank lines, and a block starts
    // immediately" loophole that let a title_value line lose to a
    // stray `action` reading. `title_entry`'s `repeat1` fix only
    // covered a title's FIRST continuation value; this covers every
    // value position (and every point within `title_page` generally),
    // since it removes the zero-blank exit for the WHOLE construct at
    // once, not one call site within it.
    //   - When there's no `title_page` at all, blank lines before the
    //     first block stay optional (0+), same as before — this only
    //     tightens the boundary that sits directly after a title page.
    //   - `optional(...)` around the post-title_page body preserves the
    //     "title page is the entire file" case: no trailing blank line
    //     is required if nothing follows it at all.
    // The block-sequence shape itself (`_blocks` below) is identical in
    // both branches — factored out rather than duplicated. Wrapped in
    // `optional()` at each call site, not inside `_blocks` itself:
    // tree-sitter forbids a non-start rule from matching the empty
    // string, so "zero blocks at all" has to live at the reference,
    // not in the shared rule's own definition.
    screenplay: ($) =>
      choice(
        seq($.title_page, optional(seq(repeat1($._blank), optional($._blocks)))),
        seq(repeat($._blank), optional($._blocks))
      ),

    // One or more blocks. Each is usually followed by at least one
    // blank line before the next — except the very last, which may
    // instead end right at EOF with no trailing blank at all (the
    // trailing, non-repeated `$._block` below carries no such
    // requirement). Shared by both `screenplay` branches above.
    _blocks: ($) => seq(repeat(seq($._block, repeat1($._blank))), $._block),

    _block: ($) =>
      choice(
        $.scene_heading,
        $.transition,
        // In practice (e.g. the canonical Brick & Steel sample) a
        // transition may directly follow an action paragraph with no
        // blank line between them.
        seq($.action, $.transition),
        $.centered,
        $.lyric,
        $.synopsis,
        $.section,
        $.page_break,
        $.dual_dialogue,
        $.dialogue,
        $.action
      ),

    // === Title page ===

    title_page: ($) => repeat1($.title_entry),

    title_entry: ($) => {
      // Per spec (#48 — see `_title_indent`'s own comment): only a
      // value directly on the key's own line is exempt from
      // indentation; every value on a following line of its own must
      // be indented.
      //
      // `title_value`'s content is `_prose_line` itself (#49) — the
      // SAME emphasis-aware rule action/dialogue already use — rather
      // than the flat, opaque `_any_line`/`_indented_line` tokens this
      // replaces, so e.g. "Title:\n\t_**BRICK & STEEL**_" (the
      // canonical Brick & Steel title, and the regression case in the
      // corpus test below) now gets real `underline`/`bold` children
      // instead of literal, unstyled text. Only `title_value` gets
      // this treatment, not `section_title` — out of scope for #49,
      // see that issue.
      const inlineValue = field('value', alias($._prose_line, $.title_value));
      const indentedValue = field(
        'value',
        alias($._title_value_indented, $.title_value)
      );
      return prec.right(seq(
        field('key', alias($._title_key, $.title_key)),
        choice(
          // "Key: value", with 0+ further indented continuation lines
          seq(inlineValue, repeat(indentedValue)),
          // "Key:" alone: every value must be its own indented line.
          //   - `repeat1`, not `repeat` (#38 regression fix): with 0+
          //     values allowed, this branch could complete with ZERO
          //     values, and nothing requires a blank line before the
          //     next top-level `_block` (`screenplay`'s own
          //     `repeat($._blank)` there is also 0+) — so a value line
          //     was structurally ambiguous with "title_page already
          //     ended, a fresh action block starts here".
          //   - That ambiguity was always latent but invisible: both
          //     readings competed via ordinary internal-token
          //     length/precedence, and the flat, whole-line token
          //     `title_value` used to be built on always won. #38 moved
          //     `italic`/`bold`/`underline` to EXTERNAL scanner tokens,
          //     which tree-sitter always tries first and accepts
          //     unconditionally on success — bypassing that length
          //     comparison entirely. So a continuation value containing
          //     well-formed emphasis (e.g. the canonical Brick & Steel
          //     title, "_**BRICK & STEEL**_") started losing to a stray
          //     `action` block instead of being captured as
          //     `title_value`.
          //   - Requiring at least one value removes the "exit with
          //     zero" reading entirely, so the ambiguity can't arise —
          //     a title-page key with a truly empty value has no
          //     legitimate use here anyway.
          //   - `#48`'s indentation requirement (now also true of the
          //     first branch's continuation lines) doesn't replace this
          //     `repeat1` — confirmed empirically it's still load-
          //     bearing: letting a `repeat` here exit with zero matches
          //     makes `_block`'s tokens (including the EXTERNAL
          //     emphasis ones) simultaneously reachable at that same
          //     position again, and external tokens win over internal
          //     ones unconditionally on success regardless of how
          //     specific the internal token's own alphabet is —
          //     `_title_indent`'s stricter pattern only helps against
          //     other INTERNAL tokens (`_prose_text`), not this. Still
          //     true post-#49: `title_value`'s content is now built on
          //     the same external-token-aware `_prose_line`, but the
          //     ambiguity this guards against is about whether a
          //     `title_value` line is reached AT ALL, not what it's
          //     built from once reached.
          //   - Trade-off this leaves open: a malformed title page
          //     (e.g. an unindented continuation line) now surfaces as
          //     a genuine parse ERROR rather than gracefully falling
          //     back to being parsed as ordinary blocks — fixing that
          //     needs `title_page`/`action` declared as a real GLR
          //     conflict, tracked separately as #50.
          seq($._blank, repeat1(indentedValue))
        )
      ));
    },

    // === Dialogue ===

    dialogue: ($) => prec.dynamic(2, dialogueBody($, $.character)),

    // Two adjacent dialogue blocks side by side (#11): the second one's
    // character cue carries the '^' dual-dialogue marker (spec's "lay
    // this out next to the previous speech" signal). No scanner needed —
    // grouping is decided purely by grammar shape:
    //   - `_dual_character` (below): `character`'s own shape, marker
    //     field MANDATORY instead of optional — reachable here only when
    //     marked.
    //   - Real ambiguity remains even so: a marked second dialogue can
    //     ALSO complete as its own standalone `$.dialogue` (marker is
    //     optional there too).
    //     - Both readings stay live (GLR) until resolved.
    //     - `prec.dynamic` below breaks the tie in favour of grouping.
    //   - No preceding dialogue to pair with (or some other block
    //     precedes it)? Falls back to an ordinary marked standalone
    //     `dialogue` — same as today, no parse ERROR.
    //   - Both members keep the ordinary `dialogue` node shape —
    //     `second` is built from the SAME `dialogueBody` helper, just
    //     aliased back to it — so existing `dialogue` queries still
    //     match either half.
    dual_dialogue: ($) =>
      prec.dynamic(
        3,
        seq(
          field('first', $.dialogue),
          repeat1($._blank),
          field('second', alias($._dual_dialogue_second, $.dialogue))
        )
      ),

    // `dual_dialogue`'s second member, own named rule purely so
    // `alias(..., $.dialogue)` above has a single rule REFERENCE to
    // collapse into one node.
    //   - Aliasing `dialogueBody`'s inline `seq(...)` directly instead
    //     produced its `character` field as a stray sibling of
    //     `first`/`second`, not nested inside `second`'s own `dialogue`.
    //   - Same pitfall `title_value` hit for #49 — see that rule's
    //     comment.
    _dual_dialogue_second: ($) =>
      dialogueBody($, alias($._dual_character, $.character)),

    // Structured character cue (#56): name, zero-or-more extensions,
    // optional dual-dialogue marker.
    //   - Mirrors `scene_heading`'s split-token technique;
    //     `_character_cue_line` below is the unaliased mirror used by
    //     `action`'s fallback for the same tokens.
    //   - The forced ("@NAME", #57) alternative gets the SAME
    //     structured shape, on its own external `_forced_character_name`
    //     token (see `scan_forced_character_name` in src/scanner.c).
    //     - Unlike the bare cue, still falls back to the flat,
    //       unstructured `_forced_character_line` (scene_heading's own
    //       `choice(structured, _forced_scene_line)` pattern): a
    //       malformed extension has nowhere else to go once `@` has
    //       committed the line to being SOME kind of character — no
    //       competing `action` reading the way the bare cue has.
    //     - `character_extension`/`character_marker`/`_character_eol`
    //       are reused as-is — same tokens, same shape, only the name
    //       token and its alphabet differ.
    character: ($) => characterCue($, false),

    // `character`'s own shape, marker field made mandatory (#11) — see
    // `dual_dialogue` above for why.
    //   - No flat fallback branch here: a marked cue that fails
    //     structured validation has no marker field to offer either
    //     way, so it can never satisfy this rule.
    //   - Falls through to ordinary `character` instead, via
    //     `dialogue`'s standalone reading.
    _dual_character: ($) => characterCue($, true),

    parenthetical: ($) => $._parenthetical_line,

    // Consecutive lyric lines (a verse, no blanks between) form one block.
    // Content after the marker supports emphasis, same as action/dialogue
    // (previously flat text only — see `_lyric_line` below).
    lyric: ($) => prec.right(repeat1($._lyric_line)),

    // === Single-line blocks ===

    // A scene heading is structured per the spec's conventions: a
    // recognised prefix (INT., EXT., ...), an optional location, an
    // optional time-of-day after the conventional " - " separator, and
    // an optional #scene number#. Only the prefix is required — "EXT."
    // or "INT. HOUSE" alone are valid headings. Locations may contain
    // hyphens, so the time is the segment after the LAST dash (see the
    // `conflicts` note). Forced headings (".MONTAGE") stay a single
    // unstructured token: a token's regular expression cannot peek past
    // the token's own end, so a bare "." marker token could not tell
    // ".MONTAGE" apart from an action line starting with "...".
    scene_heading: ($) =>
      prec.dynamic(
        2,
        choice(
          seq(
            field('prefix', alias($._scene_prefix, $.scene_prefix)),
            optional(field('location', $.location)),
            // The separator dash is aliased to a visible "-" node so
            // highlight queries can colour it; the dashes inside a
            // hyphenated location stay hidden.
            optional(
              seq(alias($._scene_dash, '-'), optional(field('time', $.time)))
            ),
            optional(field('number', alias($._scene_number, $.scene_number))),
            optional($._scene_eol)
          ),
          $._forced_scene_line
        )
      ),

    location: ($) =>
      seq(
        repeat1($._scene_word),
        repeat(seq($._scene_dash, repeat1($._scene_word)))
      ),

    time: ($) => prec.dynamic(1, repeat1($._scene_word)),

    transition: ($) =>
      prec.dynamic(2, choice($._transition_line, $._forced_transition_line)),

    // Consecutive centered lines (no blank between) form one block.
    centered: ($) => prec.right(repeat1($._centered_line)),

    // Content after the marker supports emphasis, same as action/dialogue
    // (previously flat text only — see `_synopsis_line` below).
    synopsis: ($) => $._synopsis_line,

    // A section heading: 1-6 '#' markers (more = deeper nesting) and an
    // optional title. The marker is its own node so queries can style
    // levels — its text length is the nesting depth. The line's newline
    // is left to the following blank-line separator.
    section: ($) =>
      seq(
        field('marker', alias($._section_marker, $.section_marker)),
        optional(field('title', alias($._any_line, $.section_title)))
      ),

    page_break: ($) => $._page_break_line,

    // === Action ===
    //
    // Action is the fall-through element. Its first line may also absorb
    // tokens that lexed as a character cue, transition or scene heading
    // but turned out not to be followed by what those elements require
    // (the parser was following both readings in parallel — GLR parsing,
    // see the header comment); per the spec such lines are plain action.
    action: ($) =>
      prec.dynamic(
        0,
        choice(
          // Genuinely plain action, first line and every continuation
          // line alike: gets the all-caps `caps` treatment (#19). Forced
          // action (`!ACTION`) is included here too, via
          // `_forced_action_line`'s own `_action_prose_piece` (see its
          // comment) — it's still ordinary action, just marker-led.
          seq($._action_prose_line, repeat($._action_prose_line)),
          seq($._forced_action_line, repeat($._action_prose_line)),
          // A line that lexed as a scene heading/character cue/
          // transition shape but turned out to be ordinary action.
          //   - Its own fallback token and EVERY line after it stay on
          //     the plain, unmodified `_prose_line` — not
          //     `_action_prose_line` — so this branch's alphabet
          //     matches EXACTLY what the reading it competes with
          //     expects at every position, not just the first line
          //     (#19 regression fix).
          //   - Not cosmetic: an earlier version used `_action_prose_line`
          //     here too, and it silently broke the
          //     `character`/`_character_cue_line` GLR fork (see that
          //     pair's own `conflicts` entry and comments) for any
          //     input where the line right after an otherwise-valid
          //     character cue was entirely upper-case (e.g.
          //     "DAN\nTHEN WHO WAS AT THE DOOR?").
          //     - The reason: `character`'s own continuation
          //       (`dialogue_line`, built on the plain, unmodified
          //       `_prose_piece`) and `_character_cue_line`'s
          //       continuation must offer an IDENTICAL follow-set of
          //       lookahead tokens for tree-sitter to keep treating that
          //       position as ambiguous (needing a GLR fork resolved by
          //       `dialogue`'s `prec.dynamic`).
          //     - Once `caps` existed as a token reachable from ONE side
          //       only, any lookahead of `caps` had just one legal
          //       LALR-table action (reduce `_character_cue_line`), so
          //       tree-sitter stopped forking there at all and the
          //       `action` reading won outright, bypassing precedence
          //       entirely rather than losing to it.
          //   - `_scene_start_line`/`_transition_line` don't strictly
          //     need this — their own competing readings
          //     (`scene_heading`/`transition`) have no multi-line body
          //     to keep in lock-step with; that ambiguity is "blank line
          //     next, ends the block" vs "more text, continues as
          //     action", never a token-for-token race the way
          //     `character`/`dialogue` is.
          //   - Grouped here anyway, for one simple, easy-to-audit rule:
          //     every fallback mirror keeps the same plain continuation,
          //     `caps` or not.
          seq(
            choice($._character_cue_line, $._transition_line, $._scene_start_line),
            repeat($._prose_line)
          )
        )
      ),

    // === Inline emphasis ===
    //
    // *italic*, **bold**, ***bold italics*** and _underline_, on plain
    // text (#8, #40).
    //   - `italic`/`bold`/`underline` are real grammar rules whose
    //     content may recursively contain each OTHER — e.g.
    //     "**bold *and italic* text**" (#38) or the spec's own
    //     "_Steel's face FILLS the *Leupold Mark 4* scope_" — but never
    //     themselves (an `italic` span's content cannot contain another
    //     `italic`; same for `bold`/`underline`).
    //   - `bold_italic` is the one exception: it stays the flat,
    //     self-contained token it always was — it may appear as a
    //     nested CHILD inside the other three, but its own content does
    //     not itself recurse.
    //
    // An earlier spike tried italic/bold nesting as a pure multi-token
    // grammar rule with no external scanner, and hit a real, unresolved
    // GLR limitation:
    //   - Once the opening delimiter is shifted, tree-sitter's default
    //     shift/reduce resolution commits to that reading, and when no
    //     valid closing delimiter turns out to exist several tokens
    //     later, the failure surfaces as generic error recovery rather
    //     than backtracking to a live sibling parse (the line should
    //     instead fall back to plain text, as it does when nothing
    //     pairs up).
    //   - The fix (see src/scanner.c): each OPEN token —
    //     `_italic_open`/`_bold_open`/`_underline_open` — is only ever
    //     emitted by the external scanner after it has independently
    //     validated, via its own forward lookahead, that a legal close
    //     (honoring the flanking rule, and recursing into any nested
    //     span along the way) exists later in the line.
    //   - If that validation fails, the scanner refuses to open at all,
    //     so the parser never shifts a doomed reading in the first
    //     place — GLR backtracking is never needed, because the doomed
    //     path never starts.
    //   - The CLOSE tokens and the plain `_emphasis_content_run` piece
    //     below just retrace the same, already-validated, decisions.
    //
    // Underline's OPEN/CLOSE pair is also what gives it a correctly
    // bounded span when preceded by whitespace (#40):
    //   - Unlike a plain regex token, whose reported span starts from
    //     wherever the lexer began searching (so whitespace skipped as
    //     an `extra` along the way would otherwise fold into the
    //     token), the external scanner explicitly marks leading
    //     whitespace as "skip" — see src/scanner.c.
    //   - Underline is the one of the four whose highlight attribute
    //     paints something under blank cells, which is what makes this
    //     visible (multiple spaces before "_underline_" would otherwise
    //     render as underlined too).
    italic: ($) =>
      seq(
        $._italic_open,
        repeat(choice($.bold, $.underline, $.bold_italic, $._emphasis_content_run)),
        $._italic_close
      ),

    bold: ($) =>
      seq(
        $._bold_open,
        repeat(choice($.italic, $.underline, $.bold_italic, $._emphasis_content_run)),
        $._bold_close
      ),

    bold_italic: ($) =>
      token(prec(1, new RegExp(`\\*\\*\\*${FLANKING_SAFE}\\*\\*\\*`))),

    underline: ($) =>
      seq(
        $._underline_open,
        repeat(choice($.italic, $.bold, $.bold_italic, $._emphasis_content_run)),
        $._underline_close
      ),

    // A run of plain content strictly between an emphasis span's own
    // delimiters (open/close or a nested span's boundaries).
    //   - Same PROSE_PIECE alphabet as `_prose_text` below, so it gives
    //     a mid-run boneyard/note the same "first refusal" on '/*'/'[['
    //     — see PROSE_CHAR's own comment.
    //   - But without `_prose_text`'s FLANKING_SAFE sandwich wrapper —
    //     that constraint is about the OUTER span's own boundaries,
    //     already fully enforced by src/scanner.c's pre-validation, and
    //     would be redundant (and wrong: it would forbid a content run
    //     that legitimately starts or ends adjacent to a nested span)
    //     if repeated on each inner run.
    _emphasis_content_run: ($) => token(new RegExp(`(${PROSE_PIECE}|[ \\t])+`)),

    // One line's worth of prose: plain text interspersed with emphasis
    // nodes, ending in the line's own newline (optional, so a final
    // line at end-of-file still parses — as with the historical
    // `_any_line`, see the file header). Hidden, so its children are
    // inlined directly into whatever references it — action's own
    // lines this way, aliased to a named `dialogue_line` node for
    // dialogue (below) so that node's existing shape is preserved for
    // existing queries/tools.
    //
    // None of the content tokens can themselves match a newline, so
    // `repeat` trying for one more piece always fails cleanly at the
    // end of a physical line, bounding `_prose_line` to exactly one
    // line — which is also what keeps separate `dialogue_line` nodes
    // separate, rather than several physical lines merging into one.
    //
    // Trade-off: any boneyard that opens partway through a prose line
    // — whether it closes on that same line or several lines later —
    // now ends up nested inside this `_prose_line`'s action or
    // dialogue_line node, rather than splitting the surrounding text
    // into two separate nodes with the boneyard as a sibling between
    // them (contrast the "Notes and boneyard" corpus tests). Only a
    // boneyard that occupies its own line entirely, right after a
    // blank line — before `_prose_line` has started building at all —
    // is unaffected, staying a true top-level sibling. An earlier
    // design preserved the sibling shape in every case by folding the
    // newline into the SAME token as whatever content preceded it
    // (mirroring `_any_line` exactly), but that meant no content token
    // could safely stop short of a newline either, which in turn
    // required doubling every token into "mid-line" and "line-final"
    // variants just to keep `dialogue_line` bounded to one physical
    // line — accepted as not worth the added complexity for a nesting
    // difference that still parses correctly either way (tracked as a
    // linting candidate in #37, should the distinction matter later; the
    // actual fix — a scanner-emitted synthetic split token — is scoped
    // out in #41).
    _prose_line: ($) =>
      prec.right(seq(repeat1($._prose_piece), optional($._scene_eol))),

    // One "piece" of inline prose content: an emphasis node, or a
    // single plain-text/literal-delimiter token.
    //   - Factored out of `_prose_line` so `lyric`/`synopsis`/forced
    //     `action` lines below can reuse the exact same alphabet with
    //     `repeat` (0+) instead of `_prose_line`'s `repeat1` (1+).
    //   - Those constructs' own marker characters ('~'/'='/'!') may
    //     legally be followed by nothing at all (a bare "~" line, say),
    //     which `repeat1` would reject.
    _prose_piece: ($) =>
      choice(
        $.italic,
        $.bold,
        $.bold_italic,
        $.underline,
        $._prose_text,
        $._star,
        $._star2,
        $._underscore,
        $._slash,
        $._backslash,
        $._lbracket
      ),

    // `action`'s own line, and the alphabet it builds on (#19): the
    // same overall shape as `_prose_line`/`_prose_piece` above, but with
    // `$.caps` added and the plain-text/fallback pieces swapped for
    // action-specific variants (`_action_prose_text`/`_caps_letter` —
    // see their own comments).
    //   - Scoped to `action` only, not shared with `dialogue_line`,
    //     `lyric`, `synopsis` or `title_value`:
    //     - Those keep the plain `_prose_line`/`_prose_piece` above
    //       unchanged, since the convention is specifically an
    //       action-line one (#19's own issue title).
    //     - `_forced_action_line` below opts in too, via
    //       `markedProseLine`'s own `piece` parameter, since forced
    //       action (`!ACTION`) is still ordinary action, just written
    //       with a leading marker.
    //   - Deliberately NOT threaded into `italic`/`bold`/`underline`'s
    //     own nested content (`_emphasis_content_run`): those rules are
    //     shared across every element that supports emphasis, not just
    //     action, and duplicating the whole emphasis rule set as
    //     "action-flavoured" variants just for this would be a large
    //     expansion out of proportion to the feature — a caps word
    //     *inside* an emphasis span in action text is a known, accepted
    //     scope limit for now, same spirit as #49/#55 leaving
    //     `section_title` out of their own scope.
    //   - `action`'s OWN fallback first-line tokens
    //     (`_character_cue_line`/`_transition_line`/`_scene_start_line`,
    //     used when a line lexed as one of those shapes but turned out
    //     to be action) are flat tokens, not built from `_prose_piece`
    //     at all, so they don't get caps treatment either.
    //     - A narrow, documented limitation: only a first line that ends
    //       up flowing through this rule (i.e. wasn't heading/cue/
    //       transition-shaped to begin with) sees `caps`.
    //     - Fixing that would mean rebuilding those fallbacks' own
    //       alphabets around `_action_prose_piece`, which none of the
    //       elements they're mirroring (`scene_heading`/`character`/
    //       `transition`) need for themselves.
    //   - No separate `prec.right` needed beyond what `_prose_line`
    //     already uses: `_action_prose_piece` only ever competes with
    //     itself within the same `repeat1`, same as `_prose_piece` does.
    _action_prose_line: ($) =>
      prec.right(seq(repeat1($._action_prose_piece), optional($._scene_eol))),

    _action_prose_piece: ($) =>
      choice(
        $.italic,
        $.bold,
        $.bold_italic,
        $.underline,
        $.caps,
        $._action_prose_text,
        $._caps_letter,
        $._star,
        $._star2,
        $._underscore,
        $._slash,
        $._backslash,
        $._lbracket
      ),

    // `_action_prose_text`'s own alphabet, built from ACTION_PROSE_CHAR
    // above (not the plain PROSE_CHAR every other line still uses) — see
    // that constant's own comment for why action needs a different one.
    _action_prose_text: ($) => token(new RegExp(ACTION_FLANKING_SAFE)),

    // A solitary uppercase letter that neither `caps` nor
    // `_action_prose_text` can claim.
    //   - `caps` refuses it for being too short to qualify as its own
    //     word (see CAP_WORD's own 2-character minimum).
    //   - `_action_prose_text` refuses it for not being safely paired
    //     with a following lowercase letter (see ACTION_PROSE_CHAR's
    //     own comment).
    //   - Comes up line-final ("...saw A\n"), or directly against a
    //     delimiter/digit with no lowercase letter to pair with ("R2",
    //     "T*emphasis*").
    //   - Same "structured token failed, fall back to one literal
    //     character" idiom `_star`/`_underscore` already use below.
    _caps_letter: ($) => token(/[A-Z]/),

    // A run of ALL-CAPS words in action text (#19) — see CAP_RUN's own
    // comment for the exact word-boundary rules.
    //   - `prec(3)`, the same margin `_lyric_marker`/`_synopsis_marker`/
    //     `_forced_action_marker` already rely on to beat `_prose_text`'s
    //     greedy FLANKING_SAFE catch-all.
    //     - At a shared starting position (e.g. right after `!` in
    //       forced action, or at true block start), `_action_prose_text`
    //       could otherwise win the tie by extending further, so `caps`
    //       needs the same precedence margin there — confirmed
    //       empirically the same way those markers were.
    //     - `_action_prose_text`'s OWN exclusions (see ACTION_PROSE_CHAR
    //       above) do the heavier lifting mid-run, where a competing
    //       token can't simply be out-precedenced (see that constant's
    //       own comment for why): together they cover both cases.
    //   - Deliberately a plain, internal token, not external:
    //     - Hits the same leading-whitespace span bug `boneyard`/`note`/
    //       underline's OPEN token needed external scanning to fix, but
    //       going external here collided with `_transition_line` in a
    //       way those never did — see the `externals` comment above for
    //       the full account.
    //     - Accepted as a known, minor limitation instead: a caps run
    //       preceded by whitespace that's skipped as an `extra` (i.e.
    //       any caps word not immediately preceded by another real
    //       token, e.g. "A GUN gleams.") reports its span starting one
    //       or more columns early, into that whitespace, rather than at
    //       its own first letter.
    //   - A heuristic, not a semantic judgement:
    //     - The grammar has no way to know whether a given all-caps run
    //       is actually a character's first introduction, a sound, a
    //       prop or just a writer's personal emphasis style — it
    //       captures the convention's SURFACE FORM only, same limitation
    //       #19's own issue text already flags for any approach short of
    //       full semantic analysis.
    //     - Real false positives follow from that: an emphasis
    //       interjection ("STOP!") or a fixed abbreviation ("AKA") match
    //       the same surface pattern without introducing anything at
    //       all — see the README's own "All-caps words in action"
    //       section for the fuller discussion, aimed at consumers
    //       building on this node.
    //     - A run that happens to span an entire forced action line
    //       (`!THE CAR EXPLODES.`) is expected, not a bug.
    caps: ($) => token(prec(3, new RegExp(CAP_RUN))),

    _prose_text: ($) => token(new RegExp(FLANKING_SAFE)),

    // A '*' or '**' that isn't part of a successfully-matched
    // italic/bold token (math like "3 * 4", an unpaired delimiter)
    // falls back to being one literal character. Because
    // `italic`/`bold` are themselves tokens (see the note above them),
    // this is an ordinary same-length lexer choice, resolved by
    // longest match: whenever the structured tokens DO match, they
    // win by virtue of being longer; when they don't,
    // whichever of these fires instead.
    _star: ($) => token('*'),
    _star2: ($) => token('**'),
    _underscore: ($) => token('_'),

    // A lone '/' not part of a boneyard, and a lone '\' not part of an
    // escaped delimiter: PROSE_CHAR excludes both ahead of '*'/'*'/'_'
    // (so a real "/*" or "\*" still gets first refusal), but that
    // leaves the bare character — an unclosed "/*", a "//" in a URL, a
    // trailing "\" — with nothing to consume it otherwise, the same
    // fix `_any_line` already needed for '/' (#31).
    _slash: ($) => token('/'),
    _backslash: ($) => token('\\'),

    // A lone '[' not part of a note-opening "[[" — mirrors `_slash`
    // above (#9).
    _lbracket: ($) => token('['),

    // === Comments ===
    //
    // `note` (`[[...]]`, #9) is declared only in `externals` above —
    // see the "Notes" comment near the top of this file, and
    // src/scanner.c's `scan_note`, for its matching rules (content may
    // contain line breaks but not blank lines) and its span fix.

    // `boneyard` is an `extra` (see above), so — unlike `underline` — it
    // was never exposed to the GLR-fork risk that ruled out a pure-grammar
    // fix for #40: extras are always-valid, never a choice the parser has
    // to decide between alternatives for, so nothing here disturbs
    // scene_heading the way an explicit whitespace *choice* did. What it
    // shares with `underline` is the same span bug — the JS-token version
    // reported `/* comment */`'s span starting from wherever the lexer
    // began searching, folding any preceding whitespace in — so it moved
    // to the same `src/scanner.c` external scanner and the same
    // `advance(lexer, skip)` idiom, once that machinery existed anyway.
    // Declared only in `externals` above; no `rules` entry needed.
    //
    // Note: this fixes span accuracy only. It does NOT touch the separate,
    // still-open tree-*shape* trade-off noted above `_prose_line` (a
    // boneyard opening mid-line nests inside its enclosing
    // action/dialogue_line instead of splitting it into siblings) — that
    // needs the grammar itself to split around the boneyard, not just
    // recognise its characters correctly, and is tracked separately as
    // #41.

    // === Line tokens (each includes its trailing newline) ===

    // A would-be scene heading absorbed as action's first line. While
    // the parser is still following both the heading reading and the
    // action reading of a line (GLR parsing; see the header comment),
    // the two readings must consume identical tokens, because the lexer
    // produces a single token stream for both. This rule therefore
    // mirrors the tokens of `scene_heading` — but accepts them in any
    // order, so a malformed heading falls through to plain action
    // instead of becoming a parse error.
    _scene_start_line: ($) =>
      seq(
        $._scene_prefix,
        repeat(choice($._scene_word, $._scene_dash, $._scene_number)),
        optional($._scene_eol)
      ),

    _scene_prefix: ($) =>
      token(prec(5, new RegExp(`${SCENE_PREFIX}[. ]`))),

    // A run of non-space characters in a scene heading. May contain
    // internal hyphens ("DEAD-END"); only a free-standing dash acts as
    // the location/time separator.
    //
    // Precedence 5 (like the prefix) so that an uppercase word wins
    // over the tokens that also stay in the running mid-heading: the
    // catch-all `_prose_text` (action may stop absorbing heading tokens
    // at any point, so it is always a valid alternative here) and the
    // transition token (valid because a transition may follow an
    // action block directly; it matches uppercase text while hoping
    // for a final "TO:", and while a higher-precedence token is still
    // a candidate the lexer keeps scanning past the end of the word,
    // letting `_prose_text` swallow the whole rest of the line).
    _scene_word: ($) => token(prec(5, /[^ \t\r\n-][^ \t\r\n]*/)),

    // One higher than `_scene_word`, which matches the same
    // characters, so a well-formed "#1#" wins; an unclosed "#1" still
    // falls back to being a word.
    _scene_number: ($) => token(prec(6, /#[0-9A-Za-z.\-]+#/)),

    // The location/time separator dash.
    _scene_dash: ($) => token(prec(1, '-')),

    // The heading's own newline. Both this token and `_blank` can match
    // a newline at the end of a heading; the higher precedence here
    // makes the lexer pick this one, so the heading always consumes its
    // own line ending and a genuinely blank line is still required
    // after it to close the block.
    _scene_eol: ($) => token(prec(1, new RegExp(NL))),

    _forced_scene_line: ($) =>
      token(prec(3, new RegExp(`\\.[^.\\s][^\\n]*${EOL}`))),

    // "TO:" must be immediately followed by the newline: per the spec, a
    // trailing space after the colon de-forces the line to action ("the
    // only way to prevent an uppercase TO: line becoming a transition").
    _transition_line: ($) =>
      token(prec(4, new RegExp(`[A-Z][A-Z0-9 .]*TO:${NL}`))),

    _forced_transition_line: ($) =>
      token(prec(3, new RegExp(`>[^\\n]*${EOL}`))),

    // '>' + prose content + '<' (#38 Tier 2, single delimiters per spec
    // — "bracketed with greater/less-than", e.g. ">THE END<"; not
    // doubled).
    //   - `_centered_open`/`_paren_open` below are EXTERNAL tokens (see
    //     src/scanner.c's `scan_centered_open`/`scan_paren_open`), not
    //     plain JS ones — confirmed the hard way that plain tokens
    //     aren't safe here: an early attempt used `token(prec(4, '>'))`
    //     for `_centered_open`, and "> Burn to White." (a forced
    //     transition with no closing '<') hit exactly the failure mode
    //     #38's own header describes for italic/bold/underline — the
    //     parser committed to a `centered` reading via ordinary
    //     shift/reduce, found no '<' before end of line, and surfaced a
    //     genuine parse ERROR instead of falling back to
    //     `_forced_transition_line`. The external scanner validates a
    //     legal close exists before ever emitting the OPEN token, the
    //     same fix as #38's emphasis rules (see scanner.c's file header
    //     for the general mechanism) — external tokens need no JS-level
    //     `prec()` either, since they always win over internal tokens
    //     like `_forced_transition_line` when their validation succeeds.
    //   - `_centered_close`/`_paren_close` stay plain JS tokens: content
    //     excludes both of each construct's own delimiters
    //     (CENTERED_PIECE/PAREN_PIECE), so nothing else can match
    //     either one inside — no ambiguity to resolve, no risk of the
    //     doomed-commitment failure above.
    _centered_line: ($) =>
      containerLine($, $._centered_open, $._centered_content_run, $._centered_close),

    _centered_close: ($) => token('<'),

    // Same shape as `_emphasis_content_run`, but built on CENTERED_PIECE
    // so a run stops before '>' or '<' instead of swallowing either.
    _centered_content_run: ($) =>
      token(new RegExp(`(${CENTERED_PIECE}|[ \\t])+`)),

    // `$._character_name` itself is declared only in `externals` above
    // (#56) — see src/scanner.c's `scan_character_name`. The three
    // tokens below are the plain, non-external remainder: once the name
    // has validated that a legal whole cue exists ahead, walking through
    // these is deterministic, no ambiguity left to resolve.
    _character_extension: ($) => token(prec(3, new RegExp(CHARACTER_EXTENSION))),

    _character_marker: ($) => token(prec(3, '^')),

    // Requires a REAL newline (no EOF alternative), like `_scene_eol` —
    // matching a mere prefix of a line would misclassify it. Precedence
    // 1, like `_scene_eol`, so it wins over `_blank`.
    _character_eol: ($) => token(prec(1, new RegExp(NL))),

    // Hidden mirror of `character`'s own token sequence, unaliased, for
    // `action`'s first-line fallback — the parser is still following
    // both readings in parallel (GLR parsing) until the next line
    // reveals which one wins; see `_scene_start_line` above for the same
    // technique. Unlike `_scene_start_line`, no reordering is needed:
    // extensions and the marker have one fixed order per spec, so this
    // just repeats `character`'s own shape.
    _character_cue_line: ($) =>
      seq(
        $._character_name,
        repeat($._character_extension),
        optional($._character_marker),
        $._character_eol
      ),

    // `$._forced_character_name` itself is declared only in `externals`
    // above (#57) — see src/scanner.c's `scan_forced_character_name`.
    // This flat token is the fallback `character` uses when that
    // validation fails (a malformed extension, say) — same regex as
    // before #57, unchanged.
    _forced_character_line: ($) =>
      token(prec(3, new RegExp(`@[^\\n]*${EOL}`))),

    // '(' + prose content + ')' (#38 Tier 2). See `_centered_line`
    // above for why `_paren_open` is an external token (the same
    // "unclosed delimiter must fail closed, not error" reasoning) while
    // `_paren_close` stays plain (content excludes ')' entirely via
    // PAREN_PIECE, so it's never ambiguous).
    _parenthetical_line: ($) =>
      containerLine($, $._paren_open, $._paren_content_run, $._paren_close),

    _paren_close: ($) => token(')'),

    // Same shape as `_emphasis_content_run`, but built on PAREN_PIECE so
    // a run stops before '(' or ')' instead of swallowing either —
    // matching the original flat token's own exclusion of both (no
    // nested/escaped parens support, same as before).
    _paren_content_run: ($) => token(new RegExp(`(${PAREN_PIECE}|[ \\t])+`)),

    // '~' + prose content, via `markedProseLine` above (#38 cheap
    // tier).
    //   - The marker is its own 1-character token, `prec(3)` matching
    //     the flat token this replaces. That precedence, not length, is
    //     what lets it win against `_prose_text` (which doesn't exclude
    //     '~' from its own alphabet, so could otherwise swallow the
    //     marker and everything after it as one longer, ordinary-prose
    //     match) — confirmed empirically: tree-sitter's lexer prefers a
    //     shorter, higher-precedence complete match over extending
    //     through a lower-precedence one still in progress, and this is
    //     the same precedence gap the flat token it replaces already
    //     relied on against the same rival.
    //   - Needs `prec.right`, unlike `_synopsis_line` below: `lyric` is
    //     used inside `dialogue`'s `repeat1(choice($.parenthetical,
    //     $.lyric, dialogue_line))`, with no separator required between
    //     iterations, and `dialogue_line` is `_prose_line` under an
    //     alias — so with `markedProseLine`'s trailing
    //     `optional($._scene_eol)` unmatched, a piece right after '~'
    //     is ambiguous between "more of this lyric line" and "this
    //     lyric line already ended with zero content, and a fresh
    //     dialogue_line/lyric alternative starts here instead". (See
    //     `_forced_action_line` below for the fuller version of this
    //     same reasoning — it needs the identical fix, for an analogous
    //     reason.) `lyric`'s OWN `repeat1($._lyric_line)` grouping
    //     (consecutive verse lines) was never the issue: the next
    //     `_lyric_line` there always starts with '~', disjoint from
    //     `_prose_piece`'s own alphabet.
    _lyric_line: ($) => prec.right(markedProseLine($, $._lyric_marker)),

    _lyric_marker: ($) => token(prec(3, '~')),

    // See `_lyric_line` above — same shape, same reasoning, minus the
    // `prec.right` (not needed: `synopsis` only appears once, in
    // `_block`'s own choice, never adjacent to a `_prose_piece`-based
    // repeat with no separator).
    _synopsis_line: ($) => markedProseLine($, $._synopsis_marker),

    _synopsis_marker: ($) => token(prec(3, '=')),

    _section_marker: ($) => token(prec(3, /#{1,6}/)),

    _page_break_line: ($) =>
      token(prec(6, new RegExp(`={3,}[ \\t]*${EOL}`))),

    // See `_lyric_line` above — same shape, same `prec.right` reasoning.
    //   - Needed for the same structural reason: `_forced_action_line`
    //     is one alternative in `action`'s own choice, immediately
    //     followed by `action`'s `repeat($._action_prose_line)`, with no
    //     separator required between them, so a piece right after '!'
    //     is ambiguous between "more of this line" and "this line
    //     already ended, and a fresh `_action_prose_line` starts here"
    //     — `prec.right` prefers the former.
    //   - Also fixes a real inconsistency (#38 cheap tier): a forced
    //     action line's own first line previously never got emphasis
    //     parsing at all, even though its continuation lines (via
    //     `action`'s own `repeat`) already did.
    //   - Passes `$._action_prose_piece` (#19), not the default
    //     `$._prose_piece`: forced action is still action, so its first
    //     line gets the same all-caps `caps` treatment its own
    //     continuation lines already get via `action`'s
    //     `_action_prose_line`.
    _forced_action_line: ($) =>
      prec.right(markedProseLine($, $._forced_action_marker, $._action_prose_piece)),

    _forced_action_marker: ($) => token(prec(3, '!')),

    _title_key: ($) =>
      token(prec(5, new RegExp(`(${TITLE_KEYS}):[ \\t]*`))),

    // Fallback: any non-blank line (trailing newline optional, so a
    // final line at end-of-file still parses). Only `section_title`
    // uses this now — `title_value` moved to `_prose_line` (#49), the
    // same emphasis-aware rule action/dialogue use, so a title-page
    // value can contain real `italic`/`bold`/`underline` children
    // instead of being opaque text.
    _any_line: ($) => token(new RegExp(`${ANY_LINE_BODY}(${NL})?`)),

    // A title-page continuation value's required indentation, split out
    // from the value's own content (#48, and #49 — see `title_entry`'s
    // own comment for why the split matters: `_prose_line`'s content
    // pieces include EXTERNAL emphasis tokens, which a single hand-
    // written regex token can't invoke, so the indent can no longer be
    // folded into one token together with the content it introduces
    // the way the flat token this replaces did).
    //   - Per spec ("Values can be inline with the key or they can be
    //     indented on a newline below the key... Indenting is 3 or more
    //     spaces, or a tab"), only a same-line value is exempt from
    //     indentation — this is what `title_entry` uses for every value
    //     except the first.
    //   - Not folded into `extras`' own bare `[ \t]+`: an extra only
    //     ever SKIPS whitespace, it can't enforce a 3-space MINIMUM, so
    //     the indent still needs its own explicit, higher-precedence
    //     token here to be required at all.
    //   - `prec(5)`, matching `_title_key`'s own precedence: the margin
    //     confirmed (same as elsewhere in this file, e.g. `_lyric_marker`
    //     against `_prose_text`) needed for this token to reliably beat
    //     the plain `[ \t]+` extra at the same position, so the indent
    //     is actually consumed by this token and not silently skipped
    //     as insignificant whitespace.
    //   - The indent itself is deliberately still part of `title_value`'s
    //     own reported span (via flattening — this hidden token is
    //     sequenced directly inside the aliased `title_value` wrapper in
    //     `title_entry`, unlike underline/boneyard/note's span fixes
    //     elsewhere in this file): `title_value` isn't given a highlight
    //     attribute that paints blank cells, so the same low-priority
    //     reasoning that left italic/bold unfixed applies here too — not
    //     worth an external scanner for a cosmetic-only span difference.
    _title_indent: ($) => token(prec(5, /([ ]{3,}|\t)/)),

    // Wrapper rule, not an inline `seq(...)` at the `title_entry` call
    // site: `alias()` needs a single rule REFERENCE to collapse cleanly
    // into one named node — confirmed empirically that aliasing a bare
    // `seq($._title_indent, $._prose_line)` inline instead produces TWO
    // separate `title_value` nodes (one empty, holding just the indent;
    // one holding the content) rather than one node spanning both, the
    // same "own named rule, then alias the whole thing" pattern already
    // used for `_centered_line`/`_parenthetical_line` elsewhere in this
    // file.
    _title_value_indented: ($) => seq($._title_indent, $._prose_line),

    _blank: ($) => token(new RegExp(`[ \\t]*${NL}`)),
  },
});
