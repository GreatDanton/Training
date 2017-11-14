/*
 * Exercise 3.7
 *
 * Write a program that is given an array of integers and determines the mode,
 * which is the number that appears most frequently in the array
 *
 */
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    //
    std::vector<int> arr = {150, 10, 5, 12, 3, 3, 150, 150, 10, 5, 150};
    std::unordered_map<int, int> map;

    for (int i = 0; i < arr.size(); i++) {
        int el = arr[i];
        if (map.find(el) != map.end()) {  // key found
            map[el]++;
        } else {
            map[el] = 1;
        }
    }

    // loop over map to check most frequent number
    int num = arr[0];
    int amount = 1;

    for (const auto &pair : map) {
        int frequency = pair.second;
        if (frequency > amount) {
            num = pair.first;
            amount = frequency;
        }
    }

    std::cout << "Number " << num << " appeared: " << amount << " times"
              << std::endl;

    return 0;
}