#include <stdio.h>

/**
 * Funzione che mette in ordine ascendente un array dato in ingresso con la sua lunghezza
 * 
 * @param a Array di interi da ordinare
 * @param l Lunghezza dell'array
 */
void InsertionSort(int a[], int l){
    for(int k = 1; k < l; k++){
        int x = a[k];
        int j = k-1;
        while (j>=0 && a[j] > x){
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = x;
        
    }
}

int main(){
    
     int a[10] = {543,24,543,643223,543,9,23,534,7,4};


    //SOF: STAMPA
    printf("{");
    for(int i = 0; i<(int)(sizeof(a)/sizeof(a[0])); i++) printf("%d,", a[i]);
    printf("}");
    //EOF: STAMPA

    InsertionSort(a, 10);

    printf("\n");
    //SOF: STAMPA
    printf("{");
    for(int i = 0; i<(int)(sizeof(a)/sizeof(a[0])); i++) printf("%d,", a[i]);
    printf("}");
    //EOF: STAMPA


    return 0;
}