#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int h(int A[], int B[], int n, int m);

int h(int A[], int B[], int n, int m){
    int maxA = A[0], minB = B[0];

    for(int i = 1; i<n; i++){
        if(A[i] > maxA) maxA = A[i];
    }

    for(int i = 1; i<m; i++){
        if(B[i] < minB) minB = B[i];
    }

    return (maxA < minB);
}

int main(){
    int n = 3, A[] = {1,5,5};
    int m = 2, B[] = {7,6};

    printf("%d\n", h(A,B,n,m));
    return 0;
}

/**
 * Soluzione con tempo OMEGA(n+m)
 */ 