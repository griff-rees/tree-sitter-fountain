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

// A character cue: at least one uppercase letter, no lowercase; digits,
// spaces and simple punctuation allowed; optional (extensions) such as
// (V.O.) or (CONT'D); optional ^ marker for dual dialogue.
const CHARACTER_CUE =
  `[A-Z0-9 .'\\-]*[A-Z][A-Z0-9 .'\\-]*` +
  `(\\([^()\\r\\n]*\\)[ \\t]*)*` +
  `(\\^)?[ \\t]*${NL}`;

// === Inline emphasis (#8) ===
//
// One character of plain inline prose content: excludes the emphasis
// delimiters ('*', '_'), a backslash (reserved for escaping), and —
// mirroring the boneyard fix (#31) — a '/' immediately followed by
// '*', so a boneyard opening mid-line still gets first refusal.
const PROSE_CHAR = `([^ \\t\\r\\n*_\\\\/]|/[^*\\r\\n])`;

// An escaped delimiter ('\*' or '\_') is safe content too: this is how
// the spec expects a literal delimiter character to be written without
// triggering emphasis (e.g. "\*9765\*" shows literal asterisks).
const ESCAPED_DELIM = `\\\\[*_]`;

const PROSE_PIECE = `(${PROSE_CHAR}|${ESCAPED_DELIM})`;

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

module.exports = grammar({
  name: 'fountain',

  extras: ($) => [/[ \t]+/, $.note, $.boneyard],

  conflicts: ($) => [
    [$.character, $.action],
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
  ],

  rules: {
    screenplay: ($) =>
      seq(
        optional($.title_page),
        repeat($._blank),
        repeat(seq($._block, repeat1($._blank))),
        optional($._block)
      ),

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
        $.dialogue,
        $.action
      ),

    // === Title page ===

    title_page: ($) => repeat1($.title_entry),

    title_entry: ($) =>
      prec.right(seq(
        field('key', alias($._title_key, $.title_key)),
        choice(
          // "Key: value" with optional indented continuation lines
          repeat1(field('value', alias($._any_line, $.title_value))),
          // "Key:" alone, values on the following indented lines
          seq($._blank, repeat(field('value', alias($._any_line, $.title_value))))
        )
      )),

    // === Dialogue ===

    dialogue: ($) =>
      prec.dynamic(
        2,
        seq(
          field('character', $.character),
          repeat1(
            choice(
              $.parenthetical,
              $.lyric,
              alias($._prose_line, $.dialogue_line)
            )
          )
        )
      ),

    character: ($) => choice($._character_line, $._forced_character_line),

    parenthetical: ($) => $._parenthetical_line,

    // Consecutive lyric lines (a verse, no blanks between) form one block.
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
        seq(
          choice(
            $._prose_line,
            $._forced_action_line,
            $._character_line,
            $._transition_line,
            $._scene_start_line
          ),
          repeat($._prose_line)
        )
      ),

    // === Inline emphasis ===
    //
    // *italic*, **bold**, ***bold italics*** and _underline_, on plain
    // text. Each is a single self-contained token, not a grammar rule:
    // an earlier multi-token design, whose content could itself hold a
    // NESTED italic/bold node, hit a real, unresolved GLR limitation —
    // once the opening delimiter is shifted, tree-sitter's default
    // shift/reduce resolution commits to that reading, and when no
    // valid closing delimiter turns out to exist several tokens later,
    // the failure surfaces as generic error recovery rather than
    // backtracking to a live sibling parse. A single token sidesteps
    // this: if no valid close exists anywhere on the line, the regex
    // engine's own (ordinary, non-lookaround) backtracking just fails
    // the whole token, with no parser-level backtracking involved.
    // Combining DIFFERENT delimiter types by nesting one inside another
    // on the same line — e.g. "**bold *and italic* text**", or the
    // spec's own "_Steel's face FILLS the *Leupold Mark 4* scope_" —
    // is therefore not yet recognised as one combined span; each half
    // is still found separately where it stands alone. Tracked as #38.
    italic: ($) => token(prec(1, new RegExp(`\\*${FLANKING_SAFE}\\*`))),
    bold: ($) => token(prec(1, new RegExp(`\\*\\*${FLANKING_SAFE}\\*\\*`))),
    bold_italic: ($) =>
      token(prec(1, new RegExp(`\\*\\*\\*${FLANKING_SAFE}\\*\\*\\*`))),

    // Underline shares italic/bold's flanking mechanics, but has no
    // Markdown-style "intraword" exemption in the spec: an ordinary
    // snake_case identifier like "my_variable_name" satisfies the
    // flanking rule just as validly as real emphasis does (letters
    // immediately surround both underscores), so it is read as
    // underline("variable") sandwiched between literal "my_" and
    // "_name". This is not a bug in this grammar — it is what the
    // spec, read literally, produces — but it is worth knowing before
    // running this on prose that mixes in casual underscore use.
    underline: ($) => token(prec(1, new RegExp(`_${FLANKING_SAFE}_`))),

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
    // linting candidate in #37, should the distinction matter later).
    _prose_line: ($) =>
      prec.right(
        seq(
          repeat1(
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
              $._backslash
            )
          ),
          optional($._scene_eol)
        )
      ),

    _prose_text: ($) => token(new RegExp(FLANKING_SAFE)),

    // A '*', '**' or '_' that isn't part of a successfully-matched
    // italic/bold/underline token (math like "3 * 4", an unpaired
    // delimiter, or an ordinary underscore in prose that doesn't pair
    // up) falls back to being one literal character. Because
    // `italic`/`bold`/`underline` are themselves tokens (see the note
    // above them), this is an ordinary same-length lexer choice,
    // resolved by longest match: whenever the structured tokens DO
    // match, they win by virtue of being longer; when they don't,
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

    // === Comments ===

    note: ($) => token(prec(2, new RegExp(`\\[\\[[^\\]\\n]*\\]\\]`))),

    boneyard: ($) => token(prec(2, new RegExp(`/\\*([^*]|\\*+[^*/])*\\*+/`))),

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

    _centered_line: ($) =>
      token(prec(4, new RegExp(`>[ \\t]*[^<\\n]*<[ \\t]*${EOL}`))),

    _character_line: ($) => token(prec(3, new RegExp(CHARACTER_CUE))),

    _forced_character_line: ($) =>
      token(prec(3, new RegExp(`@[^\\n]*${EOL}`))),

    _parenthetical_line: ($) =>
      token(prec(3, new RegExp(`\\([^()\\n]*\\)[ \\t]*${EOL}`))),

    _lyric_line: ($) => token(prec(3, new RegExp(`~[^\\n]*${EOL}`))),

    _synopsis_line: ($) => token(prec(3, new RegExp(`=[^\\n]*${EOL}`))),

    _section_marker: ($) => token(prec(3, /#{1,6}/)),

    _page_break_line: ($) =>
      token(prec(6, new RegExp(`={3,}[ \\t]*${EOL}`))),

    _forced_action_line: ($) => token(prec(3, new RegExp(`![^\\n]*${EOL}`))),

    _title_key: ($) =>
      token(prec(5, new RegExp(`(${TITLE_KEYS}):[ \\t]*`))),

    // Fallback: any non-blank line (trailing newline optional, so a final
    // line at end-of-file still parses).
    //
    // The token stops before "/*", so a boneyard that opens mid-line —
    // even one closing on a later line — is picked up by the `boneyard`
    // extra instead of being swallowed by the line (#31). Token regular
    // expressions cannot peek ahead, so "not containing /*" is spelled
    // out as: runs of either a non-slash character or a slash followed
    // by a non-star. The lone "/" alternative keeps a slash at the end
    // of a line (or an unclosed "/*") lexing as plain text — the slash
    // becomes its own little _any_line token — rather than an error.
    // (A trailing /? on the main alternative would be wrong: longest-
    // match would then swallow the opening slash of a real boneyard.)
    _any_line: ($) =>
      token(new RegExp(`(([^/\\r\\n]|/[^*\\r\\n])+|/)(${NL})?`)),

    _blank: ($) => token(new RegExp(`[ \\t]*${NL}`)),
  },
});
