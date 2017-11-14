/*
 *   Exercise 3-1
 *
 *   Are you disappointed we didn't do more with sorting? I'm here to help.
 *   To make sure you are comfortable with qsort, write code that uses the
 *   function to sort an array of our student struct. First have it sort by
 *   grade, and then try it again using the student ID.
 */

#include <iostream>
#include <algorithm>

struct student {
    int grade;
    int studentID;
    std::string name;
};

bool idSort(student const &A, student const &B) {
    return A.studentID > B.studentID;
}

bool gradeSort(student const &A, student const &B) {
    return A.grade > B.grade;
}

int main() {
    const int ARRAY_SIZE = 10;
    student studentArray[ARRAY_SIZE] = {
        {87, 10001, "Fred"},    {28, 10002, "Tom"},   {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},   {84, 10005, "Erin"},  {98, 10006, "Belinda"},
        {75, 10007, "Leslie"},  {70, 10008, "Candy"}, {81, 10009, "Aretha"},
        {68, 10010, "Veronica"}};

    // print unsorted array to console
    std::cout << "Initial Array\n";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << studentArray[i].grade << '\t' << studentArray[i].studentID
                  << '\t' << studentArray[i].name << '\n';
    }
    std::cout << '\n';

    // sort by id
    std::sort(studentArray, studentArray + ARRAY_SIZE, &idSort);
    std::cout << "Sorted by student ID\n";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << studentArray[i].grade << '\t' << studentArray[i].studentID
                  << '\t' << studentArray[i].name << '\n';
    }

    // sort by grade
    std::sort(studentArray, studentArray + ARRAY_SIZE, &gradeSort);
    std::cout << "\n";
    std::cout << "Sorted by student Grade\n";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << studentArray[i].grade << '\t' << studentArray[i].studentID
                  << '\t' << studentArray[i].name << '\n';
    }


    return 0;
}
