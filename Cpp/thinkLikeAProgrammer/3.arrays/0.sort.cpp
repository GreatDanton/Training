#include <iostream>

int compareFunc(const void *voidA, const void *voidB) {
    int *intA = (int *)(voidA);  // casting to pointer int
    int *intB = (int *)(voidB);
    return *intA - *intB;
}

void quickSortExample() {
    const int ARRAY_SIZE = 10;
    int intArray[ARRAY_SIZE] = {87, 28, 100, 78, 84, 98, 75, 70, 81, 68};
    qsort(intArray, ARRAY_SIZE, sizeof(int), compareFunc);
    for (int i : intArray) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

void insertionSortExample() {
    const int ARRAY_SIZE = 10;
    int intArray[ARRAY_SIZE] = {87, 28, 100, 78, 84, 98, 75, 70, 81, 68};
    int start = 0;
    int end = ARRAY_SIZE - 1;

    for (int i = start + 1; i <= end; i++) {
        for (int j = i; j > start && intArray[j - 1] > intArray[j]; j--) {
            int temp = intArray[j - 1];
            intArray[j - 1] = intArray[j];
            intArray[j] = temp;
        }
    }
    for (int i : intArray) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main() {
    //
    quickSortExample();
    insertionSortExample();
    return 0;
}