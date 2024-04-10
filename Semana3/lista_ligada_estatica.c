#include <stdio.h>

//// Inicializar a estrutura
//// Exibir os elementos da estrutura
//// Inserir elementos na estrutura
//TODO Retornar a quantidade de elementos válidos
//TODO Buscar por um elemento na estrutura
//TODO Excluir elementos da estrutura
//TODO Reinicializar a estrutura

// Cada elemento tem um sucessor e predecessor
// Cada elemento indica seu sucessor
// Saber onde está o primeiro elemento;
// Precisamos saber quais são os elementos disponíveis.

#define MAX 8
#define TIPOCHAVE int;
#define INVALIDO -1
#define bool int

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

int  calculadorNumerosValidos (LISTA* lista) {
    int contadorNumValidos = 0;
    int i = 0;
    while (lista->A[i].numChave != INVALIDO)
    {
        contadorNumValidos++;
        i++;
    }

    return contadorNumValidos;
}

void AdicionarElementos(LISTA* lista, int inputElem) {
    if (lista->dispo >= MAX) {
        printf("Lista Cheia");
        return;
    }

    int pos = lista->dispo;
    // Caso seja o primeiro item;
    if (lista->inicio == INVALIDO) {
        lista->inicio = inputElem;
        lista->A[0].numChave = inputElem;
        lista->A[0].prox = INVALIDO; //!!!!!
        lista->dispo++;
        return;
    } 

    lista->A[pos].numChave = inputElem;
    lista->A[pos].prox = INVALIDO;
    lista->dispo++;

}

bool excluirElemento (LISTA* lista, int inputElim) {
    // Reescrever o anterior
    int i = 0;
    while (lista->A[i].numChave != INVALIDO ) {
        printf("%d -", lista->A[i].numChave);
        if (lista->A[i].numChave == inputElim) {
            lista->A[i-1].prox = lista->A[i+1].prox;
            lista->dispo--;
            return 0;
        }
        i++;
    }
    printf("Nao foi encontrado esse valor");
    return INVALIDO;
}

void IMPRIMINDO (LISTA* lista) {
    int i = lista->inicio;
    for (i = 0; i < lista->dispo; i++) {
        printf("%d\n",lista->A[i].numChave);
    }
}

int main (void)
{
    LISTA minhaLista;
    InicializarLista(&minhaLista);
    printf("\tLista Inicializada\n");

    AdicionarElementos(&minhaLista, 10);
    AdicionarElementos(&minhaLista, 20);
    AdicionarElementos(&minhaLista, 30);
    AdicionarElementos(&minhaLista, 40);
    AdicionarElementos(&minhaLista, 50);
    AdicionarElementos(&minhaLista, 60);
    AdicionarElementos(&minhaLista, 70);
    AdicionarElementos(&minhaLista, 80);
    // excluirElemento (&minhaLista, 60);
    int cont = calculadorNumerosValidos(&minhaLista);
    printf("\n%d\n", cont);



    printf("\n\tLista Apos Adicoes\n");

    IMPRIMINDO(&minhaLista);


    return 0;
}