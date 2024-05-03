#include <stdio.h>
#include <stdlib.h>

//// Inicializar a estrutura
//// Inserir elementos na estrutura (Enqueue)
//// Peek()
//// Excluir elementos da estrutura (Deque)
//// Reinicializar a estrutura

typedef struct aux
{
    int chave;
    struct aux* proximo;

} NODE;

typedef NODE* PONT;

typedef struct 
{
    PONT head;
    PONT tail;
} FILA;

void inicarFila (FILA *f) 
{
    f->head = (PONT) malloc (sizeof (NODE));
    f->tail = f->head;
}

void enqueue (FILA *f, int num) 
{
    PONT new = (PONT) malloc (sizeof (NODE));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    new->chave = num;
    new->proximo = NULL;
    
    if (f->head == NULL) {
        f->head = new;
        f->tail = new;
        return;
    }

    f->tail->proximo = new;
    f->tail = new;

}

int deque (FILA *f) 
{
    if (f->head == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    PONT fifo = f->head;
    f->head = f->head->proximo;

    fifo->proximo = NULL;
    free(fifo);

    return fifo->chave;

}

int peek (FILA *f) 
{
    if (f->head == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    return f->head->chave;
}

void exibirFila (FILA* f)
{
    PONT walk = f->head;
    int i = 1;
    while (walk != NULL)
    {
        printf("%d) %d\n", i,  walk->chave);
        walk = walk->proximo;
        i++;
    }
    
    printf("Impressao Concluida\n");

    return;
}


void reiniciarFila (FILA *f)
{
    printf("\n");
    PONT walk = f->head->proximo;

    while (walk != NULL)
    {
        PONT apagar = walk;
        walk = walk->proximo;
        free(apagar);
    }

    f->head = NULL;
    f->tail = NULL;
    // f->tail = f->head;
    

    printf("Lista Limpa!\n");
    return;
}


int main (void)
{

    FILA fila;

    enqueue (&fila, 10);
    enqueue (&fila, 20);
    enqueue (&fila, 30);
    enqueue (&fila, 40);
    enqueue (&fila, 50);

    exibirFila(&fila);

    peek(&fila);

    printf("Proxio da fila: %d\n", peek(&fila));

    printf("\n");
    deque(&fila);
    exibirFila(&fila);
    printf("Proximo da fila: %d\n", peek(&fila));

    reiniciarFila (&fila);
    exibirFila(&fila);


    return 0;
}