package main

import (
	"fmt"
	"io/ioutil"
	"os"
)

func main() {
	file := "test2.txt"
	createFile(file)
	read2(file)

	fmt.Println("\nReading current dir")
	readDir(".") // read current dir
}

func readDir(dirName string) {
	dir, err := os.Open(dirName)
	if err != nil {
		// handle error
		return
	}
	defer dir.Close()

	fileInfos, err := dir.Readdir(-1)
	if err != nil {
		return
	}

	for _, file := range fileInfos {
		fmt.Println(file.Name())
	}
}

//
// creating file
func createFile(name string) {
	file, err := os.Create(name)
	if err != nil {
		// handle error
		return
	}
	defer file.Close()
	file.WriteString("Created new file")
}

//
// reading file option 2
func read2(file string) {
	bs, err := ioutil.ReadFile(file)
	if err != nil {
		return
	}
	str := string(bs)
	fmt.Println(str)
}

//
// reading file option 1
func read1() {
	file, err := os.Open("test2.txt")
	if err != nil {
		fmt.Errorf("Problem opening file %v", err)
		return
	}
	defer file.Close()

	// get file size
	stat, err := file.Stat()
	if err != nil {
		// handle error
		fmt.Errorf("Stat failed %v", err)
		return
	}
	// read the file
	bs := make([]byte, stat.Size())
	_, err = file.Read(bs)
	if err != nil {
		return
	}
	str := string(bs)
	fmt.Println(str)
}
