#include "bist.h"
#include "bit.h"
#include <stdio.h>
#include <stdlib.h>

int bistMin(Bit_node p){
    while(p -> left){
        p = p->left;
    }

    return p -> item;
};

int bistMax(Bit_node p){
    while(p -> right){
        p = p -> right;
    }

    return p -> item;
};

/*Stampa in ordine*/
void bistOrderPrint(Bit_node p){
    bitInorder(p);
};

/*Stampa in ordine inverso*/
void bistInvorderPrint(Bit_node p){
    if(p){
        bitInorder(p -> right);
        bitPrintNode(p);
        bitInorder(p -> left);
    }
};

/*DA COMPLETARE*/
int bistSearch(Bit_node r, int k){
    while(r){
        if(r->item == k)
            return r -> item;
        else if(r -> item < k)
            r = r -> right;
        else
            r = r -> left;
    }
    return NULL;
};

/*Funzione ausiliaria per bistInsert e bistDelete*/
int bistSearchParent(Bit_node r, int k, Bit_node *parent, Bit_node *p){

    *parent = NULL;
    *p = r;

    if(!r)
        return -1;
    
    while(*p){
        if(k == (*p)-> item)
            return 0;

        *parent = *p;
        *p = (*p)-> item > k ? (*p) -> left : (*p) -> right;
    }

    if(*p == NULL)
        return -1;
}



void bistInsert(Bit_node *q, int n);
int bistDelete(Bit_node *r, int k);