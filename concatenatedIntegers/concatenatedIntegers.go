/*
official: http://www.shiftedup.com/2015/05/07/five-programming-problems-every-software-engineer-should-be-able-to-solve-in-less-than-1-hour
from /r/dailyProgrammer:

Given a list of integers separated by a single space on standard input,
print out the largest and smallest values that can be obtained by
concatenating the integers together on their own line. This is from Five
programming problems every Software Engineer should be able to solve in less
than 1 hour, problem 4.
Leading 0s are not allowed (e.g. 01234 is not a valid entry).


Sample Input:
You'll be given a handful of integers per line. Example:
5 56 50

Sample Output
You should emit the smallest and largest integer you can make, per line. Example:
MIN: 50556
MAX: 56550

Challenge Input:
79 82 34 83 69
420 34 19 71 341
17 32 91 7 46

Challenge Output:
3469798283 8382796934
193413442071 714203434119
173246791 917463217

*/

/*
### Solution: ####

1. It is possible to do this with permutations, but that is inefficient
2. Another is to sort numbers and join them together, to form a long chain
*/

package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	input := "0 10 20"
	fmt.Printf("Input: %s \n", input)

	stringArr := strings.Split(input, " ")
	sortedArr := sortInts(stringArr)

	fmt.Printf("Sorted Arr: %v \n", sortedArr)
}

// transforms array of strings to array of integers
func toInts(inputArr []string) []int {
	intArr := []int{}

	for _, v := range inputArr {
		value, err := strconv.Atoi(v)
		if err != nil {
			fmt.Errorf("Input element %v is not a string", v)
		}
		intArr = append(intArr, value)
	}
	return intArr
}

// sorts according to the challenge input (from min to max, no starting with 0)
func sortInts(inputArr []string) []int {
	intArr := toInts(inputArr)
	sort.Ints(intArr[:])

	// TODO: FIX THIS -> create minArr, maxArr
	minArr := intArr
	maxArr := intArr

	fmt.Println("Min Arr ", minArr)
	fmt.Println("Max arr: ", maxArr)
	// deal for minimum
	firstChar := getFirstDigit(intArr[0])
	if firstChar == 0 {
		fmt.Printf("first digit is %v \n", firstChar)
	}

	return intArr
}

// get first digit of input integer
func getFirstDigit(input int) int {
	firstInt := strconv.Itoa(input)
	firstChar, err := strconv.Atoi(string(firstInt[0]))
	if err != nil {
		fmt.Println("Cannot turn string %v into integer", firstInt[0])
	}

	return firstChar
}
