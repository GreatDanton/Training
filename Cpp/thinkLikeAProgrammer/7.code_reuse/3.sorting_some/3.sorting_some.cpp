/*
 * Problem 3: Sorting some, leaving others alone
 *
 * A project requires you to sort an array of studentRecord objects by grade,
 * but there's a catch. Another part of the program is using a special grade
 * value of -1 to indicate a student whose records cannot be moved. So while all
 * the other records must be moved around, those with -1 grades should be left
 * exactly where they are, resulting in an array that is sorted except for -1
 * grades intersperesed throughout.
 */
#include "studentRecord.h"
#include <iostream>

void sortWithInsertionSort() {
    studentRecord Tom(87, 11523, "Tom");
    studentRecord Gladys(-1, 83764, "Gladys");
    studentRecord Sam(-1, 65342, "Sam");
    studentRecord Jane(84, 11523, "Jane");
    studentRecord John(-1, 11764, "John");
    studentRecord Art(72, 77663, "Art");

    const int arraySize = 6;
    studentRecord sra[arraySize]{Tom, Gladys, Sam, Jane, John, Art};
    int start = 0;
    int end = arraySize - 1;
    for (int i = start + 1; i <= end; i++) {
        if (sra[i].grade() != -1) {
            int rightswap = i;
            for (int leftswap = i - 1;
                 leftswap >= start &&
                     sra[leftswap].grade() > sra[rightswap].grade() ||
                 sra[leftswap].grade() == -1;
                 leftswap--) {

                if (sra[leftswap].grade() != -1) {
                    studentRecord temp = sra[leftswap];
                    sra[leftswap] = sra[rightswap];
                    sra[rightswap] = temp;
                    rightswap = leftswap;
                }
            }
        }
    }
    for (auto st : sra) {
        std::cout << st.grade() << " " << st.name() << std::endl;
    }
}

int compareStudentRecord(const void *voidA, const void *voidB) {
    studentRecord *recordA = (studentRecord *)voidA;
    studentRecord *recordB = (studentRecord *)voidB;
    return recordA->grade() - recordB->grade();
}

void sortWithQSort() {
    studentRecord Tom(87, 11523, "Tom");
    studentRecord Gladys(-1, 83764, "Gladys");
    studentRecord Sam(-1, 65342, "Sam");
    studentRecord Jane(84, 11523, "Jane");
    studentRecord John(-1, 11764, "John");
    studentRecord Art(72, 77663, "Art");
    const int arraySize = 6;
    studentRecord sra[arraySize]{Tom, Gladys, Sam, Jane, John, Art};

    // grab non -1 grades from student record array (sra) and sort it
    studentRecord *sortArray = new studentRecord[arraySize];
    int sortArrayCount = 0;
    for (int i = 0; i < arraySize; i++) {
        if (sra[i].grade() != -1) {
            sortArray[sortArrayCount] = sra[i];
            sortArrayCount++;
        }
    }

    qsort(sortArray, sortArrayCount, sizeof(studentRecord),
          compareStudentRecord);
    sortArrayCount = 0;
    // add sorted studentRecords to their place, while leaving the ones with -1
    // alone
    for (int i = 0; i < arraySize; i++) {
        if (sra[i].grade() != -1) {
            sra[i] = sortArray[sortArrayCount];
            sortArrayCount++;
        }
    }

    for (auto st : sra) {
        std::cout << st.grade() << " " << st.name() << std::endl;
    }
}

int main() {
    sortWithInsertionSort();
    std::cout << std::endl;
    sortWithQSort();
    return 0;
}