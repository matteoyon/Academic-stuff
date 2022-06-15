void dfs1(Graph g, int i, int *aux) {
    Node t;
    aux[i] = 1;
    for(t = g->list[i]; t; t = t->next)
        if(!aux[t->key]) {
            printf("%d,",t->key);
            dfs1(g,t->key,aux);
        }
}

void dfs(struct graph *g) {
    int i, *aux = calloc(g->n,sizeof(int));
    if(!aux) { fprintf(stderr,"Errore di Allocazione\n"); exit(-4); }
    for(i = 0; i < g->n; i++)
        if(!aux[i]) {
            printf("\n%d,",i);
            dfs1(g,i,aux);
        }
    free(aux);
}


//BFS
void bfs1(Graph *g, int i, int *aux) {
    Node *t;
    Intqueue *q = createqueue();
    enqueue(q,i);
    while(!emptyq(q)) {
        i = dequeue(q);
        aux[i] = 1;
        for(t = g->list[i]; t; t = t->next)
            if(!aux[t->n]) {
                enqueue(q,t->n -1);
                printf("%d,",t->n);
                aux[t->n] = 1;
            }       
    }
    destroyqueue(q);
}

void bfs(Graph *g) {
    int i, *aux = calloc(g->n,sizeof(int));
    if(!aux) { fprintf(stderr,"Errore di Allocazione\n"); exit(-4); }
    for(i = 0; i < g->n; i++)
        if(!aux[i]) {
            printf("\n%d,",i);
            bfs1(g,i,aux);
        }
    free(aux);
}