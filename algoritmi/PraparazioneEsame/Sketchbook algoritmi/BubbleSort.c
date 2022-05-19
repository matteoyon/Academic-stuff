#include <stdio.h>
#include <stdlib.h>
#define TRUE 1;
#define FALSE 0;

typedef int Bool;


/**
 * Funzione che mette in ordine ascendente un array dato in ingresso con la sua lunghezza
 * 
 * @param a Array di interi da ordinare
 * @param l Lunghezza dell'array
 */
void BubbleSort(int a[], int l){
    int i = 1;
    Bool scambiato;
    do
    {
        scambiato = FALSE;
        for(int j = 0; j <= l-i; j++){
            if(a[j] < a[j-1]){
                int aux = a[j];
                a[j] = a[j-1];
                a[j-1] = aux;
                scambiato = TRUE;
            }
        }
        i++;
    } while (scambiato == 1 && i<l);
    
}

int main(){
    
     int a[10] = {543,24,543,643223,543,9,23,534,7,4};


    //SOF: STAMPA
    printf("{");
    for(int i = 0; i<(int)(sizeof(a)/sizeof(a[0])); i++) printf("%d,", a[i]);
    printf("}");
    //EOF: STAMPA

    BubbleSort(a, 10);

    printf("\n");
    //SOF: STAMPA
    printf("{");
    for(int i = 0; i<(int)(sizeof(a)/sizeof(a[0])); i++) printf("%d,", a[i]);
    printf("}");
    //EOF: STAMPA


    return 0;
}