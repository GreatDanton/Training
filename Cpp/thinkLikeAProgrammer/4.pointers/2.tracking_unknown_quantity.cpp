/*
 *   Problem: Tracking an Unknown Quantity of Student Records
 *
 *   In this problem, you will write functions to store and manipulate a
 *   collection of student records. A student record contains a student
 *   number and a grade, both integers. The following functions are to be
 *   implemented.
 *
 *   addRecord - This function takes a pointer to a collection of student
 *   records (a student number and a grade), and it adds a new record with
 *   this data to the collection.
 *
 *   averageRecord - This function takes a pointer to a collection of student
 *   records and returns the simple average of student grades in the collection
 *   as a double.
 *
 *   The collection can be of any size. The addRecord operation is expected to
 *   be called frequently, so it must be implemented efficiently.
 */
#include <iostream>

struct listNode {
    int studentNum;
    int grade;
    listNode *next;
};

typedef listNode *studentCollection;

// add new node to student collection with student num and grade
void addRecord(studentCollection &sc, int stuNum, int gr) {
    listNode *newNode = new listNode;
    newNode->studentNum = stuNum;
    newNode->grade = gr;
    newNode->next = sc;  // this is previous head pointer
    sc = newNode;
}

// get the average record of grades in student collection
double averageRecord(studentCollection sc) {
    if (sc == NULL) {
        return 0;
    }
    // list traversal
    int count = 0;
    double sum = 0;
    listNode *loopPtr = sc;
    while (loopPtr != NULL) {
        sum += loopPtr->grade;
        count++;
        loopPtr = loopPtr->next;
    }
    double average = sum / count;
    return average;
}

int main() {
    studentCollection sc;
    listNode *node1 = new listNode;
    node1->studentNum = 1001;
    node1->grade = 78;
    listNode *node2 = new listNode;
    node2->studentNum = 1012;
    node2->grade = 93;
    listNode *node3 = new listNode;
    node3->studentNum = 1076;
    node3->grade = 85;

    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = node2 = node3 = NULL;  // avoid potential cross linking problems

    // add record to student collection
    addRecord(sc, 1274, 91);
    int avg = averageRecord(sc);
    return 0;
}