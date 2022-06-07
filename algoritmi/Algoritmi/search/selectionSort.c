#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *a, int n);
void swap(int *a, int *b);

int main(){
    int a[10] = {12,43,-23,3,6,4,-45,6,8,86};

    selectionSort(a,sizeof(a)/sizeof(a[0]));

    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++){
        printf("%d, ",a[i]);
    }
    printf("\n");
    return 0;

}

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

void selectionSort(int *a, int n){
    for(int i = 0; i < n; i++){
        int j = i;
        int min = i;
        for(; j < n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        swap(&(a[i]),&(a[min]));
    }
}