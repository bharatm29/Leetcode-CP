package trie_test

import (
	. "ds/cmd/trie"
	"testing"
)

func TestTrie(t *testing.T) {
	trie := NewTrie()

	trie.Insert("lol")
	trie.Insert("hahahah")
	trie.Insert("lmfaooo")

	if !trie.Search("lol") {
		t.Fatalf("Trie search not working :(")
	}

	if trie.Search("lmfao") {
		t.Fatalf("Trie search not working :(")
	}

	if !trie.StartsWith("lo") {
		t.Fatalf("Trie startsWith not working :(")
	}

	if trie.StartsWith("ramesh") {
		t.Fatalf("Trie startsWith not working :(")
	}

	if !trie.StartsWith("haha") {
		t.Fatalf("Trie startsWith not working :(")
	}
}
