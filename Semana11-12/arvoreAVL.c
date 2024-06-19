#include <stdio.h>
#include <stdlib.h> 

//// Criar Nó
//// getAltura
//// NovoBalanco
//// Inserir
//// rotacaoDireita
//// rotacaoEsquerda
//// Imprimir PreOrder
//// Deletar Nó
//// Buscar Nó
// https://www.javatpoint.com/avl-tree-program-in-c

//* Balance Factor = Height of the Left Subtree — Height of the Right Subtree


typedef struct aux {
    int bal;
    int chave;
    struct aux* esq;
    struct aux* dir;
} NODE;

typedef NODE* PONT;

int getAltura(PONT n) {
    if (n == NULL)
        return 0;
    return n->bal;
}

int getBalanceFactor(PONT n) {
    if (n == NULL)
        return 0;
    return getAltura(n->esq) - getAltura(n->dir);
}

int max(int a, int b) {  
    return (a > b) ? a : b;  
}  

PONT criarNode(int ch) {
    PONT novo = (NODE*) malloc(sizeof(NODE));
    novo->chave = ch;
    novo->dir = NULL;
    novo->esq = NULL;
    novo->bal = 1; 
    return novo;
}

PONT buscarChave(PONT r, int ch) {
    if (r == NULL) 
        return NULL; 

    if (r->chave == ch) {
        return r;
    } else if (r->chave > ch) {
        return buscarChave(r->esq, ch);
    } else {
        return buscarChave(r->dir, ch);
    }
}

PONT rotacaoR(PONT p) {
    // Marca os ponteiros que serão alterados 
    PONT u = p->esq;
    PONT v = u->dir;

    // Rotação
    u->dir = p;
    p->esq = v;

    // Atualiza o balanceamento
    p->bal = max(getAltura(p->esq), getAltura(p->dir)) + 1;
    u->bal = max(getAltura(u->esq), getAltura(u->dir)) + 1;

    // Retorna o ponteiro que subiu de altura, colocando-o no lugar do ponteiro problema
    return u;
}

PONT rotacaoL(PONT p) {
    PONT u = p->dir;
    PONT v = u->esq;

    u->esq = p;
    p->dir = v;

    p->bal = max(getAltura(p->esq), getAltura(p->dir)) + 1;
    u->bal = max(getAltura(u->esq), getAltura(u->dir)) + 1;

    return u;
}

PONT inserirNoAVL(PONT r, int ch) {
    if (r == NULL) {
        return criarNode(ch);
    }

    if (ch > r->chave) {
        r->dir = inserirNoAVL(r->dir, ch);
    } else if (ch < r->chave) {
        r->esq = inserirNoAVL(r->esq, ch);
    } else {
        return r;
    }

    //! COMEÇA A VERIFICAÇÃO AVL
    r->bal = 1 + max(getAltura(r->esq), getAltura(r->dir));
    int balanceFactor = getBalanceFactor(r);

    //* Rotação LL
    if (balanceFactor > 1 && ch < r->esq->chave) {
        printf("Rotacao LL\n");
        return rotacaoR(r);
    }

    //* Rotação LR
    if (balanceFactor > 1 && ch > r->esq->chave) {
        printf("Rotacao LR\n");
        r->esq = rotacaoL(r->esq);
        return rotacaoR(r);
    }



    //* Rotação RR
    if (balanceFactor < -1 && ch > r->dir->chave) {
        printf("Rotacao RR\n");
        return rotacaoL(r);
    }

    //* Rotação RL
    if (balanceFactor < -1 && ch < r->dir->chave) {
        printf("Rotacao RL \n");
        r->dir = rotacaoR(r->dir);
        return rotacaoL(r);
    }

    return r;
}

PONT minValueNode (PONT r) {
    PONT walk = r;

    while (walk->esq != NULL)
    {
        walk = walk->esq;
    }

    return walk;
    
}


PONT deletarNo(PONT r, int ch) {
    if (r == NULL) 
        return NULL;

    if (ch < r->chave) {
        r->esq = deletarNo(r->esq, ch);
    } else if (ch > r->chave) {
        r->dir = deletarNo(r->dir, ch);
    } else {
        // Caso 1 e Caso 2: Nó sem filhos ou com um filho
        if (r->esq == NULL) {
            PONT temp = r->dir;
            free(r);
            return temp;
        } else if (r->dir == NULL) {
            PONT temp = r->esq;
            free(r);
            return temp;
        } else {
            // Caso 3: Nó com dois filhos
            PONT temp = minValueNode(r->dir);
            r->chave = temp->chave;
            r->dir = deletarNo(r->dir, temp->chave);
        }
    }

    // Atualiza o balanceamento
    if (r == NULL) return r;
    r->bal = 1 + max(getAltura(r->esq), getAltura(r->dir));

    int balanceFactor = getBalanceFactor(r);

    // LL case
    if (balanceFactor > 1 && getBalanceFactor(r->esq) >= 0) {
        return rotacaoR(r);
    }
    
    // LR case
    if (balanceFactor > 1 && getBalanceFactor(r->esq) < 0) {
        r->esq = rotacaoL(r->esq);
        return rotacaoR(r); 
    }

    // RR case
    if (balanceFactor < -1 && getBalanceFactor(r->dir) <= 0) {
        return rotacaoL(r);
    }

    // RL case
    if (balanceFactor < -1 && getBalanceFactor(r->dir) > 0) {
        r->dir = rotacaoR(r->dir);
        return rotacaoL(r); 
    }

    return r;
}

void IMPRIMIR(PONT r) {
    if (r != NULL) {
        printf("%d ", r->chave);
        IMPRIMIR(r->esq);
        IMPRIMIR(r->dir);
    }
}

int main(void) {
    PONT raiz = NULL;

    raiz = inserirNoAVL(raiz, 4);
    raiz = inserirNoAVL(raiz, 2);
    raiz = inserirNoAVL(raiz, 10);
    raiz = inserirNoAVL(raiz, 1);
    raiz = inserirNoAVL(raiz, 3);
    raiz = inserirNoAVL(raiz, 7);
    raiz = inserirNoAVL(raiz, 12);
    raiz = inserirNoAVL(raiz, 5);
    raiz = inserirNoAVL(raiz, 8);
    raiz = inserirNoAVL(raiz, 11);
    raiz = inserirNoAVL(raiz, 15);

    IMPRIMIR(raiz);
    printf("\n-- Insercao do Numero 13 -- \n");
    raiz = inserirNoAVL(raiz, 13);
    IMPRIMIR(raiz);

    printf("\n-- Exclusao do Numero 10 -- \n");
    raiz = deletarNo(raiz, 10);
    IMPRIMIR(raiz);

    // PONT raiz2 = NULL;

    // raiz2 = inserirNoAVL(raiz2, 50);
    // raiz2 = inserirNoAVL(raiz2, 40);
    // raiz2 = inserirNoAVL(raiz2, 30);
    // raiz2 = inserirNoAVL(raiz2, 20);
    // raiz2 = inserirNoAVL(raiz2, 10);
    // IMPRIMIR(raiz);

    printf("\nAperte <SPACE> para finalizar\n");
    char f;
    scanf("%c", f);

    return 0;
}

