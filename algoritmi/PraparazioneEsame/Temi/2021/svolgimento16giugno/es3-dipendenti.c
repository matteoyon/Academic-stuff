#include <stdio.h>
#include <stdlib.h>

typedef struct dipendente{
    int id;
    struct dipendente *supervisore;
    Forest *subordinati;
} *Dipendente;

typedef struct node{
    Dipendente d;
    struct node *next;
} *Forest;

void stampaSubordinati(Dipendente d){
    if(d){
        for(Forest f = d -> subordinati; f != NULL; f -> next){
            printf("%d,", f -> d -> id);
        }
        for(Forest f = d -> subordinati; f != NULL; f -> next){
            stampaSubordinati(f -> d);
        }
    }
    printf("\n");
    return;
}

void supervisore(Dipendente d){
    if(d){
        printf("%d\n", d -> supervisore);
    }
    return;
}

void quantiSenzaSubordinati(Forest f){
    int foglie = 0;
    auxQuantiSenzaSub(f,&foglie);
    printf("%d\n", foglie);
}

void auxQuantiSenzaSub(Forest f, int *foglie){
    if(f){
        for(Forest g = f; g != NULL; g = g-> next){
            auxQuantiSenzaSub(g -> d -> subordinati, foglie);
        }
    }else{
        (*foglie)++;
    }
    return;
}

void stampaImpiegatiSopra(Dipendente d){
    for(Dipendente e = d -> supervisore; e != NULL; e = e -> supervisore){
        printf("%d,", e -> id);
    }
    printf("\n");
}

void stampaImpiegatiConSupervisore(Forest f){
    if(f){
        for(Forest g = f; g != NULL; g = g-> next){
            
            int padre = -1;
            if(g->d->supervisore) {
                padre = g -> d -> supervisore ->id;
            }
            
            printf("[%d,%d], ", g -> d ->id, padre);
            stampaImpiegatiConSupervisore(g -> d -> subordinati);
        }
    }
    printf("\n");
    return;
}

