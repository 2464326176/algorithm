//**************************
// Author:  yh
// Time:    2022/2/18
//**************************

#include "queue.h"
#include <iostream>


int main() {
    LinkQueue queue;
    int value = 0;
    initQueue(queue);
    printf("queue length: %d, value: %d\n", getQueueLength(queue), value);

    enQueue(queue, 5);
    enQueue(queue, 7);
    enQueue(queue, 3);
    enQueue(queue, 2);

    traverseQueue(queue);

    deQueue(queue, value);
    printf("queue length: %d, value: %d\n", getQueueLength(queue), value);
    traverseQueue(queue);
    printf("queue is empty: %d\n", isEmptyQueue(queue));

    deQueue(queue, value);
    printf("queue length: %d, value: %d\n", getQueueLength(queue), value);
    deQueue(queue, value);
    printf("queue length: %d, value: %d\n", getQueueLength(queue), value);
    deQueue(queue, value);
    printf("queue length: %d, value: %d\n", getQueueLength(queue), value);

    printf("queue is empty: %d\n", isEmptyQueue(queue));

    destroyQueue(queue);
    return 0;
}