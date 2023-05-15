/*
 * @Author: yh
 * @Date: 2023-03-13 22:52:11
 * @LastEditTime: 2023-03-13 23:24:56
 * @Description:
 * @FilePath: \algorithm\baseDataStruce\list\exam\reorderList.cpp
 */
#include "linkList.h"
#include <iostream>

void linkList(ListNode *preNode, ListNode *sufNode, ListNode *headNode) {
    ListNode *sentinelNode = headNode;
    while (preNode && sufNode) {
        ListNode *tempNode = preNode->next;
        sentinelNode->next = preNode;
        preNode->next = sufNode;
        sentinelNode = sufNode;

        preNode = tempNode;
        sufNode = sufNode->next;
    }

    if (preNode) {
        sentinelNode->next = preNode;
    }

    sentinelNode->next = preNode ? preNode : sufNode;
}

ListNode *reorderList(ListNode *head) {
    ListNode *sentinelNode = new ListNode(-1);
    sentinelNode->next = head;
    ListNode *fast = sentinelNode;
    ListNode *slow = sentinelNode;

    while (fast && slow) {
        slow = slow->next;
        fast = fast->next;
        if (fast) {
            fast = fast->next;
        }
    }

    ListNode *sufNode = slow->next;
    slow->next = nullptr;
    reverseList(sufNode);
    linkList(sentinelNode->next, sufNode, sentinelNode);
    return sentinelNode;
}

int main(int argc, char **argv) {
    ListNode *list8 = new ListNode(8);
    ListNode *list7 = new ListNode(7, list8);
    ListNode *list6 = new ListNode(6, list7);
    ListNode *list5 = new ListNode(5, list6);
    ListNode *list4 = new ListNode(4, list5);
    ListNode *list3 = new ListNode(3, list4);
    ListNode *list2 = new ListNode(2, list3);
    ListNode *list1 = new ListNode(1, list2);
    printLinkNode(list1);
    ListNode *head = reorderList(list1);
    printLinkNode(head->next);
    return 0;
}
