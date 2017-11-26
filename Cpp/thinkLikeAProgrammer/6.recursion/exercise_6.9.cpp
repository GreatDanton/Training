/*
 * Exercise 6.9:
 *
 * Some words in programming have more than one common meaning. In Chapter 4, we
 * learned about the heap, from which we get memory allocated with new. The term
 * heap also describes a binary tree in which each node value is higher than any
 * in the left or right subtree. Write a recursive function to determine wheter
 * a binary tree is a heap.
 *
 */
#include <iostream>

struct Node {
    int data;
    Node *left;
    Node *right;
};

typedef Node *binaryTree;

Node *createBinaryTree() {
    Node *rootNode = new Node;
    Node *leftNode_first = new Node;
    Node *rightNode_first = new Node;

    rootNode->data = 15;
    rootNode->left = leftNode_first;
    rootNode->right = rightNode_first;

    leftNode_first->data = 10;
    leftNode_first->left = NULL;
    leftNode_first->right = NULL;

    rightNode_first->data = 12;

    Node *leftNode_second = new Node;
    Node *rightNode_second = new Node;

    leftNode_second->data = 8;
    leftNode_second->left = NULL;
    leftNode_second->right = NULL;

    rightNode_second->data = 4;
    rightNode_second->left = NULL;
    rightNode_second->right = NULL;

    rightNode_first->left = leftNode_second;
    rightNode_first->right = rightNode_second;

    return rootNode;
}

// free all nodes of binary tree
void freeTreeMemory(Node *treeNode) {
    if (treeNode == NULL) {
        return;
    }

    freeTreeMemory(treeNode->left);
    freeTreeMemory(treeNode->right);
    delete treeNode;
}

int findLargestNum(Node *treeNode) {
    if (treeNode == NULL) {
        return 0;
    }

    int largestNum = treeNode->data;
    int leftNum = findLargestNum(treeNode->left);
    int rightNum = findLargestNum(treeNode->right);

    if (leftNum > largestNum) {
        largestNum = leftNum;
    }

    if (rightNum > largestNum) {
        largestNum = rightNum;
    }
    return largestNum;
}

// check if inserted binary tree argument is a heap (each node value is bigger
// than left or right subtree value)
bool isItHeap(Node *treeNode) {
    if (treeNode == NULL) {
        return true;
    }

    bool left = isItHeap(treeNode->left);
    bool right = isItHeap(treeNode->right);

    if (left == false || right == false) {
        return false;
    }

    int nodeNum = treeNode->data;

    if (treeNode->left != NULL) {
        int leftNum = treeNode->left->data;
        if (leftNum > nodeNum) {
            return false;
        }
    }

    if (treeNode->right != NULL) {
        int rightNum = treeNode->right->data;
        if (rightNum > nodeNum) {
            return false;
        }
    }

    return true;
}

int main() {
    binaryTree bt = createBinaryTree();
    int num = findLargestNum(bt);
    std::cout << num << std::endl;

    bool ok = isItHeap(bt);
    std::cout << std::boolalpha << ok << std::endl;

    freeTreeMemory(bt);

    return 0;
}