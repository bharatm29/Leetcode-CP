package lrucache

type Node struct {
	next *Node
	prev *Node
	key  int
	val  int
}

type LRU struct {
	head     *Node
	tail     *Node
	nodes    map[int]*Node
	capacity int
}

func NewLRU(capacity int) *LRU {
	l := &LRU{
		head: &Node{},
		tail: &Node{},

		capacity: capacity,

		nodes: map[int]*Node{},
	}

	l.head.next = l.tail
	l.tail.prev = l.head

	return l
}

func (l *LRU) Get(key int) int {
	valNode, ok := l.nodes[key]

	if !ok {
		return -1
	}

	val := valNode.val

	delete(l.nodes, key)
	l.delete_node(valNode)

	node := &Node{
		key: key,
		val: val,
	}

	l.add_node(node)

	l.nodes[key] = node

	return val
}

func (l *LRU) Put(key, val int) {
	if l.capacity == len(l.nodes) {
		delete(l.nodes, l.tail.prev.key)
		l.delete_node(l.tail.prev)
	}

	node := &Node{
		key: key,
		val: val,
	}

	l.add_node(node)

	l.nodes[key] = node
}

func (l *LRU) add_node(node *Node) {
	next_node := l.head.next

	l.head.next = node
	node.prev = l.head

	next_node.prev = node
	node.next = next_node
}

func (l *LRU) delete_node(node *Node) {
	next_node := node.next
	prev_node := node.next

	next_node.prev = prev_node
	prev_node.next = next_node
}
