/*
 * @Author: yh
 * @Date: 2023-02-06 23:37:51
 * @LastEditTime: 2023-02-07 00:05:32
 * @Description:
 * @FilePath: \algorithm\practice\linkList\detectCycle.cpp
 */
#include "linkList.h"

const ListNode *getNodeInLoop(const ListNode *headNode) {
    if (!headNode || !headNode->next) {
        return nullptr;
    }

    const ListNode *pSlowNode = headNode->next;
    const ListNode *pFastNode = pSlowNode->next;
    while (pSlowNode != nullptr && pFastNode != nullptr) {
        if (pSlowNode == pFastNode) {
            return pSlowNode;
        }
        pSlowNode = pSlowNode->next;
        pFastNode = pFastNode->next;

        if (pFastNode != nullptr) {
            pFastNode = pFastNode->next;
        }
    }

    return nullptr;
}

const ListNode *detectCycle(const ListNode *headNode) {
    const ListNode *inLoop = getNodeInLoop(headNode);
    if (!inLoop) {
        return nullptr;
    }

    const ListNode *node = headNode;
    while (node != inLoop) {
        node = node->next;
        inLoop = inLoop->next;
    }
    return node;
}

int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(6);
    ListNode *node7 = new ListNode(7);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node2;

    const ListNode *node = detectCycle(node1);
    cout << (node ? node->val : -1) << endl;

    return 0;
}