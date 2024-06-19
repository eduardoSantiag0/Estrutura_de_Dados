//? Crie um código para implementar uma árvore binária e faça uma função para calcular sua altura

//// Iniciar Raiz
//todo Adicionar nó
//todo Calcular altura
//todo Imprimir Árvore

#include <stdio.h>
#include <malloc.h>

enum Direcao {
    ESQUERDA, 
    DIREITA
};

typedef struct aux 
{
    int chave;
    struct aux* esq;
    struct aux* dir;
} NODE;

typedef NODE* PONT;


PONT criarNo (int ch)
{
    PONT novo =  (PONT) malloc (sizeof (NODE));
    novo->chave = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}


void iniciar (PONT* raiz, int ch)
{
    *raiz = criarNo(ch);
}

// void iniciar (NODE* raiz, int ch)
// {
//     raiz = criarNo(ch);
// }

PONT buscarNode (NODE* raiz, int chaveBuscada)
{
    if (raiz == NULL) return NULL;
    if (raiz->chave == chaveBuscada) return raiz;

    PONT walk = buscarNode (raiz->esq, chaveBuscada);
    if (walk != NULL) return walk;
    return buscarNode (raiz->dir, chaveBuscada);
}

// PONT buscarNode (NODE* raiz, int chaveBuscada)
// {
//     PONT walk = raiz;
//     while (raiz->chave != chaveBuscada || raiz == NULL)
//     {
//         buscarNode (raiz->esq, chaveBuscada);
//         buscarNode (raiz->dir, chaveBuscada);
//     }

//     return walk;
    
// }

void addNode (PONT raiz, int ch, int chavePai, enum Direcao dir)
{
    PONT pae = buscarNode(raiz, chavePai);
    if (pae == NULL) {
        printf("Essa chave nao existe\n");
        return;
    }

    PONT novo = criarNo(ch);
    if (novo == NULL) {
        printf("Erro ao alocar memoria\n");
        return;
    }

    if (dir == ESQUERDA) {
        pae->esq = novo;
    } else {
        pae->dir = novo;
    }
    return;
}

// void addNode (NODE* raiz, int ch, int chavePai, enum Direcao dir)
// {
//     PONT pae = buscarNode(raiz, chavePai);
//     if (pae == NULL) {
//         printf("Essa chave nao existe\n");
//         return;
//     }

//     PONT novo = criarNo(ch);

//     if (dir == ESQUERDA) {
//         pae->esq = novo;
//     } else {
//         pae->dir = novo;
//     }
//     return;
// }

void imprimir (PONT raiz)
{
    if (raiz == NULL) return;
 
    printf("%d\n", raiz->chave);

    imprimir(raiz->esq);
    imprimir(raiz->dir);
}

int max (int a,  int b)
{
    if (a >  b) return a;
    return b;
}

int calculadorAltura (PONT raiz)
{
    if (raiz == NULL) return -1;
    int altDir  = calculadorAltura (raiz->dir);
    int altEsq  = calculadorAltura (raiz->esq);

    return 1 + max (altDir, altEsq);
}

int main (void)
{
    PONT raiz; iniciar (&raiz, 10);
    addNode (raiz, 20, raiz->chave, ESQUERDA);
    addNode (raiz, 30, raiz->chave, DIREITA);

    addNode (raiz, 40, 20, ESQUERDA);
    addNode (raiz, 50, 30, DIREITA);

    addNode(raiz, 22, 20, DIREITA);
    addNode(raiz, 33, 30, ESQUERDA);
    addNode (raiz, 34, 33, ESQUERDA);

    imprimir(raiz);

    printf("\n Atura da Arvore: %d", calculadorAltura(raiz));
    addNode (raiz, 35, 34, ESQUERDA);
    printf("\n Atura da Arvore: %d", calculadorAltura(raiz));

    return 0;
}