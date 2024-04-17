#include <stdio.h>
#include <malloc.h>


//// Iniciar Lista
//// Buscar por um elemento na lista
//// Inserir elementos
//// Exibir elementos
//TODO Excluir elementos
//// Reiniciar lista


typedef struct aux{
    int chave;
    struct aux* prox;    

} ELEMENTO;

typedef struct 
{
    ELEMENTO* cabeca;
} LISTA;

typedef ELEMENTO* PONTEIRO;


void iniciarLista(LISTA* lista) {
    lista->cabeca = (ELEMENTO*) malloc (sizeof(ELEMENTO));
    lista->cabeca->prox = lista->cabeca;
}

void exibirLista (LISTA* lista) {
    PONTEIRO end = lista->cabeca->prox;

    while (end != lista->cabeca)
    {
        printf("%d\n", end->chave);
        end = end->prox;
    }

    printf("\n");
} 

ELEMENTO* buscaSequencialSentinela (LISTA* lista, int inputBusca, PONTEIRO* ant) 
{
    lista->cabeca->chave = inputBusca;
    
    // rodar a lista
    ELEMENTO* pos = lista->cabeca->prox;

    while (pos->chave < inputBusca)
    {
        *ant = pos;
        pos = pos->prox;
    }
    
    if (pos != lista->cabeca && pos->chave == inputBusca) return pos;
    return NULL;
} 

void inserirLista (LISTA* lista, int inputBusca) {
    ELEMENTO* novoElemento;
    ELEMENTO* ant;
    ELEMENTO* holder = lista->cabeca->prox;
    

    while (holder->chave < inputBusca)
    {
        holder = holder->prox;
    }

    novoElemento = holder;
    
    novoElemento = (ELEMENTO*) malloc (sizeof(ELEMENTO));
    novoElemento->chave = inputBusca;
    novoElemento->prox = holder->prox;
    holder->prox = novoElemento;
    printf("Adicionado elemento %d com sucesso.\n", inputBusca);

}

void excluirLista (LISTA* lista, int inputBusca) {
    
    ELEMENTO* end = lista->cabeca->prox;
    ELEMENTO* ant; 
    ELEMENTO* busca;

    busca = buscaSequencialSentinela(lista, inputBusca, &ant);
    if (busca == NULL) {
        printf("Elemento %d nao encontrado.\n", inputBusca);
        return;
    }

    ant->prox = busca->prox;
    free(busca);
    printf("Elemento %d excluído com sucesso.\n", inputBusca);
}

void reiniciarLista (LISTA* lista) {
    PONTEIRO end = lista->cabeca->prox;

    while (end != lista->cabeca)
    {
        PONTEIRO apagar = end;
        end = end->prox;
        free(apagar);
    }
    printf("Lista reinicializada!\n");
    lista->cabeca->prox = lista->cabeca;
}

int main (void) {

    LISTA minhaLista;

    iniciarLista(&minhaLista);
    inserirLista(&minhaLista, 10);
    inserirLista(&minhaLista, 20);
    inserirLista(&minhaLista, 15);
    inserirLista(&minhaLista, 30);
    exibirLista(&minhaLista);

    excluirLista(&minhaLista, 20);
    exibirLista(&minhaLista);

    reiniciarLista(&minhaLista);
    exibirLista(&minhaLista);


}