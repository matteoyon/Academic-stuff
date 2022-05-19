#include <stdio.h>
#include <stdlib.h>

/*
NON POSSO USARE typedef perchè è presente un puntatore ad una struct delo stesso tipo: uso un tag
*/
typedef struct node {
    int value; //Dato memorizzato
    struct node *next; //Puntatore al prossimo nodo
} *Node;


Node newLinkedList(){
    Node list = NULL;
    return list;
}

Node prependNewNode(Node list, int n){
    //Creazione
    Node newNode;
    newNode = malloc(sizeof(struct node));

    //Valore
    newNode->value = n;

    //Inserimento in testa
    newNode -> next = list;
    list = newNode;

    //Return
    return newNode;
}

Node appendNewNode(Node list, int n){
    //Creazione
    Node newNode;
    newNode = malloc(sizeof(struct node));


    //valore
    newNode -> value = n;
    newNode -> next = NULL;
    
    //Inserimento in coda
    Node toIterate = list;

    if(toIterate == NULL){
        return newNode;
    }

    while(toIterate -> next){
        toIterate = toIterate -> next;
    }
    toIterate -> next = newNode;
    
    //RETURN
    return list;
}

void showList(Node list){
    Node toIterate = list;
    if (toIterate){
        while(toIterate -> next != NULL){
            printf("[%d]->", toIterate -> value);
            toIterate = toIterate -> next;
        }
        toIterate -> value ? printf("[%d]\n", toIterate -> value) : printf("[X]\n");
    }else{
        printf("[X] (void list)\n");
    }
}

Node searchInList(Node list, int n){
    Node p;

    for(p = list; p != NULL; p = p -> next){
        if(p->value == n){
            return p;
        }
    }

    return NULL;
}

Node deleteNode(Node list, int n){

    for(Node cur = list, prev = NULL; cur != NULL && cur -> value != n; prev = cur, cur = cur -> next);

    if (cur == NULL){
        return list;
    } else if(prev == NULL) {
        list = list -> next;
    }else{
        prev -> next = cur -> next;
    }
    
    free(cur);
    return list;
}

int main(){

    Node mylist = newLinkedList();
    mylist = appendNewNode(mylist, 12);
    mylist = prependNewNode(mylist, 7);
    mylist = prependNewNode(mylist, 9);
    mylist = appendNewNode(mylist, 19);
    showList(mylist);
    
    Node target = searchInList(mylist, 7);

    printf("L'indirizzo del nodo cercato è: %d\n", target);
}