#include <stdio.h>
#define LENGTH 10

int partiziona(int a[], int i, int f){
    int perno = a[i];
    int sx = i;
    int dx = f;

    while (sx < dx){

        do{ dx--; } while (a[dx] > perno);

        do{ sx++; } while (sx < dx && a[sx] <= perno);

        if (sx < dx){
            int aux = a[sx];
            a[sx] = a[dx];
            a[dx] = aux;
        }
    }

    int aux = a[i];
    a[i] = a[dx];
    a[dx] = aux;

    return dx;
}

void quick(int a[], int i, int f){
    while(f-i>1){
        int m = partiziona(a,i,f);
        if(m-i < f-m){
            quick(a,i,m);
            i = m+1;
        } else {
            quick(a,m,f);
            f = m;
        }
    }
}

void quickSort(int a[]){
    quick(a,0,LENGTH);
}

int main(){

    int a[LENGTH] = {543,24,753,643223,83,9,23,456,7,4};


    //SOF: STAMPA
    printf("{");
    for(int i = 0; i<(int)(sizeof(a)/sizeof(a[0])); i++) printf("%d,", a[i]);
    printf("}");
    //EOF: STAMPA

    quickSort(a);

    printf("\n");
    //SOF: STAMPA
    printf("{");
    for(int i = 0; i<(int)(sizeof(a)/sizeof(a[0])); i++) printf("%d,", a[i]);
    printf("}");
    //EOF: STAMPA


    return 0;
}