/*
 * Exercise 4.6
 *
 * Let's create an implementation for strings that uses a linked list of
 * characters instead of dynamically allocated arrays. So we'll have a linked
 * list where the data payload is a single char; this will allow strings to grow
 * without having to recreate an entire string. We'll start by implementing the
 * append and characterAt functions
 *
 *
 * Exercise 4.7
 *
 * Following up on the previous exercise, implement the concatenate function.
 * Note that if we make a call concatenate(s1, s2), where both parameters are
 * pointers to the first nodes of their respective linked lists, the function
 * should create a copy of each of the nodes in s2 and append them to the end of
 * s1. That is, the function should not simply point the 'next' field of the
 * last node in s1's list to the first node of s2's list
 *
 *
 * Exercise 4.8
 *
 * Add a function to the linked-list string implementation called removeChars to
 * remove a section of characters from a string based on the position and
 * length. For example, removeChars(s1, 5, 3) would remove the three characters
 * starting at the fifth character in the string. Make sure the removed nodes
 * are properly deallocated.
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

void concatenate(charCollection &c1, charCollection c2) {
    // 1. copy nodes in c2
    // 2. add them to c1
    charCollection cc;
    stringNode *loopPtr = c2;
    stringNode *prevNode = new stringNode;

    int i = 0;
    while (loopPtr != NULL) {
        stringNode *newNode = new stringNode;
        if (i == 0) {
            cc = newNode;
        } else {
            prevNode->next = newNode;
        }

        newNode->c = loopPtr->c;
        newNode->next = NULL;

        i++;
        // in next iteration current node will become previous node
        // which will be used to set up -> next pointer
        prevNode = newNode;
        loopPtr = loopPtr->next;
    }
    // add cc to c1
    loopPtr = c1;
    while (loopPtr != NULL) {
        if (loopPtr->next == NULL) {
            loopPtr->next = cc;
            break;
        }
        loopPtr = loopPtr->next;
    }
    // we should not clean loopPtr or prevNode since loopPtr is the last element
    // of c1, if we call delete[] loopPtr we will get rid of last
    // element in c1
}

void concatenateTester() {
    std::cout << "Concatenate tester" << std::endl;
    charCollection c1;
    charCollection c2;
    stringNode *node1 = new stringNode;
    node1->c = 'A';
    stringNode *node2 = new stringNode;
    node2->c = 'B';
    node1->next = node2;
    node2->next = NULL;
    c1 = node1;

    stringNode *node3 = new stringNode;
    stringNode *node4 = new stringNode;
    node3->c = 'C';
    node4->c = 'D';
    node3->next = node4;
    node4->next = NULL;
    c2 = node3;

    concatenate(c1, c2);
    displayNodes(c1);
    delete[] c2;
    c2 = NULL;
    std::cout << "After deleting c2, displaying c1 again" << std::endl;
    displayNodes(c1);
    // this proves we are actually making copies of pointers c2
    delete[] c1;
}

void removeNodes(charCollection &cc, int index, int length) {
    stringNode *loopPtr = cc;
    stringNode *nodeBeforeRemove = new stringNode;
    stringNode *tmp = new stringNode;
    int loopCounter = 0;
    int removeCounter = 1;

    while (loopPtr != NULL) {
        // start removing elements
        if (loopCounter >= index) {
            // if we are removing first element, set collection to next field
            if (loopCounter == 0) {
                cc = loopPtr->next;
            }

            // we removed enough elements set next field in nodeBeforeRemove
            // and finish the loop
            if (removeCounter >= length) {
                nodeBeforeRemove->next = loopPtr->next;
                delete[] loopPtr;
                loopPtr = NULL;
                break;
            }
            // remove node
            tmp = loopPtr;
            delete[] loopPtr;
            loopPtr = NULL;
            loopPtr = tmp;
            removeCounter++;
        } else {
            nodeBeforeRemove = loopPtr;
        }
        // next iteration
        loopCounter++;
        loopPtr = loopPtr->next;
    }
    delete[] tmp;
    tmp = NULL;
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

    concatenateTester();
    std::cout << "remove nodes" << std::endl;
    removeNodes(cc, 1, 2);
    displayNodes(cc);

    return 0;
}