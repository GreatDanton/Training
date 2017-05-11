/*
Create such function that will return the following
Accum("abcd")  ==> A-Bb-Ccc-Dddd
Accum("abCd")  ==> A-Bb-Ccc-Dddd
*/

package main

import (
	"fmt"
	"strings"
)

const alphabet string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

func main() {
	fmt.Println(Accum("AbCd"))
}

func Accum(s string) string {
	arr := strings.Split(s, "") // create array from string
	acc := ""

	for i := 0; i < len(arr); i++ {
		char := strings.ToLower(arr[i])
		times := i + 1
		a := strings.Repeat(char, times) // repeat character * times
		acc += strings.Title(a)          // capitalize a

		if i+1 == len(arr) {
			return acc
		}
		acc += "-"
	}

	return acc
}
