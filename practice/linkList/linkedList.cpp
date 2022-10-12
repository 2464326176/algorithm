//
// Created by 24643 on 2021/10/12.
//
#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
      ListNode *slow = head, *fast = head;
      while (fast != nullptr) {
          fast = fast->next;
          if (fast != nullptr) {
              fast = fast->next;
              slow = slow->next;
          }
      }
      return slow;
  }

  ListNode *removeNthFromEnd(ListNode *head, int n) {
      ListNode *slow = head, *fast = head;
      for (int i = 0; i < n; ++i) {
          fast = fast->next;
          if (fast == nullptr) {
              break;
          }
      }

      if (fast == nullptr) {
          ListNode *tmp = head;
          head = head->next;
          delete tmp;
      } else {
          while (fast != nullptr) {
              fast = fast->next;
              if (fast != nullptr) {
                  slow = slow->next;
              }
          }
          ListNode *tmp = slow->next;
          slow->next = tmp->next;
          delete tmp;
      }
      while (head) {
          cout << head->val << endl;
          head = head->next;
      }
      return nullptr;
  }
};

int main() {
    ListNode *head = new ListNode;
    head->val = 1;
    head->next = nullptr;
    ListNode *pHead = head;
    for (int i = 2; i < 6; ++i) {
        ListNode *tmp = new ListNode;
        tmp->val = i;
        tmp->next = nullptr;
        pHead->next = tmp;
        pHead = tmp;
    }
    Solution S;
    //cout << S.middleNode(head)->val;
    ListNode *bHead;
    bHead = S.removeNthFromEnd(head, 5);

    /*while(bHead) {
        cout << pHead->val << endl;
        bHead = bHead->next;
    }*/

    return 0;
}