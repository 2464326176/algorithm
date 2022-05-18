//**************************
// Author:  yh
// Time:    2022/2/12
//**************************

#ifndef CESSENCE_LINKEDLIST_H
#define CESSENCE_LINKEDLIST_H
#include "../../common/dataType.h"


typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

Status initList(LinkList &list);
Status getElem(LinkList &list, int pos, ElemType &elem);
Status headInsertListNode(LinkList &list, ElemType elem);
Status tailInsertListNode(LinkList &list, ElemType elem);
Status insertListNode(LinkList &list, int pos, ElemType elem);
Status deleteListNode(LinkList &list, int pos, ElemType &elem);
Status destroyList(LinkList &list);
Status printList(LinkList &list);
#endif //CESSENCE_LINKEDLIST_H
