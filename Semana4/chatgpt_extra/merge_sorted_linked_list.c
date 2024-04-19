#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>



/**
 *! OBJETIVO: 
 *? Merge two sorted doubly linked lists into a single sorted doubly linked list.
 *
 * 
*/
typedef struct aux{
    int chave;
    // int proximo;
    struct aux* proximo;
    struct aux* ant;
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
    novoElemento->ant = NULL;

    // Caso seja o primeiro
    if (lista->inicio == NULL) {
        lista->inicio = novoElemento;
        return;
    }


    PONTEIRO atual = lista->inicio;
    PONTEIRO anterior = atual->ant;
    while (atual->proximo != NULL) {
        // anterior = atual;
        atual = atual->proximo;
    }

    // Final da lista
    if (atual == NULL) {
        novoElemento->proximo = NULL;
        novoElemento->ant = atual->ant;
    }


    //* Duplamente Ligada
    atual->proximo = novoElemento;
    novoElemento->ant = atual;

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


void mergeSorted (LISTA* l1, LISTA* l2, LISTA* lout) {
    ELEMENTO* pos1 = l1->inicio;
    ELEMENTO* pos2 = l2->inicio;
    ELEMENTO* out = lout->inicio;

    while (pos1 != NULL || pos2 != NULL)
    {

        ELEMENTO* novoElemento = (ELEMENTO*) malloc (sizeof(ELEMENTO));

        // pos1 maior que pos2
        // pos2 maior que pos1
        
        if (pos1->chave < pos2->chave) {
            if (out == NULL) {
                out = pos1;
                out->ant = NULL;
                lout->inicio = out;
            } else {
                printf("Trocando: %d e %d \n", pos1->chave, pos2->chave);
                out->proximo = pos1;
                pos1->ant = out;
                out = out->proximo;
            }

            pos1 = pos1->proximo;

        } else if (pos2->chave < pos1->chave) {
            if (out == NULL) {
                out = pos2;
                out->ant = NULL;
                lout->inicio = out;
            } else {
                printf("Trocando: %d e %d \n", pos1->chave, pos2->chave);
                out->proximo = pos2;
                pos2->ant = out;
                out = out->proximo;
            }

            //Atualizando
            pos2 = pos2->proximo;
        } 
        
        
        if (pos1 != NULL) {
            out->proximo = pos1;
            pos1->ant = out;
            out = out->proximo;
            pos1 = pos1->proximo;
        }


        if (pos2 != NULL) {
            out->proximo = pos2;
            pos2->ant = out;
            out = out->proximo;
            pos1 = pos1->proximo;
        }
    }


    printf("Merge Completed!\n");

    return;

}

int main (void) {


    LISTA meuArranjo1;
    inicializarLista (&meuArranjo1);

    adicionarElemento (&meuArranjo1, 20);
    adicionarElemento (&meuArranjo1, 40);
    adicionarElemento (&meuArranjo1, 60);
    adicionarElemento (&meuArranjo1, 80);
    adicionarElemento (&meuArranjo1, 60);


    LISTA meuArranjo2;
    inicializarLista (&meuArranjo2);
    adicionarElemento (&meuArranjo2, 10);
    adicionarElemento (&meuArranjo2, 30);
    adicionarElemento (&meuArranjo2, 50);
    adicionarElemento (&meuArranjo2, 70);
    adicionarElemento (&meuArranjo2, 90);



    LISTA arranjoFinal;
    inicializarLista (&arranjoFinal);


    mergeSorted (&meuArranjo1, &meuArranjo2, &arranjoFinal);

    IMPRIMIR (&arranjoFinal);




    return 0;
}