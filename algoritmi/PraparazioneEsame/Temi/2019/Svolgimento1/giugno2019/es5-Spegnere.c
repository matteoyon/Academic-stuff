#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bin2int(int *a, int n){
    
    int b = 0;
    
    for(int i = 0; i < n; i++){
    //for(int i = n - 1; i >= 0; i--){
        b += a[i] * pow(2,i);
    }

    return b;
}

int *int2bin(int b, int n){
    int *a = calloc(n,sizeof(int));

    for(int i = 0; i < n; i++){
        a[i] = b%2;
        b = b/2;
    }

    return a;

}

void press(int *c, int n, int i){
    c[i%n] = -1 * (c[i%n] - 1);
    c[(i-1)%n] = -1 * (c[(i-1)%n] - 1);
    c[(i+1)%n] = -1 * (c[(i+1)%n] - 1);
}

int main(){
    int n;

    printf("Di quante luci vuoi che sia il circuito?: ");
    scanf("%d", &n);
    int s[n];
    printf("Scrivi la disposizione di partenza del circuito: ");
    for(int i = 0; i < n; i++){
    //for(int i = n - 1; i >= 0; i--){
        scanf(" %d", &s[i]);
    }

    int m[n][pow(2,n)];
    int *aux1, *aux2;
    int i = 0;
    
    while(1){
        //aux1 = int2bin(i,n);
        for(int j = 0; j < n; j++){
            aux1 = int2bin(i,n);
            press(aux1,n,j);
            m[j][i];
            /**DA COMPLETARE***/
        }
    }
}