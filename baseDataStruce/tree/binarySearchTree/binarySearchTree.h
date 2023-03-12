/*
 * @Author: yh
 * @Date: 2022/10/1 21:47
 * @Description:
 * @FilePath: \algorithm\practice\tree\baseTree\tree.h
 */
#ifndef ALGORITHM_PRACTICE_TREE_TREE_H
#define ALGORITHM_PRACTICE_TREE_TREE_H
#include <vector>

using std::vector;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
    TreeNode(int value, TreeNode *leftNode, TreeNode *rightNode) : val(value), left(leftNode), right(rightNode) {}
};

struct TreeLevel {
    TreeNode *treeNode;
    int levelNum;
    TreeLevel(TreeNode *treeNode, int levelNum) : treeNode(treeNode), levelNum(levelNum) {}
};

class binarySearchTree{
public:
    void createBinarySearchTree();

    void increaseBst();

    TreeNode * findNextNode(TreeNode *treeNode);

    TreeNode * findNextNode1(TreeNode *treeNode)
private:
    TreeNode *root;
};
#endif // ALGORITHM_PRACTICE_TREE_TREE_H
