/*
 * Exercise 6.3:
 *
 * Write a function that is passed an array of integers and a "target" number
 * and that returns the number of occurences of the target in the array. Solve
 * the problem first using iteration, then recursion.
 */
#include <iostream>
#include <vector>

int countIterative(std::vector<int> integers, int target) {
    int count = 0;
    for (int i = 0; i < integers.size(); i++) {
        if (integers[i] == target) {
            count++;
        }
    }
    return count;
};

int countRecursive(std::vector<int> integers, int target) {
    if (integers.empty()) {
        return 0;
    }
    integers.pop_back();
    int count = countRecursive(integers, target);
    int num = integers.back();
    if (num == target) {
        count++;
    }
    integers.pop_back();
    return count;
}

int main() {
    std::vector<int> integers{1, 2, 2, 2, 3};

    int count = countIterative(integers, 2);
    std::cout << count << std::endl; // 2

    int count2 = countRecursive(integers, 2);
    std::cout << count2 << std::endl;
    return 0;
}