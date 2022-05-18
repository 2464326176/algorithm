//**************************
// Author:  yh
// Time:    2022/2/18
//**************************
#include <cstdlib>
#include <cstdio>
#include "queue.h"

Status initQueue(LinkQueue &queue) {
    queue.front = queue.rear = (QueuePtr)malloc(sizeof(QueuePtr));

    if(!queue.front) {
        exit(ERROR);
    }

    queue.front->next = nullptr;
    return EXIT_SUCCESS;
}

Status destroyQueue(LinkQueue &queue) {
    while(queue.front) {
        queue.rear = queue.front->next;
        free(queue.front);
        queue.front = queue.rear;
    }

    return EXIT_SUCCESS;
}

bool isEmptyQueue(LinkQueue &queue) {
    if(queue.front == queue.rear) {
        return true;
    }
    return false;
}

Status getQueueLength(LinkQueue &queue) {
    if(queue.front == queue.rear) {
        return 0;
    }

    int ret = 0;
    QueuePtr p = queue.front;

    while(p != queue.rear) {
        p = p->next;
        ++ret;
    }
    return ret;
}

Status getHeadNode(LinkQueue &queue, ElemType &elem) {
    if(queue.front == queue.rear) {
        return 0;
    }

    elem = queue.front->next->data;
    return EXIT_SUCCESS;
}

Status enQueue(LinkQueue &queue, ElemType elem) {
    QueuePtr p = (QueuePtr) malloc(sizeof(QNode));

    if(!p) {
        exit(OVERFLOW);
    }

    p->data = elem;
    p->next = nullptr;
    queue.rear->next = p;
    queue.rear = p;
    return EXIT_SUCCESS;
}

Status deQueue(LinkQueue &queue, ElemType &elem) {
    if(queue.front == queue.rear) {
        return EXIT_FAILURE;
    }

    QueuePtr p = queue.front->next;
    elem = p->data;

    queue.front->next = p->next;

    if(queue.rear == p) {
        queue.rear = queue.front;
    }

    free(p);
    p = nullptr;
    return EXIT_SUCCESS;
}

Status traverseQueue(LinkQueue &queue) {
    if(queue.front == queue.rear) {
        return EXIT_FAILURE;
    }

    QueuePtr p = queue.front->next;

    while(p != queue.rear) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);

    return 0;
}
