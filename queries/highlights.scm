; Syntax highlighting for Fountain screenplays.
; Capture names follow the nvim-treesitter conventions:
; https://neovim.io/doc/user/treesitter.html#treesitter-highlight-groups
;
; Where a conventional group is attribute-only in common themes (e.g.
; @markup.strong is just `bold` and @markup.italic just `italic` in
; NvChad's base46), most elements below layer a coloured capture
; underneath so they stay visible on terminals or fonts without that
; attribute. The one exception is inline emphasis (italic/bold/
; bold_italic/underline) — see that section's own comment: their
; colours live in the separate `highlights-emphasis-colours.scm`
; instead, which the README's install instructions have you merge in
; by default (the safe choice for a fresh install), since which of the
; four colours you actually want depends on what your own terminal/
; font renders and this query file has no way to detect that itself.

; Scene headings: the whole line gets the heading colour as a base
; (forced ".HEADING" lines have no child nodes, so this is all they
; get), then the structured parts are coloured individually.
(scene_heading) @markup.heading.2

(scene_prefix) @keyword

; The location/time separator dash, matching the prefix colour.
(scene_heading
  "-" @keyword)

(location) @markup.heading.2

(time) @constant

(scene_number) @number

; Sections: the marker's length is the nesting level. A generic capture
; covers every level; levels 1-3 are refined for themes that colour
; @markup.heading.N distinctly.
(section_marker) @punctuation.special

(section_title) @markup.heading

((section
  marker: (section_marker) @_marker
  title: (section_title) @markup.heading.1)
 (#eq? @_marker "#"))

((section
  marker: (section_marker) @_marker
  title: (section_title) @markup.heading.2)
 (#eq? @_marker "##"))

((section
  marker: (section_marker) @_marker
  title: (section_title) @markup.heading.3)
 (#eq? @_marker "###"))

(character) @constant

(parenthetical) @string.special

; Inline emphasis (in action and dialogue text): the semantic attribute
; only — @markup.strong is `bold`, @markup.italic just `italic`,
; @markup.underline just `underline` in many themes (e.g. NvChad's
; base46), so whether any of these renders as anything more than plain
; prose depends entirely on your terminal/font actually supporting that
; attribute (true italic support in particular is commonly missing on
; monospace fonts).
;
; A coloured fallback for whichever of these your setup can't render
; lives in the separate `highlights-emphasis-colours.scm`, merged in by
; default per the README's install instructions — kept in its own file
; rather than inlined here because trimming a colour you've verified
; you don't need (which of the four, if any, is up to what YOUR
; terminal/font actually supports — this query file has no way to
; detect that itself) is then a one-line deletion from your own merged
; copy, not an edit to this project's own file. See that file's own
; header, and the README's "Colour fallbacks for emphasis" section.
;
; _underline_ (#40): span accuracy is handled at the grammar level (an
; external scanner, see src/scanner.c) rather than here.
(italic) @markup.italic
(bold) @markup.strong
(bold_italic) @markup.strong
(bold_italic) @markup.italic
(underline) @markup.underline

; Lyrics: coloured base plus the italic attribute. Deliberately @string
; rather than @string.special so lyrics and parentheticals differ (and
; title values use @markup.raw, keeping all three groups distinct).
(lyric) @string
(lyric) @markup.italic

(transition) @keyword

; Centered text: coloured base plus the bold attribute (bold alone is
; invisible on already-uppercase lines like "> THE END <").
(centered) @markup.heading
(centered) @markup.strong

(synopsis) @comment

(note) @comment.note

(boneyard) @comment

(page_break) @punctuation.special

(title_key) @property

(title_value) @markup.raw
