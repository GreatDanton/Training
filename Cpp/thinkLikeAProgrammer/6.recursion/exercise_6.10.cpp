/*
 * Exercise 6.10:
 *
 * A binary search tree is a binaryTree in which each node value is greater than
 * any value in that node's left subtree but less than any value in the node's
 * right subtree. Write a recursive function to determine wheter a binary tree
 * is a binary search tree.
 *
 */

#include <iostream>

struct Node {
    int data;
    Node *left;
    Node *right;
};

typedef Node *binaryTree;

/*
Tree created with the function below:

         10
      /     \
    6       18
  /  \     /  \
4     8   15  21

 */
binaryTree createBinaryTree() {
    Node *rootNode = new Node;
    Node *leftNode_first = new Node;
    Node *rightNode_first = new Node;

    rootNode->data = 10;
    rootNode->left = leftNode_first;
    rootNode->right = rightNode_first;

    leftNode_first->data = 6;
    rightNode_first->data = 18;

    // left part of the first subtree node
    Node *leftNode_second_left = new Node;
    Node *leftNode_second_right = new Node;
    leftNode_second_left->data = 4;
    leftNode_second_right->data = 8;

    leftNode_second_left->left = NULL;
    leftNode_second_left->right = NULL;
    leftNode_second_right->left = NULL;
    leftNode_second_right->right = NULL;

    // right part of the first right subtree node:
    Node *rightNode_second_left = new Node;
    rightNode_second_left->data = 15;
    rightNode_second_left->left = NULL;
    rightNode_second_left->right = NULL;

    Node *rightNode_second_right = new Node;
    rightNode_second_right->data = 21;
    rightNode_second_right->left = NULL;
    rightNode_second_right->right = NULL;

    leftNode_first->left = leftNode_second_left;
    leftNode_first->right = leftNode_second_right;

    rightNode_first->left = rightNode_second_left;
    rightNode_first->right = rightNode_second_right;

    return rootNode;
}

// free binary tree from memory
void freeBinaryTree(Node *rootNode) {
    if (rootNode == NULL) {
        return;
    }
    freeBinaryTree(rootNode->left);
    freeBinaryTree(rootNode->right);
    delete rootNode;
}

// recursive function to check wheter the binary tree argument is
// binary search tree
bool isItBinarySearchTree(Node *node) {
    if (node == NULL) {
        return true;
    }

    bool b1 = isItBinarySearchTree(node->left);
    bool b2 = isItBinarySearchTree(node->right);

    if (b1 == false || b2 == false) {
        return false;
    }

    int rootData = node->data;

    if (node->left != NULL) {
        int leftData = node->left->data;
        if (leftData > rootData) {
            return false;
        }
    }

    if (node->right != NULL) {
        int rightData = node->right->data;
        if (rightData < rootData) {
            return false;
        }
    }

    return true;
}

int main() {
    binaryTree bt = createBinaryTree();
    bool b1 = isItBinarySearchTree(bt);
    std::cout << std::boolalpha << b1 << std::endl;
    freeBinaryTree(bt);
    return 0;
}