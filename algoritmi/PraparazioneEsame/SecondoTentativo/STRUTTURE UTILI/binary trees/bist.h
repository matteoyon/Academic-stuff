#ifndef BIST
#define BIST

//#include "bist.c"
#include "bit.h"
#include <stdio.h>
#include <stdlib.h>

int bistMin(Bit_node p);
int bistMax(Bit_node p);

/*Stampa in ordine*/
void bistOrderPrint(Bit_node p);

/*Stampa in ordine inverso*/
void bistInvorderPrint(Bit_node p);

int bistSearch(Bit_node r, int k);
void bistInsert(Bit_node *q, int n);
int bistDelete(Bit_node *r, int k);

#endif