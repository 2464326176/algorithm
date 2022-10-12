/*
 * @Author: yh
 * @Date: 2022/10/1 21:47
 * @Description: 
 * @FilePath: tree.h
 */
#ifndef ALGORITHM_PRACTICE_TREE_TREE_H
#define ALGORITHM_PRACTICE_TREE_TREE_H
#include <vector>

using std::vector;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct TreeLevel {
    TreeNode *treeNode;
    int levelNum;
    TreeLevel(TreeNode *treeNode, int levelNum) : treeNode(treeNode), levelNum(levelNum) {}
};

void createTree(TreeNode *tree);
// 先序遍历
void preorder(const TreeNode *root, vector<int> &visitTree);
void noRecursivePreorder(const TreeNode *root, vector<int> &visitTree);
// 中序遍历
void order(const TreeNode *root, vector<int> &visitTree);
void noRecursiveOrder(const TreeNode *root, vector<int> &visitTree);
// 后序遍历
void postorder(const TreeNode *root, vector<int> &visitTree);
void noRecursivePostorder(const TreeNode *root, vector<int> &visitTree);

vector<int> preorderTraversal(TreeNode *root);

vector<vector<int> > levelOrder(TreeNode *root);

vector<vector<int> > Print(TreeNode *pRoot);

bool recursion(TreeNode *root1, TreeNode *root2);

bool isSymmetrical(TreeNode *pRoot) {
    return recursion(pRoot, pRoot);
}

TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2);

TreeNode *Mirror(TreeNode *pRoot);

bool isValidBST(TreeNode *root);

bool isCompleteTree(TreeNode *root);

int deep(TreeNode *pRoot);

bool IsBalanced_Solution(TreeNode *pRoot);

vector<int> getPath(TreeNode* root, int target);
// 二叉搜索树的最近公共祖先
int lowestCommonAncestor(TreeNode* root, int p, int q);

// 根据前序中序 构建树
TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin);
#endif  // ALGORITHM_PRACTICE_TREE_TREE_H
