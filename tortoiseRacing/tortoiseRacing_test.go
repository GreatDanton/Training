package main

import "testing"
import "fmt"

func TestRace(t *testing.T) {
	tests := []struct {
		v1     int
		v2     int
		v3     int
		output [3]int
	}{
		{720, 850, 70, [3]int{0, 32, 18}},
		{850, 720, 10, [3]int{-1, -1, -1}},
		{80, 91, 37, [3]int{3, 21, 49}},
	}

	for _, test := range tests {
		fmt.Println(test.v1, test.v2, test.v3)
		out := Race(test.v1, test.v2, test.v3)

		if out != test.output {
			t.Errorf("Race(%q, %q, %q) = %v", test.v1, test.v2, test.v3, out)
			t.Errorf("Test wants %v", test.output)
		}
	}
}
