//**************************
// Author:  yh
// Time:    2022/5/10
//**************************
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include "binarySearchTree.h"


using namespace std;


/***
 *                   4
 *               2       5
 *            1     3        6
 */
void binarySearchTree::createBinarySearchTree() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(2, node1, node3);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node5 = new TreeNode(5, nullptr, node6);
    TreeNode *node4 = new TreeNode(4, node2, node5);
    root = node4;
}

TreeNode * binarySearchTree::increaseBst() {
    stack<TreeNode*> st;
    TreeNode *currentNode = root;
    TreeNode *firstNode = nullptr;
    TreeNode *preNode = nullptr;

    while (!currentNode || !st.empty()) {
        while (currentNode != nullptr) {
            st.push(currentNode);
        }

        currentNode = st.top();
        st.pop();
        if (preNode != nullptr) {
            preNode->right = currentNode;
        } else {
           firstNode = currentNode;
        }

        preNode = currentNode;
        currentNode->left = nullptr;
        currentNode = currentNode->right;
    }

    return firstNode;
}

TreeNode * binarySearchTree::findNextNode(TreeNode *treeNode) {
    stack<TreeNode *> st;
    TreeNode *currentNode = root;
    bool found = false;
    while (currentNode || !st.empty()) {
        while(currentNode) {
            st.emplace(currentNode);
            currentNode = currentNode->left;
        }

        currentNode = st.top();
        st.pop();
        if (found) {
            break;
        } else if (treeNode == currentNode) {
            found = true;
        }

        currentNode = currentNode->right;
    }

    return currentNode;
}

TreeNode * binarySearchTree::findNextNode1(TreeNode *treeNode) {
    TreeNode *currentNode = root;
    TreeNode *retNode = nullptr;
    while (currentNode) {
        if (currentNode->val > treeNode->val) {
            retNode = currentNode;
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }

}
void printfContainer(vector<int> visitedTree) {
    for (auto const &val : visitedTree) {
        printf("%d ", val);
    }
    printf("\n");
}


int main() {
    Tree tree;
    tree.createTree1();
    vector<int> visitedTree;
    tree.noRecursivePreorder(tree.root, visitedTree);

    return 0;
}

