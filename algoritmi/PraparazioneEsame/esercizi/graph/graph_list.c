#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int key;
    struct node *next;
} *Node;

typedef struct graph {
    int n, m; //n nodi e m vertici
    Node *list;
}*Graph ;



/* crea un grafo con n nodi */
Graph graph_new ( int n ){
    Graph g = malloc(sizeof(struct node));
    g -> n = n;
    g -> m = 0;
    g -> list = calloc(n,sizeof(Node));
};

/* distrugge il grafo g */
void graph_destroy ( Graph g ){
    for(int i = 0; i < g -> n; i++){
        for(Node n = g -> list[i]; n != NULL;){
            Node temp = n;
            n = temp -> next;            
            free(temp);
        }
    }
    free(g -> list);
    free(g);
    g = NULL;
};
/* inserisce l’arco (v,w) nel grafo g */
void graph_edgeinsert ( Graph g , int v , int w ){
    Node new = malloc(sizeof(struct node));
    new -> key = w;
    new -> next = g -> list[v];

    g -> list[v] = new;

    g -> m += 1;
};

/* legge da standard input un grafo (specificare il formato!!) */
Graph graph_read ( void );
/* stampa su standard output un grafo (specificare il formato!!) */
void graph_print ( Graph g );

int main(){
    
    Graph g = graph_new(10);
    graph_edgeinsert(g,0,2);
    graph_edgeinsert(g,8,4);
    graph_edgeinsert(g,2,9);
    graph_edgeinsert(g,5,4);

    for(int i = 0; i < g -> n; i++){
        printf("[%d]->", i);
        for(Node n = g -> list[i]; n != NULL; n = n-> next){
            printf("[%d]->", n -> key);
        }
        printf("[NULL]\n");
    } 

    graph_destroy(g);

    return 0;
}

#endif