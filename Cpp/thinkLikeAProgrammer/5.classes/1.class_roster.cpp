/*
 *  Class Roster
 *
 * Design a class or set of classes for use in a program that maintains a class
 * roster. For each student, store the student's name, ID, and final grade score
 * in the range 0-100. The program will allow student records to be added or
 * removed; display the record of a particular student, identified by ID, with
 * the grade displayed as a number and as a letter; and display the average
 * score for the class. The appropriate letter grade for particular score is
 * shown in table 5-1.
 *
 */
#include <iostream>

class studentRecord {
   public:
    studentRecord();
    studentRecord(int newGrade, int newID, std::string newName);
    int grade();
    void setGrade(int newGrade);
    int studentID();
    void setStudentID(int newID);
    std::string name();
    void setName(std::string newName);

    std::string letterGrade();

   private:
    int _grade;
    int _studentID;
    std::string _name;
    bool isValidGrade(int grade);
};

// constructors
studentRecord::studentRecord() {
    setGrade(-1);
    setName("");
    setStudentID(-1);
}

studentRecord::studentRecord(int newGrade, int newID, std::string newName) {
    setGrade(newGrade);
    setStudentID(newID);
    setName(newName);
}

int studentRecord::grade() { return _grade; }
void studentRecord::setGrade(int newGrade) {
    if (isValidGrade(newGrade)) {
        _grade = newGrade;
    }
}

int studentRecord::studentID() { return _studentID; }
void studentRecord::setStudentID(int newID) {
    // check if newID is correct - missing
    _studentID = newID;
}

std::string studentRecord::name() { return _name; }
void studentRecord::setName(std::string newName) { _name = newName; }

// support methods

// get letter grade based on _grade
std::string studentRecord::letterGrade() {
    if (!isValidGrade(_grade)) {
        return "ERROR";
    }
    const int NUMBER_CATEGORIES = 11;
    const std::string GRADE_LETTER[] = {"F",  "D", "D+", "C-", "C", "C+",
                                        "B-", "B", "B+", "A-", "A"};
    const int LOWEST_GRADE_SCORE[] = {0,  60, 67, 70, 73, 77,
                                      80, 83, 87, 90, 93};
    int category = 0;

    while (category < NUMBER_CATEGORIES &&
           LOWEST_GRADE_SCORE[category] <= _grade) {
        category++;
    }
    return GRADE_LETTER[category - 1];
}

bool studentRecord::isValidGrade(int grade) {
    if ((grade >= 0) && (grade <= 100)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    //
    return 0;
}