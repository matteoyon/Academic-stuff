#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct element {  // definizione di un elemento della lista
  char ch;
  struct element *next;    // prossimo elemento
};

typedef struct queue {
  struct element *head;
  struct element *tail;
  int count;
} *Queue;

Queue init();
void enqueue(char ch, Queue q);
char dequeue(Queue q); // assume che la coda non sia vuota

// inserite qui la funzione extract e eventuali altre funzioni aggiuntive
void extract(Queue q){
    printf("\n");
    while(q -> count > 0){
        printf("%c", dequeue(q));
    }
}


int main( int argc, char **argv ){
  Queue q, v, c, s;
  char k;

  q = init();
  v = init();
  c = init();
  s = init();

  // lettura delle lettere e inserimento nella coda q
  while((k = getchar()) != '\n'){
    enqueue(k,q);
  }

  // estrazione dalla coda e distribuzione delle lettere nelle code v,c,s
  while(q -> count > 0){
    k = dequeue(q);
        if (k == 'w' || k == 'y' || k == 'j' || k == 'k' || k =='x' || k == 'W' || k == 'Y' || k == 'J' || k == 'K' || k == 'X'){
            enqueue(k,s);
        }else if (k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u' || k == 'A' || k == 'E' || k == 'I' || k == 'O' || k == 'U'){
            enqueue(k,v);
        }else{
            enqueue(k,c);
        }
    }
  

  // stampa della coda opportuna
  switch( *argv[1] ) {
    case 'V': extract(v);
      break;
    case 'C': extract(c);
      break;
    case 'S': extract(s);
  }

  return 0;
}



Queue init(){
  Queue q = malloc(sizeof(struct queue));
  q->head = NULL;
  q->count = 0;
  return q;
}

void enqueue(char ch, Queue q){
  struct element *new = malloc(sizeof(struct element));
  new->ch = ch;
  new->next = NULL;
  if (q->head == NULL)
    q->head = new; // la coda era vuota
  else {
    q->tail->next = new; // attacco in coda
  }
  q->tail = new;
  q->count++;
}

// assumo che la coda non sia vuota
char dequeue(Queue q){
  char ch;
  struct element *testa = q->head;
  ch = testa->ch;
  q->head = q->head->next;
  free(testa);
  q->count--;
  return ch;
}