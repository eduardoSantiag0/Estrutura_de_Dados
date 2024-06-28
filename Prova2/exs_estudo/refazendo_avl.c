#include <stdio.h>
#include <stdlib.h>


typedef struct aux {
    int bal;
    int chave;
    struct aux* esq;
    struct aux* dir;
} NODE;

typedef NODE* PONT;


PONT createNode (int ch) {
    PONT novo = (PONT) malloc (sizeof (NODE));
    novo->chave = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->bal = 0;
    return novo;
}

int max (int a, int b) {
    // Calcular o máximo entre dois numeros
    return (a > b) ? a : b;
}

int getHeight (PONT raiz) {
    //De forma recursiva, contar os nós
    if (raiz == NULL) return 0;

    // Se esquerda == -1
    // int filhosEsq = getHeight (raiz->esq);

    // Se direita == +1
    // int filhosDir = getHeight (raiz->dir);


    // if (filhosEsq > filhosDir) return -1;
    // else return + 1;

    return  max(getHeight(raiz->esq), getHeight(raiz->dir)) + 1; //!!!!!!!!!!!!!!!
}

int balanceFactor (PONT raiz) {
    // Chamar getHeight da esq e da dir
    if (raiz == NULL) return 0; 
    return getHeight(raiz->esq) - getHeight(raiz->dir);
}

PONT rotacaoL (PONT raiz) {
    PONT filhoDir = raiz->dir;
    PONT temp = filhoDir->esq;

    filhoDir->esq = raiz;
    raiz->dir = temp;
    return filhoDir;

}

// PONT rotacaoLL (PONT p) {
//     PONT u = p->esq;
//     PONT v = u->esq;
//     PONT temp = u->dir;

//     u->dir = p;
//     p->esq = temp;

//     return u;
// }

PONT rotacaoR (PONT raiz) {
    PONT filhoEsq = raiz->esq;
    PONT temp = filhoEsq->dir;

    raiz->esq = temp;
    filhoEsq->dir = raiz;

    return filhoEsq;
    
}

PONT insert (PONT raiz, int ch) {
    if (raiz == NULL) return createNode (ch);

    if (ch < raiz->chave) {
        raiz->esq = insert(raiz->esq, ch);
    } else if (ch > raiz->chave) {
        raiz->dir = insert(raiz->dir, ch);
    } else {
        return raiz; 
    }

    int bal = balanceFactor(raiz);

    // LL
    if (bal > 1 && ch < raiz->esq->chave) {
        return rotacaoR(raiz);
    }

    // RR
    if (bal < -1 && ch > raiz->dir->chave) {
        return rotacaoL(raiz);
    }

    // LR
    if (bal > 1 && ch > raiz->esq->chave) {
        raiz->esq = rotacaoL(raiz->esq);
        return rotacaoR(raiz);
    }

    // RL
    if (bal < -1 && ch < raiz->dir->chave) {
        raiz->dir = rotacaoR(raiz->dir);
        return rotacaoL(raiz);
    }

    return raiz;

} 

void LOG (PONT raiz) {
    if (raiz == NULL) return;

    printf("%d - ", raiz->chave);
    LOG(raiz->esq);
    LOG(raiz->dir);

    return;
}


int main (void) {

    PONT raiz = createNode (50);

    // Inserir nós na árvore
    raiz = insert(raiz, 10);
    raiz = insert(raiz, 20);
    raiz = insert(raiz, 30);
    raiz = insert(raiz, 40);
    raiz = insert(raiz, 50);
    raiz = insert(raiz, 25);

    LOG(raiz);

    printf("\n\nAperte <SPACE> para concluir o programa\n");
    getchar();
    return 0;
} 