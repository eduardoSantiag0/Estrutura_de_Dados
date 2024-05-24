#include <stdio.h>
#include <malloc.h>

#define bool int
#define true 1
#define false 0

//? Implemente uma função para inserir um elemento em uma lista duplamente ligada:

typedef struct aux {
    int chave;
    struct aux* ant;
    struct aux* prox;
} ELEMENTO, *PONT;

typedef struct {
    PONT cabeca;
} LISTA_DUPLA;

void inicializarLista(LISTA_DUPLA* l) {
    l->cabeca = (PONT) malloc(sizeof(ELEMENTO));
    l->cabeca->prox = l->cabeca;
    l->cabeca->ant = l->cabeca;
}

bool inserirElemLista(LISTA_DUPLA* l, int ch) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    if (novo == NULL) return false;
    novo->chave = ch;

    PONT atual = l->cabeca->prox;
    while (atual->chave < ch)
    {
        atual = atual->prox;
    }
    
    // Atual é maior que o novo

    novo->prox = atual; // 4
    novo->ant = atual->ant; // 2
    atual->ant->prox = novo; // 1
    atual->ant = novo; // 3
    return true;
}

void IMPRIMIR (LISTA_DUPLA* lp)
{
    PONT walk = lp->cabeca->prox;
    while (walk != NULL && walk != lp->cabeca)
    {
        printf("%d ", walk->chave);
        walk = walk->prox;
    }
    return;
}

int  main (void)
{
    LISTA_DUPLA lp;
    inicializarLista (&lp);

    inserirElemLista (&lp, 10);
    inserirElemLista (&lp, 20);
    inserirElemLista (&lp, 40);
    inserirElemLista (&lp, 25);
    inserirElemLista (&lp, 30);

    IMPRIMIR(&lp);


    return 0;
}
