package main

import (
	"fmt"
	"math"
)

func main() {

	// first option to calculate area
	fmt.Println("Variable a")
	a := Circle{x: 0, y: 0, r: 5}
	fmt.Println(a)
	fmt.Println(circleArea(&a))
	a.x = 10
	a.y = 10
	a.r = 10
	fmt.Println(a)
	fmt.Println(circleArea(&a)) // area does not change

	// second option
	fmt.Println("")
	fmt.Println("Variable b")
	b := Circle{x: 0, y: 0, r: 20}
	fmt.Println(b.area())
	b.r = 10
	fmt.Println(b.area())

	if b.area() == circleArea(&a) {
		fmt.Println("Area of circles is equal")
	}

	fmt.Println("Rectangle part")
	R := Rectangle{a: 10, b: 20}
	fmt.Println("Area:", R.area())
}

// Circle ...
type Circle struct {
	x, y, r float64
}

func circleArea(c *Circle) float64 {
	return math.Pi * c.r * c.r
}

func (c *Circle) area() float64 {
	return math.Pi * c.r * c.r
}

// Rectangle struct
type Rectangle struct {
	a, b float64
}

// Rectangle area method
func (r *Rectangle) area() float64 {
	return r.a * r.b
}
