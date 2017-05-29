package main

import (
	"reflect"
	"testing"
)

func Test_twoSum(t *testing.T) {
	tests := []struct {
		arr    []int
		target int
		wants  []int
	}{
		{[]int{1, 2, 3, 4, 5, 6, 7, 8, 9}, 10, []int{1, 9}},
		{[]int{15, 11, 12}, 23, []int{11, 12}},
		{[]int{-1, 10, 2, 8, 9}, 9, []int{-1, 10}},
	}

	for _, test := range tests {
		out := twoSum(test.arr, test.target)

		// checks if out and test.wants are equal
		if !reflect.DeepEqual(out, test.wants) {
			t.Errorf("twoSum(%v, %v) = %v", test.arr, test.target, out)
			t.Errorf("Output should be: %v", test.wants)
		}
	}
}
