/*
Crea un programma che prende in input 2 double, calcolal'ipotenusa di un triangolo rettangolo e la stampi
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){

    //printf("%f\n", atoi(argv[1]));

    printf("%f\n",  sqrt(pow((double)atoi(argv[1]), 2) + pow((double)atoi(argv[2]), 2)));


    return 0;
}