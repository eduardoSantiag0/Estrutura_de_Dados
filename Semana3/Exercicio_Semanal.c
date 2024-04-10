#include <stdio.h>
#include <malloc.h>

#define MAX 50

/*****
    //* DESAFIO: Desejamos transformar
    //* Lista ligada dinâmica (inserção ordenada) 
    //* em uma estrutura duplamente ligada
*****/ 

//// Iniciar Lista
//// Exibir os elementos da estrutura
//// Reinicializar a Estrutura
//// Inserção de Elemento
//// Busca Ordenada
//TODO Exclusão de Elemento
//TODO Retornar a quantidade de elementos válidos


typedef struct aux
{
    int chave;
    struct aux *proximo, *anterior;

} ELEMENTO;

typedef struct 
{
    ELEMENTO* inicio;
} ARRANJO;


void inicializarLista (ARRANJO* arr) {
    arr->inicio = NULL;
}


void inserirElemListaOrdenada(ARRANJO* arranjo, int inputNum) {
    ELEMENTO* novoElemento = (ELEMENTO*) malloc (sizeof (ELEMENTO));
    novoElemento->chave = inputNum;
    
    // Primeira posição
    if (arranjo->inicio == NULL) {
        arranjo->inicio = novoElemento;
        novoElemento->anterior = NULL;
        novoElemento->proximo = NULL;
        return;
    }


    ELEMENTO* atual = arranjo->inicio;
    ELEMENTO* ant = NULL;
    
    while (atual != NULL && atual->chave < inputNum)
    {
        ant = atual;
        atual = atual->proximo;
    }

    //* Novo primeiro elemento
    if (ant == NULL) {
        novoElemento->proximo = arranjo->inicio;
        novoElemento->anterior = NULL;
        arranjo->inicio->anterior = novoElemento; //!!
        arranjo->inicio = novoElemento;
        return; 
    }

    //* Último da fila;
    if (atual == NULL) {
        novoElemento->proximo = NULL;
        novoElemento->anterior = ant;
        ant->proximo = novoElemento;
        // atual = novoElemento;
        return;
    } 

    //* Inserir no maior da lista
    // novoElemento->proximo = atual->proximo;
    // novoElemento->anterior = atual->anterior;
    // atual = novoElemento;
    novoElemento->proximo = atual;
    novoElemento->anterior = ant;

    ant->proximo = novoElemento;
    atual->anterior = novoElemento;

}

ELEMENTO*  buscarSequencialOrdenada (ARRANJO* arr, int inputBusca, ELEMENTO** anterior) {
    ELEMENTO* pos = arr->inicio;
    *anterior = NULL;

    while (pos != NULL && pos->chave < inputBusca){
        *anterior = pos->anterior;
        pos = pos->proximo;
    }

    if (pos == NULL) {
        return NULL;
    }

    return pos;
}

void exclusaoElemento (ARRANJO* arr, int inputNum) {
    ELEMENTO* pos = arr->inicio;
    ELEMENTO* anterior = NULL;

    // Primeiro
    if (pos != NULL && pos->chave == inputNum) {
        arr->inicio = pos->proximo;
        free (pos);
        printf("Numero excluido\n");
        return;
    }

    pos = buscarSequencialOrdenada(arr, inputNum, &anterior); 
    if (pos == NULL) {
        printf("Esse numero nao existe na lista\n");
        return;
    }

    // Ultimo 
    if (pos->proximo == NULL) {
        //? Anterior
        anterior->proximo = NULL; //!
        free(pos);
        printf("Ultimo Numero excluido com sucesso\n");
        return;
    }

    // Meio da Lista
    pos->proximo->anterior = pos->anterior; //?
    anterior->proximo = pos->proximo; 
    free(pos);
    printf("Numero excluido com sucesso\n");
    return;
    
}

void reinicializarLista (ARRANJO* arr) {
    ELEMENTO* atual = arr->inicio;
    ELEMENTO* proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        printf("Excluindo memoria da chave: %d\n",atual->chave);
        free(atual);
        atual = proximo;
    }

    arr->inicio = NULL;
    printf("Lista reinicializada\n");
}

void IMPRIMIR (ARRANJO* arr) {
    printf("\n");
    ELEMENTO* pos = arr->inicio;
    while (pos != NULL)
    {
        printf("%d\n", pos->chave);
        pos = pos->proximo;
    }
   
}

int main (void) {
    ARRANJO meuArranjo;

    inicializarLista(&meuArranjo);
    inserirElemListaOrdenada (&meuArranjo, 12);
    inserirElemListaOrdenada (&meuArranjo, 40);
    inserirElemListaOrdenada (&meuArranjo, 60);
    inserirElemListaOrdenada (&meuArranjo, 20);
    IMPRIMIR(&meuArranjo);
    
    exclusaoElemento(&meuArranjo, 60);
    IMPRIMIR(&meuArranjo);

    // reinicializarLista(&meuArranjo);
    // IMPRIMIR(&meuArranjo);

    return 0;
}