/*
Una successione di caratteri è un’espressione ben parentesizzata se, per ogni prefisso della successione stessa
(cioè, per ogni possibile segmento iniziale della successione), il numero di parentesi aperte “(” è maggiore o
uguale al numero di parentesi chiuse “)”, e se, complessivamente, il numero di parentesi aperte è uguale al
numero di parentesi chiuse. Questo è ciò che avviene, per esempio, nelle espressioni aritmetiche ben formate.
Scrivete un programma che legga (mediante la funzione getchar() inclusa in stdio.h) una sequenza di
caratteri terminata da . e determini se essa è un’espressione ben parentesizzata. In caso negativo, il programma
dovrà stampare in quale posizione ha identificato un errore, e il tipo di errore.
*/

#include <stdio.h>

int main(int argc, char **argv){
    char *exp = argv[1];
    int counter = 0;
    int i = 0;

    while(exp[i] != 0){
        switch(exp[i]){
            case '(':
                counter++;
                break;
            case ')':
                counter--;
            default:
                break;
        }

        if(counter < 0){
            printf("\nEspressione non ben parentesizzata");
            return 0;
        }

        i++;
    }

    printf("\nEspressione ben parentesizzata");
    return 0;

}