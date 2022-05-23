#include <stdio.h>
#include <stdlib.h>
#include "bit.h"

int main(){
    int a[9] = {69,89,28,39,66,44,12,2,71};

    bitPrintASummary(bit_arr2tree(a,9,0),0);
}