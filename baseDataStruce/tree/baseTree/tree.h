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

class Tree {
public:
    void createTree(TreeNode *tree);

    void createTree1();

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

    vector<vector<int>> levelOrder(TreeNode *root);

    vector<vector<int>> Print(TreeNode *pRoot);

    bool recursion(TreeNode *root1, TreeNode *root2);

    bool isSymmetrical(TreeNode *pRoot);

    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2);

    TreeNode *Mirror(TreeNode *pRoot);

    bool isValidBST(TreeNode *root);

    bool isCompleteTree(TreeNode *root);

    int deep(TreeNode *pRoot);

    bool IsBalanced_Solution(TreeNode *pRoot);

    void dfs(TreeNode *root, vector<int> &path, int target, bool &flag);

    vector<int> getPath(TreeNode *root, int target);
    // 二叉搜索树的最近公共祖先
    int lowestCommonAncestor(TreeNode *root, int p, int q);

    // 根据前序中序 构建树
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin);

    int dfs(TreeNode *root, int path);

    int sumOfRootNodeLeafNodePaths();

    TreeNode *root = nullptr;
};

class binarySearchTree : public Tree{
public:
    void createBinarySearchTree();

    void increaseBst();

private:
    TreeNode *root;
};
#endif // ALGORITHM_PRACTICE_TREE_TREE_H
