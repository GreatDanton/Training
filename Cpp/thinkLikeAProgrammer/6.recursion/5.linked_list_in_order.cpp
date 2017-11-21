/*
 * Problem 5:
 *
 * Write a function that is passed the head pointer of a singly linked list
 * where the data type of each node is an integer and that displays those
 * integers, one per line, in the order they appear in the list.
 *
 * Write a function that is passed the head pointer ofa singly linked list
 * where the data type of each node is an integer that displays those integers,
 * one per line, in the reverse order they appear in list
 */
#include <iostream>
#include <stack>

struct listNode {
    int data;
    listNode *next;
};

typedef listNode *listPtr;

void displayListForwardsRecursion(listPtr head) {
    if (head != NULL) {
        std::cout << head->data << "\n";
        displayListForwardsRecursion(head->next);
    }
}

void displayListBackwardsRecursion(listPtr head) {
    if (head != NULL) {
        displayListBackwardsRecursion(head->next);
        std::cout << head->data << "\n";
    }
}

void displayListForwardsIterative(listPtr head) {
    for (listPtr current = head; current != NULL; current = current->next) {
        std::cout << current->data << "\n";
    }
}

void displayListBackwardsIterative(listPtr head) {
    std::stack<listPtr> nodes;
    for (listPtr current = head; current != NULL; current = current->next) {
        nodes.push(current);
    }
    while (!nodes.empty()) {
        listPtr current = nodes.top();
        nodes.pop();
        std::cout << current->data << "\n";
    }
}

int main() {
    listPtr lp;

    listNode *node1 = new listNode;
    node1->data = 1;
    listNode *node2 = new listNode;
    node2->data = 2;
    listNode *node3 = new listNode;
    node3->data = 3;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    lp = node1;

    std::cout << "forwards recursion" << std::endl;
    displayListForwardsRecursion(lp);

    std::cout << "forwards iteration" << std::endl;
    displayListForwardsIterative(lp);

    std::cout << "backwards recursion" << std::endl;
    displayListBackwardsRecursion(lp);

    std::cout << "backwards iteration" << std::endl;
    displayListBackwardsIterative(lp);

    // free memory
    delete lp;
    delete node2;
    delete node3;
    return 0;
}