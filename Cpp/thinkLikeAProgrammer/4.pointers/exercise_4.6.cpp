/*
 * Exercise 4.6
 * Let's create an implementation for strings that uses a linked list of
 * characters instead of dynamically allocated arrays. So we'll have a linked
 * list where the data payload is a single char; this will allow strings to grow
 * without having to recreate an entire string. We'll start by implementing the
 * append and characterAt functions
 *
 */
#include <iostream>

struct stringNode {
    char c;
    stringNode *next;
};

typedef stringNode *charCollection;

void displayNodes(charCollection &c) {
    stringNode *loopPtr = c;
    while (loopPtr != NULL) {
        std::cout << loopPtr->c << std::endl;
        loopPtr = loopPtr->next;
    }
    delete[] loopPtr;
    loopPtr = NULL;
}

void append(charCollection &cc, char ch) {
    stringNode *loopPtr = cc;
    while (loopPtr != NULL) {
        if (loopPtr->next == NULL) {
            break;
        }
        loopPtr = loopPtr->next;
    }
    // loopPtr is now last element
    stringNode *node = new stringNode;
    node->c = ch;
    node->next = NULL;
    loopPtr->next = node;
}

char characterAt(charCollection &cc, int index) {
    stringNode *loopPtr = cc;
    int counter = 0;
    while (loopPtr != NULL) {
        if (index == counter) {
            return loopPtr->c;
        }
        loopPtr = loopPtr->next;
        counter++;
    }
    // index number is larger than number of elements
    return '?';
}

int main() {
    charCollection cc;

    stringNode *node1 = new stringNode;
    node1->c = 'H';
    stringNode *node2 = new stringNode;
    node2->c = 'e';
    stringNode *node3 = new stringNode;
    node3->c = 'y';

    cc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    displayNodes(cc);
    std::cout << "append: " << std::endl;
    append(cc, '!');
    displayNodes(cc);

    std::cout << "character at 2; should be y = " << characterAt(cc, 2)
              << std::endl;

    return 0;
}