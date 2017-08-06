package main

import "testing"

func TestBouncingBalls(t *testing.T) {
	tests := []struct {
		h      float64
		bounce float64
		window float64
		output int
	}{
		{3, 0.66, 1.5, 3},
		{40, 0.4, 10, 3},
		{10, 0.6, 10, -1},
		{40, 1, 10, -1},
		{5, -1, 1.5, -1},
		{10, 2 / 3, 9, 1},
	}

	for _, test := range tests {
		out := BouncingBall(test.h, test.bounce, test.window)
		if out != test.output {
			t.Errorf("BouncingBall(%f, %f, %f) = %v",
				test.h, test.bounce, test.window, out)
			t.Errorf("Test wants %v", test.output)
		}
	}
}
