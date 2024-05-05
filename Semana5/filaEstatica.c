#include <stdio.h>
#include <stdlib.h>

#define MAX 5

//// Iniciar
//// Adicionar
//// Exibir
//// Excluir
//// Exibir Inverso

typedef struct aux 
{
    int chave;
    
} ELEMENTO;



typedef struct 
{
    ELEMENTO A[MAX];
    int inicio;
    int numElem;
    
} QUEUE;

void iniciar (QUEUE* q)
{
    q->inicio = 0;
    q->numElem = 0;
}

int tamanho (QUEUE *q)
{
    return q->numElem;
}

void add (QUEUE*q, int input) 
{
    if (q->numElem >= MAX) return;

    ELEMENTO novo = { input };

    //??????????
    int posicao = (q->inicio + q->numElem) % MAX;
    
    q->A[posicao] = novo; 

    q->numElem++;
    return;
}

void delete (QUEUE* q)
{
    if (q->numElem == 0) {
        printf("Lista Vazia\n");
        return;
    }

    //??????????
    q->inicio = (q->inicio + 1) % MAX;
    
    q->numElem--;
    return;
}

void exibirLista (QUEUE* q) 
{
    if (q->numElem == 0) {
        printf("Lista Vazia\n");
        return;
    }

    printf("\nImprimindo Fila Estatica\n");

    int i = q->inicio;
    int walk;
    for (walk = 0; walk < q->numElem; walk++) {
        printf("%d\n", q->A[i].chave);

        //??????????
        i = (i + 1) % MAX;
    }

    printf("\n");
    return;
}

void restart (QUEUE* q)
{
    q->inicio = 0;
    q->numElem = 0;
}

void inversoExibir (QUEUE* q)
{

    printf("Pilha (da base para o topo): \n");
    
    int i = q->inicio;                              //* [4] [] [1] [2] [3] 
    int walk = (q->inicio + q->numElem - 1) % MAX ; //* 2 + 4 - 1  % 5 == 0
    int j;

    for (j = 0; j < q->numElem; j++) {
        printf("%d\n", q->A[walk].chave);
        walk = (walk - 1 + MAX) % MAX;              //* (0 - 1 + 5) % 5 == 4
                                                    //* (4 - 1 + 5) % 5 == 3  
                                                    //* (3 - 1 + 5) % 5 == 2
    }
    printf("\n");
    return;
}

int main (void)
{
    QUEUE pequena_fila;
    iniciar (&pequena_fila);

    add(&pequena_fila, 10);
    add(&pequena_fila, 20);
    add(&pequena_fila, 30);
    add(&pequena_fila, 40);

    exibirLista(&pequena_fila);
    inversoExibir(&pequena_fila);

    delete(&pequena_fila);
    exibirLista(&pequena_fila);

    restart(&pequena_fila);
    exibirLista(&pequena_fila);


}