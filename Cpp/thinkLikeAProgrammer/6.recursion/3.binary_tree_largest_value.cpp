/*
 * Problem 3:
 *
 * Write a function that, when given a binary tree where each node holds an
 * integer, returns the largest integer in the tree.
 *
 */

#include <iostream>

struct treeNode {
    int data;
    treeNode *left;
    treeNode *right;
};

typedef treeNode *treePtr;

int maxValue(treePtr root) {
    if (root == NULL) {
        return 0;
    }
    if (root->right == NULL && root->left == NULL) {
        return root->data;
    }
    int leftMax = maxValue(root->left);
    int rightMax = maxValue(root->right);
    int maxNum = root->data;
    if (leftMax > maxNum) {
        maxNum = leftMax;
    }
    if (rightMax > maxNum) {
        maxNum = rightMax;
    }
    return maxNum;
}

void maxValueTester() {
    treeNode *node1 = new treeNode;
    node1->data = 5;
    treeNode *leftNode = new treeNode;
    leftNode->data = 6;
    leftNode->left = NULL;
    leftNode->right = NULL;

    treeNode *rightNode = new treeNode;
    rightNode->data = 10;
    rightNode->left = NULL;
    rightNode->right = NULL;
    node1->left = leftNode;
    node1->right = rightNode;
    treePtr tp;
    tp = node1;

    int max = maxValue(tp);
    std::cout << max << std::endl;

    treeNode *subLeftNode = new treeNode;
    subLeftNode->data = 15;
    subLeftNode->left = NULL;
    subLeftNode->right = NULL;

    treeNode *subRightNode = new treeNode;
    subRightNode->data = 20;
    subRightNode->left = NULL;
    subRightNode->right = NULL;
    // left node has 1 more node
    leftNode->left = subLeftNode;
    leftNode->right = subRightNode;

    int max2 = maxValue(tp);
    std::cout << max2 << std::endl;

    delete tp;
    delete leftNode;
    delete rightNode;
    delete subLeftNode;
    delete subRightNode;
}

int main() {
    maxValueTester();
    return 0;
}