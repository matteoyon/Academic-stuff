#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(){
    int h[] = {-999, 1, 2, 5, 10, 3, 7, 11, 15, 17, 20, 9, 15, 8, 16, 21};

    swap(h,3,15);

    heapify_down(h,3,14);

    for(int i = 0; i < sizeof(h)/sizeof(h[0]); i++){
        printf("%d, ", h[i]);
    }

    return 0;
}