#include <stdio.h>

//// Iniciar Lista
//// Retornar elementos válidos
// Buscar por um elemento na lista
//// Inserir elementos - Push
//// Exibir elementos 
//// Excluir elementos - Pop
//// Reiniciar lista

#define MAX 4

typedef struct 
{
    int chave;
} REGISTRO;

typedef struct 
{
    REGISTRO A[MAX];
    int topo;
} PILHA;

void iniciarPilha (PILHA* p) {
    p->topo = -1;
}

void pushElemento (PILHA* p, REGISTRO reg) {
    if (p->topo >= MAX-1) {
        printf("Pilha Cheia\n");
        return;
    } 
    p->topo = p->topo + 1;
    p->A[p->topo] = reg; //!!!!!!!!
    printf("\tAdicionado %d na pilha\n", reg.chave);
    return;
}

void exibirPilha (PILHA* p) {
    if (p->topo == -1) {
        printf("Pilha Vazia\n");
        return;
    }

    int i;

    for (i = p->topo; i >= 0; i--) {
        printf("%d -> %d \n", i, p->A[i].chave);
    }
    
    printf("\n");
}


int numeroElemValidos(PILHA* p) {
    return p->topo + 1;
}

void popElemento (PILHA* p) {
    if (p->topo == -1) {
        printf("Lista vazia\n");
        return;
    }

    // *reg = p->A[p->topo];
    // If the stack is not empty, this line copies the element at the top of the stack (p->A[p->topo]) into the memory location pointed to by reg. This allows the caller of the function to access the removed element.

    p->topo = p->topo - 1;  

    return;
}

void reiniciarPilha (PILHA* p) {
    p->topo = -1;
}

int buscarElemento (PILHA* p, int inputBuscar) {
    int i;

    for (i = p->topo; i >= 0; i--) {
        if ( p->A[i].chave == inputBuscar) {
            printf("Numero encontrado na posicao: %d\n", i);
            return i;
        }
    }
    printf("Numero nao encontrado\n");
    return -1;
}

int main (void) {
    PILHA pill;

    iniciarPilha(&pill);
    REGISTRO re1 = {10};
    REGISTRO re2 = {20};
    REGISTRO re3 = {30};
    REGISTRO re4 = {50};
    REGISTRO re5 = {55};
    pushElemento (&pill, re1);
    pushElemento (&pill, re3);
    pushElemento (&pill, re2);
    pushElemento (&pill, re4);
    pushElemento (&pill, re5);
    exibirPilha(&pill);

    int pos = buscarElemento(&pill, 50);
    printf("%d", pos);
    popElemento(&pill);
    popElemento(&pill);
    exibirPilha(&pill);

    reiniciarPilha(&pill);
    exibirPilha(&pill);

}