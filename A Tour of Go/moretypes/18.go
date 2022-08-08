package moretypes

func Pic(dx, dy int) [][]uint8 {
	p := make([][]uint8, dy)
	for i := range p {
		p[i] = make([]uint8, dx)
	}

	for i := 0; i < dy; i++ {
		for j := 0; j < dx; j++ {
			p[i][j] = uint8(i ^ j)
		}
	}

	return p
}
