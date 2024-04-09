#include <stdio.h>

//// Inicializar a estrutura
//// Retornar a quantidade de elementos válidos
//TODO Exibir os elementos da estrutura
//TODO Buscar por um elemento na estrutura
//TODO Inserir elementos na estrutura
//TODO Excluir elementos da estrutura
//TODO Reinicializar a estrutura

// Cada elemento tem um sucessor e predecessor
// Cada elemento indica seu sucessor
// Saber onde está o primeiro elemento;
// Precisamos saber quais são os elementos disponíveis.

#define MAX 8
#define TIPOCHAVE int;
#define INVALIDO -1

//?
// typedef struct {
//     TIPOCHAVE chave;
// } REGISTRO;


typedef struct {
    // REGISTRO reg;
    int numChave;
    int prox;
} ELEMENTO;


typedef struct {
    ELEMENTO A[MAX];
    int inicio;
    int dispo;

} LISTA;


void InicializarLista(LISTA* lista) {
    int i;
    for (i = 0; i < MAX-1; i++) {
        lista->A[i].prox = i + 1;
    }
    lista->A[MAX-1].prox = INVALIDO;
    lista->inicio = INVALIDO;
    lista->dispo = 0;
}

void calculadorNumerosValidos (LISTA* lista) {
    int contadorNumValidos = 0;
    int i = 0;
    while (lista->A[i].numChave != INVALIDO)
    {
        contadorNumValidos++;
        i++;
    }

    lista->dispo = contadorNumValidos;
    
}

void AdicionarElementos(LISTA* lista, ELEMENTO inputElem) {
    int i;
    if (lista->inicio == INVALIDO) lista->inicio = inputElem.numChave;

}

void IMPRIMINDO (LISTA* lista) {
    int i;
    while (lista->A[i].prox != INVALIDO)
    {
        printf("%d\n",lista->A[i].numChave);
        i++;
        
    }
}

int main (void)
{
    LISTA minhaLista;
    InicializarLista(&minhaLista);
    printf("Lista Inicializada\n");

    ELEMENTO first = {10, NULL};

    AdicionarElementos(&minhaLista, first);


    IMPRIMINDO(&minhaLista);


    return 0;
}