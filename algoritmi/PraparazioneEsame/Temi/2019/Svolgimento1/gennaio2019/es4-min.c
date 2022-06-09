#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int allOne(int *c, int n){
    for(int i = 0; i < n; i++){
        if(c[i] == 0) return 0;
    }
    return 1;
}

int min(int *a, int *b, int n){

    int min = INT_MIN;
    int toReturn = -1;

    for(int i = 0; i < n; i++){
        if(a[i]>INT_MIN && b[i] == 0){
            min = a[i];
            toReturn = i;
        }
    }

    return toReturn;
}

int getNode(int *g, int n){
    if(g[n] != 0){
        return getNode(g,g[n]);
    }
    return n;
}

int main(){
    int v;
    scanf("%d", &v);
    int g[v], d[v], c[v];
    for(int i = 0; i < v; i++){
        scanf(" %d", g+i);
        c[i] = 0;
    }

    //printf("Ne sono uscito\n");

    d[0] = 0;
    for(int i = 1; i < v; i++) d[i] = INT_MAX;
    
    int n;
    while(allOne(c,v) == 0){
        
        n = min(d,c,v);
        c[getNode(g,n)] = 1;

        for(int j = 1; j <=6; j++){
            if(getNode(g,n+j) >= v){
                break;
            }
            printf("Sono qui dentro1\n");
            if(d[getNode(g,n)]+1 < d[getNode(g,n+j)]){
                printf("Sono qui dentro2\n");
                d[getNode(g,n+j)] = d[getNode(g,n)] + 1;
            }
            printf("Sono qui dentro2\n");
        }
    }

    printf("%d\n", d[getNode(g,v-1)]);

    return 0;
}