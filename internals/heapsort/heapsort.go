package heapsort

func HeapSort(arr []int) []int {
	h := Heap{}

	for _, i := range arr {
		h.Push(i)
	}

	for i := 0; i < len(arr); i++ {
		h.Pop()
	}

	return h.arr[1:len(h.arr)]
}

type Heap struct {
	arr    []int
	length int
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

	h.arr[0] = h.arr[h.length]

	if h.length+1 == len(h.arr) {
		h.arr = append(h.arr, -1)
	}

	h.arr[h.length+1] = val

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

	if pVal < val {
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

	if rVal < lVal && val < lVal {
		h.arr[lIndex] = val
		h.arr[index] = lVal
		h.heapifyDown(lIndex)
	} else if lVal < rVal && val < rVal {
		h.arr[rIndex] = val
		h.arr[index] = rVal
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
