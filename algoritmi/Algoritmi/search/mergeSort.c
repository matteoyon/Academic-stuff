/*
DA MIGLIORARE (SOLUZIONE ARRAY UNICO)
*/

#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *a, int n);
void swap(int *a, int *b);

int main(){
    int a[10] = {12,43,-23,3,6,4,-45,6,8,86};

    mergeSort(a,sizeof(a)/sizeof(a[0]));

    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++){
        printf("%d, ",a[i]);
    }
    printf("\n");
    return 0;

}

int *merge(int *a, int n, int *b, int m){
    int *r = calloc(m+n, sizeof(int));

    int i = 0;
    int j = 0;
    int k = 0;

    while(i < n && j < m){
        if(a[i] <= b[j]){
            r[k] = a[i];
            i++;
        }else{
            r[k] = b[j];
            j++;
        }
        k++;
    }

    if(i < n){
        for(int l = i; l < n; l++){
            r[k] = a[l];
            k++;
        }
    }else{
        for(int l = j; l < m; l++){
            r[k] = b[l];
            k++;
        }
    }

    return r;
}

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

void mergeSort(int *a, int n){
    if(n>1){
        int *b = a + (n/2);

        mergeSort(a,(n/2)-1);
        mergeSort(b,n/2);
        *a = *merge(a,(n/2)-1,b,n/2);
    }
}