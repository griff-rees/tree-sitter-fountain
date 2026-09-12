# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to
[Semantic Versioning](https://semver.org/spec/v2.0.0.html). Versions are git
tags; registry publishing is tracked in
[#15](https://github.com/griff-rees/tree-sitter-fountain/issues/15).

## [Unreleased]

### Added

- Forced character cues (`@McCLANE`) now get the same `character_name`/
  `character_extension`/`character_marker` structure `#56` gave the
  ordinary cue, instead of staying a flat, opaque token. The name is
  now an external scanner token (`src/scanner.c`'s
  `scan_forced_character_name`), sharing `#56`'s rest-of-cue validation
  (extensions, marker, a real trailing newline) via a new
  `validate_character_cue_rest` helper both scanners call. Two things
  differ from the ordinary cue, confirmed empirically via another
  disposable spike (never merged): the name's own alphabet is far more
  permissive (any character, since `@` forces recognition regardless of
  case) and needs no scene-heading/transition guard (nothing else can
  start with `@`, so there's no other live reading to collide with);
  and when validation fails (e.g. an unclosed extension), it falls back
  to the flat `_forced_character_line` token rather than to ordinary
  action text — mirroring `scene_heading`'s own
  `choice(structured, _forced_scene_line)` pattern, since a forced cue
  has no competing `action` reading the way the bare cue does
  ([#57](https://github.com/griff-rees/tree-sitter-fountain/issues/57)).

## [0.8.0] - 2026-09-12

### Added

- Character cues now expose their structure instead of lexing as one
  atomic token: `character` gains a `character_name` child, zero or
  more `character_extension` children for parenthetical extensions
  like `(V.O.)`/`(CONT'D)`, and an optional `character_marker` child
  for the `^` dual-dialogue marker — each independently queryable and
  highlighted (`queries/highlights.scm`). A disposable spike (never
  merged) first tried splitting the cue into plain grammar tokens,
  mirroring `scene_heading`'s technique; it broke broadly, including
  ordinary capitalized action text ("The cat sat quietly."), because a
  bare uppercase-letter prefix could commit to a doomed name token with
  no legal close after it — the same "committed reading, no legal
  close" ERROR `#38`'s Tier 2 (`parenthetical`/`centered`) hit. Fixed
  the same way: the name is now an external scanner token
  (`src/scanner.c`) that validates a legal whole cue — extensions,
  marker, and a real trailing newline — exists ahead before ever
  committing, so a false start falls back to ordinary action text
  instead of erroring. The scanner also explicitly cedes to a bare
  `INT`/`EXT`/`EST` scene-heading prefix and a leading `.` (forced
  scene heading), since both are otherwise fully expressible within
  the name's own alphabet and an external token always wins over an
  internal one's `prec()` once it validates. `@`-forced character cues
  (`@McCLANE`) are unchanged, deliberately out of scope for now — their
  any-case alphabet needs its own separate design
  ([#56](https://github.com/griff-rees/tree-sitter-fountain/issues/56)).

## [0.6.0] - 2026-09-11

### Added

- Same-line nested emphasis: `italic`/`bold`/`underline` are now real
  grammar rules whose content may recursively contain each other — e.g.
  `**bold *and italic* text**`, or the spec's own
  `_Steel's face FILLS the *Leupold Mark 4* scope_`. `bold_italic`
  stays the flat, atomic token it always was, but may now appear as a
  nested child inside the other three. An earlier spike found that a
  pure multi-token grammar rule (no external scanner) hits a real,
  unresolved GLR limitation — once the opening delimiter is shifted,
  tree-sitter's default shift/reduce resolution commits to that
  reading, and a missing closing delimiter surfaces as generic error
  recovery rather than backtracking to a live sibling parse. Fixed by
  having the external scanner independently validate (via forward
  lookahead) that a legal close exists before ever emitting the OPEN
  token, so the parser never shifts a doomed reading in the first
  place ([#38](https://github.com/griff-rees/tree-sitter-fountain/issues/38)).
- `lyric`, `synopsis`, forced `action` lines, `parenthetical` and
  `centered` now all support inline emphasis the same way `action`/
  `dialogue_line` already did — previously flat text only. `centered`
  and `parenthetical` needed the same pre-validating-scanner treatment
  as the nested-emphasis rules above (confirmed the hard way: a plain-
  token attempt broke an unclosed forced transition,
  `> Burn to White.`, by committing to a doomed `centered` reading)
  ([#38](https://github.com/griff-rees/tree-sitter-fountain/issues/38)).
- Title page continuation values must now be indented (3 or more
  spaces, or a tab), per spec — previously any line was silently
  accepted, regardless of indentation
  ([#48](https://github.com/griff-rees/tree-sitter-fountain/issues/48)).
- `queries/highlights-emphasis-colours.scm`: an opt-in-by-default
  companion to `highlights.scm` with one colour-fallback line per
  emphasis type (`italic`/`bold`/`bold_italic`/`underline`), each
  independent so a user who's verified their terminal/font already
  renders some of the four can trim just those lines from their own
  installed copy. See the README's "Colour fallbacks for emphasis"
  section.

### Fixed

- A forced action line's own first line (`!Forced action.`) now
  supports inline emphasis, matching its continuation lines, which
  already did ([#38](https://github.com/griff-rees/tree-sitter-fountain/issues/38)).
- `note`'s reported span could include preceding whitespace, the same
  bug [#40](https://github.com/griff-rees/tree-sitter-fountain/issues/40)
  fixed for `boneyard`/`underline` but never applied to `note` —
  unnoticed until now because the bug is only visually obvious for a
  highlight attribute that paints something over blank cells, and
  `note` typically renders as a plain foreground colour
  ([#38](https://github.com/griff-rees/tree-sitter-fountain/issues/38)).
- Title page continuation values containing well-formed emphasis (e.g.
  the canonical Brick & Steel title, `_**BRICK & STEEL**_`) were
  losing to a stray `action` block instead of being captured as
  `title_value`. Root cause: external scanner tokens (see the nested-
  emphasis entry above) unconditionally win over internal tokens like
  `_any_line` on success, which broke a length-based tie-break
  `title_entry`'s structure had silently relied on
  ([#38](https://github.com/griff-rees/tree-sitter-fountain/issues/38)).
- `italic`/`bold`/`bold_italic`/`underline` all shared one colour
  fallback (`@property`) in `queries/highlights.scm`, invisible until
  nesting (above) made two of them able to apply to overlapping spans
  at once: a nested span rendered with the identical fallback colour
  as its parent, making it indistinguishable on any terminal/font that
  also couldn't render the semantic attribute — confirmed empirically
  via Neovim's own highlighter. Each now gets its own colour, moved
  into the new `highlights-emphasis-colours.scm`
  ([#38](https://github.com/griff-rees/tree-sitter-fountain/issues/38)).

Malformed title-page structure (e.g. an unindented continuation value)
now surfaces as a genuine parse `ERROR` rather than the previous
silent misparse — more honest, but not yet a graceful fallback to
parsing the rest as ordinary blocks, which needs `title_page`/`action`
declared as a real GLR conflict
([#50](https://github.com/griff-rees/tree-sitter-fountain/issues/50)).

## [0.6.1] - 2026-09-12

### Fixed

- `italic`/`bold`/`bold_italic`/`underline`'s colour fallbacks
  (introduced in 0.6.0 above) shipped as a separate, opt-in
  `highlights-emphasis-colours.scm` file the README had users merge in
  by hand — reverted the same day: a consumer's tree-sitter query
  loader only ever auto-discovers a file literally named
  `highlights.scm`, so the second file silently did nothing unless
  merged in exactly right, confirmed the hard way when a routine local
  install got this wrong. Folded directly into `highlights.scm` as the
  default instead, colours included, no merge step required.

## [0.7.0] - 2026-09-12

### Added

- `title_value` (title page "Key: value" content) now supports inline
  emphasis the same way `action`/`dialogue_line` already did —
  previously flat, opaque text only, even for the canonical Brick &
  Steel example's own title styling
  (`Title:\n\t_**BRICK & STEEL**_`). Only `title_value`, not
  `section_title`
  ([#49](https://github.com/griff-rees/tree-sitter-fountain/issues/49)).

`title_value`'s move to emphasis-aware parsing (above) changed the
exact shape of the malformed-title-page `ERROR` recovery noted in
0.6.0 above — it's now smaller and more localised, but arguably easier
to miss than before, since an otherwise-invalid unindented line can
now recover into looking like an ordinary, error-free `title_value`;
still tracked under the same issue
([#50](https://github.com/griff-rees/tree-sitter-fountain/issues/50)),
not a new one.

## [0.5.0] - 2026-08-09

### Fixed

- `[[notes]]` are now correctly split out as `note` nodes wherever they
  appear, not just on their own line: a note opening mid-line (e.g.
  `He drinks. [[Is this too subtle?]]`) used to be swallowed whole into
  the surrounding `action`/`dialogue_line` prose, because `_prose_text`
  had no reason to stop at `[` and so out-matched the (shorter) `note`
  token on length. Fixed by giving `[[` the same "first refusal"
  `_prose_text` already gives `/*` (the boneyard fix, #31): a `[`
  immediately followed by another `[` is no longer ordinary prose
  content, so `note` gets first shot at it
  ([#9](https://github.com/griff-rees/tree-sitter-fountain/issues/9)).
- `note` now accepts line breaks inside `[[...]]`, per spec — but not a
  blank line, which still ends the note (falling back to plain text)
  rather than being absorbed by it, matching the spec's "no blank lines
  inside a note" rule
  ([#9](https://github.com/griff-rees/tree-sitter-fountain/issues/9)).

### Added

- `\[` and `\/` now escape a literal `[` or `/`, the same way `\*` and
  `\_` already escape emphasis: `\[[` no longer opens a note, and
  `\/*` no longer opens a boneyard. Not in the Fountain spec itself
  (notes and boneyards have no documented escape syntax), but a
  natural extension of the fix above — leaving the one pair of
  mid-line-swallowed delimiters with no way to write literally would
  have been a rough edge
  ([#9](https://github.com/griff-rees/tree-sitter-fountain/issues/9)).
- `\]` now escapes a literal `]` *inside* an already-open note (e.g.
  `[[a literal \] bracket]]`) — otherwise unwritable there at all,
  since a bare `]` always ends a note's content
  ([#9](https://github.com/griff-rees/tree-sitter-fountain/issues/9)).

## [0.4.1] - 2026-08-09

### Fixed

- `_underline_`'s reported span no longer absorbs preceding whitespace:
  `A dog      _wags_ its tail.` now highlights exactly `_wags_` rather
  than bleeding the underline attribute across the six preceding
  spaces. `boneyard` had the identical characteristic (its span could
  likewise swallow leading whitespace, e.g. before `/* comment */`)
  and is fixed the same way. Two pure-grammar attempts (an explicit,
  non-`extra` whitespace token — first broadly in `_prose_line`, then
  scoped to only precede `underline`) both fixed the span and both
  broke other parses (scene_heading recognition, boneyard nesting, EOF
  handling): tree-sitter's lexer resolves a token deterministically
  before GLR ever forks, so no in-grammar trick can make a whitespace
  token conditional on "a delimiter follows" without it also winning
  at every other position it's reachable. Fixed instead with this
  grammar's first external C scanner (`src/scanner.c`), using
  `advance(lexer, skip)` to trim leading whitespace from a token's
  span without it counting toward that span — the documented idiom
  for exactly this in tree-sitter's own external-scanner guide, also
  used by tree-sitter-php, -lua and -nix
  ([#40](https://github.com/griff-rees/tree-sitter-fountain/issues/40)).
- `queries/highlights.scm` now captures `(underline)` with
  `@markup.underline`; it had no capture at all previously, since
  there was no `(underline)` node to capture until this release.

### Known limitation

- The `_underline_` fix does not extend to combining different
  emphasis types by nesting one inside another (e.g. `_**bold**_`) —
  that's `#38`, unchanged by this release: `underline`'s content still
  cannot contain `*`, the same as before.
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
  (`@markup.italic`, `@markup.strong`). Implements the spec's flanking
  rule (a marker adjacent to whitespace stays literal, e.g.
  `*69 and then *23` does not italicize) and `\*` escaping
  ([#8](https://github.com/griff-rees/tree-sitter-fountain/issues/8)).
  `_underline_` is deliberately not included: it hit a genuine
  highlighting bug rather than a scope decision — a token's reported
  span always starts from wherever the lexer began searching, so any
  whitespace skipped as an extra gets folded into the following
  token's boundaries. This is true of every token in this grammar
  (`location`/`time` in `scene_heading` have the same characteristic)
  but was previously invisible, since colour and bold-weight
  attributes render nothing on blank space; underline is the first
  capture whose attribute paints something under blank cells, which
  makes multiple spaces before `_underline_` visibly render as
  underlined too. Tracked in
  [#40](https://github.com/griff-rees/tree-sitter-fountain/issues/40).

### Changed

- A boneyard that opens partway through an action or dialogue line
  (rather than on its own line) now nests inside that line's node
  instead of splitting it into two sibling nodes with the boneyard
  between them; the surrounding blank-line block separation, and the
  case of a boneyard occupying its own line, are unaffected. Traded
  off deliberately for #8 to avoid doubling every inline-content token
  into "mid-line"/"line-final" variants; see the `_prose_line` comment
  in `grammar.js`. Flagged as a possible candidate for a lint rule in
  [#37](https://github.com/griff-rees/tree-sitter-fountain/issues/37)
  if the distinction turns out to matter in practice.

### Known limitation

- Combining different emphasis types by nesting one inside another on
  the same line (e.g. `**bold *and italic* text**`, or the spec's own
  `_Steel's face FILLS the *Leupold Mark 4* scope_`) isn't recognised
  as one combined span — each half is found separately where it stands
  alone. A multi-token design capable of this nesting hit a real,
  unresolved GLR limitation; tracked in
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
