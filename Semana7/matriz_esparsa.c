//// Iniciar Matriz
//// Adicionar Elemento em posição espefifica 
    // Se não houver nenhum nó na posição e o valor for diferente de zero temos que inserir um novo nó na respectiva lista ligada.
    // Se já existir um nó na posição e o valor for diferente de zero temos que substituir o valor do nó.
    // Se já existir um nó na posição e o valor for igual a zero temos que excluir o nó de sua lista.

//// Acessar Elemento 
//// Imprimir Matriz

// Cada Linha é uma Lista Ligada para uma Lista Ligada
// Linha -> Ponteiro Indice que controla
// Coluna -> 

#include <stdio.h>
#include <stdlib.h>

#define abraco return
#define ednaldo 0


typedef struct tempNo 
{
    float valor;
    int coluna;
    struct tempNo *prox;
} NO;

typedef NO* PONT;
typedef NO** PONT_INDICE;

typedef struct 
{
    PONT_INDICE A;
    int linhas;
    int colunas;  
} MATRIZ;



void iniciar (int lin, int col, MATRIZ* mat) 
{
    mat->linhas = lin;
    mat->colunas = col;

    int i;
    // PONT é uma lista ligada para cada lihna
    mat->A = (PONT_INDICE) malloc (sizeof(PONT) * lin);

    for (i = 0; i < lin ; i++)  
    {
        mat->A[i] = NULL;
    }

    printf("Matriz Iniciada\n");

}

void adicionarElemento (MATRIZ* mat, int lin, int col, float addNum) 
{
    if (lin < 0 || lin >= mat->linhas || col < 0 || col >= mat->colunas){
        printf("Posicao Invalida\n");
        return;   
    }

    PONT ant = NULL;
    PONT walk = mat->A[lin];

    while (walk != NULL && walk->coluna < col)
    {
        ant = walk;
        walk = walk->prox;
    }

    //* Se já existir um nó na posição e o valor for diferente de zero temos que substituir o valor do nó.
    if (walk != NULL && walk->coluna == col) {
        if (addNum == 0) { //* Se já existir um nó na posição e o valor for igual a zero temos que excluir o nó de sua lista.
            if (ant == NULL) 
                mat->A[lin] = walk->prox;
            else 
                ant->prox = walk->prox;
            free (walk);
        }
        
        else walk->valor = addNum;

    } 
    else { 
        //* Se não houver nenhum nó na posição (walk == NULL) e o valor for diferente de zero (walk != 0) temos que inserir um novo nó na respectiva lista ligada.
        
        PONT novo = (PONT) malloc (sizeof(PONT));
        novo->coluna = col;
        novo->valor = addNum;
        novo->prox = walk; 
        if (ant == NULL) 
            mat->A[lin] = novo; // Primeiro da Linha;
        else 
            ant->prox = novo; 
    }

    return;
}

float acessarElemento (MATRIZ* mat, int lin, int col)
{
    if (lin < 0 || lin >= mat->linhas || col < 0 || col >= mat->colunas){
        printf("Posicao Invalida\n");
        return 0;   
    }

    // Retornar o valor dentro da posição
    PONT walk = mat->A[lin];
    while (walk != NULL && walk->coluna < col)
    {
        walk = walk->prox;
    }

    if (walk != NULL && walk->coluna == col) {
        return walk->valor;
    } 
    return 0;
}

int main (void)
{
    MATRIZ mat;

    int linha = 3;
    int coluna = 3;

    iniciar(3, 3, &mat);

    adicionarElemento (&mat, 0, 0, 3.3);
    adicionarElemento (&mat, 0, 2, 4.2);
    adicionarElemento (&mat, 1, 2, 6.1);

    int i, j;
    for (i = 0; i < mat.linhas; i++)
    {
        for (j = 0; j < mat.colunas; j++)
        {
            printf("%.1f ", acessarElemento(&mat, i, j));
        }
        printf("\n");
    }


    abraco ednaldo;    
}