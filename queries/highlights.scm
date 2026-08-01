; Syntax highlighting for Fountain screenplays.
; Capture names follow the nvim-treesitter conventions:
; https://neovim.io/doc/user/treesitter.html#treesitter-highlight-groups

(scene_heading) @markup.heading.2

(section) @markup.heading.1

(character) @constant

(parenthetical) @string.special

(lyric) @markup.italic

(transition) @keyword

(centered) @markup.strong

(synopsis) @comment

(note) @comment.note

(boneyard) @comment

(page_break) @punctuation.special

(title_key) @property

(title_value) @string
