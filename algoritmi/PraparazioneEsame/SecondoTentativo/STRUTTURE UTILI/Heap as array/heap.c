#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int father(i){
    return i/2;
};

void swap(Heap h, int i, int j){
    int a = h[i];
    int b = h[j];

    h[i] = b;
    h[j] = a;
};

void heapify_up(Heap h, int i){
    if(i>1){
        int j = father(i);
        if(h[i] < h[j]){
            swap(h, i, j);
            heapify_up(h,j);
        }
    }
};

void heapify_down(Heap h, int i, int n){
    if (2*i <= n){ //se h[i] ha almeno un figlio:
        int j;

        if(2*i == n){ //se h[i] ha solo il figlio sinistro
            j = 2*i;
        }else if(h[2*i]<h[2*i+1]){ //scegli gli il figlio più piccolo
            j = 2*i;
        }else{
            j= 2*i + 1;
        }

        if(h[j] < h[i]){
            swap(h,i,j);
            heapify_down(h,j,n);
        }
    }
}