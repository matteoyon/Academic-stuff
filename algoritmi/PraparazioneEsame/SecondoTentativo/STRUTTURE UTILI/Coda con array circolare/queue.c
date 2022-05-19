#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue newQueue(){
    Queue new = malloc(sizeof(Queue));
    new -> virtualSize = 0;
    new -> realSize = 2;
    new -> array = calloc(2,sizeof(int));
    new -> front = 1;
    new -> rear = 0;

    return new;
}


enqueue(Queue E, int i){

};

Queue dequeue(){

};

int frontValue(Queue){

};

int isEmpty(Queue){

};

void printQueue(Queue){

};