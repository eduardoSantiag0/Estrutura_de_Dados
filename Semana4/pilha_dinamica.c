#include <stdio.h>
#include <malloc.h>

//// Inserir
//// Remover
//// Exibir
//// Iniciar
//// Reiniciar

typedef struct aux{
    int chave;
    struct aux* prox;

} ELEMENTO;


typedef struct 
{
    ELEMENTO* topo;
    
} PILHA;

void iniciarLista(PILHA* p) {
    p->topo = NULL;
    printf("Lista criada\n");
    return;
}

void pushElemento (PILHA* p, int inputAdd) {
    ELEMENTO* novoElemento = (ELEMENTO*) malloc (sizeof(ELEMENTO)); 
    novoElemento->chave = inputAdd;

    // p->topo->prox = p->topo;
    novoElemento->prox = p->topo;
    p->topo = novoElemento;
    return;
}

void exibirPilha (PILHA* p)  {
    ELEMENTO* end = p->topo;

    while (end != NULL)
    {
        printf("%d\n", end->chave);
        end = end->prox;
    }
    
}

void popElemento (PILHA* p) {
    if (p->topo == NULL) return;
    ELEMENTO* apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);
}

void reiniciarPilha (PILHA* p) {
    while (p->topo != NULL)
    {
        ELEMENTO* apagar = p->topo;
        p->topo = p->topo->prox;
        free(apagar);
    }
    printf("Pilha apagada com sucesso\n");
    return;
}

int main (void) {
    PILHA pilhaDinamica;

    iniciarLista(&pilhaDinamica);
    pushElemento(&pilhaDinamica, 10);
    pushElemento(&pilhaDinamica, 20);
    pushElemento(&pilhaDinamica, 50);
    pushElemento(&pilhaDinamica, 40);
    pushElemento(&pilhaDinamica, 30);
    exibirPilha(&pilhaDinamica);

    printf("\n");

    popElemento(&pilhaDinamica);
    popElemento(&pilhaDinamica);
    exibirPilha(&pilhaDinamica);

    reiniciarPilha(&pilhaDinamica);
    exibirPilha(&pilhaDinamica);
}