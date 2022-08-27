package main

import "fmt"

func main() {
	// https://leetcode.com/problems/longest-substring-without-repeating-characters/
	fmt.Println("3. Longest Substring Without Repeating Characters")
	fmt.Println(lengthOfLongestSubstring("abcabcbb"), "(Expected: 3)")
	fmt.Println(lengthOfLongestSubstring("abba"), "(Expected: 2)")
	// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
	fmt.Println("30. Substring with Concatenation of All Words")
	fmt.Println(findSubstring("barfoothefoobarman", []string{"foo", "bar"}), "(Expected: [0 9])")
	// https://leetcode.com/problems/validate-binary-search-tree/
	fmt.Println("98. Validate Binary Search Tree")
	fmt.Println(isValidBST(&TreeNode{
		Val:   2,
		Left:  &TreeNode{Val: 1},
		Right: &TreeNode{Val: 3},
	}), "(Expected: true)")
}

type ListNode struct {
	Val  int
	Next *ListNode
}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}
