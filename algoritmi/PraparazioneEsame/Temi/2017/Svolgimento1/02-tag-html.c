#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef char *Item;

// Pila implementata come lista di interi (inserimento e cancellazione avvengono solo in testa)
struct element {
  Item value;
  struct element *next;
};
typedef struct element Element;

struct stack {
  Element *head;
};
typedef struct stack *Stack;

Stack init( void ); /* alloca lo spazio per una pila vuota e ne restituisce un puntatore */
void destroy( Stack ); /* svuota la pila liberando la memoria */
int is_empty( Stack ); /* restituisce 1 se la pila e' vuota, 0 altrimenti */
Item top( Stack ); /* se la pila non e' vuota, restituisce il top de1la pila; altrimenti esce con messaggio di errore. */
Item pop( Stack ); /* se la pila non e' vuota, estrae il top da1la pila e lo restituisce; altrimenti esce con messaggio di errore. */
void push( Stack, Item ); /* se c'e' spazio, aggiunge l'item alla pila; altrimenti esce con messaggio d'errore. */
void print_stack( Stack ); /* stampa il contenuto della pila, partendo dal top. */

/********************************************************************
INSERIRE QUI LA FUNZIONE MAIN E EVENTUALI ALTRE FUNZIONI AGGIUNTIVE
********************************************************************/


int main() {
  Stack s = init();
  char *c, *d;
  c = malloc(13*sizeof(char));
  scanf("%s13", c);
  while(strcmp(c,"\n")){
    printf("c is %s\n", c);
      if(c[0] == '<'){
        if(c[1] == '/'){
          print_stack(s);
          d = pop(s);
          printf("comparing %s and %s\n", d+1, c+2);
          if(strcmp(d+1, c+2) != 0){
            printf("NO1");
            return 0;
          }
        }else{
          printf("pushing %s into s\n", c);
          push(s,c);
          print_stack(s);
        }
      }else{
      if(is_empty(s)){
        printf("OK");
      }else{
        printf("NO2");
      }
      return 0;
    }
    c = malloc(13*sizeof(char));
    scanf("%s13", c);
  }
}




Stack init( void ) {
  Stack s = malloc( sizeof (struct stack) );
  if ( s == NULL ) {
    printf( "err malloc\n" );
    exit( EXIT_FAILURE );
  }
  s -> head = NULL;
  return s;
}


void print_stack( Stack s ) {
  Element *p;

  if ( s == NULL )
    return;

  printf( "Contenuto della pila: " );
  for ( p = s -> head; p != NULL; p = p -> next ) {
    printf( "%s", p -> value );
    printf( " " );
  }
  printf( ".\n" );
}


void destroy( Stack s ) {
  Element *p, *old;
  for ( p = s -> head; p != NULL; ) {
    old = p;
    p = p -> next;
    free( old );
  }
  free( s );
}


int is_empty( Stack s ){
  return ( s -> head == NULL );
}

Item top( Stack s ){
  if ( is_empty( s ) ) {
    printf( "err pop: pila vuota\n" );
    exit( EXIT_FAILURE );
  }

  return s -> head -> value;
}

void push( Stack s, Item item ){
  Element *new = malloc( sizeof( Element ) );

  if ( new == NULL ) {
    printf( "err push: pila piena!\n" );
    exit( EXIT_FAILURE );
  }

  new -> value = item;
  new -> next = s -> head;
  s -> head = new;
}


/******* COMPLETATE LA FUNZIONE POP: *************/

Item pop( Stack s ){
  Item item;
  Element *old;

  if ( is_empty( s ) ) {
    printf( "err pop: pila vuota\n" );
    exit( EXIT_FAILURE );
  }

  old = s -> head;
	item = old -> value;
  s -> head = old -> next;
  free(old);
  old = NULL;
	
  return item;
}