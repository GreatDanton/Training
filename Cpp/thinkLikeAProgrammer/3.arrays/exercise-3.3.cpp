/*
 *   Exercise 3-3
 *
 *   Write a bool function that is passed an array and the number of elements
 *   in that array and determines wheter the data in the array is sorted. This
 *   should require only one pass!
 */
#include <iostream>

bool isSorted(int intArray[], int array_size) {
    if (array_size < 2) {
        return true;
    }
    int first = intArray[0];
    int second = intArray[1];

    if (first > second) {
        for (int i = 0; i < array_size - 1; i++) {
            if (intArray[i] < intArray[i + 1]) {
                return false;
            }
        }
    } else if (first < second) {
        for (int i = 0; i < array_size - 1; i++) {
            if (intArray[i] > intArray[i + 1]) {
                return false;
            }
        }
    } else {  // first == second
        enum Mode {
            ASCENDING,
            DESCENDING,
        };
        int mode = -1;

        for (int i = 0; i < array_size - 1; i++) {
            int first = intArray[i];
            int second = intArray[i + 1];

            // if mode is set check for unsorted array
            if (mode != -1) {
                if (first > second && mode == ASCENDING) {
                    return false;
                } else if (first < second && mode == DESCENDING) {
                    return false;
                }
            } else {
                // set array mode (asc or desc)
                if (first != second) {
                    if (first < second) {
                        mode = ASCENDING;
                    } else {
                        mode = DESCENDING;
                    }
                }
            }
        }
    }

    // array is sorted
    return true;
}

int main() {
    int LEN = 5;
    int array1[LEN] = {1, 2, 3, 4, 5};         // true
    int array2[LEN] = {5, 4, 3, 2, 1};         // true
    int array3[LEN] = {10, 15, 16, 100, 150};  // true
    int array4[LEN] = {3, 1, 0, 10};           // false
    int array5[LEN] = {1, 1, 1, -1, -2};       // true
    int array6[LEN] = {1, 1, 1, 2, 3};         // true
    int array7[LEN] = {1, 1, 1, -1, 10};       // false
    int array8[LEN] = {1, 2, 3, 3, 3, 10};     // true

    std::cout << "array1 is sorted: " << isSorted(array1, LEN) << "\n";
    std::cout << "array2 is sorted: " << isSorted(array2, LEN) << "\n";
    std::cout << "array3 is sorted: " << isSorted(array3, LEN) << "\n";
    std::cout << "array4 is sorted: " << isSorted(array4, LEN) << "\n";
    std::cout << "array5 is sorted: " << isSorted(array5, LEN) << "\n";
    std::cout << "array6 is sorted: " << isSorted(array6, LEN) << "\n";
    std::cout << "array7 is sorted: " << isSorted(array7, LEN) << "\n";
    std::cout << "array8 is sorted: " << isSorted(array8, LEN) << "\n";

    return 0;
}