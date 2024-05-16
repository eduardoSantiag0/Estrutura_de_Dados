#include <stdio.h>
#include <stdlib.h>

//// Iniciar matriz
//// Adicionar Elementos
//// Multiplicar matrizes alocadas dinamicamente

typedef struct tempNo 
{
    int valor;
} NO;


typedef NO* PONT;
typedef NO** PONT_INDICE;

typedef struct 
{
    PONT_INDICE M; // Ponteiro para ponteiros de inteiros
    int linhas;
    int colunas;
} MATRIZ;


MATRIZ* multiplicarMatrizes(MATRIZ* m1, MATRIZ* m2){
    if (m1->colunas != m2->linhas) return NULL;
    MATRIZ* res;
    start(&res, m1->linhas,m2->colunas);
    int i,j,k;
    int valor;
    for (i = 0; i < m1->linhas; i++)
    {
        for (j = 0; j < m2->colunas; j++)
        {
            valor = 0;
            for (k = 0; k < m1->colunas; k++)
            {
                valor += m1->M[i][k]->valor * m2->M[k][j]->valor;
            }
            res->M[i][j]->valor = valor;
        }
    }
    return res;
}

void start(MATRIZ *mat, int lin, int col)
{
    mat->linhas = lin;
    mat->colunas = col;

    mat->M = (PONT_INDICE)malloc(sizeof(PONT) * lin);

    int i, j;

    for (i = 0; i < lin; i++)
    {
        mat->M[i] = (PONT)malloc(sizeof(NO) * col);

        for (j = 0; j < col; j++)
        {
            mat->M[i][j] = (NO *)malloc(sizeof(NO));
        }
    }
}

void adicionarElementos(MATRIZ *mat, int num)
{
    int i, j;

    for (i = 0; i < mat->linhas; i++)
    {
        for (j = 0; j < mat->colunas; j++)
        {
            PONT novo = (PONT)malloc(sizeof(NO));
            novo->valor = num;
            mat->M[i][j] = novo;
        }
    }
}

int main(void)
{
    // Example usage:
    MATRIZ *mat1 = (MATRIZ *)malloc(sizeof(MATRIZ));
    MATRIZ *mat2 = (MATRIZ *)malloc(sizeof(MATRIZ));

    start(mat1, 3, 3);
    start(mat2, 3, 3);

    adicionarElementos(mat1, 5);
    adicionarElementos(mat2, 2);

    MATRIZ *result = multiplicarMatrizes(mat1, mat2);

    // Print the result matrix if not NULL
    if (result != NULL)
    {
        printf("Resulting matrix:\n");
        for (int i = 0; i < result->linhas; i++)
        {
            for (int j = 0; j < result->colunas; j++)
            {
                printf("%d ", result->M[i][j]->valor);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Matrices cannot be multiplied.\n");
    }

    return 0;
}