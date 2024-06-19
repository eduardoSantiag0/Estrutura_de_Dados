#include <stdio.h>

#define MAX 5
#define true 1
#define false 0
typedef int bool;

//? Dado o seguinte código que manipula uma fila estática (não circular):
//* Saída esperada após a primeira impressão: _______________ R: 1, 2, 3, 4, 5;
//* Saída esperada após a segunda impressão: _______________ R: 3, 4, 5, 6, 7;

typedef struct {
    int chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int inicio;
    int numElementos;
} FILA;

void inicializarFila(FILA* f) {
    f->inicio = 0;
    f->numElementos = 0;
}

bool inserirElementoFila(FILA* f, REGISTRO reg) {
    if (f->numElementos == MAX) return false;
    int pos = (f->inicio + f->numElementos) % MAX;
    f->A[pos] = reg;
    f->numElementos++;
    return true;
}

bool removerElementoFila(FILA* f, REGISTRO* reg) {
    if (f->numElementos == 0) return false;
    *reg = f->A[f->inicio]; // Remove o primeiro
    f->inicio = (f->inicio + 1) % MAX;
    f->numElementos--;
    return true;
}

void imprimirFila(FILA* f) {
    for (int i = 0; i < f->numElementos; i++) {
        printf("%d ", f->A[(f->inicio + i) % MAX].chave);
    }
    printf("\n");
}

int main() {
    FILA f;
    REGISTRO r;
    
    inicializarFila(&f);
    
    r.chave = 1; inserirElementoFila(&f, r);
    r.chave = 2; inserirElementoFila(&f, r);
    r.chave = 3; inserirElementoFila(&f, r);
    r.chave = 4; inserirElementoFila(&f, r);
    r.chave = 5; inserirElementoFila(&f, r);
    
    imprimirFila(&f);
    
    removerElementoFila(&f, &r);
    removerElementoFila(&f, &r);
    
    r.chave = 6; inserirElementoFila(&f, r);
    r.chave = 7; inserirElementoFila(&f, r);
    
    imprimirFila(&f);
    return 0;
}
