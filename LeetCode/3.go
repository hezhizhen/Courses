package main

func lengthOfLongestSubstring(s string) int {
	if len(s) == 0 {
		return 0
	}
	chars := make(map[byte]int) // char: char index
	var maxLength int
	for left, right := 0, 0; right < len(s); right++ {
		char := s[right]
		lastIndex, ok := chars[char]
		if ok {
			// make sure the two pointers (left & right) won't go back
			if lastIndex+1 > left {
				left = lastIndex + 1
			}
		}
		chars[char] = right
		currLength := right - left + 1
		if currLength > maxLength {
			maxLength = currLength
		}
	}
	return maxLength
}
