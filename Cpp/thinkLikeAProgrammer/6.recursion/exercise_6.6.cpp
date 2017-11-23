/*
 * Exercise 6.6:
 *
 * Solve exercise 6-2 again, using a linked list instead of an array
 *
 * -> write a bool recursive function to determine wheter the binary string has
 * an odd parity
 */
#include <iostream>

struct Node {
    int data;
    Node *next;
};

typedef Node *LinkedList;

Node *createLinkedList() {
    Node *node1 = new Node;
    Node *node2 = new Node;
    Node *node3 = new Node;
    Node *node4 = new Node;

    node1->data = 1;
    node1->next = node2;
    node2->data = 1;
    node2->next = node3;
    node3->data = 1;
    node3->next = node4;
    node4->data = 0;
    node4->next = NULL;

    return node1;
}

bool oddParityIteration(Node *linkedList) {
    LinkedList LL = linkedList;
    Node *loopPtr = LL;

    int num = 0;
    while (loopPtr != NULL) {
        if (loopPtr->data == 1) {
            num++;
        }
        loopPtr = loopPtr->next;
    }
    if (num % 2 == 0) {
        return false;
    }
    return true;
}

bool oddParityRecursion(Node *node) {
    Node *loopPtr = node;
    if (loopPtr == NULL) {
        return false;
    }

    bool b = oddParityRecursion(loopPtr->next);
    if (loopPtr->data == 1) {
        b = !b;
    }
    return b;
}

int main() {
    //
    LinkedList LL = createLinkedList();

    bool b1 = oddParityIteration(LL);
    std::cout << std::boolalpha << b1 << std::endl;

    bool b2 = oddParityRecursion(LL);
    std::cout << std::boolalpha << b1 << std::endl;

    return 0;
}