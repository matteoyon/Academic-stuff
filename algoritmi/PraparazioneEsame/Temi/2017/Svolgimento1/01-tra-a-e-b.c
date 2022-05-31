#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <time.h>


struct bit_node {
  int item;
  struct bit_node *l, *r;
};

typedef struct bit_node *Bit_node;

// prototipi delle funzioni generali su alberi binari
Bit_node bit_new( int item );
void bit_printassummary( Bit_node p, int spaces );

// prototipi delle funzioni su alberi binari di ricerca
int bist_search( Bit_node p, int k );
void bist_insert( Bit_node *r, int item );



/***********************************************************************
INSERIRE QUI LA FUNZIONE MAIN E EVENTUALI ALTRE FUNZIONI AGGIUNTIVE
**********************************************************************/
void printNode(Bit_node p);
void myInorder(Bit_node p, int min, int max);


int main( void ){

    
    Bit_node *t;
    int v,min,max;
    while(1>0){
        scanf("%d", &v);
        if(v == 0)
            break;
        bist_insert(t,v);
    }

    scanf("%d %d", &min, &max);

    myInorder(*t,min,max);
    return 0;
}

void printNode(Bit_node p){
    printf("%d ", p -> item);
    return;
}

void myInorder(Bit_node p, int min, int max){
    if(p){
        int i = p->item;

        if (i < min)
            myInorder(p->r,min,max);
        else if (i > max)
            myInorder(p->l,min,max);
        else{
            myInorder(p->l,min,max);
            printNode(p);
            myInorder(p->r,min,max);
        }
        
        /*
        myInorder(p->l,min,max);
        if(p->item >= min && p->item <= max)
            printNode(p);
        myInorder(p->r,min,max);
        return;
        */
    }
}

/*************************************************************
Implementazione delle funzioni generali su alberi binari
***************************************************************/

Bit_node bit_new( int item ) {
  Bit_node new = malloc( sizeof( struct bit_node ) );

  if ( new == NULL ) {
    printf( "err malloc\n" );
    exit(-1);
  }

  new -> l = new -> r = NULL;
  new -> item = item;
  return new;
}


void bit_printassummary( Bit_node p, int spaces ){
  int i;
  for ( i = 0; i < spaces; i++ )
    printf( "  " );
  printf( "*" );
  if (!p)
    printf( "\n" );

  else {
    printf( "%d\n", p -> item );
    if ( p -> l || p -> r ) {
      bit_printassummary( p -> l, spaces + 1 );
      bit_printassummary( p -> r, spaces + 1 );
    }
  }
}


/**************************************************************************
* Implementazione delle funzioni specifiche su alberi binari di ricerca
*************************************************************************/

int bist_search( Bit_node p, int k ) {
  if ( p ) {
    while ( p && ( k != p -> item ) )
      p = k < p -> item ? p -> l : p -> r;
  }
  if ( p == NULL ) return 0; // 0 e' usato come valore speciale (item NULL)
  else return p -> item;
}

// assumo che item non sia già nell'albero
void bist_insert( Bit_node *r, int item ) {
  Bit_node f, p = *r, new = bit_new( item );

  if ( p == NULL ) {
    /* inserisco nell'albero vuoto */
    *r = new;
    return;
  }

  while ( p != NULL ) {
    if ( item < p -> item ) {
      f = p;
      p = p -> l;
    }

    else { // quindi  item > p -> item
      f = p;
      p = p -> r;
    }
  }

/* f e' il padre del nuovo nodo */
  if ( item < f -> item ) {
    f -> l = new;
   }
  else
    f -> r = new;
}