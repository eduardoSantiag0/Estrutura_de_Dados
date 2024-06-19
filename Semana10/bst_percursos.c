#include <stdio.h>
#include <malloc.h>

//// Iniciar Pilha
//// Push
//// Pop
//// Iniciar BST
//// Iniciar Raiz
//// Adicionar Nó
//// Criar Nó
//todo void preOrdemNaoRecursivo(PONT raiz)
//! NÃO FINALIZADO

typedef struct aux 
{
    int chave;
    struct aux *prox;
} NODE_PILHA;


typedef NODE_PILHA* PONT_PILHA;

typedef struct {
    PONT_PILHA topo;
} PILHA;


PONT_PILHA criarNo (int inChave) 
{
    NODE_PILHA *novoNo = (NODE_PILHA*) malloc (sizeof (NODE_PILHA));
    novoNo->chave = inChave;
    novoNo->prox = NULL;

    return novoNo;
}

void iniciarPilha (PILHA *p)
{
    p->topo = NULL;
}


void push (PILHA* p, int chave) 
{
    PONT_PILHA novo = criarNo(chave);
    novo->prox = p->topo;
    p->topo = novo;
    return;
}

int pop (PILHA* p) {
    
    if (p->topo == NULL) 
    {
        printf("Pilha vazia.\n");
        return -1;
    }

    PONT_PILHA out = p->topo;
    p->topo = p->topo->prox;

    int pop = out->chave;
    free(out);
    return pop;
}

void push_BST(PILHA* p, PONT_BST node) {
    PONT_PILHA novo = criarNo(node);
    novo->prox = p->topo;
    p->topo = novo;
}

PONT_BST pop_BST(PILHA* p) {
    if (p->topo == NULL) {
        printf("Pilha vazia.\n");
        return NULL;
    }

    PONT_PILHA out = p->topo;
    p->topo = p->topo->prox;

    PONT_BST node = out->node;
    free(out);
    return node;
}

void exibirPilha (PILHA* p)
{
    PONT_PILHA walk = p->topo;
    while (walk)
    {
        printf(" %d ", walk->chave);
        walk = walk->prox;
    }

    printf("\n");
    
}

typedef struct auxiliar
{
    int chave;
    struct auxiliar *esq, *dir;
    
} BST_NODE;

typedef BST_NODE* PONT_BST;

PONT_BST criarBST_Node (int chave) 
{
    PONT_BST novo = (PONT_BST) malloc (sizeof(BST_NODE));
    novo->chave = chave;
    return novo;
}

PONT_BST iniciarArvoreBST() {
    return (NULL);
}

PONT_BST adicionarNodeBST (PONT_BST raiz, PONT_BST no) 
{
    if (raiz == NULL) return no;

    if (no->chave < raiz->chave) raiz->esq = adicionarNodeBST(raiz->esq, no);
    else raiz->dir = adicionarNodeBST (raiz->dir, no);

    return raiz;
}

//! Criamos uma pilha e inserimos o nó raiz;
//* Enquanto a pilha não estiver vazia:
//* - retiramos o nó de seu topo;
//* - imprimimos seu valor;
//* - inserimos seus ﬁlhos (se existirem) na pilha

void preOrdemNaoRecursivo(PONT_BST raiz) {
    if (!raiz) return;

    PILHA stack;
    iniciarPilha(&stack);
    push(&stack, (int)(long)raiz); // Push root node onto stack (cast to long to avoid pointer-to-int warning)

    while (stack.topo != NULL) {
        PONT_BST atual = (PONT_BST)(long)pop(&stack); // Pop node from stack (cast back to pointer type)
        printf("%d ", atual->chave);

        // Push right child first so that left child is processed first
        if (atual->dir != NULL) {
            push(&stack, (int)(long)atual->dir);
        }
        if (atual->esq != NULL) {
            push(&stack, (int)(long)atual->esq);
        }
    }
    printf("\n");
}
int main (void)
{
    PILHA p;
    iniciarPilha(&p);

    PONT_BST raiz = iniciarArvoreBST();

    PONT_BST node = criarBST_Node(10);
    raiz = adicionarNodeBST(raiz, node);

    PONT_BST node2 = criarBST_Node(20);
    raiz = adicionarNodeBST(raiz, node2);

    PONT_BST node3 = criarBST_Node(30);
    raiz = adicionarNodeBST(raiz, node3);

    PONT_BST node4 = criarBST_Node(50);
    raiz = adicionarNodeBST(raiz, node4);

    PONT_BST node5 = criarBST_Node(70);
    raiz = adicionarNodeBST(raiz, node5);

    preOrdemNaoRecursivo(raiz);

    return 0;
}