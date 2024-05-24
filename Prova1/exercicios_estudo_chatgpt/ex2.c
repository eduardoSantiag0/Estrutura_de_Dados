#include <stdio.h>
#include <malloc.h>

#define bool int
#define true 1
#define false 0

// Desempilhado: _______________ 30
// Desempilhado: _______________ 20

typedef struct aux {
    int chave;
    struct aux* prox;
} ELEMENTO, *PONT;

typedef struct {
    PONT topo;
} PILHA;

void inicializarPilha(PILHA* p) {
    p->topo = NULL;
}

bool empilhar(PILHA* p, int ch) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    if (novo == NULL) return false;
    novo->chave = ch;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

bool desempilhar(PILHA* p, int* ch) {
    if (p->topo == NULL) return false;
    PONT apagar = p->topo;
    *ch = apagar->chave; //Copia a chave do topo para esse endereço
    p->topo = apagar->prox;
    free(apagar);
    return true;
}


int main() {
    PILHA p;
    int ch;
    inicializarPilha(&p);
    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);
    desempilhar(&p, &ch);
    printf("Desempilhado: %d\n", ch); // 30
    desempilhar(&p, &ch);
    printf("Desempilhado: %d\n", ch); // 20
    return 0;
}
