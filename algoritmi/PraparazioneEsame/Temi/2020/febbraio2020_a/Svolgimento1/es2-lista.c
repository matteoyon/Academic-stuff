//DA FINIRE E CORREGGERE DIOBONO

#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	struct node *next;
	char *w;
} *Node;

char *fstring_iter( char *w, Node l ){
	int vLen = 0, rLen = 5;
	char *s = calloc(rLen, sizeof(char));

	for(char *i = w; i != NULL; i++){
		if(vLen >= rLen){
			rLen *= 2;
			s = realloc(s,rLen);
		}

		if(*i == '\0') break;
		s[vLen] = *i;
		vLen++;
	}

	while(l){
		for(char *i = l -> w; i != NULL; i++){
			if(vLen >= rLen){
				rLen *= 2;
				s = realloc(s,rLen);
			}

			if(*i == '\0') break;
			
			s[vLen] = *i;
			vLen++;
		}

		l = l->next;
	}

	return s;
}

char *fstring( char *w, Node l ){
	if ( l -> next == NULL )
		return strcat( w, l -> w );

	return strcat( fstring( w, l -> next ), l -> w );
}

Node flist( Node l ) {
	if ( l -> w[0] != '\0' && l -> w[1] == '\0' )
		return l;
	Node n = malloc( sizeof(struct node) );
	n -> w = ( l -> w ) + 1;
	n -> next = l;
	return flist( n );		
}

Node build( char *w ) {
	Node lista = malloc (sizeof(struct node) );
	lista -> w = w;
	lista -> next = NULL;
	return flist( lista );
}

Node flist2( Node r ) {
	Node l = r;

	while(l -> next) l = l-> next;

	if ( l -> w[0] != '\0' && l -> w[1] == '\0' )
		return r;
	Node n = malloc( sizeof(struct node) );
	n -> w = ( l -> w ) + 1;
	l -> next = n;
	return flist2( r );		
}

Node build2( char *w ) {
	Node lista = malloc (sizeof(struct node) );
	lista -> w = w;
	lista -> next = NULL;
	return flist2( lista );
}

/**
 * [1]
 * a) build restituisce il nodo di testa di una
 * lista concatenata di stringhe.
 * 
 * b) flist viene invocata un numero di volte pari alla lunghezza
 * della stringa data in argomento alla chiamata di build (escluso '\0')
 * 
 * c) Viene verificato se la il nodo in argomento a flist contiene
 * una stringa di lunghezza 1
 * 
 * d) assegna al campo w del nodo n l'indirizzo della stringa contenuta nel nodo
 * in argomento shiftata di un carattere in avanti.
 * 
 * [2]
 * ritorna una stringa risultato della concatenazione delle stringhe nella lista
 * nel secondo argomento con un prefisso specificato nel primo argomento
 * 
 */

int main(){
	
	char word[20] = "";
	printf("%s\n", fstring(word,build2("hello")));

	return 0;
}