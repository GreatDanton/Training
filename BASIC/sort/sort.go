package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println("Hello")
	people := []Person{
		{"A", 20},
		{"B", 30},
	}

	sort.Sort(ByName(people))
	fmt.Println(people)

	// it's working
	sort.Sort(ByAge(people))
	fmt.Println(people)

	// ##### STORING SLICE INTO VARIABLE
	// if we want to store into variable
	customSort(people)

}

// storing slice into variables, what a mess
func customSort(p1 []Person) ([]Person, []Person) {
	fmt.Println("Custom sorting")
	ageDec := make([]Person, len(p1))
	copy(ageDec, p1)
	ageInc := make([]Person, len(p1))
	copy(ageInc, p1)

	sort.Sort(ByAge(ageDec))
	fmt.Println(ageDec)

	sort.Sort(sort.Reverse(ByAge(ageInc)))
	fmt.Println(ageInc)

	return ageDec, ageInc
}

type Person struct {
	Name string
	Age  int
}

type ByName []Person

func (ps ByName) Len() int {
	// should return length of the thing we are sorting
	// for slice that is len(slice)
	return len(ps)
}

func (ps ByName) Less(i, j int) bool {
	// determine wheter item at position i is strictly less than item at position j
	return ps[i].Name < ps[j].Name
}

func (ps ByName) Swap(i, j int) {
	// swaps the items
	ps[i], ps[j] = ps[j], ps[i]
}

// CUSTOM SORT
type ByAge []Person

func (age ByAge) Len() int {
	return len(age)
}

// sort highest first
func (age ByAge) Less(i, j int) bool {
	return age[i].Age > age[j].Age
}

func (age ByAge) Swap(i, j int) {
	age[i], age[j] = age[j], age[i]
}
