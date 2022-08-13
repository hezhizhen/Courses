package main

func findSubstring(s string, words []string) []int {
	counts := map[string]int{}
	for _, w := range words {
		counts[w]++
	}

	indexes := make([]int, 0)
	n := len(s)
	num := len(words)
	l := len(words[0])
	for i := 0; i < n-num*l+1; i++ {
		seen := map[string]int{}
		j := 0
		for j < num {
			word := string(s[i+j*l : i+(j+1)*l])
			if counts[word] == 0 {
				break
			}
			seen[word]++
			if seen[word] > counts[word] {
				break
			}
			j++
		}
		if j == num {
			indexes = append(indexes, i)
		}
	}

	return indexes
}
