//**************************
// Author:  yh
// Time:    2022/5/8
//**************************
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;

  ListNode(int x) :
      val(x), next(NULL) {
  }
};

class Solution {
public:
  ListNode *ReverseList(ListNode *pHead) {
      if (!pHead) {
          return pHead;
      }
      ListNode *p = pHead, *q = pHead->next;
      p->next = nullptr;

      while (q) {
          pHead = q;
          q = q->next;
          pHead->next = p;
          p = pHead;
      }
      return p;
  }

/**
 *
 * @param head ListNode类
 * @param m int整型
 * @param n int整型
 * @return ListNode类
 */
  ListNode *reverseBetween(ListNode *head, int m, int n) {
      ListNode *linkedList = new ListNode(-1);
      linkedList->next = head;
      ListNode *pre = linkedList, *cur = head;

      for (int i = 1; i < m; ++i) {
          pre = cur;
          cur = cur->next;
      }

      for (int i = m; i < n; ++i) {
          ListNode *temp = cur->next;
          cur->next = temp->next;
          temp->next = pre->next;
          pre->next = temp;
      }

      return linkedList->next;
  }

  /**
*
* @param head ListNode类
* @param k int整型
* @return ListNode类
*/
  ListNode *reverseKGroup(ListNode *head, int k) {
      ListNode *tail = head;
      // 遍历边界
      for (int i = 0; i < k; ++i) {
          if (tail == nullptr) {
              return head;
          }
          tail = tail->next;
      }
      ListNode *pre = nullptr;
      ListNode *cur = head;
      while (cur != tail) {
          ListNode *temp = cur->next;
          cur->next = pre;
          pre = cur;
          cur = temp;
      }

      head->next = reverseKGroup(tail, k);

      return pre;
  }

  ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
      if (!pHead1) {
          return pHead2;
      }

      if (!pHead2) {
          return pHead1;
      }

      ListNode *linkList = new ListNode(-1);
      ListNode *pHead = linkList;
      while (pHead1 && pHead2) {
          if (pHead1->val <= pHead2->val) {
              pHead->next = pHead1;
              pHead1 = pHead1->next;
          } else {
              pHead->next = pHead2;
              pHead2 = pHead2->next;
          }
          pHead = pHead->next;
      }

      pHead->next = (pHead1 ? pHead1 : pHead2);
      return linkList->next;
  }

  ListNode *divideKLists(vector<ListNode *> &lists, int left, int right) {
      if (left > right) {
          return nullptr;
      } else if (left == right) {
          return lists[right];
      }
      int mid = (left + right) / 2;
      return Merge(divideKLists(lists, left, mid), divideKLists(lists, mid + 1, right));
  }

  ListNode *mergeKLists(vector<ListNode *> &lists) {
      return divideKLists(lists, 0, lists.size() - 1);
  }

/**
 *
 * @param head ListNode类
 * @param n int整型
 * @return ListNode类
 */
  ListNode *removeNthFromEnd(ListNode *head, int n) {
      if (!head) {
          return head;
      }

      ListNode *pre = new ListNode(-1);
      pre->next = head;

      ListNode *cur = head;
      for (int i = 0; i < n; ++i) {
          cur = cur->next;
      }

      while (cur->next) {
          cur = cur->next;
          pre = pre->next;
      }

      ListNode *temp = pre->next;
      pre->next = temp->next;
      delete temp;
      return head;
  }
};

int main() {
    ListNode *l1 = new ListNode(0);
    ListNode *pHead1 = l1;
    for (int i = 1; i < 6; ++i) {
        ListNode *tmp = new ListNode(i);
        pHead1->next = tmp;
        pHead1 = pHead1->next;
    }

    Solution s1;
    //ListNode *ppHead = s1.ReverseList(l1);
    //ListNode *ppHead = s1.reverseBetween(l1, 2, 4);
    //ListNode *ppHead = s1.reverseKGroup(l1, 2);
    //ListNode *ppHead = s1.Merge(l1, l2);
    //ListNode *ppHead = s1.mergeKLists(V);
    ListNode *ppHead = s1.removeNthFromEnd(l1, 2);

    while (ppHead != NULL) {
        printf("%d ", ppHead->val);
        ppHead = ppHead->next;
    }

    return 0;
}