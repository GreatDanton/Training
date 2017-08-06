/*
 TAKEN FROM CODEWARS

Two tortoises named A and B must run a race. A starts with an average
speed of 720 feet per hour. Young B knows she runs faster than A and
 furthermore has not finished her cabbage.

When she starts, at last, she can see that A has a 70 feet lead but
B speed is 850 feet per hour. How long will it take B to catch A?

More generally: given two speeds v1 (A speed, integer > 0) and v2
(B speed, integer > 0) and a lead g (integer > 0) how long will it take
B to catch A?

The result will be an array [h, mn, s] where h, mn, s is the time needed in
hours, minutes and seconds (don't worry for fractions of second). If v1 >= v2
then return nil, nothing, null, None or {-1, -1, -1} for C++, C, Go.

Examples:

race(720, 850, 70) => [0, 32, 18]
race(80, 91, 37) => [3, 21, 49]

Note: you can see some other examples in "Your test cases".
        dotest(720, 850, 70, [3]int{0, 32, 18})
        dotest(820, 81, 550, [3]int{-1, -1, -1})
        dotest(80, 91, 37, [3]int{3, 21, 49})
*/

package main

import "fmt"

func main() {
	time := Race(720, 850, 70)
	fmt.Println(time)
}

// v1 = old tortoise speed
// v2 = young tortoise speed
// g = lead
// returns []{hours, minutes, seconds}
func Race(v1, v2, g int) [3]int {
	if v2 <= v1 {
		return [3]int{-1, -1, -1}
	}
	diff := v2 - v1
	t := (g * 3600) / diff // time in seconds
	// how many minutes goes into t, what is left are seconds
	seconds := t % 60
	t -= seconds // t still in seconds
	t /= 60      // t in minutes

	// how many hours goes into t, what is left are minutes
	minutes := t % 60
	t -= minutes

	// what is left are hours
	hours := t / 60

	return [...]int{hours, minutes, seconds}
}
