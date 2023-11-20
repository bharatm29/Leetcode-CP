export default class MinHeap {
    public length: number;
    private data: number[];

    constructor() {
        this.length = 0;
        this.data = [];
    }

    insert(value: number): void {
        this.data[this.length] = value;
        this.heapifyUp(this.length);
        this.length++;
    }

    delete(): number {
        if(this.length === 0){
            return -1;
        }

        this.length--;
        const val = this.data[0];

        if(this.length === 0){
            this.data = [];
            return val;
        }

        this.data[0] = this.data[this.length];
        this.heapifyDown(0);

        return val;
    }

    private heapifyDown(index: number): void {
        const lIndex = this.leftChild(index);
        const rIndex = this.rightChild(index);

        if(index >= this.length || lIndex >= this.length){
            return;
        }

        const lVal = this.data[lIndex];
        const rVal = this.data[rIndex];
        const val = this.data[index];

        if(lVal > rVal && val > rVal){
            this.data[rIndex] = val;
            this.data[index] = rVal;
            this.heapifyDown(rIndex);
        }
        else if(rVal > lVal && val > lVal){
            this.data[lIndex] = val;
            this.data[index] = lVal;
            this.heapifyDown(lIndex);
        }
    }

    private heapifyUp(index: number): void {
        if(index === 0){
            return;
        }

        const p = this.parent(index);
        const parentV = this.data[p];
        const v = this.data[index];

        if(parentV > v){
            this.data[index] = parentV;
            this.data[p] = v;
            this.heapifyUp(p); //continue heapifying up
        }
    }

    private parent(index: number): number {
        return Math.floor((index - 1) / 2);
    }

    private leftChild(index: number): number {
        return 2 * index + 1;
    }

    private rightChild(index: number): number {
        return 2 * index + 2;
    }
}
