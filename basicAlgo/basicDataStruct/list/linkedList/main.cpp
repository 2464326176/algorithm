//**************************
// Author:  yh
// Time:    2022/2/16
//**************************
#include <iostream>
#include "linkedList.h"

int main() {
    LinkList list;
    ElemType elem;
    initList(list);
    printList(list);

    headInsertListNode(list, 2);
    headInsertListNode(list, 6);
    tailInsertListNode(list, 8);
    insertListNode(list, 3, 9);
    printList(list);

    deleteListNode(list, 1, elem);
    printf("elem: %d\n", elem);
    printList(list);

    destroyList(list);
    printList(list);

    return 0;
}