package main

import (
	"testing"
)

func Test_Accum(t *testing.T) {
	tests := []struct {
		input string
		wants string
	}{
		{"Abc", "A-Bb-Ccc"},
		{"DAbc", "D-Aa-Bbb-Cccc"},
	}

	for _, test := range tests {
		out := Accum(test.input)
		if out != test.wants {
			t.Errorf("Accum(%q) = %v", test.input, out)
			t.Errorf("Test wants: %v", test.wants)
		}
	}
}
