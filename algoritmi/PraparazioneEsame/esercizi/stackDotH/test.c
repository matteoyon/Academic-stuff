#include "stack.h"
#include <stdio.h>

int main(){
    make_empty();
    is_empty();
    print_stack();
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    putchar('\n');
    print_stack();
    putchar('\n');
    printf("TOP: %d",top());
    push(6);
    push(7);
    push(8);
    push(9);
    push(10);
    putchar('\n');
    printf("%d", is_full());
    putchar('\n');
    printf("%d",top());
    pop();
    pop();
    pop();
    print_stack();
    make_empty();
    print_stack();
    pop();

    printf("\nSiamo ancora vivi");
    return(0);
}