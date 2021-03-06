#ifndef STUDENT_COLLECTION_H
#define STUDENT_COLLECTION_H

#include "studentRecord.h"

// creates a type 'firstStudentPolicy' as a pointer to a function
// that returns bool and takes two parameters of type studentRecord
typedef bool (*firstStudentPolicy)(studentRecord r1, studentRecord r2);

bool higherGrade(studentRecord r1, studentRecord r2);
bool lowerStudentNumber(studentRecord r1, studentRecord r2);
bool nameComesFirst(studentRecord r1, studentRecord r2);

class studentCollection {

  private:
    struct studentNode {
        studentRecord studentData;
        studentNode *next;
    };

  public:
    studentCollection();
    ~studentCollection();
    // copy constructor
    studentCollection(const studentCollection &original);
    // operator overload
    studentCollection &operator=(const studentCollection &rhs);

    void addRecord(studentRecord newStudent);
    studentRecord recordWithNumber(int idNum);
    void removeRecord(int idNum);
    void displayLinkedList();

    void setFirstStudentPolicy(firstStudentPolicy f);
    studentRecord firstStudent();

  private:
    firstStudentPolicy _currentPolicy;
    typedef studentNode *studentList;
    studentList _listHead;
    void deleteList(studentList &listPtr);
    studentList copiedList(const studentList original);
};

#endif