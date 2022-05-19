#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    char indirizzo[50];
} Voce;

int main(){
    Voce rubrica[20];

    int i = 0;

    while(i < (sizeof(rubrica)/sizeof(rubrica[0]))){
        printf("\nNome: ");
        scanf("%[^\n]%*c", rubrica[i].nome);
        if(strcmp(rubrica[i].nome, "0") == 0){
            break;
        }
        printf("\nIndirizzo: ");
        scanf("%[^\n]%*c", rubrica[i].indirizzo);
        i++;
    }

    for(int j=0; j<i; j++){
        printf("\n%s ==> %s", rubrica[j].nome, rubrica[j].indirizzo);
    }

    return 0;

}