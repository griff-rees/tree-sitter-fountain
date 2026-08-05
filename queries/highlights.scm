; Syntax highlighting for Fountain screenplays.
; Capture names follow the nvim-treesitter conventions:
; https://neovim.io/doc/user/treesitter.html#treesitter-highlight-groups
;
; Where a conventional group is attribute-only in common themes (e.g.
; @markup.strong is just `bold` and @markup.italic just `italic` in
; NvChad's base46), a coloured capture is layered underneath so the
; element stays visible on terminals or fonts without those attributes.

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
