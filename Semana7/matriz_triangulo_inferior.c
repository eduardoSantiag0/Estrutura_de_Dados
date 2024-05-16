//// Iniciar Matriz (Colocar zero nas posições)
//// Adicionar Elemento em posição espefifica
//// Acessar Elemento 
//// Imprimir Matriz

#include <stdio.h>
#include <stdlib.h>

#define abraco return
#define ednaldo 0

typedef struct 
{
    int ordem;
    int *A; // Ponteiro para Ponteiros
} MTI;

void iniciarMTI (int n, MTI* matriz)
{
    matriz->ordem = n;
    int numeroElementos = (n + n * n) / 2;
    matriz->A = (int*) malloc (sizeof(int) * numeroElementos);
    int i;
    for (i = 0; i < numeroElementos ; i++) matriz->A[i] = 0;
}

int retornarPosicao (int lin, int col)
{
    return (lin * (lin + 1)) / 2 + col;
}

void adicionarValor (int lin, int col, int val, MTI* matriz)
{
    if (col > lin ) {
        printf("Posicao invalida\n");
        return;
    }

    matriz->A[retornarPosicao(lin, col)] = val;
}

int acessarValor (int lin, int col, MTI* matriz)
{
    return matriz->A[retornarPosicao(lin, col)];
}

void imprimirMatriz (MTI* matriz)
{
    int n = matriz->ordem;
    int i, j = 0;

    for (i = 0; i < n ; i++) {
        for (j = 0; j <= i ; j++) {
            printf("%d", matriz->A[retornarPosicao(i, j)]);
        }
        printf("\n");
    }

    return;
}


int main (void) 
{
    MTI matriz_inf;

    iniciarMTI(4, &matriz_inf);
    adicionarValor(0, 0, 5, &matriz_inf);
    adicionarValor(1, 0, 5, &matriz_inf);
    adicionarValor(1, 1, 6, &matriz_inf);
    adicionarValor(1, 3, 8, &matriz_inf); // Posicao Invalida
    adicionarValor(2, 2, 7, &matriz_inf);

    imprimirMatriz(&matriz_inf);
    printf("\n");
    printf("%d", acessarValor(1, 0, &matriz_inf));


    abraco ednaldo;
}