#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define N 100
 
char cifra( char c, int k );
 
int main( int argc, char *argv[] ) {
 
  int k, i = 0;
  char op = *argv[1];
  char testo[N];
  char modificato[N];
 
 
  while ( ( testo[i] = getchar() ) != '\n' ) {
    i++;
  }
 
  scanf( "%d", &k );
  if ( op == 'D' )
    k = -k;
 
 
  i = 0;

  while ( testo[i]  != '\0' ) {
    modificato[i] = cifra( testo[i], k );
    i++;
  }
  modificato[i] = '\0';
 
 
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
    /*
    for (int j=1; j<=k; j++) {
      if ( c != 'z' )
        c++;
      else
        c = 'a';
    }
    return c;
    */
    
    if (c<='Z'){
      c -= 'A';
      c = (c+k)%('Z'-'A');
      c += 'A';
    }else{
      c -= 'a';
      c = (c+k)%('z'-'a');
      c += 'a';
    }

    return c;
    
  }
 
  else return c;
}