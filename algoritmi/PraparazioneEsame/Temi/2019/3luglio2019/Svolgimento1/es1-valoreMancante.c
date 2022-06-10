#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++){
        scanf(" %d", a+i);
    }

    //GESTIONE CASO numero mancante == n e numero mancante == 0
    if(a[n-1] != n){
        printf("%d\n", n);
        return 0;
    }
    if(a[0] != 0){
        printf("%d\n", 0);
        return 0;
    }


    //Ricerca dicotomica: tempo logaritmico
    int k = n/2;
    while(1){
        if(a[k] == k){
            if(a[k+1] == k+2){
                printf("%d\n", k+1);
                return 0;
            }else{
                k = (n+k)/2;
            }
        }else if(a[k] == k+1){ 
            if(a[k-1] == k-1){
                printf("%d\n", k);
                return 0;
            }else{
                k /= 2;
            }
        }
    }

    return 0;
}