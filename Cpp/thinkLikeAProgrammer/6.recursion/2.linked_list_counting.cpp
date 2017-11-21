/*
 * Problem 2:
 *
 * Write a recursive function that is given a linked list where the data type is
 * integer. The function returns the count of negative numbers in the list.
 */
#include <iostream>

struct listNode {
    int data;
    listNode *next;
};

typedef listNode *listPtr;

int countNegative(listPtr head) {
    if (head == NULL) {
        return 0;
    }

    int listCount = countNegative(head->next);
    if (head->data < 0) {
        listCount++;
    }
    return listCount;
}

void countNegativeTester() {
    listNode *node1 = new listNode;
    node1->data = -1;
    listNode *node2 = new listNode;
    node2->data = 2;
    listNode *node3 = new listNode;
    node3->data = -10;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    listPtr lp;
    lp = node1;

    int count = countNegative(lp);
    std::cout << count << std::endl; // should return 2
    // free memory
    delete node1;
    delete node2;
    delete node3;
    delete lp;
}

int main() {
    countNegativeTester();
    return 0;
}