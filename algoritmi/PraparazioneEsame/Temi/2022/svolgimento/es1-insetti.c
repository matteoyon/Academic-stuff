/**
 * Yon Matteo 954748
 */ 

#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, m, j, count = 0, temp = 0, countW = 0;
    scanf("%d %d", &n, &m);

    int samples[n];
    int windows[n - m + 1];

    for(int i = 0; i < n; i++){
        scanf(" %d", samples+i);
        if(i>0 && samples[i] > samples[i-1]) count++;
        temp += samples[i];
        if(i>=m){
            windows[j] = temp;
            j++;
            temp -= samples[i-(m-1)];
        }
    }

    for(int i = 1; i < n - m + 1; i++){
        if(windows[i] > windows[i-1]) countW++;
    }

    printf("%d %d\n", count, countW);

}

/**
 * La complessità in tempo dell'algoritmo usato è THETA(n):
 * Infatti nel primo ciclo for vengono eseguite n volte delle
 * operazioni che consideriamo a tempo costante e nel secondo
 * ciclo for n - m + 1 volte operazioni a tempo costante.
 * 
 * Dato che la grandezza di m non deve essere uguale o superare la grandezza
 * di n, nel caso limite in cui m è grande 1 il tempo asintotico
 * sarebbe THETA(n + n-1 +1) = THETA(2n) = THETA(n), mentre nell'altro caso
 * limite in cui m è grande n - 1 abbiamo THETA(n + n - n - 1 + 1) = THETA(n)
 */ 