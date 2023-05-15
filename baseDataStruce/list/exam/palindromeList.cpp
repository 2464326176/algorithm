/*
 * @Author: yh
 * @Date: 2023-03-13 23:27:22
 * @LastEditTime: 2023-03-13 23:37:01
 * @Description:
 * @FilePath: \algorithm\baseDataStruce\list\exam\palindromeList.cpp
 */
#include "linkList.h"
#include <iostream>

bool isPalindromeList(ListNode *preNode, ListNode *sufNode) {
    while (preNode && sufNode) {
        if (preNode->val == sufNode->val) {
            preNode = preNode->next;
            sufNode = sufNode->next;
        } else {
            return false;
        }
    }

    if (preNode) {
        return false;
    }

    return true;
}

bool reorderList(ListNode *head) {
    ListNode *sentinelNode = new ListNode(-1);
    sentinelNode->next = head;
    ListNode *fast = sentinelNode;
    ListNode *slow = sentinelNode;

    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
        if (fast) {
            fast = fast->next;
        }
    }

    ListNode *sufNode = slow->next;
    slow->next = nullptr;
    reverseList(sufNode);
    return isPalindromeList(sentinelNode->next, sufNode);
}

int main(int argc, char **argv) {
    ListNode *list8 = new ListNode(0);
    ListNode *list7 = new ListNode(2, list8);
    ListNode *list6 = new ListNode(3, list7);
    ListNode *list5 = new ListNode(4, list6);
    ListNode *list4 = new ListNode(4, list5);
    ListNode *list3 = new ListNode(3, list4);
    ListNode *list2 = new ListNode(2, list3);
    ListNode *list1 = new ListNode(1, list2);
    printLinkNode(list1);
    cout << reorderList(list1) << endl;

    return 0;
}