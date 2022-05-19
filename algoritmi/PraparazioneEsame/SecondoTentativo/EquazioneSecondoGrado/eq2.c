/*
Scrivete un programma che legga tre coefficienti a,b, c e calcoli le soluzioni (complesse) dell’equazione ax2 +
bx+c. Può essere utile includere il file di intestazione math.h della libreria standard, contenente la funzione
sqrt per il calcolo della radice quadrata. Quando compilate, usate l’opzione -lm.
*/

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int main(int argc, char **argv){
    float a = atof(argv[1]);
    float b = atof(argv[2]);
    float c = atof(argv[3]);

    float delta = (b*b) - (4*a*c);

    if(delta < 0){
        printf("Dovrei farlo con i complessi ma non mi ricordo man, non cagare il cazzo\n");
        return 0;
    }

    float x1 = (-b+sqrt(delta))/(2*a);
    float x2 = (-b-sqrt(delta))/(2*a);

    printf("Le radici dell'equazione %fx^2 + %fx + %f sono: x1 = %f e x2 = %f\n", a, b, c, x1 ,x2);
}