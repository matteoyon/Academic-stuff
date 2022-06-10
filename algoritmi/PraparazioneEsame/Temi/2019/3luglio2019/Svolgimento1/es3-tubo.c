#include <stdio.h>


int main(){
    int l, n;

    scanf("%d", &l);
    scanf("%d", &n);

    int s[n];
    for(int i = 0; i < n; i++){
        scanf(" %d", s+i);
    }

    int u = 0, k = 0, tot = 0;
    int min;

    while(k < n){
        min = l+1;
        for(int i = 0; i <= n; i++){
            if(s[i] < min){
                min = s[i];
                u = i;
            }
        }

        if((tot += min) >= l) break;

        s[u] = l+1;
        k++;
    }

    printf("%d\n", k);
}