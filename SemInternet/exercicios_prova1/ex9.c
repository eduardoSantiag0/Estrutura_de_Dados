#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0
typedef int bool;

//? Dada a seguinte implementação de uma matriz esparsa utilizando lista ligada:
//* Saída esperada: _______________ 30, 20, 10

typedef struct aux {
    int linha, coluna;
    int valor;
    struct aux* prox;
} ELEMENTO, *PONT;

typedef struct {
    PONT inicio;
} MATRIZ;

void inicializarMatriz(MATRIZ* m) {
    m->inicio = NULL;
}

bool inserirElementoMatriz(MATRIZ* m, int linha, int coluna, int valor) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    if (novo == NULL) return false;
    novo->linha = linha;
    novo->coluna = coluna;
    novo->valor = valor;

    //!!!
    novo->prox = m->inicio; // Matriz fim ao começo == Pilha ??
    m->inicio = novo;
    return true;
}

void imprimirMatriz(MATRIZ* m) {
    PONT atual = m->inicio;
    while (atual != NULL) {
        printf("Linha: %d, Coluna: %d, Valor: %d\n", atual->linha, atual->coluna, atual->valor);
        atual = atual->prox;
    }
}

int main() {
    MATRIZ m;
    inicializarMatriz(&m);
    
    inserirElementoMatriz(&m, 1, 1, 10);
    inserirElementoMatriz(&m, 2, 3, 20);
    inserirElementoMatriz(&m, 4, 1, 30); 
    
    imprimirMatriz(&m);
    return 0;
}

