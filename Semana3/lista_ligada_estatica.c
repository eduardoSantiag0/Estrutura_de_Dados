#include <stdio.h>

//// Inicializar a estrutura
//// Exibir os elementos da estrutura
//// Inserir elementos na estrutura
//// Retornar a quantidade de elementos válidos
//// Buscar por um elemento na estrutura
//// Excluir elementos da estrutura
//// Reinicializar a estrutura
//// Ordenar Lista Ligada

//* Cada elemento tem um sucessor e predecessor
//* Cada elemento indica seu sucessor
//* Saber onde está o primeiro elemento;
//* Precisamos saber quais são os elementos disponíveis.

#define MAX 8
#define TIPOCHAVE int;
#define INVALIDO -1
#define bool int

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

void ReinicializarLista(LISTA* lista) {
    lista->inicio = INVALIDO;
    lista->dispo = 0;
}

int  calculadorNumerosValidos (LISTA* lista) {
    int contadorNumValidos = 0;
    int i = lista->inicio;
    printf("\nLISTA Endereco: %p\n", lista);
    while (i != INVALIDO)
    {
        contadorNumValidos++;
        i = lista->A[i].prox;
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
        lista->inicio = pos;
        lista->A[pos].numChave = inputElem;
        lista->A[pos].prox = INVALIDO; //!!!!!
        lista->dispo++;
        return;
    } 

    lista->A[pos].numChave = inputElem;
    lista->A[pos].prox = INVALIDO;


    int i = lista->inicio;
    while (lista->A[i].prox != INVALIDO) {
        i = lista->A[i].prox; //!!!!!
    }
    lista->A[i].prox = pos;
    lista->dispo++;

}

bool excluirElemento (LISTA* lista, int inputElim) {
    if (lista->inicio == INVALIDO) {
        printf("Lista Vazia\n");
        return 1;
    }

    // Reescrever o anterior
    int i = lista->inicio;
    int ant = INVALIDO;
    while (lista->A[i].numChave != inputElim && i != INVALIDO ) {
        ant = i;
        i = lista->A[i].prox;
    }

    if (i == INVALIDO) {
        printf("Nao foi encontrado esse valor");
        return 1;
    }

    // Primeiro item
    if (ant == INVALIDO) {
        lista->inicio = lista->A[i].prox;
    } else {
        lista->A[ant].prox = lista->A[i].prox; // Pula o i
    }
    lista->dispo--;
    printf("Elemento %d removido", inputElim);
    return 0;

}


int buscarElemento (LISTA* lista, int inputNum) {
    int i = lista->inicio;

    while (i != INVALIDO && lista->A[i].numChave != inputNum)
    {
        i = lista->A[i].prox;   
    }

    if (i == INVALIDO) {
        printf ("Nao foi encontrado esse numero");
        return INVALIDO;
    } else {
        return i;
    }

}

void ordenarListaLigada(LISTA* lista) {
    int trocou = 1;

    while (trocou == 1) {
        trocou = 0; 
        int atual = lista->inicio; 
        int anterior = INVALIDO; 

        while (lista->A[atual].prox != INVALIDO) {
            int proximo = lista->A[atual].prox; //!

            // Troca valores
            if (lista->A[atual].numChave > lista->A[proximo].numChave) { 
                int temp = lista->A[atual].numChave;
                lista->A[atual].numChave = lista->A[proximo].numChave;
                lista->A[proximo].numChave = temp;

                trocou = 1;
            }

            anterior = atual; //!
            atual = proximo; //!
        }
    }
}


void IMPRIMINDO (LISTA* lista) {
    if (lista->inicio == INVALIDO) {
        printf("\nLista Vazia");
    }
    printf("\n");
    int i = lista->inicio;
    while (i != INVALIDO)
    {
        printf("%d\n",lista->A[i].numChave);
        i = lista->A[i].prox;
    }
    printf("\n");
}

int main (void)
{
    LISTA minhaLista;
    InicializarLista(&minhaLista);

    AdicionarElementos(&minhaLista, 10);
    AdicionarElementos(&minhaLista, 30);
    AdicionarElementos(&minhaLista, 50);
    AdicionarElementos(&minhaLista, 20);
    AdicionarElementos(&minhaLista, 60);
    AdicionarElementos(&minhaLista, 70);
    AdicionarElementos(&minhaLista, 80);
    AdicionarElementos(&minhaLista, 40);
    excluirElemento (&minhaLista, 10);
    IMPRIMINDO(&minhaLista);

    printf("Numeros Validos: %d\n", calculadorNumerosValidos(&minhaLista));

    printf("Elemento encontrado na posicao: %d\n", buscarElemento(&minhaLista, 30));

    // ReinicializarLista (&minhaLista);
    ordenarListaLigada (&minhaLista);
    IMPRIMINDO(&minhaLista);



    return 0;
}