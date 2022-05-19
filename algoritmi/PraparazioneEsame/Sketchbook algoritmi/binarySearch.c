#include <stdio.h>

/**
 * Funzione che restituisce un indice dato un array di interi ordinato e un elemento di cui trovare
 * l'indice o -1 se l'elemento non è presente
 * 
 * @param a Array di interi ordinato
 * @param l Lunghezza dell'array
 * @param x elemento da cercare
 * @return indice di x in a o -1 se non presente
 */
    
int searchInt(int a[], int l, int x){

    int sx = 0;
    int dx = l; //Va memorizzato l e non l-1 perchè la divisione di default va a floor, non andrai in segmentation fault
    int pos = -1;

    while (sx < dx && pos == -1){
        int n = (sx+dx) / 2;

        if (x == a[n]) pos = n;
        else if (x < a[n]) dx = n;
        else sx = n+1; //Ricordati il +1!!!!!!!!
    }

    return pos;
}
    

int main(){
    //Array in cui effettuare la ricerca
    int a[15] = {1, 29, 37, 49, 52, 69, 72, 84, 92, 104, 110, 123, 139, 145, 151};

   
    printf("%d", searchInt(a,(int)sizeof(a)/sizeof(a[0]),92));



    return 0;
}