#include <stdio.h>
#include <stdlib.h>

//-------------------------------------
//definizioni varie
typedef int Item;

struct bitnode {
	Item item ;
	struct bitnode *l , *r;
};

typedef struct bitnode * Bitnode;

void bit_printnode(Bitnode p, int spaces);
Bitnode bitnew(Item valore);
Bitnode bit_arr2tree(Item a[], int size, int j);
void bit_preorder(Bitnode p);
void bit_inorder ( Bitnode p );
void bit_postorder ( Bitnode p );
void bit_printassummary ( Bitnode p , int spaces );
//------------------------------------------

Bitnode bitnew(Item valore) {
	Bitnode nuovonodo = malloc(sizeof(struct bitnode));
	nuovonodo -> item = valore;
	return nuovonodo;
}

Bitnode bit_arr2tree(Item a[], int size, int j) {

	if (j >= size) {
		return NULL;
	} else {
		Bitnode new = bitnew(a[j]);
		new -> l = bit_arr2tree(a, size, 2*j+1);
		new -> r = bit_arr2tree(a, size, 2*j+2);
		return new;
	}

}

//-----------------------------------
// metodi che stampano
void bit_preorder(Bitnode p ){
	if ( p ) {
		bit_printnode(p, 0);
		bit_preorder(p -> l );
		bit_preorder( p -> r );
	}
}

void bit_inorder ( Bitnode p ){
	if ( p ) {
		bit_inorder ( p -> l );
		bit_printnode ( p, 0 );
		bit_inorder ( p -> r );
	}
}

void bit_postorder ( Bitnode p ){
	if ( p ) {
		bit_postorder ( p -> l );
		bit_postorder ( p -> r );
		bit_printnode ( p, 0);
	}
}

void bit_printnode(Bitnode p, int spaces) {
	for (int i = 0; i < spaces; i++) {
		printf(" ");
	}
	
	if (p == NULL) {
		printf("* \n");
	} else {
		printf("*%d\n ", p -> item);
	}
}


void bit_printassummary ( Bitnode p , int spaces ) {
	if (p != NULL) {
		
		bit_printnode(p, spaces);
		spaces++;
		if ((p -> l == NULL) && (p -> r != NULL)) {
			bit_printnode(NULL, spaces);
			
		} 

		bit_printassummary(p -> l, spaces );

		if ((p -> l != NULL) && (p -> r == NULL)) {
			bit_printnode(NULL, spaces);
					
		} 
		
		bit_printassummary( p -> r, spaces );
		
		spaces--;
	}
}

//------------------------------------------


int main() {
	int array[9] = {0, 1, 2, 3, 4, 5, 6, 7}, size =8;

	Bitnode root = bit_arr2tree(array, size, 0);

	//bit_preorder(root);
	//printf("\n");
	bit_printassummary(root, 0);


}
