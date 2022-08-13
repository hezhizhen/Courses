package main

import "fmt"

func main() {
	// 30. Substring with Concatenation of All Words
	// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
	fmt.Println(findSubstring("barfoothefoobarman", []string{"foo", "bar"})) // [0, 9]
	// 98. Validate Binary Search Tree
	// https://leetcode.com/problems/validate-binary-search-tree/
	fmt.Println(isValidBST(&TreeNode{
		Val:   2,
		Left:  &TreeNode{Val: 1},
		Right: &TreeNode{Val: 3},
	})) // true
}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}
