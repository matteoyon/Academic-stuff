/*
COMPRENSIONE DEL CODICE:
1) a)  build restituisce un nodo che contiene l'ultima lettera della stringa w e che
	   punta a un nodo che contiene la penultima e l'ultima lettera che punta a un 
	   nodo che contiene terzultima, penultima e ultima lettara di w...
   b) quante lettere ha w
   c) controlla che la prima lettera della stringa contenuta in l non sia '\0'
      e che la seconda lo sia invece. quindi che la stringa abbia una sola lettera
   d) mette nel nuovo il valore del vecchio vettore di char senza il primo char

2) fstring, se usata dopo build e flist, unisce la parola completa a alla parola senza la prima lettera, alla
   parola senza le prime due lettere... (ciao -> ciao+iao+ao+o)
   ripercorre la lista creata dalle altre due funzioni ma al contrario, lo fa
   in maniera ricorsiva, *w deve essere vuoto e la lista deve essere generata dalle
   altre due funzioni. 
*/

//SCRITTURA DEL CODICE:
#include <stdio.h>
#include <stdlib.h>

#define N 100

//1
typedef struct node {
	char *w;
	struct node * next;
} *Node;

int main() {
			
}

//2
char *fstring_iter(char *w, Node l) {

	while (l -> next != NULL) {
		l = l -> next;
	}
	char *a = l -> w;
	
	//char *stringa = malloc(N);
	int counter = 0;
	for (int i = 0; a[i] != '\0'; i++ ) {
		for (int j = i+1; a[j] != '\0'; j++ ) {
			w[counter] = a[j];
			counter++;
			//boh
		}
	}

	return w;
}


//3

Node flist( Node l ) {
	if ( l -> w[0] == '\0' )
		return l;
	Node n = malloc( sizeof(struct node) );
	for (int )
	n -> w = ( a )
	n -> next = l;
	return flist( n );		
}

Node build2( char *w ) {
	// invar
	Node lista = malloc (sizeof(struct node) );
	lista -> w = w;
	lista -> next = NULL;
	return flist( lista );
}
