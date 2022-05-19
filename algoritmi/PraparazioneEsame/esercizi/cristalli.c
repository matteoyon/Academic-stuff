#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int latoCristallo(int t){
    int temp = pow(2,t);
    return((2*temp) - 1);
}

char **creaMatrice(int n){
    char **a = calloc(n, sizeof(char **));
    for(int i = 0; i < n; i++){
        a[i] = calloc(n, sizeof(char *));
        for(int j = 0; j < n; j++){
            a[i][j] = '.';
        }
    }

    return a;
}

void stampaMatrice(char **m, int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j < n; j++){
            putchar(m[i][j]);
        }
        putchar('\n');
    }
}

void crist(char **m, int r0, int c0, int l){
    
    if(l <= 1){
        m[r0][c0] = '*';
    }else{
        int h = (l/2);
        m[r0+h][c0+h] = '*';

        crist(m, r0, c0, l/2);
        crist(m, r0+(l/2)+1, c0, l/2);
        crist(m, r0, c0+(l/2)+1, l/2);
        crist(m, r0+(l/2)+1, c0+(l/2)+1, l/2);
    }
}

void cristallo(char **m, int l){
    crist(m,0,0,l);
}

int main(){
    
    char **matrix ;
    int t , lato ;
    scanf("%d", &t);
    
    
    if( t >= 0 ){

        lato = latoCristallo ( t ); // dimensione della matrice

        matrix = creaMatrice ( lato ); // crea matrice per rappresentare il cristallo

        cristallo ( matrix , lato ); // costruisce il cristallo avente lato assegnato

        stampaMatrice ( matrix , lato ); // stampa la matrice
    }
    
    
    return 0;
}