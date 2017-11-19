/*
 * Exercise 5.3:
 *
 * Take the variable-length string functions from Chapter 4 (append,
 * concatenate and characterAt) and use them to create a class for
 * variable-length strings, making sure to implement all necessary constructors,
 * a destructor, and an overloaded assignment operator.
 *
 *
 * Exercise 5.4:
 *
 * Take the variable-length string class of the previous exercise, replace
 * the characterAt method with an overloaded [] operator. For example, if
 * myString is an object of our class, then myString[1] should return the same
 * result as myString.characterAt(1)
 *
 */

#include "myString.h"
#include <iostream>

void classTester() {
    std::cout << "### classTester" << std::endl;
    arrayString a = new char[3]{'A', 'B', 0};
    myString str(a);
    delete[] a;
    a = NULL;
    str.displayString();
}

void appendTester() {
    std::cout << "### appendTester" << std::endl;
    arrayString a = new char[3]{'A', 'B', 0};
    myString str(a);
    delete[] a;
    a = NULL;
    str.append('C');
    str.displayString(); // ABC
}

void characterAtTester() {
    std::cout << "### characterAtTester" << std::endl;
    arrayString a = new char[3]{'A', 'B', 0};
    myString str(a);
    delete[] a;
    a = NULL;
    str.append('C');
    std::cout << str.characterAt(2) << std::endl; // C
}

// testing class1 = class2
void overloadedOperatorTester() {
    std::cout << "### Overloaded Operator = tester" << std::endl;
    arrayString a = new char[3]{'A', 'B', 0};
    myString str(a);
    delete[] a;
    a = NULL;
    myString b = str;
    b.displayString();
    std::cout << &a << std::endl;
    std::cout << &b << std::endl; // different memory positions = OK
}

// testing myClass[1]
void overloadBracketsTester() {
    std::cout << "### Overloaded Operator [] tester" << std::endl;
    arrayString a = new char[3]{'A', 'B', 0};
    myString str(a);
    delete[] a;
    a = NULL;
    char myChar = str[0];
    std::cout << myChar << std::endl; // should be 'A'
    char myChar2 = str[1];
    std::cout << myChar2 << std::endl; // should be 'B'
    char myChar3 = str[2];
    std::cout << myChar3 << std::endl; // should be 0;
    char myChar4 = str[3];
    std::cout << myChar4 << std::endl;
}

int main() {
    classTester();
    std::cout << std::endl;
    appendTester();
    std::cout << std::endl;
    characterAtTester();
    std::cout << std::endl;
    overloadedOperatorTester();
    std::cout << std::endl;
    overloadBracketsTester();
    return 0;
}