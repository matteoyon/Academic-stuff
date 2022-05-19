#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct stack{
    int top;
    int array[LENGTH];
} Stack;

Stack s;

/* svuota la pila */
void make_empty(){
    s.top = -1;
};

/* restituisce 1 se la pila e' vuota, 0 altrimenti */
int is_empty(){
    if(s.top == -1) return 1;
    return 0;
};

/* restituisce 1 se la pila e' piena, 0 altrimenti */
int is_full(){
    if(s.top == LENGTH -1) return 1;
    return 0;
};

/* se la pila non e' vuota, restituisce il top de1la pila; 
altrimenti esce con messaggio di errore. */
int top(){
    if(is_empty() == 1){
        printf("\nLa pila è vuota");
        exit(0);
    }else{
        return s.array[s.top];
    }
};

/* se la pila non e' vuota, estrae il top da1la pila; 
altrimenti esce con messaggio di errore. */
int pop(){
     if(is_empty() == 1){
        printf("\nLa pila è vuota");
        exit(0);
    }else{
        int toReturn = s.array[s.top];
        s.top--;
        return toReturn;
    }
};

/* se c'e' spazio, aggiunge n alla pila; 
altrimenti esce con messaggio d'errore. */
void push( int n){
    if(s.top >= LENGTH-1){
        printf("\nLa pila è piena");
        exit(0);
    }else{
        s.top++;
        s.array[s.top] = n;
    }
};

/* stampa il contenuto della pila, partendo dal top. */
void print_stack(){
    printf("{");
    int p = s.top;
    while (p >= 0){
        printf("%d ", s.array[p--]);
    }
    printf("}");
}