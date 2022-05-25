#include <stdio.h>
#include <stdlib.h>
#include "grafi.h"

struct listnode{
    struct listnode *next;
    int v;
}

typedef struct graph{
    int n, m;
    struct listnode **A;
} *Graph;

//Crea un grafo con n nodi
Graph graphNew(int n){

    Graph g = malloc(sizeof(struct graph));
    if(!g){
        fprintf(stderr,"Errore di allocazione\n");
        exit(EXIT_FAILURE);
    }
    g -> n = n;
    g -> A = calloc(n, sizeof(struct listnode*));

    return g;
}


//Da implementare
void graphDestroy(Graph g){
      
}

//Funzione inserimento arco (v,w) (SUPPONIAMO GRAFO NON ORIENTATO)
void graphEdgeInsert(Graph g, int v, int w){
    g-> A[v] = listNodeInsert(g->A[v],w);
    g-> A[w] = listNodeInsert(g->A[w],v);
}

//Funzione di inserimento nodo
struct listnode *listNodeInsert(struct listnode *list, int v){
    struct listnode *new = malloc(sizeof(struct listnode));
    new -> v = v;
    new -> next = list;
    return new;
}