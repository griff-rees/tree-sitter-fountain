# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to
[Semantic Versioning](https://semver.org/spec/v2.0.0.html). Versions are git
tags; registry publishing is tracked in
[#15](https://github.com/griff-rees/tree-sitter-fountain/issues/15).

## [Unreleased]

## [0.10.0] - 2026-09-12

### Added

- Dual dialogue: two adjacent `dialogue` blocks group into one
  `dual_dialogue` node when the second's cue carries the `^` marker
  ([#11](https://github.com/griff-rees/tree-sitter-fountain/issues/11)).
  - `first`/`second` fields hold the two `dialogue` members, unchanged
    in shape from a standalone `dialogue`.
  - Works for both ordinary and forced (`@NAME`) cues.
  - A marker with nothing to pair with (or a malformed marked cue)
    falls back to an ordinary standalone `dialogue`, not a parse error.

## [0.9.0] - 2026-09-12

### Added

- Forced character cues (`@McCLANE`) get the same structured
  extensions/marker as the ordinary cue
  ([#57](https://github.com/griff-rees/tree-sitter-fountain/issues/57)).
  - Adds `character_name`, zero or more `character_extension` children,
    and an optional `character_marker`.
  - An unclosed extension falls back to the flat cue instead of
    erroring.

## [0.8.0] - 2026-09-12

### Added

- Character cues expose their structure instead of one atomic token
  ([#56](https://github.com/griff-rees/tree-sitter-fountain/issues/56)).
  - Adds `character_name`, zero or more `character_extension` children
    (`(V.O.)`, `(CONT'D)`), and an optional `character_marker` (`^`).
  - Each is independently queryable and highlighted.
  - `@`-forced cues are unchanged here — landed separately as `#57`.

## [0.6.0] - 2026-09-11

### Added

- Same-line nested emphasis: `italic`/`bold`/`underline` can now
  recursively contain each other, e.g. `**bold *and italic* text**`
  ([#38](https://github.com/griff-rees/tree-sitter-fountain/issues/38)).
  - `bold_italic` stays a flat leaf, nestable inside the other three.
- `lyric`, `synopsis`, forced `action` lines, `parenthetical` and
  `centered` now all support inline emphasis the same way `action`/
  `dialogue_line` already did — previously flat text only
  ([#38](https://github.com/griff-rees/tree-sitter-fountain/issues/38)).
- Title page continuation values must now be indented (3 or more
  spaces, or a tab), per spec — previously any line was silently
  accepted, regardless of indentation
  ([#48](https://github.com/griff-rees/tree-sitter-fountain/issues/48)).
- `queries/highlights-emphasis-colours.scm`: an opt-in-by-default
  companion to `highlights.scm` with one colour-fallback line per
  emphasis type, each independent so a user who's verified their
  terminal/font already renders some of the four can trim just those
  lines from their own installed copy.

### Fixed

- A forced action line's own first line (`!Forced action.`) now
  supports inline emphasis, matching its continuation lines, which
  already did ([#38](https://github.com/griff-rees/tree-sitter-fountain/issues/38)).
- `note`'s reported span could include preceding whitespace, the same
  bug [#40](https://github.com/griff-rees/tree-sitter-fountain/issues/40)
  fixed for `boneyard`/`underline` but never applied to `note`
  ([#38](https://github.com/griff-rees/tree-sitter-fountain/issues/38)).
- Title page continuation values containing well-formed emphasis (e.g.
  the canonical Brick & Steel title, `_**BRICK & STEEL**_`) were losing
  to a stray `action` block instead of being captured as `title_value`
  ([#38](https://github.com/griff-rees/tree-sitter-fountain/issues/38)).
- `italic`/`bold`/`bold_italic`/`underline` all shared one colour
  fallback in `queries/highlights.scm`, making a nested span
  indistinguishable from its parent on terminals/fonts that can't
  render the semantic attribute either — each now gets its own colour
  ([#38](https://github.com/griff-rees/tree-sitter-fountain/issues/38)).

### Known limitation

- Malformed title-page structure (e.g. an unindented continuation
  value) now surfaces as a genuine parse `ERROR` rather than the
  previous silent misparse — more honest, but not yet a graceful
  fallback to parsing the rest as ordinary blocks
  ([#50](https://github.com/griff-rees/tree-sitter-fountain/issues/50)).

## [0.6.1] - 2026-09-12

### Fixed

- `italic`/`bold`/`bold_italic`/`underline`'s colour fallbacks (0.6.0)
  shipped as a separate `highlights-emphasis-colours.scm` file —
  reverted the same day.
  - A consumer's query loader only auto-discovers a file named
    `highlights.scm`, so the second file silently did nothing.
  - Folded directly into `highlights.scm` as the default instead.

## [0.7.0] - 2026-09-12

### Added

- `title_value` (title page "Key: value" content) now supports inline
  emphasis the same way `action`/`dialogue_line` already did —
  previously flat, opaque text only, even for the canonical Brick &
  Steel example's own title styling. Only `title_value`, not
  `section_title`
  ([#49](https://github.com/griff-rees/tree-sitter-fountain/issues/49)).

### Known limitation

- `title_value`'s move to emphasis-aware parsing (above) changed the
  exact shape of the malformed-title-page `ERROR` recovery noted in
  0.6.0 above — smaller and more localised, but arguably easier to
  miss; still tracked under the same issue
  ([#50](https://github.com/griff-rees/tree-sitter-fountain/issues/50)).

## [0.5.0] - 2026-08-09

### Fixed

- `[[notes]]` are now correctly split out as `note` nodes wherever they
  appear, not just on their own line — a note opening mid-line (e.g.
  `He drinks. [[Is this too subtle?]]`) used to be swallowed whole into
  the surrounding prose
  ([#9](https://github.com/griff-rees/tree-sitter-fountain/issues/9)).
- `note` now accepts line breaks inside `[[...]]`, per spec — but not a
  blank line, which still ends the note rather than being absorbed by
  it, matching the spec's "no blank lines inside a note" rule
  ([#9](https://github.com/griff-rees/tree-sitter-fountain/issues/9)).

### Added

- `\[` and `\/` now escape a literal `[` or `/`, the same way `\*` and
  `\_` already escape emphasis: `\[[` no longer opens a note, and
  `\/*` no longer opens a boneyard
  ([#9](https://github.com/griff-rees/tree-sitter-fountain/issues/9)).
- `\]` now escapes a literal `]` *inside* an already-open note (e.g.
  `[[a literal \] bracket]]`) — otherwise unwritable there at all,
  since a bare `]` always ends a note's content
  ([#9](https://github.com/griff-rees/tree-sitter-fountain/issues/9)).

## [0.4.1] - 2026-08-09

### Fixed

- `_underline_`'s reported span no longer absorbs preceding whitespace:
  `A dog      _wags_ its tail.` now highlights exactly `_wags_`
  ([#40](https://github.com/griff-rees/tree-sitter-fountain/issues/40)).
  - `boneyard` had the same issue, fixed the same way, using this
    grammar's first external C scanner.
- `queries/highlights.scm` now captures `(underline)` with
  `@markup.underline`; it had no capture at all previously, since
  there was no `(underline)` node to capture until this release.

### Known limitation

- The `_underline_` fix does not extend to combining different
  emphasis types by nesting one inside another (e.g. `_**bold**_`) —
  that's `#38`, unchanged by this release.
- Boneyard's separate mid-line *nesting* trade-off (opens partway
  through a line and nests inside that line's node instead of
  splitting it into siblings — see 0.4.0's entry below) is unchanged;
  this release fixes span accuracy only, not tree shape. Tracked
  separately as
  [#41](https://github.com/griff-rees/tree-sitter-fountain/issues/41).

## [0.4.0] - 2026-08-08

### Added

- Inline emphasis inside action and dialogue text: `*italics*`,
  `**bold**` and `***bold italics***`, with matching highlight captures
  ([#8](https://github.com/griff-rees/tree-sitter-fountain/issues/8)).
  - Implements the spec's flanking rule (a marker adjacent to
    whitespace stays literal, e.g. `*69 and then *23` does not
    italicize) and `\*` escaping.
  - `_underline_` isn't included yet — a span-accuracy bug, not a
    scope decision, tracked in
    [#40](https://github.com/griff-rees/tree-sitter-fountain/issues/40).

### Changed

- A boneyard that opens partway through an action or dialogue line now
  nests inside that line's node instead of splitting it into two
  sibling nodes; on its own line, unaffected.
  - Traded off deliberately for `#8`; flagged as a possible lint-rule
    candidate in
    [#37](https://github.com/griff-rees/tree-sitter-fountain/issues/37)
    if it matters in practice.

### Known limitation

- Combining different emphasis types by nesting one inside another on
  the same line (e.g. `**bold *and italic* text**`, or the spec's own
  `_Steel's face FILLS the *Leupold Mark 4* scope_`) isn't recognised
  as one combined span — each half is found separately where it stands
  alone. Tracked in
  [#38](https://github.com/griff-rees/tree-sitter-fountain/issues/38).

## [0.3.3] - 2026-08-05

### Fixed

- A transition-shaped line with trailing whitespace after the colon
  (`CUT TO: `) now de-forces to action, as the spec prescribes — the
  trailing space is Fountain's escape hatch for keeping such a line out
  of transition styling
  ([#24](https://github.com/griff-rees/tree-sitter-fountain/issues/24),
  completing it: the mid-line boneyard half was fixed in 0.3.1).

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
