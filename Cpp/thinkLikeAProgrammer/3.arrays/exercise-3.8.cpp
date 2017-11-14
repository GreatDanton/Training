/*
 *  Exercise 3.8
 *
 *  Write a program that processes an array of student objects and determines
 *  the grade quartiles - that is, the grade one would need to score as well as
 *  or better than 25% of the students, 50% of the students, and 75% of the
 *  students.
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

struct student {
    int grade;
    int studentID;
    std::string name;
};

double getMedian(std::vector<int> &intArray) {
    int size = intArray.size();
    int index = size / 2.0;
    if (size % 2 == 0) {
        int firstNum = intArray[index - 1];
        int secondNum = intArray[index];
        return (firstNum + secondNum) / 2.0;
    }
    // if intArr is odd
    return intArray[index];
}

bool sortDesc(student &A, student &B) { return A.grade > B.grade; }

int main() {
    const int ARRAY_SIZE = 10;
    student studentArray[ARRAY_SIZE] = {
        {87, 10001, "Fred"},    {28, 10002, "Tom"},   {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},   {84, 10005, "Erin"},  {98, 10006, "Belinda"},
        {75, 10007, "Leslie"},  {70, 10008, "Candy"}, {81, 10009, "Aretha"},
        {68, 10010, "Veronica"}};
    // sort array by grades;
    std::sort(studentArray, studentArray + ARRAY_SIZE, sortDesc);
    std::vector<int> studentGrades;
    for (auto st : studentArray) {
        studentGrades.push_back(st.grade);
    }
    // split array in half
    int half = ARRAY_SIZE / 2;
    std::vector<int> lowerHalf;
    std::vector<int> upperHalf;

    if (ARRAY_SIZE % 2 == 0) {
        for (int i = 0; i < half; i++) {
            upperHalf.push_back(studentArray[i].grade);
        }

        for (int i = half; i < ARRAY_SIZE; i++) {
            lowerHalf.push_back(studentArray[i].grade);
        }
    } else {  // odd number
        for (int i = 0; i < half; i++) {
            upperHalf.push_back(studentArray[i].grade);
        }

        for (int i = half + 1; i < ARRAY_SIZE; i++) {
            lowerHalf.push_back(studentArray[i].grade);
        }
    }

    double Q1 = getMedian(lowerHalf);
    double Q2 = getMedian(studentGrades);
    double Q3 = getMedian(upperHalf);

    std::cout << "Grade quartiles" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "first quartile  Q1: " << Q1 << std::endl;
    std::cout << "second quartile Q2: " << Q2 << std::endl;
    std::cout << "third quartile  Q3: " << Q3 << std::endl;

    return 0;
}