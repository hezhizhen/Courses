package main

func isValidBST(root *TreeNode) bool {
	return valid(root, nil, nil)
}

func valid(root, min, max *TreeNode) bool {
	if root == nil {
		return true
	}
	if min != nil && root.Val <= min.Val {
		return false
	}
	if max != nil && root.Val >= max.Val {
		return false
	}
	return valid(root.Left, min, root) && valid(root.Right, root, max)
}
