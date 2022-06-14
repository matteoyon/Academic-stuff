#include <stdio.h>
#include <stdlib.h>

int robot(){
    int stackSize = 2, sp = -1, pairs = 0;
    char c, sx = 'Z', dx = 'Z', *stack = malloc(stackSize*sizeof(char));

    while((c = getchar()) != '\n'){
        if(sx == 'Z' && dx == 'Z'){
            printf("sx %c\n", c);
            sx = c;
        }else if(sx != 'Z' && dx == 'Z'){
            switch(sx){
                case 'F':
                    if(sp != -1 && stack[sp] == 'K'){
                        printf("dx pop F\n");
                        dx = 'K';
                        sp--;
                        ungetc(c,stdin);
                    }else{
                        printf("dx %c\n", c);
                        dx = c;
                    }
                    break;
                case 'K':
                    if(sp != -1 && stack[sp] == 'F'){
                        printf("dx pop K\n");
                        sx = 'F';
                        sp--;
                        ungetc(c,stdin);
                    }else{
                        printf("dx %c\n", c);
                        dx = c;
                    }
                    break;
            }
        }

        if(sx != 'Z' && dx != 'Z'){
            if(sx != dx){
                pairs++;
                printf("+1\n");
                sx = 'Z';
                dx = 'Z';
            }else{
                sp++;
                if(sp > stackSize){
                    stackSize *= 2;
                    stack = realloc(stack,stackSize*sizeof(char));
                }

                stack[sp] = dx;
                dx = 'Z';
                printf("dx push %c\n",stack[sp]);
            }
        }
    }

    printf("%d, %c ", pairs, sx);
    for(; sp >= 0; sp--){
        printf("%c ", stack[sp]);
    }
    printf("\n");

    if(sx == 'Z' && dx == 'Z' && sp == -1) return 0;

    return 1;
}

int main(void){
    printf("%d\n", robot());
    return 0;
}