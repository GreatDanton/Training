#include <iostream>

struct student {
    int grade;
    int studentID;
    std::string name;
};

int main() {
    const int ARRAY_SIZE = 10;
    student studentArray[ARRAY_SIZE] = {
        {87, 10001, "Fred"},    {28, 10002, "Tom"},   {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},   {84, 10005, "Erin"},  {98, 10006, "Belinda"},
        {75, 10007, "Leslie"},  {70, 10008, "Candy"}, {81, 10009, "Aretha"},
        {68, 10010, "Veronica"}};

    // find highest grade
    int highPosition = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (studentArray[i].grade > studentArray[highPosition].grade) {
            highPosition = i;
        }
    }
    student student = studentArray[highPosition];

    std::cout << "Highest grade" << std::endl;
    std::cout << student.name << std::endl;
    std::cout << student.grade << std::endl;
    std::cout << student.studentID << std::endl;
    return 0;
}