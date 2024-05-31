#include <stdio.h>
#include <malloc.h>

//// Iniciar
//// Adicionar
//// Criar No
//// Buscar
//// Impressão
//// Tamanho
//todo Remover

typedef int bool;

typedef struct aux {
    int chave;
    struct aux *esq, *dir;
} NO;

typedef NO* PONT;

PONT inicializa () {
    return (NULL);
}

PONT adicionar (PONT raiz,PONT no)
{
    if (raiz == NULL) return (no);
    
    if (raiz->chave > no->chave) 
        raiz->esq = adicionar(raiz->esq, no);
    else 
        raiz->dir = adicionar(raiz->dir, no);
    
    return (raiz);
}

PONT criarNo (int ch) {
    PONT novoNo = (PONT) malloc (sizeof(NO));
    novoNo->chave = ch;
    novoNo->esq = NULL;
    novoNo->dir = NULL;

    return novoNo;
}

PONT buscarChave (PONT raiz, int ch) 
{
    if (raiz == NULL) return (NULL);
    if (raiz->chave == ch) return (raiz);
    if (ch > raiz->chave) 
        return (buscarChave(raiz->esq, ch)); //? Porque retornar
    else 
        return (buscarChave(raiz->dir, ch));

}

PONT buscarChaveComPai (PONT raiz, int ch, PONT* pai) 
{
    PONT atual = raiz;
    *pai = NULL;

    while (atual)
    {
        if (atual->chave == ch) return atual;
        *pai = atual;
        if (ch < atual->chave) 
            atual = atual->esq;
        else atual = atual->dir;
    }

    return NULL;
    
}

void IMPRIMIR (PONT raiz) 
{
    if (raiz == NULL) return;
    IMPRIMIR(raiz->esq);
    IMPRIMIR(raiz->dir);
    printf("%d\n", raiz->chave);
}

int tamanho (PONT raiz)
{
    if (raiz == NULL) return 0;
    int l = tamanho (raiz->esq);
    int r = tamanho (raiz->dir);

    return l + r + 1;
}


//! Para saber Pai do Nó, Nó a ser Removido, Nó Substituto, Pai do Nó a ser Movido
// Passos: 
// Encontrar o nó a ser buscado
// Descobrir quantos filhos ele tem
// Caso só tenha um, ele será promovido
// Caso tenha dois, usa-se dois ponteiros auxiliares para encontrar o filho mais a direita da esquerda
// Ou seja, o maior dos números menores que o nó a ser excluido
// 


PONT remover(PONT raiz, int ch)
{
    PONT pai, noParaRemover, paiAux, filhoPromovido;
    // pai -> pai do nó que será removido
    // q / filhoPromovido -> nó que será promovido
    // p / paiAux -> nó auxiliar que serve como pai de Q
    // no / noParaRemover -> nó a ser removido 

    noParaRemover = buscarChaveComPai (raiz, ch, &pai);
    if (noParaRemover == NULL) return raiz;

    //* Caso tenha um ou nenhum filho
    if (!noParaRemover->esq  || !noParaRemover->dir) {
        if (!noParaRemover->esq) filhoPromovido = noParaRemover->dir;
        else filhoPromovido = noParaRemover->esq;
    }

    //* Tem dois filhos
    else { 

        // Procurando o maior número dos menores
        paiAux = noParaRemover;
        filhoPromovido = noParaRemover->esq;
        while (filhoPromovido->dir)
        {
            paiAux = filhoPromovido;
            filhoPromovido = paiAux->dir;
        }
        
        // Se paiAux não é igual a noParaRemover, ajusta os ponteiros
        if (paiAux != noParaRemover) {
            paiAux->dir = filhoPromovido->esq;
            filhoPromovido->esq = noParaRemover->esq;
        }

        // Atualiza os ponteiros
        filhoPromovido->dir = noParaRemover->dir;
    }
    
    // Caso o nó a ser removido é a raiz;
    if (!pai) {
        free(noParaRemover);
        return(filhoPromovido);
    }

    // Troca os ponteiros nó a ser removido
    if (ch < pai->chave) pai->esq = filhoPromovido;
    else pai->dir = filhoPromovido;
    free(noParaRemover);
    return raiz;

}

int main (void) {

    PONT raiz = inicializa();

    PONT p = criarNo(23); raiz = adicionar(raiz, p);
    PONT q = criarNo(13); raiz = adicionar(raiz, q);
    PONT r = criarNo(44); raiz = adicionar(raiz, r);
    PONT l = criarNo(54); raiz = adicionar(raiz, l); 
    PONT m = criarNo(8); raiz = adicionar(raiz, m); 
    PONT n = criarNo(18); raiz = adicionar(raiz, n); 
    PONT y = criarNo(30); raiz = adicionar(raiz, y); 
    
    PONT busca = buscarChave(raiz, 44);
    // printf("%d", busca->chave);

    IMPRIMIR(raiz);
    printf("\n Tamanho: %d\n", tamanho(raiz));

    remover(raiz, 44);

    IMPRIMIR(raiz);
    printf("\n Tamanho: %d", tamanho(raiz));

    return 0;
}