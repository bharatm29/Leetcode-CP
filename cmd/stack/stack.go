package stack

type Node[T any] struct {
	prev *Node[T]
	val  T
}

type Stack[T any] struct {
	top    *Node[T]
	length int
}

func NewStack[T any]() *Stack[T] {
	return &Stack[T]{}
}

func (s *Stack[T]) Size() int {
	return s.length
}

func (s *Stack[T]) Flatten() []T {
	ls := []T{}

	top := s.top

	for ; top != nil; top = top.prev {
		ls = append(ls, top.val)
	}

	return ls
}

func (s *Stack[T]) Push(val T) {
	s.length++

	node := &Node[T]{
		val: val,
	}

	node.prev = s.top

	s.top = node
}

func (s *Stack[T]) Pop() T {
	s.length--

	val := s.top.val

	s.top = s.top.prev

	return val
}

func (s *Stack[T]) Top() T {
	return s.top.val
}
