#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef int bool;
typedef int TIPOCHAVE;

typedef struct{
  TIPOCHAVE chave;
} REGISTRO;

typedef struct {
  REGISTRO A[MAX+1];
  int numElem;
} LISTA;

void inicializarLista(LISTA* arranjo) {
    arranjo->numElem = 0;
}

int adicionarElemento(LISTA* arranjo, REGISTRO inputNum) {
    int tam_atual = arranjo->numElem;
    if (tam_atual >= MAX || inputNum.chave < 0) {
        return -1;
    }

    arranjo->A[tam_atual] = inputNum;

    arranjo->numElem++;
    return 0;
}

int main (void) {

    LISTA lista;
    // Iniciar lista
    inicializarLista(&lista);


    REGISTRO reg1 = {10};
    // Add Elemento
    adicionarElemento (&lista, reg1);

    int i;

    printf("%d\n", lista.A[0].chave);



    return 0;
}