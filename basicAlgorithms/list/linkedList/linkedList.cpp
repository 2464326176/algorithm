//**************************
// Author:  yh
// Time:    2022/2/12
//**************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

Status initList(LinkList &list) {
    list = (LinkList)malloc(sizeof(LinkList));

    if(nullptr == list) {
        exit(EXIT_FAILURE);
    }

    list->data = 0;
    list->next = nullptr;
    return EXIT_SUCCESS;
}

/*
 * Function description: get the element of pos position of the linked list
 * @param list
 * @param pos
 * @param elem out
 *
 * @return success or fail
 */
Status getElem(LinkList &list, int pos, ElemType &elem) {
    LinkList p = list;
    int j = 0;

    while(p && j < pos - 1) {
        p = p->next;
        ++j;
    }

    if(!p || j > pos) {
        return EXIT_FAILURE;
    }

    elem = p->next->data;
    return EXIT_SUCCESS;
}

/*
 * Function description: insert the element of pos position of the linked list
 * @param list
 * @param pos
 * @param elem
 *
 * @return success or fail
 */
Status insertListNode(LinkList &list, int pos, ElemType elem) {
    LinkList p = list;
    int j = 0;

    while((j < pos - 1) && p) {
        p = p->next;
        ++j;
    }

    if(!p || j > pos) {
        return EXIT_FAILURE;
    }

    LinkList tmpNode = (LNode*)malloc(sizeof(LNode));
    tmpNode->data = elem;
    tmpNode->next = p->next;
    p->next = tmpNode;
    ++list->data;
    return EXIT_SUCCESS;
}

/*
 * Function description: delete the element of pos position of the linked list
 * @param list
 * @param pos
 * @param elem out
 *
 * @return success or fail
 */
Status deleteListNode(LinkList &list, int pos, ElemType &elem) {
    LinkList p = list;
    int j = 0;
    while(p->next && j < pos -1) {
        p = p->next;
        ++j;
    }

    if(!(p->next) || j > pos - 1) {
        return EXIT_FAILURE;
    }

    LinkList tmpNode = p->next;
    p->next = tmpNode->next;
    elem = tmpNode->data;
    free(tmpNode);
    tmpNode = nullptr;
    --list->data;
    return EXIT_SUCCESS;
}

/*
 * Function description: destroy the List
 * @return success or fail
 */
Status destroyList(LinkList &list) {
    LinkList p = list;
    list = nullptr;

    while(p) {
        LinkList tmpNode = p;
        p = p->next;
        free(tmpNode);
        tmpNode = nullptr;
    }

    return EXIT_SUCCESS;
}

/*
 * Function description: printf the elements of the linked list
 * @return success or fail
 */
Status printList(LinkList &list) {
    if(!list) {
        exit(EXIT_FAILURE);
    }
    printf("list length: %d\n", list->data);

    LinkList p = list->next;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
    return EXIT_SUCCESS;
}

/*
 * Function description: head insert the linked list node
 * @return success or fail
 */
Status headInsertListNode(LinkList &list, ElemType elem) {
    LinkList p = list;
    LinkList tmpNode = (LinkList)malloc(sizeof(LinkList));
    tmpNode->data = elem;
    tmpNode->next = p->next;
    p->next = tmpNode;
    ++list->data;
    return EXIT_SUCCESS;
}

/*
 * Function description: tail insert the linked list node
 * @return success or fail
 */
Status tailInsertListNode(LinkList &list, ElemType elem) {
    LinkList p = list;

    while(p->next) {
        p = p->next;
    }

    LinkList tmpNode = (LinkList)malloc(sizeof(LinkList));
    tmpNode->data = elem;
    tmpNode->next = p->next;
    p->next = tmpNode;
    ++list->data;
    return EXIT_SUCCESS;
}
