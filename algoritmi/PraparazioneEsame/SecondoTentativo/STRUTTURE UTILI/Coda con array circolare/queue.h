#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE

#include "queue.c"

typedef struct queue{
    int *array;
    int front;
    int rear;

    int virtualSize;
    int realSize;
} *Queue;

enqueue(Queue E, int i);

Queue dequeue();

int frontValue(Queue);

int isEmpty(Queue);

void printQueue(Queue); 

#endif