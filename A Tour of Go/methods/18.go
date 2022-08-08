package methods

import "fmt"

type IPAddr [4]byte

func (a IPAddr) String() string {
	return fmt.Sprintf("%d.%d.%d.%d", a[0], a[1], a[2], a[3])
}
