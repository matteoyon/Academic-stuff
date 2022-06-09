#include <stdio.h>
#include <stdlib.h>

void press(int *c, int n, int i){
    c[i%n] = -1 * (c[i%n] - 1);
    c[(i-1)%n] = -1 * (c[(i-1)%n] - 1);
    c[(i+1)%n] = -1 * (c[(i+1)%n] - 1);
}

void printError(){
    printf("ERRORE: RETE NON CREATA\n");
}

int main(){
    char comando;
    int n, temp, m;
    int *c = NULL;

    while(1){
        scanf("%c", &comando);

        switch(comando){
            case '+':
                scanf(" %d", &n);
                free(c);
                c = calloc(n,sizeof(int));
                break;
            
            case 'o':
                if(c){
                    for(int i = 0; i < n; i++){
                        scanf(" %d", &c[i]);
                    }
                }else{
                    printError();
                }
                break;
            
            case 'p':
                if(c){
                    for(int i = 0; i < n; i++){
                        printf("%d ", c[i]);
                    }
                    printf("\n");
                }else{
                    printError();
                }                    
                    break;
            
            case 's':
                if(c){
                    scanf(" %d", &temp);
                    press(c,n,temp+n-1);
                }else{
                    printError();
                }
                break;

            case 'S':
                if(c){
                    scanf(" %d", &m);
                    for(int i = 0; i < m; i++){
                        scanf(" %d", &temp);
                        press(c,n,temp+n-1);
                    }
                }else{
                    printError();
                }
                break;

            case 'f':
                return 0;
                break;

        }
    }


    return 0;
}