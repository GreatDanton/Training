#include "studentCollection.h"
#include "scIterator.h"
#include "studentRecord.h"
#include <cstring>
#include <iostream>

bool higherGrade(studentRecord r1, studentRecord r2) {
    return r1.grade() > r2.grade();
}

bool lowerStudentNumber(studentRecord r1, studentRecord r2) {
    return r1.studentID() < r2.studentID();
}

bool nameComesFirst(studentRecord r1, studentRecord r2) {
    return strcmp(r1.name().c_str(), r2.name().c_str()) < 0;
}

// constructor
studentCollection::studentCollection() {
    _listHead = NULL;
    _currentPolicy = NULL;
}

// destructor
studentCollection::~studentCollection() { deleteList(_listHead); }

// operator overload
// Call:
// > s2 = s1;
// will create s2 a deep copy of s1
studentCollection &studentCollection::operator=(const studentCollection &rhs) {
    // we check if the object on the left hand side is different that the object
    // on the right hand side
    // check wheter the pointers are different
    if (this != &rhs) {
        // avoid memory leak by deleting left hand side
        deleteList(_listHead);
        // copy the right hand side to _listHead
        _listHead = copiedList(rhs._listHead);
    }
    // return pointer to the left hand side object
    return *this;
}

// copy constructor
// > studentCollection s2(s1);
// will declare s2 and copy the nodes from s1 into it.
studentCollection::studentCollection(const studentCollection &original) {
    _listHead = copiedList(original._listHead);
}

void studentCollection::addRecord(studentRecord newStudent) {
    studentNode *newNode = new studentNode;
    newNode->studentData = newStudent;
    newNode->next = _listHead;
    _listHead = newNode;
}

// finds record with studentID == idNum
studentRecord studentCollection::recordWithNumber(int idNum) {
    studentNode *loopPtr = new studentNode;
    while (loopPtr != NULL && loopPtr->studentData.studentID() != idNum) {
        loopPtr = loopPtr->next;
    }
    // if student with desired id is not found
    if (loopPtr == NULL) {
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    }
    return loopPtr->studentData;
}

// remove student record from student collection
void studentCollection::removeRecord(int idNum) {
    studentNode *loopPtr = _listHead;
    studentNode *trailing = NULL; // node in previous iteration
    while (loopPtr != NULL && loopPtr->studentData.studentID() != idNum) {
        trailing = loopPtr;
        loopPtr = loopPtr->next;
    }
    // record was not found exit early
    if (loopPtr == NULL) {
        return;
    }
    // first element was removed, repoint _listHead
    if (trailing == NULL) {
        _listHead = _listHead->next;
    } else {
        trailing->next = loopPtr->next;
    }
    delete loopPtr;
}

void studentCollection::displayLinkedList() {
    studentNode *loopPtr = _listHead;
    while (loopPtr != NULL) {
        std::cout << loopPtr->studentData.studentID() << " ";
        loopPtr = loopPtr->next;
    }
    std::cout << std::endl;
}

void studentCollection::deleteList(studentList &listPtr) {
    while (listPtr != NULL) {
        studentNode *temp = listPtr;
        listPtr = listPtr->next;
        delete temp;
    }
}

// create deep copy of studentList argument
studentCollection::studentList
studentCollection::copiedList(const studentList original) {
    if (original == NULL) {
        return NULL;
    }

    studentList newList = new studentNode;
    newList->studentData = original->studentData;
    studentNode *oldLoopPtr = original->next;
    studentNode *newLoopPtr = newList;
    while (oldLoopPtr != NULL) {
        // create new node , advance newLoopPtr to point to it
        newLoopPtr->next = new studentNode;
        newLoopPtr = newLoopPtr->next;
        // copy the data from the old node to the new
        newLoopPtr->studentData = oldLoopPtr->studentData;
        // next iteration
        oldLoopPtr = oldLoopPtr->next;
    }
    // asign NULL to the last element of newLoop
    newLoopPtr->next = NULL;
    return newList;
}

void studentCollection::setFirstStudentPolicy(firstStudentPolicy f) {
    _currentPolicy = f;
}

studentRecord studentCollection::firstStudent() {
    if (_listHead == NULL && _currentPolicy == NULL) {
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    }
    studentNode *loopPtr = _listHead;
    studentRecord first = loopPtr->studentData;
    loopPtr = loopPtr->next;
    while (loopPtr != NULL) {
        if (_currentPolicy(loopPtr->studentData, first)) {
            first = loopPtr->studentData;
        }
        loopPtr = loopPtr->next;
    }
    return first;
}

scIterator studentCollection::firstItemIterator() {
    return scIterator(_listHead);
}