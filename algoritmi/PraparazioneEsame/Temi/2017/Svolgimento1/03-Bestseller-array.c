#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//FORMATO: title TAB author TAB publisher TAB mm/dd/yyyy TAB Fiction
typedef struct date{
    short int day;
    short int month;
    short int year;
} *Date;

typedef struct bestseller {
    char *titolo;
    char *autore;
    char *editore;
    Date data;
    char *genere;
} *Bs;


Bs read_bs(); // legge una riga con i dati di un bestseller
void print_bs( Bs b); // stampa i dettagli di un bestseller


int main(){
  char comando = '\0';
  short int d, m, y;
  int vSize = 0;
  int rSize = 2;

  Bs *array = malloc(rSize * sizeof(Bs));

  while( (comando = getchar()) != 'f' ) {
    switch( comando ) {

    case '+': // seguito da riga con dettagli su un bestseller
      if(vSize >= rSize){
          rSize *= 2;
          array = realloc(array,rSize * sizeof(Bs));
      }
      array[vSize] = read_bs();
      vSize++;
      
     //printf("DATA: %d/%d/%d\n", array[vSize-1]->data->month,array[vSize-1]->data->day,array[vSize-1]->data->year);

      break;

    case '?': // seguito da una data. stampa il libro bestseller in quella data
      scanf( " %hd/%hd/%hd", &m, &d, &y);
      for(int i = 0; i < vSize; i++){
          Bs b = array[i];

        if(   
            b->data->day == d &&
            b->data->month == m &&
            b->data->year == y
        )
            print_bs(b);

      }
      
      break;

    }
  }

  return 0;
}





// legge da standard input fino a quando non trova un carattere di tabulazione (e ignorando gli spazi iniziali)
char *read_tab( void ) {
  char *p, c;
  int size = 2;
  int n = 0;

  p = malloc( size );
  while ( isspace( c = getchar() ) )
      ;

  while ( c != EOF ) {

    /* se ho terminato lo spazio, raddoppio l'allocazione */
    if ( n >= size ) {
      size *=2;
      //printf( "\nnew size = %d\n", size );
      p = realloc( p, size * sizeof(char) );
    }

    /* memorizzo l'n-esimo elemento */
    if ( c == '\t' || c == '\n' ) { /* se leggo '\t', memorizzo '\0' e interrompo */
      p[n] = '\0';
      break;
    }

    p[n++] = c;
    c = getchar();
  }

  //printf( "%s\n", p );
  return p;
}

// legge una riga con i dati di un bestseller e la memorizza in una struttura di cui restituisce l'indirizzo
Bs read_bs(){
  Bs toReturn = malloc(sizeof(struct bestseller));

  toReturn -> titolo = read_tab();
  toReturn -> autore = read_tab();
  toReturn -> editore = read_tab();

  Date d = malloc(sizeof(struct date));
  //char *american = read_tab();

  
  char t;
  while(isspace(t = getchar()));
  ungetc(t,stdin);

  scanf("%hd/%hd/%hd", &(d -> month), &(d -> day), &(d -> year));

  toReturn -> data = d;

  toReturn -> genere = read_tab();

  return toReturn;
}

// stampa i dettagli di un bestseller
void print_bs( Bs b)
{
    printf("%hd/%hd/%hd: %s - %s\n", b->data->month, b->data->day, b->data->year, b->titolo, b->autore);
}