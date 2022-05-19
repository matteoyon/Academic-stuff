#include "bit.h"
#include <stdio.h>
#include <stdlib.h>

Bit_node bitNew(int n){
    Bit_node p = calloc(1,sizeof(struct bit_node));
    p -> item = n;
    p -> right = NULL;
    p -> left = NULL;
    return p;
};

void bitDestroy(Bit_node p){
    free(p);
    p = NULL;
};

int bitItem(Bit_node p){
    reutrn p -> item;
};

Bit_node bitLeft(Bit_node p){
    return p -> left;
};
Bit_node bitRight(Bit_node p){
    return p-> right;
};
void bitPrintNode(Bit_node p){
    printf("[%d]", p -> item);
};

void bitPreorder(Bit_node p){
    if(p){
        bitPrintNode(p);
        bitPreorder(p -> left);
        bitPreorder(p -> right);
    }
};

void bitInorder(Bit_node p){
    if(p){
        bitInorder(p -> left);
        bitPrintNode(p);
        bitInorder(p -> right);
    }
};
void bitPostorder(Bit_node p){
    if(p){
        bitPostorder(p -> left);
        bitPreorder(p -> right);
        bitPostorder(p);
    }
};


/*
DA IMPLEMENTARE
*/
void bitPrintASummary(Bit_node p, int spaces){
    printf("Ah boh che ne so io");
};

Bit_node bit_arr2tree(int *a, int size, int i);