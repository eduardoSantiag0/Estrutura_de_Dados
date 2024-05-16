#include <stdio.h>
#include <stdlib.h>


//* Arvore N-ária
//// Iniciar Nó Raiz
//// Criar nó
//// Buscar
//// Exibir
//// Inserir

typedef struct aux
{
    int chave;
    struct aux* filho_prim;
    struct aux* prox_irmao;
} NO;

typedef NO* PONT;

PONT criarNo (int chave)
{
    PONT novo = (PONT) malloc (sizeof (NO));
    novo->chave = chave;
    novo->filho_prim = NULL;
    novo->prox_irmao = NULL;
    return novo;
}

void inicarRaiz (PONT* raiz, int chave)
{
    *raiz = criarNo(chave);
}

PONT buscarNo (PONT raiz, int chaveBusca)
{
    if (raiz == NULL) return NULL;
    if (raiz->chave == chaveBusca) return raiz;

    PONT aux = raiz->filho_prim;
    while (aux)
    {
        PONT resp = buscarNo(aux, chaveBusca);
        if (resp) return resp;
        aux = aux->prox_irmao;
    }
    return NULL;
}

void insercao (PONT raiz, int novaChave, int chavePai)
{
    PONT pai = buscarNo(raiz, chavePai);
    if (!pai) return;
    PONT novoFilho = criarNo(novaChave);

    if (pai->filho_prim == NULL) {
        pai->filho_prim = novoFilho;
        return;
    }

    PONT p = pai->filho_prim;
    while (p->prox_irmao)
    {
        p = p->prox_irmao;
    }
    p->prox_irmao = novoFilho;
    return;
}

void IMPRIMIR_ARVORE (PONT raiz)
{
    if (raiz == NULL) return;

    printf("%d ", raiz->chave);
    
    PONT aux = raiz->filho_prim;
    while (aux)
    {
        IMPRIMIR_ARVORE (aux);
        aux = aux->prox_irmao;
    }

    printf("\n");

}

int main (void)
{
    PONT raiz_poggers;
    inicarRaiz (&raiz_poggers, 1);
    
    insercao(raiz_poggers, 2, raiz_poggers->chave);
    insercao(raiz_poggers, 3, raiz_poggers->chave);

    insercao(raiz_poggers, 5, 2);
    insercao(raiz_poggers, 4, 3);

    IMPRIMIR_ARVORE(raiz_poggers);

    return 0;
}