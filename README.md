# tree-sitter-fountain

A [tree-sitter](https://tree-sitter.github.io/tree-sitter/) grammar for
[Fountain](https://fountain.io), the plain-text screenplay markup format.

The grammar implements the [Fountain syntax specification](https://fountain.io/syntax)
and parses the canonical [Brick & Steel](https://fountain.io/_downloads/Brick-&-Steel.fountain)
sample screenplay with no errors (see `examples/` and `test/corpus/`).

This targets **Fountain 1.1**: forced action (`!`), forced character (`@`),
lyrics (`~`) and lowercase character extensions are all supported, and 1.0's
deprecated trailing-space action forcing is not. See
[Fountain 1.1: Use the Force](https://johnaugust.com/2014/fountain-1-1-use-the-force)
for a rundown of what changed from 1.0.

## Supported syntax

- Title pages (`Title:`, `Credit:`, `Author:`, …, including indented multi-line values)
- Scene headings (`INT.`/`EXT.`/`EST.`/`I/E` and forced `.HEADING`), with
  the prefix, location, time-of-day (after the last free ` - ` dash) and
  scene number (`#1#`) exposed as separate child nodes; forced headings
  remain a single unstructured node
- Action, including forced `!ACTION` and all-caps words (a character's
  first introduction, a notable sound/prop, or a camera-relevant
  element — see [All-caps words in action](#all-caps-words-in-action)
  below)
- Character cues and dialogue, including extensions (`(V.O.)`), forced `@Characters`,
  and the `^` dual-dialogue marker, plus dual dialogue (two adjacent
  cues laid out side by side, spec's `^` marker on the second)
- Inline emphasis inside action, dialogue, parenthetical, centered and
  title-page text: `*italics*`, `**bold**`, `***bold italics***` and
  `_underline_`, including the spec's flanking rule (spaces adjacent to
  a marker keep it literal), `\*`/`\_` escaping, and same-line nesting
  of one type inside another (e.g. `**bold *and italic* text**`)
- Parentheticals
- Lyrics (`~`)
- Transitions (`CUT TO:` and forced `> Transition`), including the spec's
  blank-line rules: an uppercase line followed by text is action, not a cue
  or transition
- Centered text (`> THE END <`)
- Sections (`#`) and synopses (`=`)
- Page breaks (`===`)
- Notes (`[[...]]`) and boneyards (`/* ... */`)

Contributions welcome — see `test/corpus/` for what's covered case by case.

### All-caps words in action

Screenwriting convention sets certain words in action lines in all
capitals: a character's first introduction, a significant sound or
prop, or a camera-relevant element. This is a heuristic, not a semantic
judgement — the grammar has no way to know *why* a given run of
capitals was written that way, so it highlights the convention's
surface form (a run of one or more all-caps words, minimum two
characters each, joined by single spaces) rather than any particular
meaning. It's scoped to action text only (including forced `!ACTION`),
not dialogue, lyrics, synopses or title values, since those aren't part
of the convention.

A related, separate convention covers how a screenplay signals its own
ending. Per the [Fountain spec](https://fountain.io/syntax), a bare
`THE END` line is plain action — it gets no special treatment, and (per
the same character-cue-vs-action ambiguity that a lone all-caps line
like `BRICK AND STEEL` already has to resolve) doesn't even get
all-caps highlighting when it's the only line in its paragraph. The two
spec-conformant ending forms are centered text (`> THE END <`, as in
the *Brick & Steel* sample) or a forced transition (`> FADE OUT.`) —
either renders as its own distinct, highlighted node. Writing `THE END`
as its own line partway through an action paragraph (with a preceding
non-blank line) *does* still pick up all-caps highlighting, just not
the more emphatic centered/transition treatment a true ending
convention gets.

## Using with Neovim

This grammar plus the queries in `queries/` are the building blocks for
Fountain screenplay support in Neovim (in the spirit of
[Better Fountain](https://marketplace.visualstudio.com/items?itemName=piersdeseilligny.betterfountain)
for VS Code).

1. Register the parser with [nvim-treesitter](https://github.com/nvim-treesitter/nvim-treesitter):

   ```lua
   vim.filetype.add({ extension = { fountain = "fountain", spmd = "fountain" } })

   local parser_config = require("nvim-treesitter.parsers").get_parser_configs()
   parser_config.fountain = {
     install_info = {
       url = "https://github.com/griff-rees/tree-sitter-fountain",
       files = { "src/parser.c", "src/scanner.c" },
     },
     filetype = "fountain",
   }
   ```

2. Run `:TSInstall fountain`.

3. Copy `queries/highlights.scm` onto your runtimepath, e.g.:

   ```sh
   mkdir -p ~/.config/nvim/queries/fountain
   cp queries/highlights.scm ~/.config/nvim/queries/fountain/highlights.scm
   ```

### Colour fallbacks for emphasis

`italic`, `bold`, `bold_italic` and `underline` each carry a semantic
highlight capture (`@markup.italic`, `@markup.strong`,
`@markup.underline`) in `highlights.scm`, plus an independent colour
underneath (`@property`/`@attribute`/`@function`/`@type`, one per
type). The semantic capture alone isn't enough: whether it renders as
anything more than plain prose depends entirely on your terminal/font
— true italic support in particular is commonly missing on monospace
fonts, and a theme where `@markup.italic` is attribute-only (as in
NvChad's base46, for example) leaves such text visually identical to
plain prose on a font without it. Worse, since emphasis types can nest
inside each other (`**bold *and italic* text**`), a shared fallback
colour would make the inner span indistinguishable from its parent on
a setup that can't render either one's attribute — the four are
deliberately independent colours for exactly this reason, so nesting
always stays visible regardless of what your setup renders.

If you've verified your own terminal/font already renders one or more
of these attributes correctly, the matching colour line is redundant
for you — since a tree-sitter query can't detect that automatically
(there's no portable way to introspect terminal/font glyph support),
trimming it is a manual, one-line edit to your own installed copy:
delete `(italic) @property`, `(bold) @attribute`,
`(bold_italic) @function` and/or `(underline) @type` for whichever
you've confirmed you don't need.

## Development

Requires [Node.js](https://nodejs.org) (npm ships with it).

```sh
npm install                  # fetches the tree-sitter CLI
npx tree-sitter generate     # regenerate src/ after editing grammar.js
npx tree-sitter test         # run the corpus tests in test/corpus/
npx tree-sitter parse examples/brick-and-steel.fountain
```

### Releasing

Each merged PR gets its own release, so regressions can be bisected by
version. The flow: promote the changelog's Unreleased section to the new
version, run `npx tree-sitter version X.Y.Z` (which updates
`package.json`, `tree-sitter.json`, `Cargo.toml`, `pyproject.toml` and
the generated build files in one step), commit, then create an annotated
tag `vX.Y.Z` and push it. New features bump the minor digit, fixes the
patch digit. Registry publishing is tracked in
[#15](https://github.com/griff-rees/tree-sitter-fountain/issues/15).

Note that the tree-sitter CLI parses the regular expressions in `grammar.js`
with the syntax of Rust's [`regex` crate](https://docs.rs/regex/latest/regex/#syntax),
which is stricter than JavaScript's (e.g. `[` must be escaped inside a
character class).

### Design

Fountain gives meaning to each line of text according to its content *and*
the blank lines around it — an uppercase line is a character cue only when
the line below it is not blank, otherwise it is action. The grammar
therefore lexes whole lines as single tokens (each including its trailing
newline), treats blank lines as block separators, and resolves the
lookahead-dependent cases with [GLR](#glossary) conflicts and dynamic
precedence instead of an external C scanner. Scene headings are the one
exception to the line-as-one-token rule: they are split into smaller
tokens so their prefix, location, time and scene number appear as
separate nodes. See the commentary in `grammar.js` for details.

### Glossary

- **GLR parsing** — short for "generalized left-to-right,
  rightmost-derivation" parsing. An ordinary LR parser reads tokens left
  to right and must commit to a single interpretation at every step,
  with only a fixed peek ahead. A *generalized* LR parser lifts that
  restriction: at a declared ambiguity it follows every viable
  interpretation in parallel and discards each one as soon as later
  input rules it out. Tree-sitter switches to GLR parsing wherever a
  grammar declares a
  [`conflicts` entry](https://tree-sitter.github.io/tree-sitter/creating-parsers/3-writing-the-grammar#using-conflicts),
  and uses the grammar's `prec.dynamic` values to choose a winner when
  more than one interpretation survives to the end. For more depth see
  the [GLR parser article](https://en.wikipedia.org/wiki/GLR_parser) on
  Wikipedia, and tree-sitter's implementation in
  [`lib/src/parser.c`](https://github.com/tree-sitter/tree-sitter/blob/master/lib/src/parser.c)
  and [`lib/src/stack.c`](https://github.com/tree-sitter/tree-sitter/blob/master/lib/src/stack.c)
  (the latter holds the parallel parse stacks).

## Contributing

Issues and pull requests are very welcome — extra test cases in
`test/corpus/` (real-world screenplays that misparse are especially
valuable) and further editor queries (`folds.scm`, `indents.scm`) are
all good places to start. Please run
`npx tree-sitter test` before submitting, and follow
[Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/) for
commit messages. Contributors are expected to follow the
[Contributor Covenant](https://www.contributor-covenant.org/version/2/1/code_of_conduct/).

## Acknowledgements

- [Fountain](https://fountain.io) was created by John August and Nima
  Yousefi, with the specification developed by Stu Maschwitz and others;
  the *Brick & Steel* sample used in `examples/` is by Stu Maschwitz.
- Earlier drafts of this grammar (preserved in `grammar-old.js`) drew on
  [UserNobody14/tree-sitter-fountain](https://github.com/UserNobody14/tree-sitter-fountain),
  whose work is gratefully acknowledged.
- Carson Fire's [vim-fountain](https://www.vim.org/scripts/script.php?script_id=3880)
  plugin (maintained as [kblin/vim-fountain](https://github.com/kblin/vim-fountain))
  has provided Fountain support in Vim since 2012 and inspired the editor
  experience this project works toward; its scene-navigation and
  uppercase-entry mappings remain the benchmark for the planned companion
  Neovim plugin.

## License

MIT
