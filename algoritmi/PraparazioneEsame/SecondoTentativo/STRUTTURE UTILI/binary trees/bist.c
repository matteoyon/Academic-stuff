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
};
void bistInsert(Bit_node *q, int n);
int bistDelete(Bit_node *r, int k);