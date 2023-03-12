//**************************
// Author:  yh
// Time:    2022/2/11
//**************************
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "seqLinkedList.h"

Status initList(SqList &list) {
    list.elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));

    if (!list.elem) {
        exit(OVERFLOW);
    }
    memset(list.elem, 0, LIST_INIT_SIZE * sizeof(ElemType));
    list.length = 0;
    list.listSize = LIST_INIT_SIZE;
    return EXIT_SUCCESS;
}

/*
 * Function description: insert elem before pos
 * @param list
 * @param pos
 * @param elem
 *
 * @return success or fail
 */
Status insertList(SqList &list, int pos, ElemType elem) {
    if ((pos < 1) || (pos > list.length + 1)) {
        return EXIT_FAILURE;
    }

    if (list.length >= list.listSize) {
        ElemType *newBase = (ElemType *) realloc(list.elem, (list.listSize + LIST_INCREMENT) * sizeof(ElemType));
        if (!newBase) {
            exit(OVERFLOW);
        }

        list.elem = newBase;
        list.listSize += LIST_INCREMENT;
    }

    ElemType *q = &list.elem[pos - 1];
    for (ElemType *p = &list.elem[list.length - 1]; p >= q; --p) {
        *(p + 1) = *p;
    }

    *q = elem;
    ++list.length;
    return EXIT_SUCCESS;
}

/*
 * Function description: delete elem before pos
 * @param list
 * @param pos
 * @param elem
 *
 * @return success or fail
 */
Status deleteList(SqList &list, int pos, ElemType &elem) {
    if ((pos < 1) || (pos > list.length + 1)) {
        return EXIT_FAILURE;
    }

    ElemType *p = &list.elem[pos - 1];
    elem = *p;
    ElemType *q = list.elem + list.length - 1;

    for (++p; p <= q; ++p) {
        *(p - 1) = *p;
    }

    --list.length;
    return EXIT_SUCCESS;
}

/*
 * Function description: search elem pos
 * @param list
 * @param elem
 *
 * @return elem pos
 */
Status getElemPos(SqList &list, ElemType elem) {
    int i = 1;
    ElemType *p = list.elem;

    while ((i < list.length) && !(*p++ == elem)) {
        ++i;
    }

    return i <= list.length ? i : 0;
}

/*
 * Function description: search elem of list
 */
Status printfList(SqList &list) {
    if ((nullptr == list.elem) || (list.length < 1)) {
        exit(INFEASIBLE);
    }
    for (int i = 0; i < list.length; ++i) {
        printf("%d ", *(list.elem + i));
    }
    printf("\n");
    return 0;
}

/*
 * Function description: clear the list, then set element value to zero
 */
Status clearList(SqList &list) {
    memset(list.elem, 0, sizeof(list.length));
    list.length = 0;
    return 0;
}

/*
 * Function description: destroy the list
 */
Status destroyList(SqList &list) {
    free(list.elem);
    list.elem = nullptr;
    list.length = 0;
    list.listSize = 0;
    return 0;
}
