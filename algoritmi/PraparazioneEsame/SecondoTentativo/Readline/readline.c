#include <stdio.h>
#include <stdlib.h>

char *readline(char c){
    int n = 1, i = 0;
    char g, *l = calloc(n,sizeof(char));

    if(l == NULL){
        return NULL;
    }

    do{
        g = getchar();
        if(i >= n){
            n *= 2;
            l = realloc(l,n);
        }
        l[i] = g;
        
        if(l[i] != g){
            return NULL;
        }

        i++;

    }while(g!=c);

    return l;
}



int main(){
    printf("\nHai scritto: %s e sei stato zio perato", readline('\n'));
    return 0;
}