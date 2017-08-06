package main

import (
	"testing"
)

var tests = []struct {
	input []int
	wants int
}{
	{[]int{1, 2, 3}, 6},
	{[]int{-1, 2, 10, 5}, 16},
	{[]int{-1, -2, -3}, -6},
	{[]int{100, 200, 300}, 600},
}

func Test_WithForLoop(t *testing.T) {

	for _, test := range tests {
		out := withForLoop(test.input)
		if out != test.wants {
			t.Errorf("withForLoop(%q) = %v", test.input, out)
			t.Errorf("Output should be: %v", test.wants)
		}
	}
}

func Test_withWhileLoop(t *testing.T) {
	for _, test := range tests {
		out := withWhileLoop(test.input)
		if out != test.wants {
			t.Errorf("withWhileLoop(%q) = %v", test.input, out)
			t.Errorf("Output should be: %v", test.wants)
		}
	}
}

func Test_withRecursion(t *testing.T) {
	for _, test := range tests {
		out := withRecursion(test.input, 0)
		if out != test.wants {
			t.Errorf("withRecursion(%q) = %v", test.input, out)
			t.Errorf("Output should be: %v", test.wants)
		}
	}
}
