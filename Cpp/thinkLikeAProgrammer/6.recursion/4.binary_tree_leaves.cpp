/*
 * Problem 4:
 * For a class that implements a binary tree, add a publicly accessible method
 * that returns the number of leaves (nodes without children) in the tree. The
 * counting of leaves should be performed using recursion.
 */
#include <iostream>

class binaryTree {
  public:
    int publicLeafCount();

  private:
    struct binaryTreeNode {
        int data;
        binaryTreeNode *left;
        binaryTreeNode *right;
    };
    typedef binaryTreeNode *treePtr;
    treePtr _root;
    int privateLeafCount(treePtr rootPtr);
};

int binaryTree::privateLeafCount(treePtr rootPtr) {
    if (rootPtr == NULL) {
        return 0;
    }
    if (rootPtr->right == NULL && rootPtr->left == NULL) {
        return 1;
    }
    int leftCount = privateLeafCount(rootPtr->left);
    int rightCount = privateLeafCount(rootPtr->right);
    return leftCount + rightCount;
}

// public wrapper function
int binaryTree::publicLeafCount() { return privateLeafCount(_root); }

int main() { return 0; }