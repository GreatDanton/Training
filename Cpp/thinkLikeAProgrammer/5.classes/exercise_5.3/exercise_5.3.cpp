/*
 *  Take the variable-length string functions from Chapter 4 (append,
 * concatenate and characterAt) and use them to create a class for
 * variable-length strings, making sure to implement all necessary constructors,
 * a destructor, and an overloaded assignment operator.
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

void overloadedOperatorTester() {
    std::cout << "### Overloaded Operator tester" << std::endl;
    arrayString a = new char[3]{'A', 'B', 0};
    myString str(a);
    delete[] a;
    a = NULL;
    myString b = str;
    b.displayString();
    std::cout << &a << std::endl;
    std::cout << &b << std::endl; // different memory positions = OK
}

int main() {
    classTester();
    std::cout << std::endl;
    appendTester();
    std::cout << std::endl;
    characterAtTester();
    std::cout << std::endl;
    overloadedOperatorTester();
    return 0;
}