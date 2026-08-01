# tree-sitter-fountain

A [tree-sitter](https://tree-sitter.github.io/tree-sitter/) grammar for
[Fountain](https://fountain.io), the plain-text screenplay markup format.

The grammar implements the [Fountain syntax specification](https://fountain.io/syntax)
and parses the canonical [Brick & Steel](https://fountain.io/_downloads/Brick-&-Steel.fountain)
sample screenplay with no errors (see `examples/` and `test/corpus/`).

## Supported syntax

- Title pages (`Title:`, `Credit:`, `Author:`, …, including indented multi-line values)
- Scene headings (`INT.`/`EXT.`/`EST.`/`I/E` and forced `.HEADING`)
- Action, including forced `!ACTION`
- Character cues and dialogue, including extensions (`(V.O.)`), forced `@Characters`,
  and the `^` dual-dialogue marker
- Parentheticals
- Lyrics (`~`)
- Transitions (`CUT TO:` and forced `> Transition`), including the spec's
  blank-line rules: an uppercase line followed by text is action, not a cue
  or transition
- Centered text (`> THE END <`)
- Sections (`#`) and synopses (`=`)
- Page breaks (`===`)
- Notes (`[[...]]`) and boneyards (`/* ... */`)

Not yet parsed as distinct nodes: inline emphasis (`*italics*`, `**bold**`,
`_underline_`) inside lines, multi-line notes, and scene numbers (`#1#`) —
these currently remain part of their containing line. Contributions welcome.

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
       files = { "src/parser.c" },
     },
     filetype = "fountain",
   }
   ```

2. Run `:TSInstall fountain`.

3. Copy `queries/highlights.scm` to `queries/fountain/highlights.scm` on your
   runtimepath (e.g. `~/.config/nvim/queries/fountain/highlights.scm`).

## Development

Requires [Node.js](https://nodejs.org) (npm ships with it).

```sh
npm install                  # fetches the tree-sitter CLI
npx tree-sitter generate     # regenerate src/ after editing grammar.js
npx tree-sitter test         # run the corpus tests in test/corpus/
npx tree-sitter parse examples/brick-and-steel.fountain
```

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
lookahead-dependent cases with GLR conflicts and dynamic precedence instead
of an external C scanner. See the commentary in `grammar.js` for details.

## Contributing

Issues and pull requests are very welcome — extra test cases in
`test/corpus/` (real-world screenplays that misparse are especially
valuable), the missing inline syntax above, and further editor queries
(`folds.scm`, `indents.scm`) are all good places to start. Please run
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

## License

MIT
