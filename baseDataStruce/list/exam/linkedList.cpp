//
// Created by 24643 on 2021/10/12.
//
#include "linkList.h"
#include <iostream>

ListNode *constructRootList() {
    ListNode *pHeadNode = new ListNode(0);
    ListNode *pNextNode = pHeadNode;
    for (int i = 1; i < 6; ++i) {
        ListNode *pTmpNode = new ListNode(i);
        pNextNode->next = pTmpNode;
        pNextNode = pTmpNode;
    }

    return pHeadNode;
}

ListNode *constructList() {
    ListNode *pHeadNode = new ListNode(1);
    ListNode *pNextNode = pHeadNode;
    for (int i = 2; i < 6; ++i) {
        ListNode *pTmpNode = new ListNode(i);
        pNextNode->next = pTmpNode;
        pNextNode = pTmpNode;
    }

    return pHeadNode;
}

void printLinkNode(ListNode *headNode) {
    cout << "----------------------------------" << endl;
    ListNode *pHeadNode = headNode;
    while (pHeadNode) {
        cout << pHeadNode->val << " ";
        pHeadNode = pHeadNode->next;
    }
    cout << endl;
    cout << "----------------------------------" << endl;
}

void reverseList(ListNode *&pHead) {
    if (!pHead) {
        return;
    }

    ListNode *prev = nullptr;
    ListNode *cur = pHead;
    while (cur != nullptr) {
        ListNode *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    pHead = prev;
}

ListNode *getMiddleNode(ListNode *head) {
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

ListNode *addList(ListNode *list1, ListNode *list2) {
    ListNode *head = new ListNode(-1);
    ListNode *cur = head;
    ListNode *pList1 = list1;
    ListNode *pList2 = list2;
    int carry = 0;
    while (pList1 || pList2) {
        int sum = (pList1 ? pList1->val : 0) + (pList2 ? pList2->val : 0) + carry;
        carry = sum >= 10 ? 1 : 0;

        if (pList1) {
            pList1 = pList1->next;
        }

        if (pList2) {
            pList2 = pList2->next;
        }

        ListNode *tmpNode = new ListNode(sum % 10);
        cur->next = tmpNode;
        cur = tmpNode;
    }

    if (carry) {
        cur->next = new ListNode(carry);
    }

    return head;
}