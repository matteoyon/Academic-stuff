#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



struct element {  // elemento di lista
  char ch;
  struct element *next;    // prossimo elemento
};


struct graph {
  int n, m;
  struct element **A; // vettore delle liste di adiacenza
};

typedef struct graph *Graph;

Graph newGraph( int n ); /* alloca una struttura grafo con n nodi */
void addEdge( Graph g, char x, char y); /* inserisce l'arco x -> y */
void printGraph( Graph g ); /* stampa su standard output le liste di adiacenza di g */
void printList( Graph g, char c ); /* stampa su standard output le liste di adiacenza di g */


// funzione read
Graph read(){
    int m;

    printf("Quante regole? ");
    scanf("%d", &m);
    printf("\nScrivi le tue regole: ");
    
    Graph g = newGraph(m);

    /*
    char c;
    while((c = getchar()) != '\n'){
        if(!isspace(c)){
            addEdge(g,c,getchar());
        }
    }*/

    char c, d;
    for(int i = 0; i < m; i++){
        scanf(" %c%c", &c , &d);
        addEdge(g,c,d);
    }

    return g;
}


// funzione followers
void followers(Graph g, char k){
    printf("\n");
    struct element **al = g -> A;
    struct element *curr;
    for ( curr = al[k-'A']; curr != NULL; curr = curr -> next ) {
		printf( "%c", curr -> ch );
	}
}


// funzione max
void max(Graph g){
    int n = g -> n;
    int v = 0;
    int a[n];
	struct element **al = g -> A;
	struct element *curr;

    for ( int i = 0; i < n; i++ ) {
        a[i] = 0;
		for ( curr = al[i]; curr != NULL; curr = curr -> next ) {
			a[i]++;
		}
		if(a[i]>v) v = a[i];
	}

    printf("\n");
    for ( int i = 0; i < n; i++ ){
        if(a[i] == v){
            printf( "%c", i+'A' );
        }
    }

}


int main( int argc, char *argv[]){
  Graph g = read();
  char c;
  scanf( " %c", &c );
  followers(g,c);
  max(g);
  return 0;
}




/* crea una struttura grafo con n nodi */
Graph newGraph( int n ){

	Graph g = malloc(sizeof(struct graph));
	if(!g) {
        	fprintf(stderr,"Errore di Allocazione\n");
	        exit(EXIT_FAILURE);
	}
	g -> n = n;
	g -> A = calloc( n, sizeof( struct element* ) ); // vettore delle liste di adiacenza: g -> A [i] e' la lista dell'i-esimo nodo
	return g;
}



// inserimento in liste di adiacenza
struct element *list_insert( struct element *list, char ch ) {
	struct element *new = malloc( sizeof( struct element ) );
	new -> ch = ch;
	new -> next = list;
	return new;

}

// inserisce nel grafo l'arco x -> y
void addEdge( Graph g, char x, char y){
  g->A[x-'A'] = list_insert(g->A[x-'A'],y);
}

/* stampa su standard output le liste di adiacenza di g */
void printGraph( Graph g ){
	printf( "\n************** stampo grafo\n" );
	int n = g -> n;
	struct element **al = g -> A;
	struct element *curr;

	printf( "%d nodi\n%d archi\n", n, g -> m );

	for ( int i = 0; i < n; i++ ) {
		printf( "%c:", 'A'+i );
		for ( curr = al[i]; curr != NULL; curr = curr -> next ) {
			printf( " %c", curr -> ch );
		}
		printf( "\n" );
	}
	printf( "fine stampa grafo *************************\n\n");

}