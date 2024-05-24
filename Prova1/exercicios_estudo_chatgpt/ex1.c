#include <stdio.h>
#define MAX 100

//? Considere a seguinte implementação de uma lista sequencial:
//? Preencha as lacunas abaixo com o que seria impresso pela execução do programa:

//! Resposta

// Tamanho da lista: _______________ R: 3
// Elemento 0: _______________ R: 10
// Elemento 1: _______________ R: 30
// Elemento 2: _______________ R: 20

typedef struct {
    int chave;
    // outros campos...
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int nroElem;
} LISTA;

void inicializarLista(LISTA* l) {
    l->nroElem = 0;
}

int tamanho(LISTA* l) {
    return l->nroElem;
}

int inserirElemLista(LISTA* l, REGISTRO reg, int i) {
    if (i < 0 || i > l->nroElem || l->nroElem == MAX) return 0;
    for (int j = l->nroElem; j > i; j--) { // j > i == Está inserindo onde já tem um número
        l->A[j] = l->A[j - 1]; // Abrindo Espaço
    }
    l->A[i] = reg; // Adiciona o número
    l->nroElem++;
    return 1;
}


int main() {
    LISTA l;
    REGISTRO r;
    inicializarLista(&l);
    
    r.chave = 10;
    inserirElemLista(&l, r, 0);

    r.chave = 20;
    inserirElemLista(&l, r, 1);
    
    r.chave = 30;
    inserirElemLista(&l, r, 1);

    printf("Tamanho da lista: %d\n", tamanho(&l));
    for (int i = 0; i < l.nroElem; i++) {
        printf("Elemento %d: %d\n", i, l.A[i].chave);
    }
    return 0;
}

