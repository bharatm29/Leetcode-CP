package linked_list_test

import (
	. "ds/cmd/linked_list"
	"testing"
)

func TestLinkedList(t *testing.T) {
	list := NewLinkedList[int]()

	// size and clear
	if list.Size() != 0 {
		t.Fatalf("Initial length not 0, got %d", list.Size())
	}

    list.Clear()
	if list.Size() != 0 {
		t.Fatalf("Length not 0 after clearing, got %d", list.Size())
	}

	// prepend
	list.Prepend(1)

	if list.Get(0) != 1 {
		t.Fatalf("Prepend function not working, expected prepended 1 got %d", list.Get(0))
	}

	list.Prepend(2)

	if list.Get(0) != 2 {
		t.Fatalf("Prepend function not working, expected prepended 2 got %d", list.Get(0))
	}

	// append
	list.Append(3)

	if list.Get(list.Size()-1) != 3 {
		t.Fatalf("Append function not working, expected appended 3 got %d", list.Get(list.Size()-1))
	}

	list.Append(4)

	if list.Get(list.Size()-1) != 4 {
		t.Fatalf("Append function not working, expected appended 4 got %d", list.Get(list.Size()-1))
	}

	// remove
	list.Remove(1)
	if list.Size() != 3 {
		t.Fatalf("length not 3 after removing from list with 4 elements, got %d", list.Size())
	}
    testList(list, []int{2, 3, 4}, t)

    //insertAt
    list.InsertAt(0, 5)
    list.InsertAt(list.Size() - 1, 6)
    list.InsertAt(2, 7)

	if list.Size() != 6 {
		t.Fatalf("length not 6 after inserting in a list with 3 elements, got %d", list.Size())
	}

    testList(list, []int {5, 2, 7, 3, 4, 6}, t)

    //removeAt
    list.RemoveAt(0)
    list.RemoveAt(list.Size() - 1)
    list.RemoveAt(1)
    testList(list, []int{2, 3, 4}, t)
}

func testList(l *LinkedList[int], arr []int, t *testing.T) {
	ls := l.Flatten()

	for idx, i := range arr {
		if i != ls[idx] {
			t.Fatalf("expected list %v got flattened %v", arr, ls)
			return
		}
	}
}
