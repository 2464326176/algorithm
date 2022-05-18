//**************************
// Author:  yh
// Time:    2022/2/18
//**************************

#ifndef CESSENCE_QUEUE_H
#define CESSENCE_QUEUE_H

#include "../common/dataType.h"
typedef int ElemType;

typedef struct QNode{
    ElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;


Status initQueue(LinkQueue &queue);
Status destroyQueue(LinkQueue &queue);
bool isEmptyQueue(LinkQueue &queue);
Status getQueueLength(LinkQueue &queue);
Status getHeadNode(LinkQueue &queue, ElemType &elem);
Status enQueue(LinkQueue &queue, ElemType elem);
Status deQueue(LinkQueue &queue, ElemType &elem);
Status traverseQueue(LinkQueue &queue);



#endif //CESSENCE_QUEUE_H
