

struct listnode {
  struct listnode *next;
  int v;
};


struct struttura{
	struct listnode *a; // testa
	struct listnode *b; // coda
};



struct struttura *createStruttura(){
	struct struttura *str = malloc( sizeof (struct struttura));
	str -> a = NULL; // testa
	str -> b = NULL; // coda

	return str;
}

void f1( struct struttura *str, int i ){ // inserimento in coda con caso di test avuota
	struct listnode *new = malloc( sizeof( struct listnode ));
	new -> v = i;
	new -> next = NULL;

	if ( str -> a == NULL ) 
		str -> a = new;
	else 
		str -> b -> next = new;

	str -> b = new;
}

int f2( struct struttura *str ){ // pop di uno stack, rimuove lemento imn testa
	struct listnode *h = str -> a;
	int v = h -> v;
	if ( str -> b == h ) {
		str -> b = NULL;
	}
	str -> a = h -> next;
	free( h );
	return v;
}

int isEmpty( struct struttura *str ) {
	if ( str== NULL || str -> a == NULL)
		return 1;
	else
		return 0;
}

