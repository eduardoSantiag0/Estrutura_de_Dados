#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0
typedef int bool;

//? Considere o seguinte programa que manipula uma lista ligada circular:
//* Saída esperada: _______________ R: 30, 20, 10


typedef struct aux {
    int chave;
    struct aux* prox;
} ELEMENTO, *PONT;

typedef struct {
    PONT cabeca;
} LISTA_CIRCULAR;

void inicializarLista(LISTA_CIRCULAR* l) {
    l->cabeca = (PONT) malloc(sizeof(ELEMENTO));
    l->cabeca->prox = l->cabeca;
}

bool inserirElemLista(LISTA_CIRCULAR* l, int ch) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    if (novo == NULL) return false;
    novo->chave = ch;
    novo->prox = l->cabeca->prox;
    l->cabeca->prox = novo; // Último adicionado  é o próximo
    return true;
}

void imprimirLista(LISTA_CIRCULAR* l) {
    PONT atual = l->cabeca->prox;
    while (atual != l->cabeca) {
        printf("%d ", atual->chave);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    LISTA_CIRCULAR l;
    inicializarLista(&l);
    
    inserirElemLista(&l, 10);
    inserirElemLista(&l, 20);
    inserirElemLista(&l, 30);
    
    imprimirLista(&l);
    // 30, 20, 10
    return 0;
}
