#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
 
#define HASHSIZE 10
 
// PRODOTTI
typedef struct prodotto {
    char *key;
    char *desc;
    int price;
} *Item;
 
 
Item newItem( char *key ) {
  Item p = malloc(sizeof(struct prodotto));
  p -> key = malloc(HASHSIZE*10);
  p -> desc = malloc(HASHSIZE*10);
  strcpy(p -> key, key);
  return p;
}
 
void printItem( Item p ){
 if(p){
    printf("\nkey: %s,\tdescrizione: %s,\tprezzo: %d", p -> key, p -> desc, p-> price);
 }
}
 
 
 
// ELEMENTO DI LISTA
struct element {  // definizione di un elemento della lista
  Item item;
  struct element *next;    // prossimo elemento
};
 
// LISTA DI COLLISIONE
typedef struct element *List;
Item list_find( List c, char *w );
List list_insert( List c, Item p ); // crea nuovo elemento, lo inserisce in testa alla catena e restituisce l'indirizzo della nuova testa
void list_print( List h );
 
// DIZIONARIO IMPLEMENTATO CON HASHTABLE
typedef struct ht {
  List array[HASHSIZE];
  int count; // parole inserite
} *Dict;
 
Dict dict_init ();
void dict_print( Dict h );
Item dict_lookup ( Dict t, char *key ); // Restituisce l'Item con chiave key, oppure NULL se key non è nel dizionario
void dict_add( Dict t, Item p ); // aggiunge l'item p nel dizionario
unsigned long hash ( char *s ); // funzione di hash
 
 
/* MAIN
**************/
 
int main(){
  char comando[3] = "";
  Dict h = dict_init();
 
 
  while( 1 ) {
    scanf( "%s", comando );
    //printf( "LETTO COMANDO <%s>\n", comando );
    if ( comando[0] == 'f' ) // uscita
      return 0; 
 
 
    if ( isdigit( comando[0] ) ) { // calcola somma dei prezzi dei prodotti che seguono
      int n = atoi(comando);
      int tot = 0;
      int prods = 0;
      Item p;
      char temp[10];
        for(int i = 0; i < n; i++){
            scanf(" %s10", temp);
            p = dict_lookup(h,temp);
            if(p){
                tot += p -> price;
                prods++;
            }else{
                printf("Non esiste il prodotto <%s>\n", temp);
            }
        }
      printf( "Il totale è %d per %d prodotti\n", tot, prods );
    }
 
    else{
      char key[10], descrizione[10];
      int prezzo;
      Item p;

      switch( comando[0] ) {
 
      case '+': // aggiungo o aggiorno prodotto
        scanf( "%s%s%d", key, descrizione, &prezzo);
        

        if(p = dict_lookup(h,key)){
        }else{
            p = newItem(key);
            dict_add(h,p);
        }
        
        strcpy(p -> desc, descrizione);
        p -> price = prezzo;

        break;
 
 
      case '!': // cerca il prezzo di un prodotto
        scanf( "%s", key);

        if(p = dict_lookup(h,key)){
            printf("Il prezzo di <%s> è %d\n", p -> key, p -> price);
        }else{
            printf("Non esiste il prodotto <%s>\n", key);
        }
        break;
 
      case 'p':
        dict_print(h); 
        break;
      }
    }
  }
 
  return 0;
}
 
 
 
 
 
 
 
/* FUNZIONI DI GESTIONE DELLA CHAIN (lista)
*******************************************/
 
 
// Inserisce in testa e restituisce la nuova testa.
List list_insert( List h, Item p ){
  struct element *new = malloc( sizeof( struct element ) );
  new -> item = p;
  new -> next = h;
  return new;
}
 
 
/* Cerca un item con chiave key nella list c. Se lo trova ne restituisce l'indirizzo, altrimenti restituisce NULL. */
Item list_find( List c, char *key ){
  struct element *p;
  for( p = c  ; p!= NULL; p = p->next ) {
    if( strcmp( p -> item -> key, key ) == 0 ) {
      return p -> item;
    }
  }
  return NULL;
}
 
 
/* Stampa gli elementi della Lista di trabocco */
void list_print( List h ) {
  /* h e' usato  per attraversare la  lista */
  for( ; h!= NULL; h=h->next){
    printItem( h -> item );
    putchar('\n');
  }
}
 
 
 
 
/* FUNZIONI DI GESTIONE DELLA HASHTABLE
*******************************************/
 
 
// Crea una hastable di con HASHSIZE buckets
Dict dict_init () {
    Dict t = malloc ( sizeof ( struct ht ) );
    t -> count = 0;
 
    for ( int i = 0; i < HASHSIZE; i++ )
        t -> array[i] = NULL;
    return t;
}
 
// funzione di hash
unsigned long hash( char *str )
{
    unsigned long hash = 5381;
    int c;
 
    while ( (c = *str++) )
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
 
    return hash % HASHSIZE;
}
 
// cerca l'item con chiave key
Item dict_lookup ( Dict t, char *key ) {
    return list_find( t -> array[hash(key)], key );
}
 
 
// inserisce l'item nel dizionario
 void dict_add( Dict t, Item p ){
    int i = hash( p -> key);
    t -> array[i] = list_insert ( t -> array[i], p );
    t -> count++;
//    printArray( t -> array[i] -> ln_arr, t -> array[i] -> count );
}
 
 
 
// stampa il dizionario
 void dict_print( Dict t ){
  for ( int i =0; i < HASHSIZE; i++ ) {
    //printf( "[%d]:\t", i );
    list_print( t -> array[i]) ;
  }
}