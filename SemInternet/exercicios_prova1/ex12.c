#include <stdio.h>
#define MAX 5

#define true 1
#define false 0
typedef int bool;

typedef struct {
    int A[MAX];
    int topo;
} PILHA;

void inicializarPilha(PILHA* p) {
    p->topo = -1;
}

bool empilhar(PILHA* p, int ch) {
    if (p->topo == MAX - 1) return false;
    p->A[++(p->topo)] = ch; //!!!!
    return true;
}

bool desempilhar(PILHA* p, int* ch) {
    if (p->topo == -1) return false;
    *ch = p->A[(p->topo)--];
    return true;
}

void imprimirPilha(PILHA* p) {
    for (int i = p->topo; i >= 0; i--) {
        printf("%d ", p->A[i]);
    }
    printf("\n");
}

int main() {
    PILHA p;
    int ch;
    inicializarPilha(&p);
    
    empilhar(&p, 1);
    empilhar(&p, 2);
    empilhar(&p, 3);
    empilhar(&p, 4);
    empilhar(&p, 5);
    
    imprimirPilha(&p);
    
    desempilhar(&p, &ch);
    desempilhar(&p, &ch);
    
    imprimirPilha(&p);
    return 0;
}
