package main

import "fmt"

func main() {
	x := 1.5
	squarePointer(&x) // dereference (access value of x)
	fmt.Println(x)    // x is 2.25 (square of x)

	y := 0
	p := &y
	fmt.Println("Pointer p ==> y is: ", *p)
	*p++
	fmt.Println("y should be 1: real value: ", *p)

	z := new(int) // create new pointer
	*z += 2
	fmt.Println("z should be 2, real value: ", *z)

	j := new(int)
	k := new(int)
	*j = 1
	*k = 2
	swap(j, k)
	fmt.Printf("j: %v \nk: %v \n", *j, *k)
}

func squarePointer(x *float64) {
	*x = *x * *x
}

func swap(x, y *int) {
	temp := *x
	*x = *y
	*y = temp
}
