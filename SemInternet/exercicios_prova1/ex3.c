#include <stdio.h>
#define MAX 50

#define true 1
#define false 0
typedef int bool;

//? Descreva o que o código acima faz e aponte possíveis melhorias.
// Fila com númmero máximo de elementos
// Deque


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
    int pos = (f->inicio + f->numElementos) % MAX; //!!!
    f->A[pos] = reg;
    f->numElementos++;
    return true;
}

int main (void)
{
    FILA fila;
    inicializarFila(&fila);


    int laelu = 1 % 50;
    printf("%d\n", laelu);
    laelu = 2 % 50;
    printf("%d\n", laelu);
    laelu = 3 % 50;
    printf("%d\n", laelu);
    laelu = 4 % 50;
    printf("%d\n", laelu);
    laelu = 5 % 50;
    printf("%d\n", laelu);

    return 0;
}