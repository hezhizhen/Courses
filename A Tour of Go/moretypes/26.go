package moretypes

// Fibonacci is a function that returns
// a function that returns an int.
func Fibonacci() func() int {
	f2, f1 := 0, 1
	return func() int {
		f := f2
		f2, f1 = f1, f+f1

		return f
	}
}
