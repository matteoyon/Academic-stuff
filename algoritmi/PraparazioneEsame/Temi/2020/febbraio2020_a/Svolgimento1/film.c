#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int p[n];
    for(int i = 0; i < n; i++){
        scanf(" %d", p+i);
    }

    int l = 0, t = 1;

    for(int i = 1; i < n; i++){
        if (p[i] >= p[i-1]){
            t++;
        }else{
            if(t>l){
                l = t;
            }
            t = 1;
        }
    }

    if(t>l) l = t;

    printf("%d\n", l);

    return 0;
}