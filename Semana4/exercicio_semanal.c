#include <stdio.h>
#define MAX 5


//! Objetivo:  Fazer uma pilha que imprima ao inverso


typedef struct 
{
    int chave;
} ELEMENTO;


typedef struct 
{
    int topo;
    ELEMENTO A[MAX];
} PILHA;

void iniciarPilha(PILHA* p) {
    p->topo = -1;
}

void adicionarPilha (PILHA* p, int inputAdd) {
    if (p->topo >= MAX-1) return;

    ELEMENTO novoElemento = {inputAdd};

    p->topo ++;
    p->A[p->topo] = novoElemento;
    return;

}

void pop(PILHA* p) {
    p->topo--;
    return;
}

void exibirInverso (PILHA* p) {
    int i;

    printf("\tNormal\n");
    for (i = p->topo; i >= 0; i--) {
        printf("%d\n", p->A[i].chave);
    }

    printf("\tInverso\n");
    for (i = 0; i <= p->topo; i++) {
        printf("%d\n", p->A[i].chave);
    }
}

int main (void) {
    PILHA pilha;
    iniciarPilha (&pilha);
    adicionarPilha(&pilha, 10);
    adicionarPilha(&pilha, 20);
    adicionarPilha(&pilha, 30);
    adicionarPilha(&pilha, 40);
    exibirInverso(&pilha);

    pop(&pilha);
    exibirInverso(&pilha);


    return 0;
}