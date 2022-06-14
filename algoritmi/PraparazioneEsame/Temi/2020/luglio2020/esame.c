#include <stdlib.h>
#include <stdio.h>

struct node {
	int item ;
	struct node * next ;
};
typedef struct {
	struct node * head ;
} * List ;



void list_print(List l) {
	struct node *root = l -> head;
	while (root != NULL) {
		printf("%d ", root -> item);
		root = root -> next;
	}
}


void list_addAtEnd(List l, int value) {
	struct node *root = l -> head;
	struct node *new_node = malloc(sizeof(struct node));
	new_node -> item = value;
	new_node -> next = NULL;
	if (root == NULL) {
		root = new_node;
	} else {
		while (root -> next != NULL) {
			root = root -> next;
		}
	root -> next = new_node;

	}

}

typedef struct {
	
	struct node * head;
	struct node * tail;
} DList;

void dlist_addAtEnd(DList *l, int value) {
	struct node *new_node = malloc(sizeof(struct node));
	new_node -> item = value;
	if ((l -> head == NULL) && ( l -> tail == NULL)) {
		l -> head = new_node;
		l -> tail = new_node;
	} else {
		l -> tail -> next = new_node;
		l -> tail = new_node;	
	}
}

// listatend On
// dlistatend O1

/*


*/

