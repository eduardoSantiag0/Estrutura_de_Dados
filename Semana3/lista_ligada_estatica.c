#include <stdio.h>

//// Inicializar a estrutura
//TODO Retornar a quantidade de elementos válidos
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

void AdicionarElementos(LISTA* lista, int inputElem) {
    int pos = lista->dispo;
    // Caso seja o primeiro item;
    if (lista->inicio == INVALIDO) {
        lista->inicio = inputElem;
        lista->A[0].numChave = inputElem;
        lista->A[0].prox = INVALIDO;
    }

    int i = 0;
    while (lista->A[i].prox != INVALIDO)
    {
        i++;
    } 
    lista->A[i].prox = inputElem;


}

void IMPRIMINDO (LISTA* lista) {
    //!
    int i = lista->inicio;
    while (lista->A[i].prox != INVALIDO)
    {
        printf("%d\n",lista->A[i].numChave);
        i = lista->A[i].prox; //!
    }
}

int main (void)
{
    LISTA minhaLista;
    InicializarLista(&minhaLista);
    printf("\tLista Inicializada\n");

    AdicionarElemento(&minhaLista, 10);
    AdicionarElemento(&minhaLista, 20);
    AdicionarElemento(&minhaLista, 30);
    AdicionarElemento(&minhaLista, 40);

    printf("\tLista Após Adicoes\n");
    IMPRIMINDO(&minhaLista);


    return 0;
}