/*
Given an array of integers, return indices of the two numbers such
that they add up to a specific target.

You may assume that each input would have exactly one solution, and
you may not use the same element twice.


Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	nums := []int{2, 7, 11, 15}
	target := 9

	out := twoSum(nums, target)
	fmt.Println(out)
	out2 := twoSum([]int{15, 11, 12}, 26)
	fmt.Println(out2)
}

func twoSum(nums []int, target int) []int {
	sort.Ints(nums) // sorting array of integers
	for _, v := range nums {
		t := target - v

		j := sort.SearchInts(nums, t) // get index of t in nums
		if t == nums[j] {             // check if t exists in nums
			return []int{v, t}
		}
	}
	return []int{-1, -1}
}
