package tree_sitter_fountain_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_fountain "github.com/griff-rees/tree-sitter-fountain/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_fountain.Language())
	if language == nil {
		t.Errorf("Error loading fountain grammar")
	}
}
