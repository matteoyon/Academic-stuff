/*
Algoritmo RisolviP2(Matrice[n][m] M) -> int
    A <- Matrice[n][m]
    A[0][0] <- 0
    for i<-1 to n-1:
        A[i][0] <- A[i-1][0] + M[i][0]
    for i<-1 to n-1:
        A[0][i] <- A[0][i-1] + M[0][i]
    for i<-1 to n-1:
        for j<-1 to m-1:
            A[i][j] = M[i][j] + min(A[i-1][j],A[i][j-1])
    
    return A[n-1][m-1]
*/

#include <stdio.h>
#include <stdlib.h>
#define O 5
#define N 5

int min(int a, int b);
int risolviP2(int M[][O], int n,int m);

int main(){
    int n = N;
    int m = O;

    int M[N][O] = { {7,1,8,4,4},
                    {9,1,8,4,4},
                    {1,1,8,4,4},
                    {1,9,8,4,4},
                    {1,1,1,1,1}  };    

    printf("r2 = %d\n", risolviP2(M,n,m));

}

int min(int a, int b){
    if(a < b) return a;
    return b;
}

int risolviP2(int M[][O], int n,int m){
    int A[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            A[i][j] = 0;
        }
    }
    for(int i = 1; i < n; i++){
        A[i][0] = A[i-1][0] + M[i][0];
    }
    for(int i = 1; i < m; i++){
        A[0][i] = A[0][i-1] + M[0][i];
    }
    for (int i = 1; i <= n-1; i++){
        for (int j = 1; j <= m-1; j++){
            A[i][j] = M[i][j] + min(A[i-1][j],A[i][j-1]);
        }
    }

    return A[n-1][m-1];
}