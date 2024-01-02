package linkedlist

import "fmt"

type Node[T comparable] struct {
	prev *Node[T]
	next *Node[T]
	val  T
}

type LinkedList[T comparable] struct {
	head   *Node[T]
	tail   *Node[T]
	length int
}

func NewLinkedList[T comparable]() *LinkedList[T] {
	return &LinkedList[T]{
		length: 0,
		head:   nil,
		tail:   nil,
	}
}

func (l *LinkedList[T]) Size() int {
	return l.length
}

func (l *LinkedList[T]) Clear() int {
	len := l.length

	l.head = nil
	l.tail = nil

	return len
}

func (l *LinkedList[T]) Flatten() []T {
	head := l.head

	ls := []T{}

	for head != nil {
		ls = append(ls, head.val)
		head = head.next
	}

	return ls
}

func (l *LinkedList[T]) Prepend(val T) {
	l.length++

	node := &Node[T]{
		val: val,
	}

	if l.head == nil {
		l.head = node
		l.tail = node
		return
	}

	node.next = l.head
	l.head.prev = node
	l.head = node
}

func (l *LinkedList[T]) Append(val T) {
	l.length++

	node := &Node[T]{
		val: val,
	}

	if l.head == nil {
		l.head = node
		l.tail = node
		return
	}

	node.prev = l.tail
	l.tail.next = node
	l.tail = node
}

func (l *LinkedList[T]) Remove(val T) T {
	curr := l.head

	for curr != nil {
		if curr.val == val {
			return l.removeNode(curr)
		}

		curr = curr.next
	}

	return val
}

func (l *LinkedList[T]) InsertAt(index int, val T) {
	if index >= l.length {
		fmt.Println("LOL: List out of index")
	}

	if index == 0 {
		l.Prepend(val)
		return
	}
	if index == l.Size()-1 {
		l.Append(val)
		return
	}

	l.length++

	curr := l.getNode(index)

	node := &Node[T]{
		val: val,
	}

	node.next = curr

	node.prev = curr.prev
	if curr.prev != nil {
		curr.prev.next = node
	}

	curr.prev = node
}

func (l *LinkedList[T]) RemoveAt(index int) T {
	return l.removeNode(l.getNode(index))
}

func (l *LinkedList[T]) Get(index int) T {
	if index >= l.length {
		fmt.Println("LOL: List out of index")
	}

	curr := l.head

	for i := 0; i < index; i++ {
		curr = curr.next
	}

	return curr.val
}

func (l *LinkedList[T]) removeNode(node *Node[T]) T {
	l.length--
	if l.length == 0 {
		l.head = nil
		l.tail = nil
		return node.val
	}

	if node == l.head {
		l.head = node.next
	}

	if node == l.tail {
		l.tail = node.prev
	}

	if node.prev != nil {
		node.prev.next = node.next
	}
	if node.next != nil {
		node.next.prev = node.prev
	}

	node.next = nil
	node.prev = nil

	return node.val
}

func (l *LinkedList[T]) getNode(index int) *Node[T] {
	curr := l.head

	for i := 0; i < index; i++ {
		curr = curr.next
	}

	return curr
}
