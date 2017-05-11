/* Write a function that computes the list of the first 100 Fibonacci numbers.
By definition, the first two numbers in the Fibonacci sequence are 0 and 1, and
each subsequent number is the sum of the previous two. As an example, here
are the first 10 Fibonnaci numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, and 34.
*/

package main

import (
	"fmt"
)

func main() {
	seq := fibonacci(30)
	fmt.Println(seq)
}

// returns fibonacci sequence with n items
func fibonacci(n int) []int {
	seq := []int{}

	for i := 0; i < n; i++ {
		if i == 0 || i == 1 {
			seq = append(seq, i)
		} else {
			num1 := seq[len(seq)-1]
			num2 := seq[len(seq)-2]
			seq = append(seq, num1+num2)
		}
	}
	return seq
}
