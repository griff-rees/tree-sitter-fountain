/**
 * @file A markup syntax for screenplays.
 * @author Dr Griffith Rees <grees@turing.ac.uk>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: 'fountain',

  extras: $ => [
    // $.note,
    $.boneyard,
    $.synopsis,
    /[\s\u00A0]/ // Include regular and non-breaking spaces
  ],

  rules: {
    // The root of the document
    screenplay: $ => seq(
      optional($.title_page),
      repeat($.element)
    ),

    // Elements can be any of the screenplay components
    element: $ => choice(
      $.scene_heading,
      $.action,
      $.centered,
      $.character,
      $.dialogue,
      $.parenthetical,
      $.transition,
      $.lyric,
      $.page_break,
      $.section,
      $.synopsis,
      // $.note,
      $.boneyard
    ),

    // TITLE PAGE
    title_page: $ => repeat1($.title_page_entry),
    title_page_entry: $ => seq(
      field('key', choice(
        'Title',
        'Credit',
        'Author',
        'Authors',
        'Source',
        'Draft date',
        'Contact'
      )),
      ':',
      field('value', choice(
        seq(' ', /.+/),
        repeat1(seq('\n', /\s{3,}|\t/, /.+/))
      )),
      '\n'
    ),

    // SCENE HEADING
    scene_heading: $ => seq(
      choice(
        seq('.', field('forced', /.+/)),
        seq(
          field('prefix', choice('INT', 'EXT', 'EST', 'INT/EXT', 'I/E', 'INT./EXT')),
          /[ .]/,
          field('location', /.+/)
        )
      ),
      optional(field('scene_number', $.scene_number)),
      '\n'
    ),
    scene_number: $ => seq('#', /[A-Za-z0-9.-]+/, '#'),

    // ACTION
    action: $ => choice(
      seq('!', field('forced', /.+/), '\n'),
      seq(field('text', $.inline_text), '\n')
    ),

    // CENTERED TEXT
    centered: $ => seq('>', field('text', $.inline_text), '<', '\n'),

    // CHARACTER
    character: $ => choice(
      seq('@', field('forced', /.+/), '\n'),
      seq(field('name', /[A-Z][A-Z0-9 .,'()-]*/), '\n')
    ),

    // DIALOGUE
    dialogue: $ => seq(
      $.character,
      optional($.parenthetical),
      repeat(choice(
        seq($.spoken),
        seq($.parenthetical)
      )),
      '\n'
    ),
    spoken: $ => seq(field('text', $.inline_text), '\n'),

    // PARENTHETICAL
    parenthetical: $ => seq('(', field('text', $.inline_text), ')', '\n'),

    // DUAL DIALOGUE
    dual_dialogue: $ => seq(
      $.character,
      '^',
      '\n',
      $.dialogue
    ),

    // LYRIC
    lyric: $ => seq('~', field('text', $.inline_text), '\n'),

    // TRANSITION
    transition: $ => choice(
      seq(field('text', /[A-Z][A-Z0-9 .,'()-]*/), 'TO:', '\n'),
      seq('>', field('forced', /.+/), '\n')
    ),

    // PAGE BREAK
    page_break: $ => seq('=', '=', '=', repeat('='), '\n'),

    // SECTION HEADINGS
    section: $ => seq(
      repeat('#'),
      ' ',
      field('title', $.inline_text),
      '\n'
    ),

    // SYNOPSIS
    synopsis: $ => seq('=', ' ', field('text', /.+/), '\n'),

    // NOTE
    // note: $ => seq('[[', field('text', /[^\\]]+|\\](?!])|\\[(?!\\[)*/), ']]'),

    // BONEYARD (commented out text)
    boneyard: $ => seq(
      '/*',
      field('content', /([^*]|\\*[^/]|\\n)*/),
      '*/'
    ),

    // INLINE TEXT WITH EMPHASIS
    inline_text: $ => repeat1(choice(
      // $.normal_text,
      $.emphasis
    )),

    normal_text: $ => /[^_*~\[]+|[_*~\[]/,
    //     regex parse error:
    //         [^_*~\\[]+|\\[_*~\\[]
    //                     ^^
    //     error: unclosed character class
    
    emphasis: $ => choice(
      $.italic,
      $.bold,
      $.bold_italic,
      $.underline
    ),

    italic: $ => seq('*', field('text', $.emphasis_content), '*'),
    bold: $ => seq('**', field('text', $.emphasis_content), '**'),
    bold_italic: $ => seq('***', field('text', $.emphasis_content), '***'),
    underline: $ => seq('_', field('text', $.emphasis_content), '_'),

    emphasis_content: $ => repeat1(choice(
      /\[^_*~\[\]+/,
      $.emphasis,
      '\[_*~\[\]'
    ))
  }
});
