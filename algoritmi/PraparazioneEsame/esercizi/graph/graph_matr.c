#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct graph{
    int n, m; //n = #vertici, m = #lati
    int **A; //Matrice di adiacenza
} *Graph;

/* crea un grafo con n nodi */
Graph graph_new ( int n ){
    int i;
    Graph g;

    //Allocazione dello spazio
    g = malloc(sizeof(struct graph));
    g->A = calloc(n, sizeof(int *));
    for(i = 0; i<n; i++){
        g->A[i] = calloc(n, sizeof(int));
    }
    g->n = n;
}

/* distrugge il grafo g */
void graph_destroy ( Graph g ){
    for(int i = 0; i < g->n; i++){
        /*
        for(int j = 0; j < g->n; j++){
            free(&(g->A[i][j]));
        }
        */
        free(g->A[i]);
    }
    free(g->A);
    free(g);
    g = NULL;
};

/* inserisce l’arco (v,w) nel grafo g */
void graph_edgeinsert ( Graph g , int v , int w ){
    if(g->A[v][w] == 0){
        g->A[v][w] = 1;
        g->m++;
    }else if(g -> A[v][w] == 1){
        printf("\nArco (%d,%d) già presente nel grafo", v,w);
    }
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
        for(int j = 0; j < g -> n; j++){
            printf("[%d] ", g->A[i][j]);
        }
        printf("\n");
    }

    graph_destroy(g);

    return 0;
}