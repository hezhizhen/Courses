package methods

import "io"

type Rot13Reader struct {
	R io.Reader
}

func (r Rot13Reader) Read(b []byte) (int, error) {
	n, err := r.R.Read(b)
	if err != nil {
		return 0, err
	}
	for i := 0; i < n; i++ {
		b[i] = rot13(b[i])
	}
	return n, nil
}

func rot13(b byte) byte {
	if b >= 'A' && b <= 'Z' {
		b = 'A' + (b-'A'+13)%26
	} else if b >= 'a' && b <= 'z' {
		b = 'a' + (b-'a'+13)%26
	}
	return b
}
