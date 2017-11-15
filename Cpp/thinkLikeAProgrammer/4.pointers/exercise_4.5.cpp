/*
 * Exercise 4-4
 *
 * Write a function removeRecord that takes a pointer to a studentCollection
 * and a student number and that removes the record with that student number
 * from the collection
 *
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

void displayNodes(studentCollection &s);

// removes node from linked list with studentNum == stuNum
void removeRecord(studentCollection &sc, int stuNum) {
    if (sc == NULL) {
        return;
    }

    listNode *loopPtr = sc;
    listNode *previousNode = new listNode;
    int i = 0;
    while (loopPtr != NULL) {
        if (loopPtr->studentNum == stuNum) {
            if (i == 0) {
                sc = sc->next;
                break;
            }

            // if element is last element
            if (loopPtr->next == NULL) {
                previousNode->next = NULL;
                break;
            }

            // none of the above is true, replace previous node next with
            // current node next (this will leave out our current element -
            // loopPtr);
            previousNode->next = loopPtr->next;
            break;
        }
        // prepare for next iteration
        i++;
        previousNode = loopPtr;
        loopPtr = loopPtr->next;
    }
    // clean memory
    delete[] loopPtr;
}

void displayNodes(studentCollection &sc) {
    listNode *loopPtr = sc;
    while (loopPtr != NULL) {
        std::cout << loopPtr->studentNum << std::endl;
        loopPtr = loopPtr->next;
    }
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
    displayNodes(sc);

    std::cout << "Removing nodes" << std::endl;
    removeRecord(sc, 1012);
    displayNodes(sc);

    std::cout << "next removal" << std::endl;
    removeRecord(sc, 1274);
    displayNodes(sc);
    return 0;
}