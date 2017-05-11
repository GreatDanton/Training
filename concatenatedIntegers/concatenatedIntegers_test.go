package main

import (
	"reflect"
	"testing"
)

// Testing customSort function from the main package
func TestSort(t *testing.T) {
	var tests = []struct {
		input []string
		wants []int
	}{
		{[]string{"10", "1", "11"}, []int{1, 10, 11}},
		{[]string{"0", "1", "10", "5"}, []int{1, 0, 5, 10}},
		{[]string{"76", "82", "83", "0", "1"}, []int{0, 1, 76, 82, 83}},
	}

	for _, test := range tests {
		out := sortInts(test.input)
		if !reflect.DeepEqual(out, test.wants) {
			t.Errorf("customSort(%q) = %v", test.input, out)
			t.Errorf("Output should be: %v", test.wants)
		}
	}
}

// Testing toInts function, that takes array of strings and turns
// it into array of integers
func TestToInts(t *testing.T) {
	tests := []struct {
		input []string
		wants []int
	}{
		{[]string{"1", "2", "3", "4"}, []int{1, 2, 3, 4}},
		{[]string{"89", "100", "0", "1"}, []int{89, 100, 0, 1}},
	}

	for _, test := range tests {
		got := toInts(test.input)
		if !reflect.DeepEqual(got, test.wants) {
			t.Errorf("toInts(%q) = %v", test.input, got)
			t.Errorf("Output should be %v", test.wants)
		}
	}
}
