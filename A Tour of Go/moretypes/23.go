package moretypes

import "strings"

func WordCount(s string) map[string]int {
	words := strings.Fields(s)
	ret := make(map[string]int)
	for _, word := range words {
		ret[word]++
	}
	return ret
}
