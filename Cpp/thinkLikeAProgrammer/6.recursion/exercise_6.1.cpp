/*
 * Exercise 6.1:
 *
 * Write a function to compute the sum of just the positive numbers in an array
 * on integers. First, solve the problem using iteration. Then, using the
 * technique shown in this chapter, convert your iterative function to a
 * recursive function.
 */
#include <iostream>

// sum using iteration
int sumPositiveIterative(int integers[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        int num = integers[i];
        if (num > 0) {
            sum += num;
        }
    }
    return sum;
}

// sum using recursion
int sumPositiveRecursive(int integers[], int size) {
    if (size == 0) {
        return 0;
    }
    int lastItem = integers[size - 1];
    if (lastItem < 0) {
        lastItem = 0;
    }
    int allButLast = sumPositiveRecursive(integers, size - 1);
    return lastItem + allButLast;
}

int main() {
    const int size = 4;
    int integers[size]{1, 2, -1, 3};

    int sum1 = sumPositiveIterative(integers, size);
    std::cout << sum1 << std::endl;

    int sum2 = sumPositiveRecursive(integers, size);
    std::cout << sum2 << std::endl;
}