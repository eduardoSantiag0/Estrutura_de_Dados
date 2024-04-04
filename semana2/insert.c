#include <stdio.h>
#include <stdbool.h>
#define MAX 50

typedef int TiPOCHAVE;

typedef struct 
{
    TiPOCHAVE chave;
} REGISTRO;

typedef struct 
{
    REGISTRO A[MAX];
    int numElem; 
} LISTA;


bool inserirElemLista(LISTA* arranjo, REGISTRO inputNum, int inputPosicao){
    int j;

    if ((arranjo->numElem == MAX) || (inputPosicao < 0) || (inputPosicao > arranjo->numElem))
        return false;
    
    
    for (j = arranjo->numElem; j > inputPosicao; j--) 
        arranjo->A[j] = arranjo->A[j-1];

    arranjo->A[inputPosicao] = inputNum;
    arranjo->numElem++;
    return true;
}

int main (void)
{
    LISTA lista;

    lista.numElem = 0;
    
    REGISTRO reg1 = {10}; 
    REGISTRO reg2 = {20}; 
    REGISTRO reg3 = {400}; 
    REGISTRO reg4 = {66}; 
    
    inserirElemLista(&lista, reg1, 0); 
    inserirElemLista(&lista, reg2, 1); 
    printf("Second element: %d\n", lista.A[1].chave);
    inserirElemLista(&lista, reg3, 1); 
    printf("Second element: %d\n", lista.A[1].chave);
    inserirElemLista(&lista, reg4, 1); 
    
    printf("Number of elements in the list: %d\n", lista.numElem);
    printf("Second element: %d\n", lista.A[1].chave);


    return 0;
}