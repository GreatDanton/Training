/*
 * Exercise 6.7:
 *
 * Solve exercise 6.3 again, using a linked list instead of an array
 *
 * -> function that is passed linked list and target, that returns number of
 * occurences of the target
 *
 */
#include <iostream>

struct Node {
    int data;
    Node *next;
};

typedef Node *LinkedList;

int occurencesIteratively(LinkedList LL, int target) {
    int count = 0;
    Node *loopPtr = new Node;
    loopPtr = LL;

    while (loopPtr != NULL) {
        if (loopPtr->data == target) {
            count++;
        }
        loopPtr = loopPtr->next;
    }
    return count;
}

int occurencesRecursively(Node *node, int target) {
    if (node->next == NULL) {
        return 0;
    }
    int count = occurencesIteratively(node->next, target);
    if (node->data == target) {
        count++;
    }
    return count;
}

int main() {
    Node *node1 = new Node;
    Node *node2 = new Node;
    Node *node3 = new Node;
    Node *node4 = new Node;

    node1->data = 1;
    node1->next = node2;
    node2->data = 2;
    node2->next = node3;
    node3->data = 2;
    node3->next = node4;
    node4->data = 2;
    node4->next = NULL;

    LinkedList LL = node1;
    int count1 = occurencesIteratively(LL, 2);
    std::cout << count1 << std::endl;

    int count2 = occurencesRecursively(LL, 2);
    std::cout << count2 << std::endl;

    delete LL;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}