#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

void merge(int a[], int i, int m, int f, int x[]){
    int i1 = i;
    int i2 = m;
    int k = 0;

    while(i1<m && i2<f){
        if(a[i1]<=a[i2]){
            x[k] = a[i1];
            i1++;
        }else{
            x[k] = a[i2];
            i2++;
        }
        k++;
    }

    if(i1 < m){
        for(int j = i1; j < m; j++){
            x[k] = a[j];
            k++;
        }
    }else{
        for(int j = i2; j < f; j++){
            x[k] = a[j];
            k++;
        }
    }
    for (int k = 0; k < f - i; k++){
        a[i+k] = x[k];
    }
}

void mSort(int a[], int i, int f, int x[]){
    if (f-i > 1){
        int m = (i+f)/2;
        mSort(a,i,m,x);
        mSort(a,m,f,x);
        merge(a,i,m,f,x);
    }
}

/**
 * Funzione che mette in ordine ascendente un array dato in ingresso
 * 
 * @param a Array di interi da ordinare
 * @param l Lunghezza dell'array
 */
void mergeSort(int a[]){
   int x[LENGTH];
   mSort(a,0,LENGTH,x);

}

int main(){

    int a[LENGTH] = {543,24,753,643223,83,9,23,456,7,4};


    //SOF: STAMPA
    printf("{");
    for(int i = 0; i<(int)(sizeof(a)/sizeof(a[0])); i++) printf("%d,", a[i]);
    printf("}");
    //EOF: STAMPA

    mergeSort(a);

    printf("\n");
    //SOF: STAMPA
    printf("{");
    for(int i = 0; i<(int)(sizeof(a)/sizeof(a[0])); i++) printf("%d,", a[i]);
    printf("}");
    //EOF: STAMPA


    return 0;
}