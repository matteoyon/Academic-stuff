#ifndef BIT
#define BIT

//#include "bit.c"
#include <stdio.h>
#include <stdlib.h>

typedef struct bit_node {
    int item;
    struct bit_node *right;
    struct bit_node *left;
} *Bit_node;

Bit_node bitNew(int);
void bitDestroy(Bit_node);

int bitItem(Bit_node);
Bit_node bitLeft(Bit_node);
Bit_node bitRight(Bit_node);
void bitPrintNode(Bit_node);

void bitPreorder(Bit_node);
void bitInorder(Bit_node);
void bitPostorder(Bit_node);

void bitPrintASummary(Bit_node p, int spaces);
Bit_node bit_arr2tree(int *a, int size, int i);

#endif