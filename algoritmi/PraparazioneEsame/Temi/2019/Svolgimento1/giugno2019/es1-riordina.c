#include <stdio.h>

void swap(int *a, int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf(" %d", a+i);
    }

    int s = 0;
    int e = n-1;

    while(s < e){

        if(a[s] > a[e]) swap(a+s,a+e);

        if(a[s] != 1){
            s++;
        }

        if(a[e] != 0){
            e--;
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ",a[i]);
    }

    printf("\n");
    return 0;
}