//**************************
// Author:  yh
// Time:    2022/2/11
//**************************

#ifndef CESSENCE_SEQLINKEDLIST_H
#define CESSENCE_SEQLINKEDLIST_H
#include "../../common/dataType.h"

#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10
typedef int ElemType;

typedef struct {
    ElemType *elem;
    int length;
    int listSize;
}SqList;

Status initList(SqList &list);
Status clearList(SqList &list);
Status destroyList(SqList &list);
Status insertList(SqList &list, int pos, ElemType elem);
Status deleteList(SqList &list, int pos, ElemType &elem);
Status getElemPos(SqList &list, ElemType elem);
Status printfList(SqList &list);

#endif //CESSENCE_SEQLINKEDLIST_H
