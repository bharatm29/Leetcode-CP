package stack_test

import (
	. "ds/cmd/stack"
	"testing"
)

func TestStack(t *testing.T) {
	s := NewStack[int]()

	if s.Size() != 0 {
		t.Fatalf("Initial stack size not 0, got %d", s.Size())
	}

	s.Push(1)
	s.Push(2)
	s.Push(3)
	s.Push(4)

	testStack(s, []int{4, 3, 2, 1}, t)

	s.Pop()
	s.Pop()
	testStack(s, []int{2, 1}, t)

	if s.Top() != 2 {
		t.Fatalf("Expected top value %d, got %d", 2, s.Top())
	}
}

func testStack(s *Stack[int], arr []int, t *testing.T) {
	ls := s.Flatten()

	if len(ls) != len(arr) {
		t.Fatalf("expected list %v got flattened %v", arr, ls)
		return
	}

	for idx, i := range arr {
		if i != ls[idx] {
			t.Fatalf("expected list %v got flattened %v", arr, ls)
			return
		}
	}
}
