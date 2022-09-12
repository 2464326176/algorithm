#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
      ListNode *p1;
      int n1 = 0, n2 = 0;
      while (l1 != NULL) {
          n1 = n1 * 10 + l1->val;
          l1 = l1->next;
      }
      while (l2 != NULL) {
          n2 = n2 * 10 + l2->val;
          l2 = l2->next;
      }
      n1 = n1 + n2;
      while (n1 / 10) {
          ListNode *t1;
          t1 = (ListNode *) malloc(sizeof(ListNode));
          t1->val = n1 % 10;
          t1->next = p1;
          p1 = t1;
          n1 = n1 / 10;
      }
      return p1;
  }
};

int main() {
    ListNode *p1;
    ListNode *tmp1;
    for (int i = 0; i < 3; ++i) {
        tmp1 = (ListNode *) malloc(sizeof(ListNode));
        tmp1->val = i + 2;
        tmp1->next = p1;
        p1 = tmp1;
    }
    ListNode *p2;
    ListNode *tmp2;
    for (int i = 0; i < 3; ++i) {
        tmp2 = (ListNode *) malloc(sizeof(ListNode));
        tmp2->val = i + 2;
        tmp2->next = p2;
        p2 = tmp2;
    }

    Solution s1;
    ListNode *p3 = s1.addTwoNumbers(p1, p2);
    printf("-----------------\n");
    return 0;
}