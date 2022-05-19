#include <stdio.h>
#include <stdlib.h>

/**
 * Funzione che mette in ordine ascendente un array dato in ingresso con la sua lunghezza
 * 
 * @param a Array di interi da ordinare
 * @param l Lunghezza dell'array
 */
void SelectionSort(int a[], int l){
    for(int k = 0; k <= l-2; k++){
        int m = k;
        for(int j = k+1; j <= l-1; j++){
            if (a[j] < a[m]) m = j;
        }

        int aux = a[k];
        a[k] = a[m];
        a[m] = aux;
    }
}

int main(){

    int a[10] = {543,24,543,643223,543,9,23,534,7,4};


    //SOF: STAMPA
    printf("{");
    for(int i = 0; i<(int)(sizeof(a)/sizeof(a[0])); i++) printf("%d,", a[i]);
    printf("}");
    //EOF: STAMPA

    SelectionSort(a, 10);

    printf("\n");
    //SOF: STAMPA
    printf("{");
    for(int i = 0; i<(int)(sizeof(a)/sizeof(a[0])); i++) printf("%d,", a[i]);
    printf("}");
    //EOF: STAMPA


    return 0;
}