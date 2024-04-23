#include <stdio.h>
#include <stdlib.h>

//// Inicializar a estrutura
//// Retornar a quantidade de elementos válidos
//// Exibir os elementos da estrutura
//// Inserir elementos na estrutura (duas funções)
//// Excluir elementos da estrutura (duas funções)
//// Reinicializar a estrutura

typedef struct auxElem 
{
    int chave;
    struct auxElem* anterior;
    struct auxElem* proximo;
    
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct 
{
    PONT cabeca;
    
} DEQUE;

int elementosValidos (DEQUE* d) 
{
    int tam = 0;
    PONT walk = d->cabeca->proximo;
    while (walk != d->cabeca)
    {
        tam++;
        walk = walk->proximo;
    }
    
    return tam;
}

void inicializar (DEQUE* d) 
{
    d->cabeca = (PONT) malloc (sizeof (ELEMENTO));
    d->cabeca->proximo = d->cabeca;
    d->cabeca->anterior = d->cabeca;

    printf("Deque Inicializado\n");
    printf("\n");

}


void exibirDeque (DEQUE* d)
{
    PONT walk = d->cabeca->proximo;
    int i = 1;
    while (walk != d->cabeca)
    {
        printf("%d) %d\n",i, walk->chave);
        walk = walk->proximo;
        i++;
    }

    printf("Todos os elementos foram exibidos!\n");
    printf("\n");

}

void exibirDequeFim (DEQUE* d)
{
    PONT walk = d->cabeca->anterior;
    int i = 1;
    while (walk != d->cabeca)
    {
        printf("%d) %d\n",i, walk->chave);
        walk = walk->anterior;
        i++;
    }

    printf("Todos os elementos foram exibidos!\n");
    printf("\n");

}


void adicionarNoDequeInicio (DEQUE *d, int inputNum) 
{
    PONT novoElemento = (PONT) malloc (sizeof (ELEMENTO));
    novoElemento->chave = inputNum;
    novoElemento->proximo = d->cabeca;
    novoElemento->anterior = d->cabeca->anterior;

    //! Diff
    d->cabeca->anterior = novoElemento;
    novoElemento->anterior->proximo = novoElemento;

    printf("%d foi adicionado com sucesso\n", novoElemento->chave);

}

void adicionarNoDequeFinal (DEQUE *d, int inputNum) 
{
    PONT novoElemento = (PONT) malloc (sizeof (ELEMENTO));
    novoElemento->chave = inputNum;
    novoElemento->proximo = d->cabeca;
    novoElemento->anterior = d->cabeca->anterior;

    //! Diff
    d->cabeca->anterior = novoElemento;
    novoElemento->anterior->proximo = novoElemento;

    printf("%d foi adicionado com sucesso\n", novoElemento->chave);

}


void reinicarDeque (DEQUE* d)
{
    PONT walk = d->cabeca->proximo;

    while (walk != d->cabeca)
    {
        PONT apagar = walk;
        walk = walk->proximo;
        free(apagar);
    }

    d->cabeca->proximo = d->cabeca;
    d->cabeca->anterior = d->cabeca;
    printf("\n");
    
}

void excluirNoDeque (DEQUE *d) 
{
    if (d->cabeca->proximo == d->cabeca) {
        printf("Lista vazia\n");
        return;
    }


    PONT apagar = d->cabeca->proximo;

    //! Diff
    d->cabeca->proximo = apagar->proximo;
    apagar->proximo->anterior = d->cabeca;
    printf ("%d excluido com sucesso!\n", apagar->chave);

    free(apagar);
    printf("\n");

}

void excluirNoDequeFim (DEQUE *d) 
{
    if (d->cabeca->proximo == d->cabeca) {
        printf("Lista vazia\n");
        return;
    }


    PONT apagar = d->cabeca->anterior;

    //! Diff
    d->cabeca->anterior = apagar->anterior;
    apagar->anterior->proximo = d->cabeca;
    printf ("%d excluido com sucesso!\n", apagar->chave);

    free(apagar);

    printf("\n");

}

void verMaior (DEQUE *d, int* max)
{
    PONT walk = d->cabeca->proximo;
    int maior = 0;
    while (walk != d->cabeca)
    {
        if (walk->chave > maior) 
            maior = walk->chave;

        walk = walk->proximo;
    }

    *max = maior;
    printf("\n");

}


int main (void) 
{

    DEQUE deque;

    inicializar(&deque);

    adicionarNoDequeInicio (&deque, 10);
    adicionarNoDequeInicio (&deque, 20);
    adicionarNoDequeInicio (&deque, 30);
    adicionarNoDequeInicio (&deque, 40);
    adicionarNoDequeInicio (&deque, 50);
    adicionarNoDequeFinal (&deque, 70);



    exibirDeque (&deque);

    excluirNoDequeFim (&deque);
    exibirDeque (&deque);
    exibirDequeFim (&deque);


    int* p;
    verMaior (&deque,p);
    printf("Maior encontrado foi %d", *p);

    printf("Numero de elementos validos -> %d\n",elementosValidos(&deque));
    
    excluirNoDeque(&deque);
    excluirNoDeque(&deque);
    excluirNoDeque(&deque);
    exibirDeque (&deque);

    reinicarDeque (&deque);
    exibirDeque (&deque);
    excluirNoDeque(&deque);

    return 0;
}