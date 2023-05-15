/*
 * @Author: yh
 * @Date: 2023-02-06 22:30:11
 * @LastEditTime: 2023-03-13 21:40:30
 * @Description:
 * @FilePath: \algorithm\baseDataStruce\list\exam\linkList.h
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

ListNode *constructRootList();

ListNode *constructList();

void printLinkNode(ListNode *headNode);

void reverseList(ListNode *&pHead);

ListNode *getMiddleNode(ListNode *head);

ListNode *removeNthFromEnd(ListNode *head, int n);

ListNode *addList(ListNode *list1, ListNode *list2);

#endif // LINK_LIST_H