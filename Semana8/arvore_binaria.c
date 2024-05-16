#include <stdio.h>
#include <stdlib.h>

//// Iniciar Nó Raiz
//// Buscar
//// Inserir


enum LADO {
    ESQ, 
    DIR
}; 

typedef struct aux {
    int valor;
    struct aux *esq, *dir;
} NO;

typedef NO* PONT;



PONT criarNo (int chave) 
{
    PONT novoNo = (PONT) malloc (sizeof (NO));
    novoNo->valor = chave;
    novoNo->dir = NULL;
    novoNo->esq = NULL;
    return novoNo;
}

void iniciarRaiz (PONT* raiz, int chave)
{
    *raiz = criarNo(chave);
    return;
}

PONT buscarNaArvore (PONT raiz, int chaveBusca) 
{
    if (raiz == NULL) return NULL;
    if (raiz->valor == chaveBusca) return raiz;
    PONT aux = buscarNaArvore(raiz->esq, chaveBusca);
    if (aux) return aux;
    return buscarNaArvore(raiz->dir, chaveBusca);
}



void inserirNo (PONT raiz, int novaChave, int chavePai,enum LADO lado) 
{
    PONT paiBusca = buscarNaArvore(raiz, chavePai);
    if (!paiBusca) return;

    PONT novoElemento = criarNo(novaChave);

    if (lado == ESQ) {
        novoElemento->esq = paiBusca->dir;
        paiBusca->esq = novoElemento;
    } else {
        novoElemento->esq = paiBusca->dir;
        paiBusca->dir = novoElemento;
    } 

    return;
}

void imprimirInOrder(PONT raiz) {
    if (raiz == NULL) return;
    imprimirInOrder(raiz->esq);
    printf("%d ", raiz->valor);
    printf("\n");
    imprimirInOrder(raiz->dir);
}

int main (void) 
{
    PONT raiz = NULL;
    iniciarRaiz(&raiz, 10);

    inserirNo(raiz, 5, raiz->valor, ESQ); 
    inserirNo(raiz, 15, raiz->valor, DIR); 
    
    inserirNo(raiz, 50, 15, ESQ); 
    inserirNo(raiz, 45, 15, DIR); 

    inserirNo(raiz, 35, 5, ESQ); 
    inserirNo(raiz, 6, 5, DIR); 

    imprimirInOrder(raiz);

    return 0;
}