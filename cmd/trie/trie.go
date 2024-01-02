package trie

type Node struct {
	links [52]*Node
	flag  bool
}

func (node *Node) containsKey(c rune) bool {
	return node.links[getIndex(c)] != nil
}

func (node *Node) get(c rune) *Node {
	return node.links[getIndex(c)]
}

func (node *Node) set(c rune, nodee *Node) {
	node.links[getIndex(c)] = nodee
}

func (node *Node) setEnd() {
	node.flag = true
}

func (node *Node) isEnd() bool {
	return node.flag
}

type Trie struct {
	root *Node
}

func (t *Trie) Insert(s string) {
	node := t.root

	for _, c := range s {
		if !node.containsKey(c) {
			node.set(c, newNode())
		}

		node = node.get(c)
	}

	node.setEnd()
}

func (t *Trie) Search(s string) bool {
	node := t.root

	for _, c := range s {
		if !node.containsKey(c) {
			return false
		}

		node = node.get(c)
	}

	return node.isEnd()
}

func (t *Trie) StartsWith(s string) bool {
	node := t.root

	for _, c := range s {
		if !node.containsKey(c) {
			return false
		}

		node = node.get(c)
	}

	return true
}

func NewTrie() *Trie {
	return &Trie{
		root: newNode(),
	}
}

func newNode() *Node {
	return &Node{
		links: [52]*Node{},
		flag:  false,
	}
}

func getIndex(c rune) int {
	return int(c) - int('A')
}
