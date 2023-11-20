type Node<T> = {
    value: T,
    next?: Node<T>,
    prev?: Node<T>
}

export default class DoublyLinkedList<T> {
    public length: number;
    private head?: Node<T>;
    private tail?: Node<T>;

    constructor() {
        this.length = 0;
        this.head = this.tail = undefined;
    }

    prepend(item: T): void {
        const node = {value: item} as Node<T>;

        this.length++;

        if(!this.head){
            this.head = this.tail = node;
            return;
        }

        node.next = this.head;
        this.head.prev = node;
        this.head = node;
    }

    insertAt(item: T, index: number): void {
        if(index > this.length){
            throw new Error("lol");
        }
        else if(index === this.length){
            this.append(item);
            return;
        }
        else if(index === 0){
            this.prepend(item);
            return;
        }

        this.length++;

        const node = {value: item} as Node<T>;

        const curr = this.getAt(index) as Node<T>;

        if(curr.prev){
            curr.prev.next = node;
        }

        node.prev = curr.prev;
        node.next = curr;
        curr.prev = node;
    }
    append(item: T): void {
        const node = {value: item} as Node<T>;

        this.length++;

        if(!this.head || !this.tail){
            this.head = this.tail = node;
            return;
        }

        node.prev = this.tail;
        this.tail.next = node;
        this.tail = node;
    }

    remove(item: T): T | undefined {
        let curr = this.head;

        for(let i = 0; curr && i < this.length; i++){
            if(curr.value === item){
                break;
            }
            curr = curr.next;
        }

        if(!curr){
            return;
        }

        return this.removeNode(curr);
    }

    get(index: number): T | undefined {
        return this.getAt(index)?.value;
    }

    removeAt(idx: number): T | undefined {
        const node = this.getAt(idx);
        if(!node){
            return undefined;
        }
        return this.removeNode(node);
    }

    private removeNode(node: Node<T>): T | undefined {
        if(--this.length === 0){
            const res = node.value;
            this.head = this.tail = undefined;
            return res;
        }

        if(this.head === node){
            this.head = this.head.next;
        }
        if(this.tail === node){
            this.tail = this.tail.prev;
        }

        if(node.prev){
            node.prev.next = node.next;
        }

        if(node.next){
            node.next.prev = node.prev;
        }

        node.next = node.prev = undefined;

        return node.value;
    }

    private getAt(index: number): Node<T> | undefined {
        let curr = this.head;

        for(let i = 0; curr && i < index && i < this.length; i++){
            curr = curr.next;
        }

        return curr;
    }
}
