#include <stdio.h>
#include <malloc.h>

//? Preencha as lacunas abaixo com o que seria impresso pela execução do programa:
//* Saída esperada: _______________ R: 30, 20, 10

#define true 1
#define false 0
typedef int bool;

typedef struct aux {
    int chave;
    struct aux* prox;
} ELEMENTO, *PONT;

typedef struct {
    PONT inicio;
} LISTA_LIGADA;

void inicializarLista(LISTA_LIGADA* l) {
    l->inicio = NULL;
}

bool inserirElemLista(LISTA_LIGADA* l, int ch) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    if (novo == NULL) return false;
    novo->chave = ch;

    novo->prox = l->inicio;
    l->inicio = novo;
    
    return true;
}

void imprimirLista(LISTA_LIGADA* l) {
    int cont = 0;
    PONT atual = l->inicio;
    while (atual != NULL) {
        cont++;
        printf(" %d -> %d\n", cont, atual->chave);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    LISTA_LIGADA l;
    inicializarLista(&l);
    
    inserirElemLista(&l, 10);
    inserirElemLista(&l, 20);
    inserirElemLista(&l, 30);
    
    imprimirLista(&l);
    return 0;
}

