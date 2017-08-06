// Write three functions that compute the sum of the numbers in a
//given list using a for-loop, a while-loop, and recursion.

package main

import (
	"fmt"
)

func main() {
	numbers := []int{1, 2, 3, 4}
	// should return 10
	sum1 := withForLoop(numbers)
	sum2 := withWhileLoop(numbers)
	sum3 := withRecursion(numbers, 0)

	fmt.Printf("Sum 1: %v \n", sum1)
	fmt.Printf("Sum 2: %v \n", sum2)
	fmt.Printf("Sum 3: %v \n", sum3)
}

// function one with for loop
func withForLoop(inputArr []int) int {
	sum := 0
	for _, v := range inputArr {
		sum += v
	}

	return sum
}

func withWhileLoop(inputArr []int) int {
	i := 0
	sum := 0
	for { // while true do:
		if i >= len(inputArr) {
			break
		}
		sum += inputArr[i]
		i++
	}
	return sum
}

// sum numbers with recursion
func withRecursion(inputArr []int, sum int) int {
	if len(inputArr) == 0 {
		return sum
	}
	sum += inputArr[0]
	inputArr = inputArr[1:]
	return withRecursion(inputArr, sum)
}
