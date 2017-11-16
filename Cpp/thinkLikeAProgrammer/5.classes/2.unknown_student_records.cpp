/*
 *   Problem: Tracking an Unknown Quantity of Student Records
 *
 *   In this problem, you will write a class with methods to store and
 *   manipulate a collection of student records. A student record contains
 *   a student number and a grade, both integers, and a string for the student
 *   name. The following functions are to be implemented:
 *
 *   addRecord - This method takes a student number, name, and grade and adds
 *   a new record with this data to the collection.
 *
 *   recordWithNumber - This function takes a student number and retrieves the
 *   record with that student number from the collection.
 *
 *   removeRecord - This function takes a student number and removes the record
 *   with that student number from the collection.
 *
 *   The collection can be of any size. The addRecord operation is expected to
 *   be called frequently, so it must be implemented efficiently.
 */
#include "1.studentRecord.h"
#include <iostream>

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

  private:
    typedef studentNode *studentList;
    studentList _listHead;
    void deleteList(studentList &listPtr);
    studentList copiedList(const studentList original);
};

// constructor
studentCollection::studentCollection() { _listHead = NULL; }

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

// main
int main() {
    studentCollection s;
    studentRecord stu3(84, 1152, "Sue");
    studentRecord stu2(75, 4875, "Ed");
    studentRecord stu1(98, 2938, "Todd");
    s.addRecord(stu3);
    s.addRecord(stu2);
    s.addRecord(stu1);
    s.displayLinkedList();
    std::cout << "Removing" << std::endl;
    s.removeRecord(2938);
    s.displayLinkedList();

    return 0;
}