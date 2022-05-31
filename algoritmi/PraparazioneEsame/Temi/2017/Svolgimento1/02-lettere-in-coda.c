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
    while(q->count != 0){
        putchar(dequeue(q));
    }
    free(q);
    q = NULL;
}


int main(int argc, char *argv[]){
  Queue q, v, c, s;

  q = init();
  v = init();
  c = init();
  s = init();

  char l;
  while((l = getchar()) != '\n'){
      enqueue(l, q);
  }

  while(q->count != 0){
        char l = dequeue(q);

        if(
            l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u'||
            l == 'A' || l == 'E' || l == 'I' || l == 'O' || l == 'U'
        ) enqueue(l, v);

        else if(
            l == 'w' || l == 'y' || l == 'j' || l == 'k' || l == 'x'||
            l == 'W' || l == 'Y' || l == 'J' || l == 'K' || l == 'X'
        ) enqueue(l, s);

        else enqueue(l, c);
  }
  free(q);
  q = NULL;

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