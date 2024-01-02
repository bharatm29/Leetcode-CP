package queue_test

import (
	. "ds/cmd/queue"
	"testing"
)

func TestQueue(t *testing.T) {
    q := NewQueue[int]()

    if q.Size() != 0 {
        t.Fatalf("Initial queue size not 0, got %d", q.Size())
    }

    q.Push(1)
    q.Push(2)
    q.Push(3)
    testList(q, []int{1, 2, 3}, t)

    q.Push(4)
    q.Push(5)

    q.Pop()
    q.Pop()
    testList(q, []int{3, 4, 5}, t)

    q.Pop()
    if q.Front() != 4 {
        t.Fatalf("Expected Front val %d, got %d instead", 4, q.Front())
    }
}

func testList(q *Queue[int], arr []int, t *testing.T) {
	ls := q.Flatten()

	for idx, i := range arr {
		if i != ls[idx] {
			t.Fatalf("expected list %v got flattened %v", arr, ls)
			return
		}
	}
}
