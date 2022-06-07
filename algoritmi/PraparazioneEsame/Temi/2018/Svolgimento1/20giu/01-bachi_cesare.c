#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define N 100
 
char cifra( char c, int k );
 
int main( int argc, char *argv[] ) {
 
  int k, i = 0;
  char op = *argv[1];//Da deferenziare con *. Inoltre argv[0] corrisponde al nome del programma, argv[1] al primo argomento
  char testo[N];
  char modificato[N]; //usare direttamente un array mi permette di non dover usare una malloc
 
 
  while ( ( testo[i] = getchar() ) != '\n' ) {
    i++;
  }

  
  scanf( "%d", &k );
  if ( op == 'D' )
    k = k * -1;
 
 
  i = 0;
  while ( testo[i]  != '\n' ){ //invece di finire al terminatore, finisco il loop al '\n' (presente perchè conseguenza della riga 17)
    modificato[i] = cifra( testo[i], k );
    i++;
  }
  modificato[i] = '\0'; //Inserisco terminatore di stringa
 
 
  printf ( "Testo inserito: %s\n", testo );
  if ( op == 'C')
    printf ( "Testo cifrato:" );
  else
    printf ( "Testo decifrato:");
  printf ( " %s\n", modificato );
 
  return 0;
 
}
 
 
char cifra( char c, int k) {
 
  if ( isalpha( c ) ) {
    
    int g = 'A' - 'a'; //per gestire il caso k numero negativo definisco un intero g per calcolare il modulo.
    int h;

    if(c >= 'a'){ //Inserisco un if per distinguere il caso minuscolo o maiuscolo
      h = 'a';
    }else{
      h = 'A';
    }  

    c = (c - h + k)%g + h;
  }
 
  return c;
}