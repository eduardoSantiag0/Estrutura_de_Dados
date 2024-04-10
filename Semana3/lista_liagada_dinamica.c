#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//* LISTA LIGADA DINAMICA
//// Inicializar a estrutura
//// Inserir elementos na estrutura
//// Retornar a quantidade de elementos válidos
//// Exibir os elementos da estrutura
//// Buscar por um elemento na estrutura
//// Excluir elementos da estrutura
//// Reinicializar a estrutura
// Ordenar Lista Ligada

typedef struct aux{
    int chave;
    // int proximo;
    struct aux* proximo;
} ELEMENTO;


typedef struct 
{
    ELEMENTO* inicio;
    
} LISTA;

typedef ELEMENTO* PONTEIRO;

void inicializarLista (LISTA* lista) {
    lista->inicio = NULL;
}

void adicionarElemento (LISTA* lista, int inputChave) {
    ELEMENTO* novoElemento = (ELEMENTO*) malloc (sizeof (ELEMENTO));
    if (novoElemento == NULL) {
        printf("Erro: não foi possível alocar memória para novo elemento\n");
        return;
    }

    novoElemento->chave = inputChave;
    novoElemento->proximo = NULL;

    // Caso seja o primeiro
    if (lista->inicio == NULL) {
        lista->inicio = novoElemento;
        return;
    }


    PONTEIRO start = lista->inicio;
    while (start->proximo != NULL) {
        start = start->proximo;
    }
    start->proximo = novoElemento;

}

int tamanho (LISTA* lista) {
    if (lista->inicio == NULL) {
        printf("Lista Vazia!\n");
        return 0;
    }

    PONTEIRO end = lista->inicio;
    int tam = 1;

    while (end->proximo != NULL) {
        tam++;
        end = end->proximo;
    }

    return tam;
}

int buscarElemento (LISTA* lista, int inputNum) {

    ELEMENTO* busca = lista->inicio;
    int pos = 0;
    while (busca != NULL)
    {
        if (busca->chave == inputNum) {
            printf("Elemento Encontrado\n");
            return pos;
        }

        pos++;
        busca = busca->proximo;
    }
    return 0;
} 

void excluirElemento (LISTA* lista, int inputExcluir) {
    ELEMENTO* atual = lista->inicio;
    ELEMENTO* anterior = NULL;

    if (atual->chave == inputExcluir) {
        lista->inicio = atual->proximo;
        free(atual);
        return;
    }

    while (atual != NULL)
    {
        if (atual->chave == inputExcluir) {
            anterior->proximo = atual->proximo;
            printf("Elemento excluido com sucesso!\n");
            free (atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    printf("Nao foi  encontrado\n");
    return;
    
}

void reiniciarLista (LISTA* lista) {
    ELEMENTO* atual = lista->inicio;
    ELEMENTO* proximo;

    while (atual != NULL) {
        
        proximo = atual->proximo;
        printf("Excluindo memoria da chave: %d\n",atual->chave);
        free(atual);
        atual = proximo;
    }

    free(lista->inicio);
    printf("Lista reinicializada\n");
}

void IMPRIMIR (LISTA* lista) {
    ELEMENTO* start = lista->inicio;
    while (start != NULL)
    {
        printf("%d\n", start->chave);
        start = start->proximo;
    }
    
}

int main (void) {

    LISTA meuArranjo;
    inicializarLista (&meuArranjo);
    printf("Numero de itens na lista: %d\n", tamanho(&meuArranjo));
    adicionarElemento (&meuArranjo, 20);
    adicionarElemento (&meuArranjo, 40);
    adicionarElemento (&meuArranjo, 44);
    adicionarElemento (&meuArranjo, 60);
    adicionarElemento (&meuArranjo, 7);
    adicionarElemento (&meuArranjo, 99);
    printf("Numero de itens na lista: %d\n", tamanho(&meuArranjo));
    IMPRIMIR (&meuArranjo);
    printf("Posicao do elemento: %d\n", buscarElemento(&meuArranjo, 7));
    excluirElemento(&meuArranjo, 7);
    IMPRIMIR (&meuArranjo);
    reiniciarLista(&meuArranjo);



    return 0;
}