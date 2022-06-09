#include <stdio.h>
#include <math.h>

int main(){
    int n;

    printf("Di quante luci vuoi che sia il circuito?: ");
    scanf("%d", &n);
    int a[n];
    printf("Scrivi la disposizione di partenza del circuito: ");
    for(int i = 0; i < n; i++){
    //for(int i = n - 1; i >= 0; i--){
        scanf(" %d", &a[i]);
    }

    int b = 0;
    for(int i = 0; i < n; i++){
    //for(int i = n - 1; i >= 0; i--){
        b += a[i] * pow(2,i);
    }

    printf("%d\n",b);

    return 0;
}