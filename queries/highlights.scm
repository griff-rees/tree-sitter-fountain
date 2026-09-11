; Syntax highlighting for Fountain screenplays.
; Capture names follow the nvim-treesitter conventions:
; https://neovim.io/doc/user/treesitter.html#treesitter-highlight-groups
;
; Where a conventional group is attribute-only in common themes (e.g.
; @markup.strong is just `bold` and @markup.italic just `italic` in
; NvChad's base46), most elements below layer a coloured capture
; underneath so they stay visible on terminals or fonts without that
; attribute — inline emphasis (italic/bold/bold_italic/underline)
; included; see that section's own comment for why nesting makes this
; one non-optional.

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
; — @markup.strong is `bold`, @markup.italic just `italic`,
; @markup.underline just `underline` in many themes (e.g. NvChad's
; base46), so whether any of these renders as anything more than plain
; prose depends entirely on your terminal/font actually supporting that
; attribute (true italic support in particular is commonly missing on
; monospace fonts) — PLUS a coloured fallback underneath (@property/
; @attribute/@function/@type below), one per type, each independently
; coloured in virtually any complete colorscheme.
;
; Unlike the other elements above, the colour fallback here isn't
; optional: italic/bold/underline can nest inside each other, and
; bold_italic nests inside any of the three as a leaf (#38), so a
; SHARED fallback colour becomes invisible for the inner span whenever
; your setup also can't render its semantic attribute — confirmed
; empirically via Neovim's own highlighter (`vim.inspect_pos`) that a
; nested `(underline (italic))` — e.g. the spec's own "_Steel's face
; FILLS the *Leupold Mark 4* scope_" — resolved both nodes' base colour
; to the same group when they shared one, making the inner span
; indistinguishable from the text around it. None of the four below
; collide with any other capture already used in this file
; (@constant/@string/@string.special/@keyword/@comment/@comment.note/
; @markup.heading/@markup.raw/@punctuation.special/@number) — the
; actual colour chosen for each is arbitrary (this project has no code
; semantics to map onto), only mutual distinctness matters. If your own
; terminal/font already renders one of the four distinctly without it
; (verified empirically, not assumed), trim that one capture line from
; your own installed copy of this file — this project's own copy stays
; a single self-contained `highlights.scm`, colours included by
; default, rather than a second file you'd otherwise have to remember
; to merge in yourself.
;
; _underline_ (#40): span accuracy is handled at the grammar level (an
; external scanner, see src/scanner.c) rather than here.
(italic) @markup.italic
(italic) @property
(bold) @markup.strong
(bold) @attribute
(bold_italic) @markup.strong
(bold_italic) @markup.italic
(bold_italic) @function
(underline) @markup.underline
(underline) @type

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
