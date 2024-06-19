#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0
typedef int bool;

//? Analise o seguinte programa: 
//* Saída esperada: _______________ R: 10, 20, 30

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
    printf("Topo P: %d\n", p->topo->chave);

    return true;
}

bool desempilhar(PILHA* p, int* ch) {
    if (p->topo == NULL) return false;
    PONT apagar = p->topo;
    *ch = apagar->chave;
    p->topo = apagar->prox;
    free(apagar);
    return true;
}

void inverterPilha(PILHA* p) {
    PILHA aux1, aux2;
    inicializarPilha(&aux1);
    inicializarPilha(&aux2);
    int ch;
    
    printf("\nPilha Auxiliar 1: \n");
    while (desempilhar(p, &ch)) {
        empilhar(&aux1, ch);
    }
    
    printf("\nPilha Auxiliar 2: \n");
    while (desempilhar(&aux1, &ch)) {
        empilhar(&aux2, ch);
    }
    printf("\nPilha Principal: \n");
    while (desempilhar(&aux2, &ch)) {
        empilhar(p, ch);
    }
}

int main() {
    PILHA p;
    inicializarPilha(&p);
    
    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);
    // 30, 20, 10
    
    printf("\tInvertendo: \n");
    inverterPilha(&p);

    
    int ch;
    printf("\t\nResultado: \n");

    while (desempilhar(&p, &ch)) {
        printf("%d ", ch);
    }
    printf("\n");
    return 0;
}
