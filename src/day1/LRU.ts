type Node<T> = {
    value: T,
    next?: Node<T>,
    prev?: Node<T>,
}

function createNode<V>(value: V): Node<V> {
    return { value };
}

export default class LRU<K, V> {
    private length: number;
    private head?: Node<V>;
    private tail?: Node<V>;

    private lookup: Map<K, Node<V>>;
    private reverseLookup: Map<Node<V>, K>;

    constructor(private capacity: number = 10) {
        this.head = undefined;
        this.tail = undefined;

        this.length = 0;

        this.lookup = new Map<K, Node<V>>();
        this.reverseLookup = new Map<Node<V>, K>;
    }

    update(key: K, value: V): void {
        //check the cache for existence
        let node = this.lookup.get(key);

        //if it dosen't exist just return undefined;
        if(!node){
            node = createNode(value);
            this.length++;
            this.prepend(node);
            this.trimCache();

            this.lookup.set(key, node);
            this.reverseLookup.set(node, key);
        }
        else {
            //if it does exist, just move the thing to the beginning of the list
            this.detach(node);
            this.prepend(node);

            //in case the value has changed
            node.value = value;
        }
    }

    get(key: K): V | undefined {
        //check the cache for existence
        const node = this.lookup.get(key);

        //if it dosen't exist just return undefined;
        if(!node){
            return undefined;
        }

        //update the value we found and move it to the front

        this.detach(node);
        this.prepend(node);

        //return the value we found
        return node.value;
    }

    private detach(node: Node<V>){
        if(node.prev){
            node.prev.next = node.next;
        }

        if(node.next){
            node.next.prev = node.prev;
        }

        if(this.length === 1){
            this.head = this.tail = undefined;
        }

        if(this.head === node){
            this.head = this.head.next;
        }
        if(this.tail === node){
            this.tail = this.tail.prev;
        }

        node.next = node.prev = undefined;
    }

    private prepend(node: Node<V>){
        if(!this.head){
            this.head = node;
            return;
        }

        this.head.prev = node;
        node.next = this.head;

        this.head = node;
    }

    private trimCache() {
        if(this.length <= this.capacity){
            //the length is ok.
            return;
        }

        const tail = this.tail as Node<V>;
        this.detach(tail);

        const key = this.reverseLookup.get(tail) as K;

        this.lookup.delete(key);
        this.reverseLookup.delete(tail);

        this.length--;
    }
}
