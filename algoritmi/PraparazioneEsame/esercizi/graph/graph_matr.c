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
        for(int j = 0; j < g->n; j++){
            free(g->A[i][j]);
        }
        free(g->A[i]);
    }
    free(g->A);
    free(g->m);
    free(g->n);
    free(g);
};

/* inserisce l’arco (v,w) nel grafo g */
void graph_edgeinsert ( Graph g , int v , int w ){
    if(g->A[v][w] == 0){
        g->A[v][w] = 1;
        g->m++;
    }else if(g-A[v][w] == 1){
        printf("\nArco (%d,%d) già presente nel grafo", v,w);
    }
};
/* legge da standard input un grafo (specificare il formato!!) */
Graph graph_read ( void );
/* stampa su standard output un grafo (specificare il formato!!) */
void graph_print ( Graph g );