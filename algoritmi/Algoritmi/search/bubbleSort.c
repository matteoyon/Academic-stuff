#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *a, int n);
void swap(int *a, int *b);

int main(){
    int a[10] = {12,43,-23,3,6,4,-45,6,8,86};

    bubbleSort(a,sizeof(a)/sizeof(a[0]));

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

void bubbleSort(int *a, int n){
    int changes;
    for(int i = 1; i < n; i++){
        changes = 0;
        for(int j = 0; j < n - i; j++){
            if(a[j] > a[j+1]){
                swap(&(a[j]),&(a[j+1]));
                changes++;
            }
        }
        if(changes == 0) break;
    }
    return;
}