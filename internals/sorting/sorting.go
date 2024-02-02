package sorting

func BubbleSort(arr []int) []int {
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr)-i-1; j++ {
			if arr[j+1] < arr[j] {
				temp := arr[j+1]
				arr[j+1] = arr[j]
				arr[j] = temp
			}
		}
	}

	return arr
}

func QuickSort(arr *[]int, low, high int) {
	if low >= high {
		return
	}

	pivotIndex := partition2(arr, low, high)

	QuickSort(arr, low, pivotIndex-1)
	QuickSort(arr, pivotIndex+1, high)
}

func partition(arr *[]int, low, high int) int {
    pivotVal := (*arr)[high]

    index := low - 1

    for i := low; i < high; i++{
        if (*arr)[i] < pivotVal {
            index++

            temp := (*arr)[i]
            (*arr)[i] = (*arr)[index]
            (*arr)[index] = temp
        }
    }

    index++

    (*arr)[high] = (*arr)[index]
    (*arr)[index] = pivotVal
 
	return index
}

func partition2(arr *[]int, low, high int) int {
    pivot := (*arr)[low]

    i := low
    j := high

    for i < j {
        for i < high && (*arr)[i] <= pivot {
            i++
        }
        for j >= low && (*arr)[j] > pivot {
            j--
        }

        if (i < j){
            temp := (*arr)[j]
            (*arr)[j] = (*arr)[i]
            (*arr)[i] = temp
        }
    }

    (*arr)[low] = (*arr)[j]
    (*arr)[j] = pivot

    return j
}

func InsertionSort(arr []int) []int {
    for i := 1; i < len(arr); i++ {
        key := arr[i]
        j := i - 1

        for j >= 0 && arr[j] > key {
            arr[j + 1] = arr[j]
        }

        arr[j + 1] = key
    }

    return arr
}

func SelectionSort(arr []int) []int {
    for i := 0; i < len(arr); i++ {
        idx := i

        for j := i + 1; j < len(arr); j++ {
            if arr[j] < arr[idx] {
                idx = j
            }
        }

        temp := arr[i]
        arr[i] = arr[idx]
        arr[idx] = temp
    }

    return arr
}
