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
    PILHA din_pilha;

    iniciarLista(&din_pilha);
    pushElemento(&din_pilha, 10);
    pushElemento(&din_pilha, 20);
    pushElemento(&din_pilha, 50);
    pushElemento(&din_pilha, 40);
    pushElemento(&din_pilha, 30);
    exibirPilha(&din_pilha);

    printf("\n");

    popElemento(&din_pilha);
    popElemento(&din_pilha);
    exibirPilha(&din_pilha);

    reiniciarPilha(&din_pilha);
    exibirPilha(&din_pilha);
}