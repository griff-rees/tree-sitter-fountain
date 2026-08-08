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

; Inline emphasis (in action and dialogue text): coloured base plus the
; matching attribute(s), same pattern as lyrics/centered text below.
; This matters most for italic: bold usually falls back to a
; brightened colour even without a bold font face, but italic has no
; such fallback — if the terminal font has no true italic face
; (common for monospace fonts) and the terminal doesn't synthesize one
; (most don't), the attribute alone renders nothing, and without a
; colour underneath that text is indistinguishable from plain prose.
; @property is otherwise unused in flowing action/dialogue text, so it
; doesn't collide with character/parenthetical/lyric/centered's
; existing colours here.
;
; _underline_ is not implemented yet (#40 — a token's reported span
; swallows preceding whitespace, which is invisible for colour/bold
; but would visibly bridge gaps for underline's own line-drawing
; attribute); there is no (underline) node to capture until then.
(italic) @property
(italic) @markup.italic
(bold) @property
(bold) @markup.strong
(bold_italic) @property
(bold_italic) @markup.strong
(bold_italic) @markup.italic

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
