#include <stdio.h>
#include <malloc.h>


#define true 1
#define false 0
typedef int bool;

//? Analise o seguinte programa que utiliza duas filas para implementar uma fila de prioridade:
//* Saída esperada: _______________ R: 2, 4, 1, 3

typedef struct aux {
    int chave;
    struct aux* prox;
} ELEMENTO, *PONT;

typedef struct {
    PONT inicio;
} FILA;

void inicializarFila(FILA* f) {
    f->inicio = NULL;
}

bool inserirElementoFila(FILA* f, int ch) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    if (novo == NULL) return false;
    novo->chave = ch;
    novo->prox = NULL;
    
    if (f->inicio == NULL) {
        f->inicio = novo;
    } else {
        PONT atual = f->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    return true;
}

bool removerElementoFila(FILA* f, int* ch) {
    if (f->inicio == NULL) return false;
    PONT apagar = f->inicio;
    *ch = apagar->chave;
    f->inicio = f->inicio->prox;
    free(apagar);
    return true;
}

void imprimirFila(FILA* f) {
    PONT atual = f->inicio;
    while (atual != NULL) {
        printf("%d ", atual->chave);
        atual = atual->prox;
    }
    printf("\n");
}

typedef struct {
    FILA normal;
    FILA prioridade;
} FILA_PRIORIDADE;

void inicializarFilaPrioridade(FILA_PRIORIDADE* f) {
    inicializarFila(&f->normal);
    inicializarFila(&f->prioridade);
}

bool inserirElementoFilaPrioridade(FILA_PRIORIDADE* f, int ch, bool isPrioridade) {
    if (isPrioridade) {
        return inserirElementoFila(&f->prioridade, ch);
    } else {
        return inserirElementoFila(&f->normal, ch);
    }
}

bool removerElementoFilaPrioridade(FILA_PRIORIDADE* f, int* ch) {
    if (!removerElementoFila(&f->prioridade, ch)) {
        return removerElementoFila(&f->normal, ch);
    }
    return true;
}

int main() {
    FILA_PRIORIDADE fp;
    int ch;
    inicializarFilaPrioridade(&fp);
    
    inserirElementoFilaPrioridade(&fp, 1, false); 
    inserirElementoFilaPrioridade(&fp, 2, true); 
    inserirElementoFilaPrioridade(&fp, 3, false); 
    inserirElementoFilaPrioridade(&fp, 4, true); 
    
    while (removerElementoFilaPrioridade(&fp, &ch)) {
        printf("%d ", ch);
    }
    printf("\n");
    return 0;
}
