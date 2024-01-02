package binarytree_test

import (
	. "ds/cmd/binary_tree"
	"testing"
)

func TestBinTree(t *testing.T) {
	root := Insert(nil, 10)
	root = Insert(root, 2)
	root = Insert(root, 4)
	root = Insert(root, 13)
	root = Insert(root, 12)
	root = Insert(root, 15)

    testTree(root, []int{2, 4, 10, 12, 13, 15}, t)

    if !Search(root, 15) {
        t.Fatalf("Couldn't find the inserted item %d", 15)
    }

    if Search(root, 6) {
        t.Fatalf("Found the non-inserted item %d", 6)
    }

    if GetVal(FindMax(root)) != 15 {
        t.Fatalf("Expected max as %d but found %d", 15, GetVal(FindMax(root)))
    }

    if GetVal(FindMin(root)) != 2 {
        t.Fatalf("Expected min as %d but found %d", 2, GetVal(FindMin(root)))
    }

    root = Delete(root, 12)
    testTree(root, []int{2, 4, 10, 13, 15}, t)

    root = Delete(root, 10)
    testTree(root, []int{2, 4, 13, 15}, t)
}

func testTree(root *Node, arr []int, t *testing.T) {
	ls := []int{}

	Inorder(root, &ls)

    if len(ls) != len(arr) {
        t.Fatalf("expected list %v got inordered %v", arr, ls)
    }

	for idx, i := range arr {
		if i != ls[idx] {
			t.Fatalf("expected list %v got inordered %v", arr, ls)
			return
		}
	}
}
