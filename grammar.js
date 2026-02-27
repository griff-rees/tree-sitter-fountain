/**
 * @file A markup syntax for screenplays.
 * @author Dr Griffith Rees <grees@turing.ac.uk>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check
/// tree-sitter-fountain/grammar.js
module.exports = grammar({
  name: 'fountain',

  extras: $ => [
    $.note,
    $.boneyard,
    $.synopsis,
    /[\s\u00A0]/ // Include regular and non-breaking spaces
  ],

  rules: {
    screenplay: $ => seq(
      optional($.title_page),
      repeat($.element)
    ),

    element: $ => choice(
      $.scene_heading,
      $.action,
      $.centered,
      // $.character,
      $.dialogue,
      $.parenthetical,
      $.transition,
      $.lyric,
      $.page_break,
      $.section,
      $.synopsis,
      $.note,
      $.boneyard
    ),

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
        repeat1(seq('\n', /[\s\t]{3,}/, /.+/))
      )),
      '\n'
    ),

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
    
    scene_number: $ => seq('#', /[A-Za-z0-9\.\-]+/, '#'),

    action: $ => choice(
      seq('!', field('forced', /.+/), '\n'),
      seq(field('text', $.inline_text), '\n')
    ),

    centered: $ => seq('>', field('text', $.inline_text), '<', '\n'),

    // character: $ => choice(
    //   seq('@', field('forced', /.+/), '\n'),
    //   // seq(field('name', /[A-Z][A-Z0-9 .,'()\-\x{2013}\x{2014}]+/u), '\n')
    //   seq(field('name', /[A-Z][A-Z0-9 .,'()-]*/), '\n')
    // ),

    character: $ => choice(
      seq('@', /.+/, '\n'),
      seq(/[A-Z][A-Z0-9 .,'()-]*/, '\n')  // No lowercase, must be uppercase
    ),

    // dialogue: $ => seq(
    //   $.character,
    //   optional($.parenthetical),
    //   repeat(choice(
    //     seq($.spoken),
    //     seq($.parenthetical)
    //   )),
    //   '\n'
    // ),

    dialogue: $ => prec.left(1, seq(
      $.character,
      optional($.parenthetical),
      repeat(choice($.spoken, $.parenthetical)),
      '\n'
    )),
    
    spoken: $ => seq(field('text', $.inline_text), '\n'),

    parenthetical: $ => seq('(', field('text', $.inline_text), ')', '\n'),

    dual_dialogue: $ => seq(
      $.character,
      '^',
      '\n',
      $.dialogue
    ),

    lyric: $ => seq('~', field('text', $.inline_text), '\n'),

    transition: $ => choice(
      // seq(field('text', /[A-Z][A-Z0-9 .,'()\-\x{2013}\x{2014}]+/u), 'TO:', '\n'),
      seq(field('text', /[A-Z][A-Z0-9 .,'()-]*/), 'TO:', '\n'),
      seq('>', field('forced', /.+/), '\n')
    ),

    page_break: $ => seq('=', '=', '=', repeat('='), '\n'),

    section: $ => seq(
      repeat('#'),
      ' ',
      field('title', $.inline_text),
      '\n'
    ),

    synopsis: $ => seq('=', ' ', field('text', /.+/), '\n'),

    // note: $ => seq('[[', field('text', /[^\\\]]+|\\\](?!\])|\\\[?!\[)*/), ']]'),
    // Following https://github.com/UserNobody14/tree-sitter-fountain/blob/1f8e7f77b6e9b8bdfd120cd65df0048d5cc9b147/grammar.js#L222C6-L222C52
    note: $ => token(seq('[[', /[^[\]]]+/, ']]')),

    boneyard: $ => seq(
      '/*',
      field('content', /([^*]|\\\*[^/]|\\\n)*/),
      '*/'
    ),

    inline_text: $ => repeat1(choice(
      $.normal_text,
      $.emphasis
    )),

    // normal_text: $ => /[^_*~\\[]+|\\[_*~\\[]/,
    normal_text: $ => /((\\(\*|_))|[A-Za-z0-9.,'\-!? &;])+/,
    
    emphasis: $ => choice(
      $.italic,
      $.bold,
      $.bold_italic,
      $.underline
    ),

    // italic: $ => seq('*', field('text', $.emphasis), '*'),
    // bold: $ => seq('**', field('text', $.emphasis), '**'),
    // bold_italic: $ => seq('***', field('text', $.emphasis), '***'),
    // underline: $ => seq('_', field('text', $.emphasis), '_'),

    italic: $ => seq('*', field('text', $.emphasis_content), '*'),
    bold: $ => seq('**', field('text', $.emphasis_content), '**'),
    bold_italic: $ => seq('***', field('text', $.emphasis_content), '***'),
    underline: $ => seq('_', field('text', $.emphasis_content), '_'),

    // emphasis_content: $ => repeat1(choice(
    //   /\[^_*~\[\]+/,
    //   $.emphasis,
    //   '\\[_*~\\[]'
    //   // '\[_*~\[\]'
    // ))
    emphasis_content: $ => repeat1(choice(
      /[^_*~\[\]]+/,          // Text without formatting chars
      $.emphasis,             // Nested formatting
      /\\[_*~\[\]]/           // Escaped special characters
    ))
  }
});
