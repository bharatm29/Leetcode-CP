package heap

type Heap struct {
	arr    []int
	length int
}

func NewHeap() *Heap {
	return &Heap{}
}

func (h *Heap) Size() int {
	return h.length
}

func (h *Heap) Push(val int) {
	if len(h.arr) <= h.length {
		h.arr = append(h.arr, -1)
	}

	h.arr[h.length] = val
	h.heapifyUp(h.length)

	h.length++
}

func (h *Heap) Pop() int {
	if h.length == 0 {
		return -1
	}

	val := h.arr[0]
	h.length--

	if h.length == 0 {
		h.arr = []int{}

		return val
	}

	h.arr[0] = h.arr[h.length]

	h.arr = h.arr[:h.length+1]

	h.heapifyDown(0)

	return val
}

func (h *Heap) heapifyUp(index int) {
	if index == 0 {
		return
	}

	parentIndex := getParentIndex(index)
	parentVal := h.arr[parentIndex]
	val := h.arr[index]

	if parentVal > val {
		h.arr[parentIndex] = val
		h.arr[index] = parentVal

		h.heapifyUp(parentIndex)
	}
}

func (h *Heap) heapifyDown(index int) {
	leftIndex, rightIndex := getLeftIndex(index), getRightIndex(index)
	if index >= h.length || leftIndex >= h.length {
		return
	}

	leftVal, rightVal := h.arr[leftIndex], h.arr[rightIndex]
	val := h.arr[index]

	if rightVal > leftVal && val > leftVal {
		h.arr[index] = leftVal
		h.arr[leftIndex] = val

		h.heapifyDown(leftIndex)
	} else if leftVal > rightVal && val > rightVal {
		h.arr[index] = rightVal
		h.arr[rightIndex] = val

		h.heapifyDown(rightIndex)
	}
}

func getParentIndex(index int) int {
	return (index - 1) / 2
}

func getLeftIndex(index int) int {
	return (2 * index) + 1
}

func getRightIndex(index int) int {
	return (2 * index) + 2
}
