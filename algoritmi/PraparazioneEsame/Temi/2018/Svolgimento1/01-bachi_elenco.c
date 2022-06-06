#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

typedef char *String;
typedef struct{
  int size;
  int count;
  String *content;
} *Elenco;


int main( void ) {
  Elenco b = NULL;
  //int /*size = 4,*/ i = 0;
  char name[N+1] = "";

  b = malloc( sizeof(Elenco) );
  b -> size = 4;
  b -> count = 0;
  b -> content = calloc( b -> size, sizeof(char *) );

  while(1) {
    /*
    è opportuno riorganizzare il flusso in modo che la stringa FINE non venga
    memorizzata in coda all'array, ma che quando viene inserito il ciclo venga immediatamente interrotto.
    */
    scanf( "%s", name );
    if( strcmp( name, "FINE" ) == 0 ) break;

    /*
    Sostituisco b->count con i. In un uso più in generale del programma sarebbe stato meglio
    il contrario così che ogni elenco tenga traccia della propria dimensione, ma in questo specifico
    caso l'uso di i mi permette di non dover accedere ad un valore in una struct, ma in maniera più veloce ad una
    variabile del programma.
    */
    if ( b -> count == b -> size ) {
      b -> size *= 2;
      b-> content = realloc (b-> content, b -> size * sizeof(char *));
    }

    /*
    Nel programma originale andavo a memorizzare l'indirizzo di name all'interno di
    ogni elemento di content. Ne risulta che alla fine del programma ogni elemento di content punta
    all'ultimo elemento che viene memorizzato in name, ovvero "FINE".
    Occorre invece allocare lo spazio per una nuova stringa e copiare il contenuto di name,
    non il riferimento.
    */
    b -> content[b -> count] = malloc(N*sizeof(char));
    strcpy(b->content[b -> count], name);
    b -> count++;

  }

  for ( int k = 0; k < b -> count; k++ )
      printf( "%s\n", b -> content[k] );

  return 0;
}