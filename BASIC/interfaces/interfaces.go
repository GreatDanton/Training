package main

import "fmt"

func main() {
	r1 := Rectangle{a: 10, b: 20}
	fmt.Println(r1.area())
	r2 := Rectangle{a: 5, b: 5}

	fmt.Println("Total Area:", totalArea(&r1, &r2))
	fmt.Println("Total Perimeter:", totalPerimeter(&r1, &r2))
}

// Shape interface
type Shape interface {
	area() float64
	perimeter() float64
}

func totalArea(shapes ...Shape) float64 {
	var area float64
	for _, s := range shapes {
		area += s.area()
	}
	return area
}

func totalPerimeter(shapes ...Shape) float64 {
	var perimeter float64
	for _, s := range shapes {
		perimeter += s.perimeter()
	}
	return perimeter
}

// Rectangle ...
type Rectangle struct {
	a, b float64
}

func (r *Rectangle) area() float64 {
	return r.a * r.b
}

func (r *Rectangle) perimeter() float64 {
	return 2*r.a + 2*r.b
}
