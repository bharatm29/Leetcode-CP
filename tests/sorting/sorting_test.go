package sorting_test

import (
	. "algos/internals/sorting"
	"testing"
)

func TestSorting(t *testing.T) {
	arr := []int{1, 2, 6, 8, 4, 7}

	testList(BubbleSort(arr), []int{1, 2, 4, 6, 7, 8}, t)
	testList(InsertionSort(arr), []int{1, 2, 4, 6, 7, 8}, t)
	testList(SelectionSort(arr), []int{1, 2, 4, 6, 7, 8}, t)

	QuickSort(&arr, 0, len(arr)-1)
	testList(arr, []int{1, 2, 4, 6, 7, 8}, t)
}

func testList(ls []int, arr []int, t *testing.T) {
	if len(ls) != len(arr) {
		t.Fatalf("expected list %v got %v", arr, ls)
	}

	for index, i := range arr {
		if ls[index] != i {
			t.Fatalf("expected list %v got %v", arr, ls)
		}
	}
}
