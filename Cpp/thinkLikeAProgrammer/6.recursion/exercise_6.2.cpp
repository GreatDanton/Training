/*
 * Exercise 6.2:
 *
 * Consider an array representing a binary string, where every element's data
 * value is 0 or 1. Write a bool function to determine wheter the binary string
 * has odd parity (an odd number of 1 bits). Hint: Remember that the recursive
 * function is going to return true (odd) or false (even), not the count of 1
 * bits. Solve the problem first using iteration, then recursion.
 */
#include <iostream>

bool oddParityIterative(int integers[], int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        int num = integers[i];
        if (num == 1) {
            count++;
        }
    }

    if (count % 2 == 0) {
        return false;
    }

    return true;
}

bool oddParityRecursive(int integers[], int size) {
    if (size == 0) {
        return false;
    }

    bool myBool = oddParityRecursive(integers, size - 1);
    if (integers[size - 1] == 1) {
        myBool = !myBool;
    }
    return myBool;
}

int main() {
    //
    const int size = 4;
    int integers[size]{0, 1, 0, 1};  // return false
    int integers2[size]{1, 0, 1, 1}; // return true

    bool i1 = oddParityIterative(integers, size);
    std::cout << std::boolalpha << i1 << std::endl; // should be false
    bool i2 = oddParityIterative(integers2, size);
    std::cout << std::boolalpha << i2 << std::endl; // should be true

    std::cout << std::endl;
    bool i3 = oddParityRecursive(integers, size);
    std::cout << std::boolalpha << i3 << std::endl;

    bool i4 = oddParityRecursive(integers2, size);
    std::cout << std::boolalpha << i4 << std::endl;
    return 0;
}