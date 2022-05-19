#include <stdio.h>
#include <stdlib.h>

typedef struct biNode{
    int info;
    struct node *next;
    struct node *prev;
} *BiNode;

typedef struct biList{
    BiNode first;
    BiNode last;
} *BiList;

BiList append(BiList list, int n){
    BiNode newNode;
    newNode -> info = n;
    newNode -> prev = list -> last;
    list -> last = newNode;

    return list;
}

BiList prepend(BiList list, int n){
    BiNode newNode;
    newNode -> info = n;
    list -> first -> prev = newNode;
    newNode -> next = list -> first;
    list -> first = newNode;

    return list;
}

int main(){
    BiList first, last; 
}