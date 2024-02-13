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

	h.length--
	val := h.arr[0]

	if h.length == 0 {
		h.arr = []int{}
		return val
	}

	h.arr[0] = h.arr[h.length]
	h.heapifyDown(0)

	return val
}

func (h *Heap) heapifyUp(index int) {
	if index == 0 {
		return
	}

	pIndex := getParentIndex(index)
	pVal := h.arr[pIndex]

	val := h.arr[index]

	if pVal > val {
		h.arr[pIndex] = val
		h.arr[index] = pVal
		h.heapifyUp(pIndex)
	}
}

func (h *Heap) heapifyDown(index int) {
	lIndex, rIndex := getLeftIndex(index), getRightIndex(index)

	if index >= h.length || lIndex >= h.length {
		return
	}

	lVal, rVal := h.arr[lIndex], h.arr[rIndex]
	val := h.arr[index]

	if rVal > lVal && val > lVal {
		h.arr[index] = lVal
		h.arr[lIndex] = val
		h.heapifyDown(lIndex)
	} else if lVal > rVal && val > rVal {
		h.arr[index] = rVal
		h.arr[rIndex] = val
		h.heapifyDown(rIndex)
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
