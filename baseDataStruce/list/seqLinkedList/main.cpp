//**************************
// Author:  yh
// Time:    2022/2/17
//**************************
#include <stdio.h>
#include "seqLinkedList.h"

int main() {
    SqList sqList;
    ElemType elem = 0;

    initList(sqList);

    insertList(sqList, 1, 2);
    insertList(sqList, 2, 6);
    insertList(sqList, 3, 3);
    insertList(sqList, 4, 4);
    insertList(sqList, 5, 1);

    printfList(sqList);
    deleteList(sqList, 1, elem);
    printfList(sqList);

    int pos = getElemPos(sqList, 6);
    printf("pos: %d", pos);

    destroyList(sqList);
    return 0;
}