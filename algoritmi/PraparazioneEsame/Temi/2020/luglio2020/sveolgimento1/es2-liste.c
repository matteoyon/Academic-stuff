#include <stdio.h>
#include <stdlib.h>

struct node {
    int item ;
    struct node * next ;
};

typedef struct {
    struct node * head ;
} * List ;

typedef struct dNode{
    int item;
    struct dNode *next;
    struct dNode *prev;
} *DNode;

typedef struct dList {
    DNode head;
    DNode tail;
} *DList;


void dlist_addAtEnd(DList l, int value){
    if(l){
        DNode new = malloc(sizeof(struct dNode));
        new -> item = value;
        new -> next = NULL;
        new -> prev = l -> tail;
        l -> tail -> next = new;
    }
}



void list_print(List l){
    for(struct node *n = l -> head; n != NULL; n = n -> next){
        printf("[%d]->");
    }
    printf("NULL\n");
}

void list_addAtEnd(List l, int value){
    if(l){
        struct node *new = malloc(sizeof(struct node));
        new -> item = value;
        new -> next = NULL;

        if(l -> head){
            struct node *last = l -> head;
            for(;last -> next != NULL; last = last -> next){}
            last -> next = new;
        }else{
            l -> head = new;
        }
    }
}

/**
 * 4)
 * La complessità in tempo di list_addAtEnd è lineare rispetto
 * alla lunghezza della lista a cui vogliamo aggiungere l'elemento
 * mentre quella di dlist_addAtEnd è costante
 * 
 * 
 * 5)
 * Data una lista concatenata e un valore intero, mistery
 * ritorna il nodo che nella lista precede il nodo contenente il valore indicato.
 * Se la lista è vuota ritorna NULL, mentre se l'elemento non è presente nella lista
 * viene ritornato l'ultimo elemento della lista.
 */
