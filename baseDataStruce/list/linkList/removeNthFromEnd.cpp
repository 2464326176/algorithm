/*
 * @Author: yh
 * @Date: 2023-02-06 22:30:51
 * @LastEditTime: 2023-02-06 23:19:15
 * @Description:
 * @FilePath: \algorithm\practice\linkList\removeNthFromEnd.cpp
 */
#include "iostream"
#include "linkList.h"

void removeNthFromEnd(ListNode *&headNode, int k) {
    if (!headNode) {
        return;
    }

    ListNode *pDummyNode = new ListNode(-1);
    pDummyNode->next = headNode;
    ListNode *pHeadNode = headNode;

    for (int i = 1; i < k; ++i) {
        if (pHeadNode) {
            pHeadNode = pHeadNode->next;
        } else {
            return;
        }
    }

    while (pHeadNode->next != nullptr) {
        pHeadNode = pHeadNode->next;
        pDummyNode = pDummyNode->next;
    }

    ListNode *pTmpNode = pDummyNode->next;

    if (pTmpNode == headNode) {
        headNode = headNode->next;
    }

    pDummyNode->next = pTmpNode->next;
    delete pTmpNode;
    pTmpNode = nullptr;
}

int main() {
    ListNode *pHeadNode = constructList();
    printLinkNode(pHeadNode);
    removeNthFromEnd(pHeadNode, 9);
    printLinkNode(pHeadNode);
    return 0;
}