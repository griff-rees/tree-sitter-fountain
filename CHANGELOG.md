# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to
[Semantic Versioning](https://semver.org/spec/v2.0.0.html). Versions are git
tags; registry publishing is tracked in
[#15](https://github.com/griff-rees/tree-sitter-fountain/issues/15).

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
