/**
 * @file Tree-sitter grammar for Fountain (https://fountain.io), a plain-text
 * screenplay markup format.
 * @author Dr Griffith Rees <grees@turing.ac.uk>
 * @license MIT
 *
 * The element definitions and disambiguation rules implemented here follow
 * the Fountain syntax specification: https://fountain.io/syntax
 *
 * Approach: in Fountain, the meaning of each line of text in the file is
 * determined by its content and by the blank lines around it — for example,
 * an uppercase line is a character cue only when the line below it is not
 * blank; otherwise it is action. This grammar therefore treats every
 * text line as a single token that includes its trailing newline, and
 * treats a blank line as its own `_blank` token separating blocks.
 * Disambiguation that needs lookahead (character cue vs. action, above) is
 * handled with declared GLR conflicts plus dynamic precedence, avoiding an
 * external C scanner.
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

module.exports = grammar({
  name: 'fountain',

  extras: ($) => [/[ \t]+/, $.note, $.boneyard],

  conflicts: ($) => [
    [$.character, $.action],
    [$.scene_heading, $.action],
    [$.transition, $.action],
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
              alias($._any_line, $.dialogue_line)
            )
          )
        )
      ),

    character: ($) => choice($._character_line, $._forced_character_line),

    parenthetical: ($) => $._parenthetical_line,

    lyric: ($) => $._lyric_line,

    // === Single-line blocks ===

    scene_heading: ($) =>
      prec.dynamic(2, choice($._scene_line, $._forced_scene_line)),

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
    // but turned out (via GLR) not to be followed by what those elements
    // require; per the spec they are then plain action.
    action: ($) =>
      prec.dynamic(
        0,
        seq(
          choice(
            $._any_line,
            $._forced_action_line,
            $._character_line,
            $._transition_line,
            $._scene_line
          ),
          repeat($._any_line)
        )
      ),

    // === Comments ===

    note: ($) => token(prec(2, new RegExp(`\\[\\[[^\\]\\n]*\\]\\]`))),

    boneyard: ($) => token(prec(2, new RegExp(`/\\*([^*]|\\*+[^*/])*\\*+/`))),

    // === Line tokens (each includes its trailing newline) ===

    _scene_line: ($) =>
      token(prec(5, new RegExp(`${SCENE_PREFIX}[. ][^\\n]*${EOL}`))),

    _forced_scene_line: ($) =>
      token(prec(3, new RegExp(`\\.[^.\\s][^\\n]*${EOL}`))),

    _transition_line: ($) =>
      token(prec(4, new RegExp(`[A-Z][A-Z0-9 .]*TO:[ \\t]*${NL}`))),

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
    _any_line: ($) => token(new RegExp(`[^\\r\\n]+(${NL})?`)),

    _blank: ($) => token(new RegExp(`[ \\t]*${NL}`)),
  },
});
