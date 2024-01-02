package queue

type Node[T any] struct {
	next *Node[T]
	prev *Node[T]
	val  T
}

type Queue[T any] struct {
	head   *Node[T]
	tail   *Node[T]
	length int
}

func NewQueue[T any]() *Queue[T] {
	return &Queue[T]{}
}

func (q *Queue[T]) Size() int {
	return q.length
}

func (q *Queue[T]) Flatten() []T {
	ls := []T{}

	head := q.head

	for ; head != nil; head = head.next {
		ls = append(ls, head.val)
	}

	return ls
}

func (q *Queue[T]) Push(val T) {
	q.length++

	node := &Node[T]{
		val: val,
	}

	if q.head == nil {
		q.head = node
		q.tail = node
		return
	}

	q.tail.next = node
	node.prev = q.tail
	q.tail = node
}

func (q *Queue[T]) Pop() T {
    q.length--

    if q.length == 0 {
        val := q.head.val

        q.head = nil
        q.tail = nil

        return val
    }

    val := q.head.val

    q.head = q.head.next

    return val
}

func (q *Queue[T]) Front() T {
    return q.head.val
}
