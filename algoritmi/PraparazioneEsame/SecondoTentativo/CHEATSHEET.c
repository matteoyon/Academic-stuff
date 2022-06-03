/*

FORMATTAZIONE:
    %d intero
    %c carattere
    %s stringa

questa cosa figa:
    i > j ? i : j;

dimensione di un vettore di tipo qualsiasi:
    sizeof(a)/sizeof(a[0]);
    NB: dentro una funzione l'operatore sizeof NON PUO ESSERE USATO (usa invece e )

scanf con stringhe con spazi: 
    scanf("%[^\n]%*c", &variabile);

Regole di conversione implicita:
    •Espressioni aritmetiche: gli operandi vengono PROMOSSI
    •Assegnamenti: lato dx viene convertito al tipo del lato sx
    •Funzione definita o definita prima della chiamata: ogni argomento e convertito implicitamente al
        tipo del parametro corrispondente
    •Funzione non dichiarata o definita prima della chiamata: vengono eseguite promozioni di default

Per costanti come INT_MAX o INT_MIN
    #include <limits.h>

Stringhe:
    #include <string.h>

Dichiarazione e assegnamento puntatori:

    Questa scrittura:
        int i, *p;
        p = &i;

    E questa:
        int i;
        int *p = &i;
    
    SONO LA STESSA COSA (Anche se la seconda può sembrare fuorviante).


Se voglio dichiarare una variabile in una funzione e preservarla in memoria devo usare static:
    int fun(){
        static int i = 1;
        return i; 
    }
Non restituire mai un puntatore ad una variabile locale A MENO CHE non l'abbia dichiarata static.

SCRITTURE ILLEGALI:
    se a[N] array e *p intero:
    a++ >>>> NO
    a = p >>>> NO

    il NOME di un array è un puntatore COSTANTE all'inizio dell'array


Se voglio usare un vettore bidimensionale come argomento di una funzione, devo sempre specificare la seconda dimensione
    esempio:
    void stampa(char c[][10]){...}



Array frastagliato (ad esempio per un insieme di stringhe di lunghezza variabile)
    char *stringhe[7] = {"rosso", "arancione", "giallo", "verde", "blu", "indaco", "violetto"};



Il nome di un array di stringa può essere considerato come puntatore ad una stringa. Ad esempio come parametro di funzione,
si può usare INDIFFERENTEMENTE:
    char *c[]
    char **c
Ma devo utilizzare dichiarazioni diverse a seconda che usi array bidimensionali o frastagliati:
    char **c e c[][10] NON SONO LA STESSA COSA


ARGOMENTI IN LINEA DI COMANDO
    int main(int argc, char *argv[]){...}
    OPPURE
    int main(int argc, char **argv){...}
    
    argc -> #argomenti INCLUSO il nome del comando
    argv -> array frastagliato di stringhe di lunghezza argc+1

    argv[0] -> nome del comando
    argv[1] -> primo argomento
    argv[argv-1] -> ultimo argomento
    argv[argc] -> NULL (No segmentation fault, not yet)



ALLOCAZIONE DINAMICA
    NB: lo spazio che allochiamo dinamicamente non viene liberato in uscita dalle funzioni: va deallocato manualmente
    
    ********ATTENZIONE**********
    MALLOC, CALLOC E REALLOC restituiscono un puntatore a NULL SE l'allocazione non ha successo:
    è NECESSARIO gestire il caso dato che il rischio è quello di usare il puntatore a NULL come se stesse
    effettivamente puntando a memoria allocata e quindi provocare errori.
    ****************************


    MALLOC
    tipo* p;
    p = malloc(sizeInByte); //Per sizeInByte si può usare un espressione del tipo n*sizeof(tipo)

    Con la Malloc è necessario inizializzare



    CALLOC
    La calloc prende come argomento il numero di elementi, la size di ogni elemento e restituisce un  puntatore al primo elemento.
    INOLTRE TUTTO è GIA' INIZIALIZZATO A 0!!!!!

    tipo* p;
    p = calloc(numberOfElements, sizeOfElements);



    REALLOC
    ridimensiona lo spazio puntato da p alla nuova dimensione size.
    è importante usare sempre un puntatore temporaneo per il valore di ritorno di realloc.
    In caso contrario può succedere che il puntatore originario venga trasformato in NULL:

    int *p, *tmp;
    p = malloc(size);
    ....
    tmp = realloc(p, size); //NB: p deve già puntare ad un blocco allocato dinamicamente
    if(tmp!=NULL){
        ptr=tmp;
    }

    Realloc cerca di ridimensionare il vettore in loco, ma se non ce la fa lo rialloca altrove:
    ATTENZIONE AGLI AGGIORNAMENTI DI ALTRI RIFERIMENTI dopo che si è chiamato realloc


    FREE
    dealloca lo spazio di memoria

    free(p);
    p = NULL; //Necessario, così viene dimenticato l'indirizzo a cui puntava p, che NON DEVE PIU' INTERESSARMI

    ***********ATTENZIONE AI MEMORY LEAK***********
    p = malloc(...)
    q = malloc(...)
    p = q; //In questo caso p non punta più all'area di memoria  di due righe sopra, MA
           //Quell'area non è più utilizzabile perchè non è stata fatta la free: STO SPRECANDO MEMORIA.
    
    è necessario deallocare prima di riassegnare:
    p = malloc(...)
    q = malloc(...)
    free(p);
    p = q;
    ***********************************************

INTERFACCE E CLIENT
    Se vuoi creare una libreria:
    -file .h e .c
    -includi il file .h tra "" nel file main e nel file .c
    -In compilazione devi compilare tutti i file .c
    -Protezione con #ifndef OPPURE (non ufficiale ma si fa) #pragma once

STRUTTURE DI DATI:
    Pila -> linkedList
    Coda -> bidirectional LinkedList

    Heap -> dato che uno heap è un albero binario completo per definizione,
            può essere comodo rappresentare uno heap come un array: {IGNORE,1,2,3,4,5,6,7,8,9,10,11}
            Si usa IGNORE perchè ci facilita il calcolo dei figli sinistro e destro:
            Nodo i:
                figlio sx := 2i
                figlio dx := 2i+1
                padre di i:= i/2 (divisione intera)

NEXT CHAR come in Java:
    puoi fare una cosa del tipo:
        char u;
        u = getchar();
        ////////fai quello che devi fare con u/////////
        ungetc(u,stdin);

        

*/