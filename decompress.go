package main

import "C"

import (
	"github.com/gen2brain/go-unarr"
	"fmt"
)

func main() {
}

//export extract
func extract(compressed string, path string) bool {
	a, err := unarr.NewArchive(compressed)
	if err != nil {
		fmt.Println(err)
		return false
	}
	defer a.Close()
	
	_, err = a.Extract(path)
	if err != nil {
		fmt.Println(err)
		return false
	}
	
	return true
}
