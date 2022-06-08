#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int *createJumps( int, int );


int main() {
	int r, c; 
	scanf( "%d %d", &r, &c);

	int *jump = createJumps( r, c );

	int n = r*c ;
	printf( "%d\n", n );
	for ( int i = 1; i <= n; i++ )	
		printf( "%d ", jump[i] );
	printf( "\n" );
	
	return 0;
}

int *createJumps( int r, int c ){
	int n = r * c;
	int *jump = calloc( n, sizeof(int) ); // con una calloc inizializzo già tutto a 0

	int s, m, t;
	scanf( "%d", &s );

	while ( s > 0) {	
		scanf( "%d %d", &m, &t );
		jump[m] = t; //è la casella m-1 che ti porta a t-1, non t ad m
		s--;//devo decrementare s altrimenti non esco dal loop
	}

	
	int l, start, len;
	scanf( "%d", &l );

	for (int i = 0; i < l; i++ ) {	
		scanf( "%d %d", &start, &len );
		int row, col, end;
		row = r - 1 - (start-1)/c;
		col = (start-1) % c;
		if ( ( row + r ) % 2 == 0 ) 
			col = c - col;

		row = row - len + 1;
		end = c * ( r - row );
		if ( ( row + r ) % 2 == 0  )
			end -= col - 1; //bisogna considerare l'offset di 1
		else 
			end += col - c + 1;
		
		jump[start] = end-1;
	}


	return jump;
}








