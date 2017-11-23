/*
 * Exercise 6.5:
 *
 * Solve exercise 6-1 again, using a linked list instead of an array
 *
 * -> function to compute sum of just the positive numbers in linked list of
 * integers
 * -> iterative function, recursive function
 */
#include <iostream>

struct Node {
    int data;
    Node *next;
};

typedef Node *LinkedList;

Node *createList() {
    Node *node1 = new Node;
    node1->data = -1;
    Node *node2 = new Node;
    node2->data = 5;
    Node *node3 = new Node;
    node3->data = 2;
    Node *node4 = new Node;
    node4->data = -5;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    return node1;
}

void ClearNodes(Node *rootNode) {
    Node *loopPtr = rootNode;

    while (loopPtr != NULL) {
        Node *temp = loopPtr;
        loopPtr = temp->next;
        delete temp;
    }
}

int sumWithIteration(Node *LinkedList) {
    int sum = 0;
    Node *loopPtr = LinkedList;
    while (loopPtr != NULL) {
        if (loopPtr->data > 0) {
            sum += loopPtr->data;
        }
        loopPtr = loopPtr->next;
    }
    return sum;
}

int sumWithRecursion(Node *node) {
    if (node == NULL) {
        return 0;
    }
    int current = 0;
    if (node->data > 0) {
        current = node->data;
    }
    int sum = sumWithRecursion(node->next);
    return sum + current;
}

int main() {
    LinkedList LL;
    LL = createList();

    int sum = sumWithIteration(LL);
    std::cout << sum << std::endl;

    int sum2 = sumWithRecursion(LL);
    std::cout << sum2 << std::endl;

    ClearNodes(LL);
    return 0;
}