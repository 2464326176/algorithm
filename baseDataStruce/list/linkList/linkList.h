/*
 * @Author: yh
 * @Date: 2023-02-06 22:30:11
 * @LastEditTime: 2023-02-06 23:07:46
 * @Description:
 * @FilePath: \algorithm\practice\linkList\linkList.h
 */
#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *constructList() {
    ListNode *pHeadNode = new ListNode(0);
    ListNode *pNextNode = pHeadNode;
    for (int i = 1; i < 6; ++i) {
        ListNode *pTmpNode = new ListNode(i);
        pNextNode->next = pTmpNode;
        pNextNode = pTmpNode;
    }

    return pHeadNode;
}

void printLinkNode(const ListNode *headNode) {
    const ListNode *pHeadNode = headNode;
    while (pHeadNode) {
        cout << pHeadNode->val << " ";
        pHeadNode = pHeadNode->next;
    }

    cout << endl;
}
#endif // LINK_LIST_H