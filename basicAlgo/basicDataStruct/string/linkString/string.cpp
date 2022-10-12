/*
 * @Author: yh
 * @Date: 2022-02-20 23:08:13
 * @LastEditTime: 2022-05-21 02:38:01
 * @Description:
 * @FilePath:
 * \algorithm\basicAlgorithms\basicDataStruct\string\linkString\string.cpp
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string.h"

Status initString(LString &string) {
    string.head = (Chunk *) malloc(sizeof(Chunk));
    if (!string.head) {
        exit(EXIT_FAILURE);
    }
    string.tail = nullptr;
    string.head->next = string.tail;
    string.currentLength = 1;
    return 0;
}

int getLength(LString string) { return string.currentLength; }

Status clear(LString &string) {
    Chunk *pHead = string.head;
    while (string.currentLength) {
        Chunk *tmp = pHead;
        pHead = pHead->next;
        if (tmp) {
            free(tmp);
            tmp = nullptr;
        }
        --string.currentLength;
    }

    string.head = string.tail = nullptr;
    string.currentLength = 0;
    return 0;
}

Status concat(LString &string, LString firstString, LString secondString) {
    if (string.head) {
        free(string.head);
        string.head = nullptr;
    }

    string.head =

    return 0;
}

Status subString(LString subString, LString string, int pos, int len) {

    return 0;
}
