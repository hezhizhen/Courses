package main

import (
	"fmt"
	"gotour/concurrency"
	"gotour/flowcontrol"
	"gotour/methods"
	"gotour/moretypes"
	"io"
	"os"
	"strings"

	"golang.org/x/tour/pic"
	"golang.org/x/tour/reader"
	"golang.org/x/tour/tree"
	"golang.org/x/tour/wc"
)

func main() {
	// https://go.dev/tour/flowcontrol/8
	fmt.Println(flowcontrol.Sqrt(2))
	// https://go.dev/tour/moretypes/18
	pic.Show(moretypes.Pic)
	// https://go.dev/tour/moretypes/23
	wc.Test(moretypes.WordCount)
	// https://go.dev/tour/moretypes/26
	f := moretypes.Fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
	// https://go.dev/tour/methods/18
	hosts := map[string]methods.IPAddr{
		"loopback":  {127, 0, 0, 1},
		"googleDNS": {8, 8, 8, 8},
	}
	for name, ip := range hosts {
		fmt.Printf("%v: %v\n", name, ip)
	}
	// https://go.dev/tour/methods/20
	fmt.Println(methods.Sqrt(2))
	fmt.Println(methods.Sqrt(-2))
	// https://go.dev/tour/methods/22
	reader.Validate(methods.MyReader{})
	// https://go.dev/tour/methods/23
	s := strings.NewReader("Lbh penpxrq gur pbqr!")
	r := methods.Rot13Reader{s}
	io.Copy(os.Stdout, &r)
	// https://go.dev/tour/methods/25
	m := methods.Image{}
	pic.ShowImage(m)
	// https://go.dev/tour/concurrency/8
	ch := make(chan int)
	go concurrency.Walk(tree.New(1), ch)
	for c := range ch {
		fmt.Println(c)
	}
	fmt.Println(concurrency.Same(tree.New(1), tree.New(1)))
	fmt.Println(concurrency.Same(tree.New(1), tree.New(2)))
	fmt.Println(concurrency.Same(tree.New(2), tree.New(1)))
	// https://go.dev/tour/concurrency/10
	concurrency.Crawl("https://golang.org/", 4, concurrency.FakeFetcher)
}
