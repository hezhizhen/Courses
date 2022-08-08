package concurrency

import (
	"fmt"
	"sync"
)

var defaultCrawler = &Crawler{
	crawled: make(map[string]bool),
}

type Crawler struct {
	mux     sync.Mutex
	crawled map[string]bool
}

func (c Crawler) Crawled(url string) bool {
	c.mux.Lock()
	defer c.mux.Unlock()
	return c.crawled[url]
}

func (c *Crawler) MarkAsCrawled(url string) {
	c.mux.Lock()
	defer c.mux.Unlock()
	c.crawled[url] = true
}

type Fetcher interface {
	// Fetch returns the body of URL and
	// a slice of URLs found on that page.
	Fetch(url string) (body string, urls []string, err error)
}

// Crawl uses fetcher to recursively crawl
// pages starting with url, to a maximum of depth.
func Crawl(url string, depth int, fetcher Fetcher) {
	var wg sync.WaitGroup
	// This implementation doesn't do either:
	if depth <= 0 {
		return
	}
	// Don't fetch the same URL twice
	if defaultCrawler.Crawled(url) {
		return
	}
	body, urls, err := fetcher.Fetch(url)
	if err != nil {
		fmt.Println(err)
		return
	}
	defaultCrawler.MarkAsCrawled(url)
	fmt.Printf("found: %s %q\n", url, body)
	for _, u := range urls {
		// Fetch URLs in parallel
		wg.Add(1)
		go func(u string) {
			defer wg.Done()
			Crawl(u, depth-1, fetcher)
		}(u)
	}
	wg.Wait()
}

// fakeFetcher is Fetcher that returns canned results.
type fakeFetcher map[string]*fakeResult

type fakeResult struct {
	body string
	urls []string
}

func (f fakeFetcher) Fetch(url string) (string, []string, error) {
	if res, ok := f[url]; ok {
		return res.body, res.urls, nil
	}
	return "", nil, fmt.Errorf("not found: %s", url)
}

// FakeFetcher is a populated fakeFetcher.
var FakeFetcher = fakeFetcher{
	"https://golang.org/": &fakeResult{
		"The Go Programming Language",
		[]string{
			"https://golang.org/pkg/",
			"https://golang.org/cmd/",
		},
	},
	"https://golang.org/pkg/": &fakeResult{
		"Packages",
		[]string{
			"https://golang.org/",
			"https://golang.org/cmd/",
			"https://golang.org/pkg/fmt/",
			"https://golang.org/pkg/os/",
		},
	},
	"https://golang.org/pkg/fmt/": &fakeResult{
		"Package fmt",
		[]string{
			"https://golang.org/",
			"https://golang.org/pkg/",
		},
	},
	"https://golang.org/pkg/os/": &fakeResult{
		"Package os",
		[]string{
			"https://golang.org/",
			"https://golang.org/pkg/",
		},
	},
}
