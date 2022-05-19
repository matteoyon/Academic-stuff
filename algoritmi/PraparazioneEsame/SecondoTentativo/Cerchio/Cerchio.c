/*Scrivete un programma che legga (in una variabile di tipo float) il raggio di un cerchio e ne stampi l’area.
Tenete presente che il file math.h della libreria standard contiene la definizione della costante M_PI, pari al
valore di π (il rapporto tra la circonferenza ed il diametro). Quando compilate, usate l’opzione -lm.*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char** argv){
    
    if(argc<2){
        printf("\nValore del raggio non rilevato.\n");
        return 1;
    }

    float r = atof(argv[1]);
    float a = r*r*M_PI;

    printf("L'area del cerchio è di %f", a);
    return 0;
}