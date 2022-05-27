#include <stdio.h>

//RICORRENZA: Opt(j) = max{I[j].v+Opt(p(j)), Opt(j-1))}


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int i[], int f[], int v[], int n){
    int k, h;
    for (k = 0; k < n-1; k++)
        for (h = 0; h < n-k-1; h++)
            if(f[h] > f[h+1]){
                swap(&f[h], &f[h+1]);
                swap(&i[h], &i[h+1]);
                swap(&v[h], &v[h+1]);
            }
}

void sort(int *i, int *f, int *v, int size){
    bubbleSort(i,f,v,size);
}

void calculateP(int j, int *i, int *f, int *v, int *P){
    for(int a = 0; a < j; a++){
        if(f[a] <= i[j-1]) P[j] = a+1;
    }
}

int main(){

    //Input di j intervalli
    int j;

    printf("Quanti intervalli vuoi considerare? ");
    scanf("%d", &j);

    int i[j], f[j], v[j];
    printf("\nScrivi i tuoi intervalli nel  formato <INIZIO-FINE VALORE>:\n");
    for(int k = 0; k<j; k++){
        scanf("%d-%d %d", i+k, f+k, v+k);
    }
    
    //Riordino intervalli con key = f
    sort(i,f,v,j);

    /*
    printf("\n");
    for(int k = 0; k<j; k++){
        printf("%d-%d %d\n", i[k], f[k], v[k]);
    }
    */



    //Calcola p(j) per ogni j e memorizzalo in Array P
    int P[j+1];
    P[0] = 0;
    for (int k = 1; k <= j; k++){
        P[k] = 0;
        calculateP(k,i,f,v,P);
    }

    for (int k = 0; k <= j; k++){
        printf("%d, ", P[k]);
    }

    
    int M[j+1];
    M[0] = 0;
        //M[k] = max{I[k].v+M[P[k]], M[k-1]}
    for(int k = 1; k <= j; k++){
        if(v[k-1] + M[P[k]] > M[k-1]){
            M[k] = v[k-1] + M[P[k]];
        }else{
            M[k] = M[k-1];
        }
    }


    printf("\n%d", M[j]);

    for(int k = j; k >= 0; ){
        if(M[k] == 0){
            break;
        }else if(M[k] > M[k-1]){
            printf("\n%d-%d %d", i[k-1], f[k-1], v[k-1]);
            k = P[k];
        }else{
            k--;
        }
    }
    
    printf("\n");
    return 0;
}

/*
int *p(int j){
    /*
    Ritorna MASSIMO i t.c.
        • i < j
        • I[i].f < I[j].i


    
}

*/