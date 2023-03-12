//**************************
// Author:  yh
// Time:    2022/5/10
//**************************
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include "tree.h"


using namespace std;

/*
 *              5
 *      8               7
 *          3       6
 *              4
 */
void Tree::createTree(TreeNode *tree) {
    TreeNode *tree1 = new TreeNode(5);
    TreeNode *tree2 = new TreeNode(8);
    TreeNode *tree3 = new TreeNode(3);
    TreeNode *tree4 = new TreeNode(7);
    TreeNode *tree5 = new TreeNode(6);
    TreeNode *tree6 = new TreeNode(4);

    tree1->left = tree2;
    tree1->right = tree4;
    tree2->right = tree3;

    tree4->left = tree5;
    tree5->left = tree6;

    tree = tree1;
}

// 3,9,5,#,#,1,#,#,0,#,2,#,#
/*                  3
 *          9               0
 *      5       1               2
 */
void Tree::createTree1() {
    TreeNode *t5 = new TreeNode(5);
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t9 = new TreeNode(9, t5, t1);
    TreeNode *t0 = new TreeNode(0, nullptr, t2);
    TreeNode *t3 = new TreeNode(3, t9, t0);
    root = t3;
}

void Tree::preorder(const TreeNode *root, vector<int> &visitTree) {
    if (root) {
        visitTree.push_back(root->val);
        preorder(root->left, visitTree);
        preorder(root->right, visitTree);
    }
}

void Tree::noRecursivePreorder(const TreeNode *root, vector<int> &visitTree) {

}

void Tree::order(const TreeNode *root, vector<int> &visitTree) {
    if (root) {
        order(root->left, visitTree);
        visitTree.push_back(root->val);
        order(root->right, visitTree);
    }
}

void Tree::noRecursiveOrder(const TreeNode *root, vector<int> &visitTree) {
    std::stack<const TreeNode *> st;
    const TreeNode *currentNode = root;
    while (currentNode || !st.empty()) {
        while (currentNode) {
            st.push(currentNode);
            currentNode = currentNode->left;
        }

        currentNode = st.top();
        st.pop();
        visitTree.emplace_back(currentNode->val);
        currentNode = currentNode->right;
    }
}

void Tree::postorder(const TreeNode *root, vector<int> &visitTree) {
    if (root) {
        postorder(root->left, visitTree);
        postorder(root->right, visitTree);
        visitTree.push_back(root->val);
    }
}

void Tree::noRecursivePostorder(const TreeNode *root, vector<int> &visitTree) {

}

vector<int> Tree::preorderTraversal(TreeNode *root) {
    vector<int> treeNodeTraver;
    preorder(root, treeNodeTraver);
    return treeNodeTraver;
}

vector<vector<int> > Tree::levelOrder(TreeNode *root) {
    vector<vector<int> > vectorTree;
    queue<TreeLevel> treeQueue;

    if (!root) {
        return vectorTree;
    }

    int i = 0;
    treeQueue.push({root, i});
    while (!treeQueue.empty()) {
        vector<int> vc;
        int treeQueueSize = treeQueue.size();
        for (int j = 0; j < treeQueueSize; ++j) {
            TreeLevel treeLevel = treeQueue.front();
            i = treeLevel.levelNum;
            vc.push_back(treeLevel.treeNode->val);
            treeQueue.pop();
            if (treeLevel.treeNode->left) {
                treeQueue.push({treeLevel.treeNode->left, i + 1});
            }

            if (treeLevel.treeNode->right) {
                treeQueue.push({treeLevel.treeNode->right, i + 1});
            }
        }
        vectorTree.push_back(vc);
    }

    return vectorTree;
}

vector<vector<int> > Tree::Print(TreeNode *pRoot) {
    vector<vector<int> > vectorTree;
    queue<TreeNode *> treeQueue;

    if (!pRoot) {
        return vectorTree;
    }

    int flag = 0;
    treeQueue.push(pRoot);
    while (!treeQueue.empty()) {
        vector<int> vc;
        flag = flag ? 0 : 1;
        int treeQueueSize = treeQueue.size();
        for (int j = 0; j < treeQueueSize; ++j) {
            TreeNode *treeNode = treeQueue.front();
            vc.push_back(treeNode->val);
            treeQueue.pop();
            if (treeNode->left) {
                treeQueue.push(treeNode->left);
            }

            if (treeNode->right) {
                treeQueue.push(treeNode->right);
            }
        }

        if (!flag) {
            reverse(vc.begin(), vc.end());
        }
        vectorTree.push_back(vc);
    }
    return vectorTree;
}

bool Tree::recursion(TreeNode *root1, TreeNode *root2) {
    if ((root1 == nullptr) && (root2 == nullptr)) {
        return true;
    }

    if ((root1 == nullptr) || (root2 == nullptr) || (root1->val != root2->val)) {
        return false;
    }

    return (recursion(root1->right, root2->left) && recursion(root1->left, root2->right));
}

bool Tree::isSymmetrical(TreeNode *pRoot) {
    return recursion(pRoot, pRoot);
}

TreeNode *Tree::mergeTrees(TreeNode *t1, TreeNode *t2) {
    if (t1 == nullptr) {
        return t2;
    }

    if (t2 == nullptr) {
        return t1;
    }

    TreeNode *head = new TreeNode(t1->val + t2->val);
    head->left = mergeTrees(t1->left, t2->left);
    head->right = mergeTrees(t1->right, t2->right);
    return head;
}

TreeNode *Tree::Mirror(TreeNode *pRoot) {
    if (!pRoot) {
        return nullptr;
    }

    if (!pRoot->left && !pRoot->right) {
        return pRoot;
    }

    TreeNode *temp = pRoot->right;
    pRoot->right = pRoot->left;
    pRoot->left = temp;

    Mirror(pRoot->left);
    Mirror(pRoot->right);

    return pRoot;
}

int pre = INT_MIN;

bool Tree::isValidBST(TreeNode *root) {
    if (!root) {
        return true;
    }

    if (!isValidBST(root->left)) {
        return false;
    }

    if (root->val <= pre) {
        return false;
    }

    pre = root->val;

    if (!isValidBST(root->right)) {
        return false;
    }

    return true;
}

bool Tree::isCompleteTree(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }

    queue<TreeNode *> que;
    que.push(root);
    bool flag = false;
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; ++i) {
            TreeNode *temp = que.front();
            que.pop();
            if (temp == nullptr) {
                flag = true;
            } else {
                if (flag) {
                    return false;
                }
                que.push(temp->left);
                que.push(temp->right);
            }
        }
    }
    return true;
}

int Tree::deep(TreeNode *pRoot) {
    if (pRoot == nullptr) {
        return 0;
    }
    int left = deep(pRoot->left);
    int right = deep(pRoot->right);
    return (left > right) ? left + 1 : right + 1;
}

bool Tree::IsBalanced_Solution(TreeNode *pRoot) {
    if (!pRoot) {
        return true;
    }
    int left = deep(pRoot->left);
    int right = deep(pRoot->right);

    if ((left - right > 1) || (left - right < -1)) {
        return false;
    }

    return (IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right));
}

// ¶þ²æËÑË÷Ê÷
void Tree::dfs(TreeNode *root, vector<int> &path, int target, bool &flag) {
    if (flag || !root) {
        return;
    }

    TreeNode *pTreeNode = root;
    path.push_back(pTreeNode->val);
    if (pTreeNode->val == target) {
        flag = true;
        return;
    }

    if (pTreeNode->left) {
        dfs(pTreeNode->left, path, target, flag);
    }

    if (pTreeNode->right) {
        dfs(pTreeNode->right, path, target, flag);
    }

    if (flag) {
        return;
    }

    path.pop_back();
}

vector<int> Tree::getPath(TreeNode *root, int target) {
    vector<int> path;
    TreeNode *pTreeNode = root;

    while (pTreeNode->val != target) {
        path.push_back(pTreeNode->val);
        if (pTreeNode->val > target) {
            pTreeNode = pTreeNode->left;
        } else {
            pTreeNode = pTreeNode->right;
        }
    }
    path.push_back(pTreeNode->val);
    return path;
}

int Tree::lowestCommonAncestor(TreeNode *root, int p, int q) {
//    vector<int> pPath = getPath(root, p);
//    vector<int> qPath = getPath(root, q);
//    int res = 0;
//
//    for (int i = 0; i < pPath.size() && i < qPath.size(); ++i) {
//        if (pPath[i] == qPath[i]) {
//            res = pPath[i];
//        } else {
//            break;
//        }
//    }
//    return res;
    vector<int> path1, path2;
    bool flag1 = false, flag2 = false;
    dfs(root, path1, p, flag1);
    dfs(root, path2, q, flag2);
    int res = 0;

    for (int i = 0; i < path1.size() && i < path2.size(); ++i) {
        if (path1[i] == path2[i]) {
            res = path1[i];
        } else {
            break;
        }
    }
    return res;
}

TreeNode *Tree::reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    int m = pre.size();
    int n = vin.size();

    if (m == 0 || n == 0) {
        return nullptr;
    }

    TreeNode *treeNode = new TreeNode(pre[0]);
    for (int i = 0; i < vin.size(); ++i) {
        if (pre[0] == vin[i]) {
            std::vector<int> leftPre(pre.begin() + 1, pre.begin() + i + 1);
            std::vector<int> leftVin(vin.begin(), vin.begin() + i);
            treeNode->left = reConstructBinaryTree(leftPre, leftVin);
            std::vector<int> rightPre(pre.begin() + i + 1, pre.end());
            std::vector<int> rightVin(vin.begin() + i + 1, vin.end());
            treeNode->right = reConstructBinaryTree(rightPre, rightVin);
            break;
        }
    }
    return treeNode;
}

int Tree::dfs(TreeNode *root, int path) {
    if (root == nullptr) {
        return 0;
    }

    path = path * 10 + root->val;
    if (root->left == nullptr && root->right == nullptr) {
        return path;
    }

    return dfs(root->left, path) + dfs(root->right, path);
}

int Tree::sumOfRootNodeLeafNodePaths() {
    return dfs(root, 0);
}

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
    int *p = new int(5);


    return 0;
}

