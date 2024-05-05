#include <stdio.h>

//todo PILHATRIPLA
// Os comportamentosda pilha 1 e da pilha 3 serão iguais aos implementados na PILHADUPLA

// A base da pilha 1 é fixa na posição zero do arranjo e o topo cresce em direção ao fim do arranjo; 
// A pilha 2 terá o valor de sua base inicializado como MAX/3 e seu topo crescerá em direção ao fim do arranjo.
// A base da pilha 3 é fixa na posição MAX-1 do arranjo e o topo desta pilha cresce em direção ao início do arranjo.

// A pilha 2 poderá ser deslocada para a esquerda ou para a direita se, respectivamente, a pilha 1 ou a pilha 3 precisarem de espa¸co para a inserção de novos elemento

//todo Iniciar Pilha
//todo Inserir
//todo Excluir Elemento
//todo Deslocar direita 
//todo Deslocar esquerda

#define MAX 6 // Cada pilha tem dois espaços
#define TRUE 1
#define FALSE 0
#define NP 3 


typedef struct 
{
    int valor;
} WRAPPER;

typedef struct 
{
    WRAPPER A[MAX];
    int base[NP+1];
    int topo[NP+1];

} PILHATRIPLA;


void iniciarArranjo (PILHATRIPLA *pt) 
{
    pt->base[0] = 0;
    pt->base[1] = MAX / 3;
    pt->base[2] = MAX - 1;

    //????????
    pt->topo[0] = pt->base[0] - 1;
    pt->topo[1] = pt->base[1] - 1;
    pt->topo[2] = pt->base[2] - 1;

    return;

}

int excluirElementoPilha(PILHATRIPLA* p, int inputNum, int pilhaK) {}

int main (void)
{

    PILHATRIPLA pilhaTripla;

    iniciarArranjo(&pilhaTripla);


    return 0;
}