#include <stdio.h>

//todo PILHATRIPLA
// Os comportamentosda pilha 1 e da pilha 3 serão iguais aos implementados na PILHADUPLA

// A base da pilha 1 é fixa na posição zero do arranjo e o topo cresce em direção ao fim do arranjo; 
// A pilha 2 terá o valor de sua base inicializado como MAX/3 e seu topo crescerá em direção ao fim do arranjo.
// A base da pilha 3 é fixa na posição MAX-1 do arranjo e o topo desta pilha cresce em direção ao início do arranjo.

//todo A pilha 2 poderá ser deslocada para a esquerda ou para a direita se, respectivamente, a pilha 1 ou a pilha 3 precisarem de espaço para a inserção de novos elemento

//// Iniciar Pilha
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

int pilhaKCheia (PILHATRIPLA *pt, int k) 
{
    if(pt->topo[k] == pt->base[k + 1] - 1) return TRUE;
    else return FALSE;
}

void pushElem (PILHATRIPLA* pt, int inputNum, int pilhaK) 
{
    if (pilhaK < 0 || pilhaK > 3) {
        printf("Pilha nao existe\n");
        return;
    }

    // if (pt->topo[pilhaK] == pt->base[pilhaK] - 1){
    //     printf("Pilha Vazia\n");
    //     return;
    // }

    if (pilhaKCheia (pt, pilhaK)) {
        printf("Pilha Cheia!\n");
        return;
    }

    // Última pilha está caindo na segunda;
    // A pilha do meio não está entrando;

    if (pilhaK == 2) { //  Última Pilha
        pt->topo[pilhaK]--;
        pt->A[pt->topo[pilhaK]].valor = inputNum;

    } else if (pilhaK == 0) { // Primeira Pilha
        pt->topo[pilhaK]++;
        pt->A[pt->topo[pilhaK]].valor = inputNum;

    } else { // Pilha do Meio
        pt->topo[pilhaK]++;
        pt->A[pt->topo[pilhaK]].valor = inputNum;
    }

    return;
}

int excluirElementoPilha(PILHATRIPLA* pt, int pilhaK) 
{
    if (pt->topo[pilhaK] == pt->base[pilhaK]) {
        return FALSE;
    }

    pt->topo[pilhaK]--;
    return TRUE;
}

int peekPilha (PILHATRIPLA* pt, int pilhaK)
{
    return pt->A[pt->topo[pilhaK]].valor;
}

void imprimirPilha (PILHATRIPLA* pt, int pilhaK)
{
    if (pilhaK < 0 || pilhaK >= NP) return;


    int walk;
    int contador = 1;

    printf("Pilha %d: \n" , pilhaK);
    for (walk = pt->topo[pilhaK]; walk >= pt->base[pilhaK]; walk--) {
        printf("%d) %d\n",contador, pt->A[walk].valor);
        contador++;
    }

    printf("\n");
}

int main (void)
{

    PILHATRIPLA pilhaTripla;

    iniciarArranjo(&pilhaTripla);
    pushElem(&pilhaTripla, 10, 0);
    pushElem(&pilhaTripla, 20, 0);


    pushElem(&pilhaTripla, 40, 1);
    pushElem(&pilhaTripla, 50, 1);

    pushElem(&pilhaTripla, 70, 2);
    pushElem(&pilhaTripla, 80, 2);

    

    imprimirPilha(&pilhaTripla, 0);
    imprimirPilha(&pilhaTripla, 1);
    imprimirPilha(&pilhaTripla, 2);

    return 0;
}