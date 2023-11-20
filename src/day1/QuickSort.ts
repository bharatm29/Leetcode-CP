function qs(arr: number[], lo: number, hi: number){
    if(lo >= hi){
        return;
    }

    const pivotIndex = pivot(arr, lo, hi);
    qs(arr, lo, pivotIndex - 1);
    qs(arr, pivotIndex + 1, hi);
}

function pivot(arr: number[], lo: number, hi: number) {
    const pivotVal = arr[hi];
    let index = lo - 1;

    for(let i = lo; i < hi; i++){
        if(arr[i] <= pivotVal){
            index++;

            const temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
        }
    }

    index++;

    arr[hi] = arr[index];
    arr[index] = pivotVal;

    return index;
}

export default function quick_sort(arr: number[]): void {
    qs(arr, 0, arr.length - 1);
}

