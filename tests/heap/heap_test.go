package heap_test

import (
	. "ds/cmd/heap"
	"testing"
)

func TestHeap(t *testing.T) {
	h := NewHeap()

	if h.Size() != 0 {
		t.Fatalf("Initial heap size not 0, got %d", h.Size())
	}

	h.Push(2)
	h.Push(9)
	h.Push(3)
	h.Push(1)

	if h.Size() != 4 {
		t.Fatalf("Heap size after inserting 4 elements is not %d, got %d", 4, h.Size())
	}

	inter := h.Pop()
	if inter != 1 {
		t.Fatalf("Expected minimum value %d, got %d", 1, inter)
	}

	inter = h.Pop()
	if inter != 2 {
		t.Fatalf("Expected minimum value %d, got %d", 2, inter)
	}

	if h.Size() != 2 {
		t.Fatalf("Heap size after deleting 2 elements is not %d, got %d", 2, h.Size())
	}

	h.Push(1)

	inter = h.Pop()
	if inter != 1 {
		t.Fatalf("Expected minimum value %d, got %d", 1, inter)
	}
}
