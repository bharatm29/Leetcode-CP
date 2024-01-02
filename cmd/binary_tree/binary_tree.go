package binarytree

type Node struct {
	left  *Node
	right *Node
	val   int
}

func GetVal(node *Node) int {
    return node.val
}

func Insert(root *Node, val int) *Node {
	if root == nil {
		return &Node{val: val}
	}

	if root.val < val {
		root.right = Insert(root.right, val)
	} else {
		root.left = Insert(root.left, val)
	}

	return root
}

func Inorder(root *Node, ls *[]int) {
	if root == nil {
		return
	}

	Inorder(root.left, ls)

	*(ls) = append(*(ls), root.val)

	Inorder(root.right, ls)
}

func Search(root *Node, val int) bool {
	if root == nil {
		return false
	}

	if root.val == val {
		return true
	} else if root.val > val {
		return Search(root.left, val)
	} else {
		return Search(root.right, val)
	}
}

func Delete(root *Node, val int) *Node {
    if root == nil {
        return root
    }

    if root.val > val {
        root.left = Delete(root.left, val)
    } else if root.val < val {
        root.right = Delete(root.right, val)
    } else if root.left == nil && root.right == nil {
        root = nil
    } else  if root.left == nil {
        root = root.right
    } else if root.right == nil {
        root = root.left
    } else {
        temp := FindMin(root.right)
        root.val = temp.val

        root.right = Delete(root.right, temp.val)
    }

    return root
}

func FindMin(root *Node) *Node { if root == nil {
        return root
    }

    if root.left == nil {
        return root
    }

    return FindMin(root.left)
}

func FindMax(root *Node) *Node {
    if root == nil {
        return root
    }

    if root.right == nil {
        return root
    }

    return FindMax(root.right)
}
