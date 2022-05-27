#include <stdio.h>
#include <stdlib.h>

typedef struct oggetto{
    int tipo;
    int valore;
    int peso;
} *Oggetto;

int main(){
    //p <- GRANDEZZA DELLO ZAINO
    int p;
    printf("Quanto è grande lo zaino? ");
    scanf("%d", &p);

    //n <- quante tipologie di oggetti
    int n;
    printf("Quante tipologie di oggetti hai a disposizione? ");
    scanf("%d", &n);

    /*
    INPUT OGGETTI
    */
    Oggetto o = malloc(n*sizeof(struct oggetto));
    printf("\nScrivi i tuoi oggetti nel  formato <VALORE PESO>:\n");
    for(int k = 0; k<n; k++){
        int v, p;
        scanf("%d %d", &v, &p);
        (o+k)->tipo = k;
        (o+k)->peso = p;
        (o+k)->valore = v;
    }

    
    int s[p+1];
    for(int i = 0; i <= p; i++){
        s[i] = 0;
    }

    for(int i = 0; i <= p; i++){
        for(int k = 0; k<n; k++){
           int q = i + (o+k)->peso;
           if(q <= p && s[q] < s[i] + (o+k)->valore){ //Lazy evaluation mi protegge da seg fault
               s[q] = s[i] + (o+k)->valore;
           } 
        }

        printf("\n");
        for(int j = 0; j <= p; j++){
            printf("[%d]", s[j]);
        }
    }

    printf("\nIl valore massimo che riesci a portare è: %d", s[p]);

    return 0;
}