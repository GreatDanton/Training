/* Write a function that combines two lists by alternatingly taking elements. For example:
given the two lists [a, b, c] and [1, 2, 3], the function should return [a, 1, b, 2, c, 3].
*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	list1 := []string{"a", "b", "c"}
	list2 := []int{1, 2, 3}
	list2_str := make([]string, len(list2))
	// go cannot mix integers and strings
	for i, v := range list2 {
		list2_str[i] = strconv.Itoa(v)
	}

	combinedArr := combineLists(list1, list2_str)
	fmt.Println(combinedArr)
}

// combine two []string arrays
func combineLists(list1, list2 []string) []string {
	combinedArr := []string{}

	// if lengths of lists are the same we can write:
	for i := range list1 {
		l1 := list1[i]
		l2 := list2[i]
		combinedArr = append(combinedArr, l1, l2)
	}
	return combinedArr
}
