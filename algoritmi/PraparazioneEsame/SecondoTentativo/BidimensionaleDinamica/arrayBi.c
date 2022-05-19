#include <stdio.h>
#include <stdlib.h>

#define N 20
#define M 30

char **creaMatrice(int n, int l){
    char **m;

    m = calloc(n, sizeof(char *));
    for (int r = 0; r < n; r++){
        *(m+r) = calloc(l, sizeof(char));
    }

    for(int r=0; r<n; r++){
        for(int c = 0; c<l; c++){
            m[r][c] = 'E';
        }
    }

    return m;
}

int main(){
    char **m = creaMatrice(N,M);

    for(int i = 0; i < N; i++){
        putchar('\n');
        for(int j = 0; j < N; j++){
            putchar('[');
            putchar(m[i][j]);
            putchar(']');
        }
    }



    return 0;
}