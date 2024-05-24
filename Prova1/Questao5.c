#include <stdio.h>
#define true 1
#define false 0
#define MAX 50

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    int inicio;
    int numElementos;
    REGISTRO A[MAX];
} FILA;

void inicializarFila(FILA *f) {
    f->inicio = 0;
    f->numElementos = 0;
}

bool inserirElementoFila(FILA* f, REGISTRO reg) {
    if (f->numElementos == MAX) return false; 
    // if (f->inicio == NULL) return false;
    f->A[f->numElementos] = reg;
    f->numElementos++;
    return true;
}

bool removerElementoFila(FILA* f, REGISTRO* reg) {
    if (f->numElementos == 0) return false; // Fila vazia
    *reg = f->A[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->numElementos--;
    return true;
}

void imprimirFila(FILA* f) {
    int i;
    for (i = 0; i < f->numElementos; i++) {
        int pos = (f->inicio + i) % MAX;
        printf("Elemento %d: %d\n", i, f->A[pos].chave);
    }
}

int main() {
    FILA f;
    REGISTRO r;

    inicializarFila(&f);

    // Inserir elementos na fila
    r.chave = 10;
    inserirElementoFila(&f, r);
    r.chave = 20;
    inserirElementoFila(&f, r);
    r.chave = 30;
    inserirElementoFila(&f, r);

    // Imprimir a fila
    imprimirFila(&f);

    // Remover elementos da fila
    // removerElementoFila(&f, &r);
    // printf("Removido: %d\n", r.chave);
    // removerElementoFila(&f, &r);
    // printf("Removido: %d\n", r.chave);

    // Imprimir a fila novamente

    return 0;
}
