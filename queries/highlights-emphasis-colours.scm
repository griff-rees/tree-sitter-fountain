; Colour fallbacks for inline emphasis (italic/bold/bold_italic/
; underline) — companion to highlights.scm, not loaded automatically by
; nvim-treesitter or any other tree-sitter consumer (it only auto-
; discovers a file literally named `highlights.scm` per language). The
; README's install instructions have you concatenate this file with
; highlights.scm into your own runtimepath copy by default — this is
; the safe choice for a fresh install, since without it
; italic/bold/bold_italic/underline render as nothing more than plain
; prose on any terminal/font that can't render their attribute.
;
; Why this lives in a separate file rather than being folded directly
; into highlights.scm: whether you actually WANT a given colour is a
; call only you can make, empirically (try it, see what renders) — no
; tree-sitter query can detect what your terminal/font supports (no
; portable way to introspect glyph/attribute support from a static
; .scm file, or even from Neovim's own Lua API). Keeping these four
; lines separate, each independent, makes trimming the ones you've
; verified you don't need a one-line deletion from your own merged
; copy, rather than hunting through a combined file. If your terminal
; already renders true italic but not bold, delete just the `bold`
; line from your copy, keep the rest. Note that `bold_italic` is its
; own separate choice too, not implied by keeping/dropping `italic`'s
; and `bold`'s: it's a single leaf node (`***...***`), not built from
; the other two, so it needs its own line kept or dropped.
;
; Each of the four gets its OWN colour, not a shared one — do not
; collapse them back to one shared capture (e.g. reusing @property for
; more than one): italic/bold/underline can nest inside each other, and
; bold_italic nest inside any of the three as a leaf (#38), so a shared
; fallback becomes invisible for the inner span whenever your setup
; also can't render ITS attribute — confirmed empirically via Neovim's
; own highlighter (`vim.inspect_pos`) that a nested `(underline
; (italic))` — e.g. the spec's own "_Steel's face FILLS the *Leupold
; Mark 4* scope_" — resolved both nodes' base colour to the identical
; group when they shared one, making the italic span indistinguishable
; from the underlined text around it on a font without true italic
; support. @property/@attribute/@function/@type below are ordinary,
; independently-coloured syntax groups in virtually any complete
; colorscheme, and none collide with any other capture already used in
; highlights.scm (@constant/@string/@string.special/@keyword/@comment/
; @comment.note/@markup.heading/@markup.raw/@punctuation.special/
; @number) — the actual colour chosen for each is arbitrary (this
; project has no code semantics to map onto), only mutual distinctness
; matters.

(italic) @property

(bold) @attribute

(bold_italic) @function

(underline) @type
