type Node<T> = {
    value: T;
    next?: Node<T>;
}

export default class SinglyLinkedList<T> {
    public length: number;
    private head?: Node<T>;
    private tail?: Node<T>;

    constructor() {
        this.length = 0;
        this.head = this.tail = undefined;
    }

    prepend(item: T): void {
        this.length++;

        const node = { value: item } as Node<T>;

        if (!this.head || !this.tail) {
            this.head = this.tail = node;
            return;
        }

        node.next = this.head;
        this.head = node;
    }

    insertAt(item: T, index: number): void {
        if (index >= this.length) {
            return;
        }

        if (index === this.length) {
            this.append(item);
            return;
        }

        if (index === 0) {
            this.prepend(item);
            return;
        }

        let curr = this.head;
        let prev = curr;

        for (let i = 0; i < index && curr; i++) {
            prev = curr;
            curr = curr.next;
        }

        const node = { value: item } as Node<T>;

        if (prev) {
            prev.next = node;
        }

        node.next = curr;
    }

    append(item: T): void {
        this.length++;

        const node = { value: item } as Node<T>;

        if (!this.head || !this.tail) {
            this.head = this.tail = node;
            return;
        }

        this.tail.next = node;
        this.tail = node;
    }

    remove(item: T): T | undefined {
        let curr = this.head;
        let prev = curr;

        for (let i = 0; i < this.length && curr; i++) {
            if (curr.value === item) {
                break;
            }

            prev = curr;
            curr = curr.next;
        }

        return this.removeNode(curr, prev);
    }

    get(index: number): T | undefined {
        if (index >= this.length) {
            return undefined;
        }

        let curr = this.head;

        for (let i = 0; i < index && curr; i++, curr = curr.next) { }

        return curr?.value;
    }

    removeAt(index: number): T | undefined {
        if (index >= this.length) {
            return undefined;
        }

        let curr = this.head;
        let prev = curr;

        for (let i = 0; i < index && curr; i++) {
            prev = curr;
            curr = curr.next;
        }

        return this.removeNode(curr, prev);
    }

    private removeNode(curr: Node<T> | undefined, prev: Node<T> | undefined): T | undefined {
        if (!curr) {
            return undefined;
        }

        this.length--;

        if (this.head === curr) {
            this.head = this.head.next;
            curr.next = undefined;
            return curr.value;
        }

        if (prev) {
            prev.next = curr.next;
        }

        curr.next = undefined;

        return curr.value;
    }
}
