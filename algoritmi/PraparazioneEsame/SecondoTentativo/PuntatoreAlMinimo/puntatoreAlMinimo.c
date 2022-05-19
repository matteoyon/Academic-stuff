#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//INPUT: array a lunghezza n
//OUTPUT: indirizzo all'elemento più piccolo dell'array
int *smallest(int a[], int n){

    int *c = a;
    for(int j = 0; j <= n; j++){
        if (*(a+j) < *c){
            c = a+j;
        }
    }

    return c;

}

int main(){

    int seq[100];
    int i = 0;

    for(;i < sizeof(seq)/sizeof(seq[0]);){
        scanf("%d", &seq[i]);
        if(seq[i] == 0){
            i--;
            break;
        }
        i++;
    }
    
    int *minimum = smallest(seq,i);

    printf("\nIl valore minimo della sequenza ha indirizzo %d e ha valore %d", minimum, *minimum);

    return 0;
}
