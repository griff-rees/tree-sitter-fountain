# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to
[Semantic Versioning](https://semver.org/spec/v2.0.0.html). Versions are git
tags; registry publishing is tracked in
[#15](https://github.com/griff-rees/tree-sitter-fountain/issues/15).

## [0.3.2] - 2026-08-05

### Changed

- Development toolchain: tree-sitter-cli upgraded to 0.26 (parser
  regenerated, language ABI 15) with the node, Rust and Python binding
  runtimes aligned to match; releases now bump every package manifest
  with `npx tree-sitter version`, documented in the README
  ([#33](https://github.com/griff-rees/tree-sitter-fountain/issues/33)).

### Fixed

- Author email updated across the package metadata
  ([#7](https://github.com/griff-rees/tree-sitter-fountain/issues/7)).

## [0.3.1] - 2026-08-05

### Fixed

- Boneyards that open mid-line are now recognised, including ones that
  close on a later line — previously the whole `/* ... */` span was
  swallowed by the containing line, so "commented-out" text still parsed
  as screenplay content
  ([#31](https://github.com/griff-rees/tree-sitter-fountain/issues/31);
  also the boneyard half of the mid-line case in
  [#24](https://github.com/griff-rees/tree-sitter-fountain/issues/24)).
  An unclosed `/*` remains plain text. Known limitation: when a boneyard
  closes exactly at a line end, the newline after it ends the block, so
  an action paragraph continuing on the next line parses as two action
  nodes.

## [0.3.0] - 2026-08-05

### Added

- Scene headings are structured: the prefix (`INT.`, `EXT.`, …), location,
  time-of-day (the segment after the last free ` - ` dash) and scene number
  (`#1#`) are separate child nodes, each optional except the prefix, with
  matching highlight captures (the separator dash is coloured like the
  prefix). Forced `.HEADING` lines remain a single
  unstructured node
  ([#21](https://github.com/griff-rees/tree-sitter-fountain/issues/21),
  [#10](https://github.com/griff-rees/tree-sitter-fountain/issues/10)).

## [0.2.0] - 2026-08-02

### Added

- Section headings expose their nesting: `(section (section_marker) (section_title))`,
  with the marker's length giving the level ([#12](https://github.com/griff-rees/tree-sitter-fountain/issues/12)).

### Fixed

- Consecutive standalone lyric lines (a verse with no character cue above
  it) no longer produce an ERROR node; like centered text, they merge into
  one block.

### Changed

- Highlight queries layer coloured captures under attribute-only groups so
  centered text and lyrics stay visible in themes where `@markup.strong` /
  `@markup.italic` carry no colour, and section titles get per-level
  heading captures ([#26](https://github.com/griff-rees/tree-sitter-fountain/issues/26)).

## [0.1.0] - 2026-08-01

### Added

- Working grammar for the full block-level [Fountain syntax](https://fountain.io/syntax):
  title pages, scene headings, action, character cues and dialogue (including
  extensions, forced `@` cues and the dual-dialogue `^` marker),
  parentheticals, lyrics, transitions, centered text, sections, synopses,
  page breaks, notes and boneyards.
- Corpus test suite (`test/corpus/`) covering every element type, plus the
  canonical Brick & Steel sample in `examples/`, which parses with zero
  errors.
- Neovim syntax highlighting queries (`queries/highlights.scm`).
- Project scaffolding and bindings for Node, Rust, Python, Go, Swift and C.
- CI workflow: regenerates the parser (verifying `src/` is in sync), runs the
  corpus tests, parses the examples, and runs the node binding tests on Linux
  and macOS.
- README, MIT license file, and contributing guidance.

### Changed

- Rewrote the draft grammar with a line-oriented design: whole lines are
  lexed as single tokens, blank lines separate blocks, and the spec's
  lookahead-dependent disambiguation (character cue vs. action) is resolved
  with GLR ("generalized left-to-right, rightmost-derivation") conflicts and
  dynamic precedence instead of an external scanner (see the
  [README glossary](README.md#glossary)).
  All regexes are Rust-`regex`-compatible, so `tree-sitter generate` runs
  cleanly (the previous draft failed to generate at all).
- CRLF line endings and files without a trailing newline now parse
  correctly.
