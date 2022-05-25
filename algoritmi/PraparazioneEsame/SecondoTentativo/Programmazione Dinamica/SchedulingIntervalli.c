#include <stdio.h>

//RICORRENZA: Opt(j) = max{I[j].v+Opt(p(j)), Opt(j-1))}

int main(){

    //Input di j intervalli

    //Riordino intervalli con key = f

    //Calcola p(j) per ogni j e memorizzalo in Array P

    /*
    int M[j+1];
    M[0] = 0;
    for(int k = 1; k <= j; k++){
        M[k] = max{I[k].v+M[P[k]], M[k-1]}
    }

    print(M[j]);

    for(int k = j; k >= 0; ){
        if(M[k] = 0){
            break;
        }else if(M[k] > M[k-1]){
            print(I[k]);
            k = p(k);
        }else{
            k--;
        }
    }
    */


    return 0;
}

int *p(int j){
    /*
    Ritorna MASSIMO i t.c.
        • i < j
        • I[i].f < I[j].i


    */
}