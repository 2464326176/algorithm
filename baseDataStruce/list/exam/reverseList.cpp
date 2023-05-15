/*
 * @Author: yh
 * @Date: 2022-05-08 09:22:58
 * @LastEditTime: 2023-03-13 21:50:49
 * @Description:
 * @FilePath: \algorithm\baseDataStruce\list\exam\reverseList.cpp
 */

#include "linkList.h"

int main() {
    ListNode *pHeadNode = constructList();
    printLinkNode(pHeadNode);
    reverseList(pHeadNode);
    printLinkNode(pHeadNode);
    return 0;
}