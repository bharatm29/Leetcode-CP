package heapsort_test

import (
	. "algos/internals/heapsort"
	"testing"
)

func TestHeapSort(t *testing.T) {
	arr := []int{1, 9, 8, 4, 5, 2}

	sorted_arr := HeapSort(arr)
    expected_arr := []int{1, 2, 4, 5, 8, 9}

	for index, i := range expected_arr {
		if i != sorted_arr[index] {
			t.Fatalf("expected sorted arr %v, got %v", expected_arr, sorted_arr)
		}
	}
}
