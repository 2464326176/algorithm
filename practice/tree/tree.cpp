//**************************
// Author:  yh
// Time:    2022/5/10
//**************************
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param root TreeNode类
   * @return int整型vector
   */
  void preorder(TreeNode *root, vector<int> &visitTree) {
      if (root) {
          visitTree.push_back(root->val);
          preorder(root->left, visitTree);
          preorder(root->right, visitTree);
      }
      return;
  }

  void order(TreeNode *root, vector<int> &visitTree) {
      if (root) {
          order(root->left, visitTree);
          visitTree.push_back(root->val);
          order(root->right, visitTree);
      }
      return;
  }

  void postorder(TreeNode *root, vector<int> &visitTree) {
      if (root) {
          postorder(root->left, visitTree);
          postorder(root->right, visitTree);
          visitTree.push_back(root->val);
      }
      return;
  }

  vector<int> preorderTraversal(TreeNode *root) {
      vector<int> treeNodeTraver;
      preorder(root, treeNodeTraver);

      return treeNodeTraver;
  }

  /**
 *
 * @param root TreeNode类
 * @return int整型vector<vector<>>
 */
  struct TreeLevel {
    TreeNode *treeNode;
    int levelNum;

    TreeLevel(TreeNode *treeNode, int levelNum) : treeNode(treeNode), levelNum(levelNum) {}
  };

  vector<vector<int> > levelOrder(TreeNode *root) {
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

  vector<vector<int> > Print(TreeNode *pRoot) {
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

  bool recursion(TreeNode *root1, TreeNode *root2) {
      if ((root1 == nullptr) && (root2 == nullptr)) {
          return true;
      }

      if ((root1 == nullptr) || (root2 == nullptr) || (root1->val != root2->val)) {
          return false;
      }

      return (recursion(root1->right, root2->left) && recursion(root1->left, root2->right));
  }

  bool isSymmetrical(TreeNode *pRoot) {
      return recursion(pRoot, pRoot);
  }

/**
 *
 * @param t1 TreeNode类
 * @param t2 TreeNode类
 * @return TreeNode类
 */
  TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
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

  TreeNode *Mirror(TreeNode *pRoot) {
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

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param root TreeNode类
 * @return bool布尔型
 */
  int pre = INT_MIN;

  bool isValidBST(TreeNode *root) {
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

  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param root TreeNode类
   * @return bool布尔型
   */
  bool isCompleteTree(TreeNode *root) {
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

  int deep(TreeNode *pRoot) {
      if (pRoot == nullptr) {
          return 0;
      }
      int left = deep(pRoot->left);
      int right = deep(pRoot->right);
      return (left > right) ? left + 1 : right + 1;
  }

  bool IsBalanced_Solution(TreeNode *pRoot) {
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
};

int main() {
    TreeNode tree(0);
    TreeNode treeNode1(1);
    TreeNode treeNode2(2);

    TreeNode treeNode3(3);
    TreeNode treeNode4(4);
    TreeNode treeNode5(5);
//    tree.left = &treeNode1;
//    tree.right = &treeNode2;

    Solution s;
//    for(auto &val : s.preorderTraversal(&tree)) {
//        printf("%d ", val);
//    }
    /*for (auto &val: s.Print(&tree)) {
        for (auto &v: val) {
            printf("%d ", v);
        }
        printf("\n");
    }
    printf("\n");*/
    //printf("%d ", s.isSymmetrical(&tree));
    //TreeNode* node = s.mergeTrees(&tree, &treeNode3);
    TreeNode *node = s.Mirror(&tree);
    for (auto &val: s.preorderTraversal(node)) {
        printf("%d ", val);
    }
    return 0;
}