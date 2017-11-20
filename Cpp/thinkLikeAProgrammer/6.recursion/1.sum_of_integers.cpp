/*
 * Problem 1:
 *
 * Write a recursive function that is given an array of integers and the size of
 * the array as parameters. The function returns the sum of the integers in the
 * array.
 */
#include <iostream>

int arraySumRecursive(int integers[], int size) {
    if (size == 0) {
        return 0;
    }
    int lastNumber = integers[size - 1];
    int allButLastSum = arraySumRecursive(integers, size - 1);
    return lastNumber + allButLastSum;
}

// count number of 0 in integers array
int zeroCountRecursive(int numbers[], int size) {
    if (size == 0) {
        return 0;
    }
    int count = zeroCountRecursive(numbers, size - 1);
    if (numbers[size - 1] == 0) {
        count++;
    }
    return count;
}

int main() {
    int integers[3] = {3, 2, 1};
    int sum = arraySumRecursive(integers, 3);
    std::cout << sum << std::endl;

    int numbers[5] = {0, 1, 0, 3, 5};
    int sum2 = zeroCountRecursive(numbers, 5);
    std::cout << sum2 << std::endl;
    return 0;
}