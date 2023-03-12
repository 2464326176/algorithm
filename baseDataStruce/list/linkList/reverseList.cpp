/*
 * @Author: yh
 * @Date: 2022-05-08 09:22:58
 * @LastEditTime: 2023-02-07 00:08:28
 * @Description:
 * @FilePath: \algorithm\practice\linkList\reverseList.cpp
 */
//**************************
// Author:  yh
// Time:    2022/5/8
//**************************
#include "linkList.h"

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

int main() {
    ListNode *pHeadNode = constructList();
    printLinkNode(pHeadNode);
    reverseList(pHeadNode);
    printLinkNode(pHeadNode);
    return 0;
}