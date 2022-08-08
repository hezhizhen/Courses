package flowcontrol

import (
	"fmt"
	"math"
)

func Sqrt(x float64) float64 {
	z := 1.0
	for math.Abs(z*z-x) >= 1e-10 {
		fmt.Println(z)
		z -= (z*z - x) / (2 * z)
	}
	return z
}
