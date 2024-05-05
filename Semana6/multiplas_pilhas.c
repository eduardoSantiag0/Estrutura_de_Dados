#include <stdio.h>

//// Iniciar Lista
//// Retornar elementos válidos
//// Retornar numero de pilhas
//// Verificar se uma pilha está cheia
//// Excluir elementos - Pop
//todo Deslocar para direita
//todo Deslocar para esquerda
//todo Inserir elementos - Push
//// Exibir elementos 
//// Reiniciar lista

#define MAX 9
#define NP 3
#define true 1
#define false 0

typedef struct 
{
    int num;
}NODE;

typedef struct 
{
    NODE A[MAX];

    int base[NP+1];
    //! base = An array of integers that stores the base index of each stack.

    int topo[NP+1];
    //! topo = An array of integers that stores the top index of each stack.
    
} MULT_PILHAS;

void inicarPilhas (MULT_PILHAS *mp)
{
    int i;
    for (i = 0; i <= NP; i++) {
        // Total de Pilhas = 3

        mp->base[i] = (i * (MAX / NP) );
        // Index das Bases: 0, 3, 6

        mp->topo[i] = mp->base[i] - 1;
        // Index dos Topos: 
        // Initializes the top index of the stack to one element below the base index.
    }
    return;
}

int tamanhoDaPilhaK (MULT_PILHAS *mp, int k)
{
    if (k < 0 || k >= NP) return -1;
    return mp->topo[k] - mp->base[k] + 1;
}

int tamanhoTotalPilhas (MULT_PILHAS *mp, int k)
{
    int i;
    int tamanho = 0;

    for (i = 0; i < NP; i++) {
        tamanho+=tamanhoDaPilhaK (mp, i);
    }

    return tamanho;
}

int pilhaKCheia (MULT_PILHAS *mp, int k) 
{
    // if (mp->topo[k + 1] == mp->base[k - 1]) return true;
    if(mp->topo[k] == mp->base[k + 1] - 1) return true;
    else return false;
}


int paraDireita (MULT_PILHAS *mp, int pilhaK) 
{
    if (pilhaK < 1 || pilhaK >  NP - 1) return false;
    int i;
    if (mp->topo[pilhaK < mp->base[pilhaK + 1] - 1]) {
        for ( i = mp->topo[pilhaK]; i >= mp->base[pilhaK] ; i--) {
            mp->A[i+1] = mp->A[i];
        }
        mp->topo[pilhaK]++;
        mp->base[pilhaK]++;
        return true;
    }

    return false;
}

int paraEsquerda(MULT_PILHAS* p, int k) {
    if( (k < 1) || (k > NP-1) ) return false;
    int i;

    if(p->topo[k-1] < p->base[k] - 1){
        for(i = p->base[k]; i <= p->topo[k]; i++)
        p->A[i-1] = p->A[i];
        p->topo[k]--;
        p->base[k]--;
        return true;
    }
    return false;
}


void pushPilha (MULT_PILHAS *mp, int inputNum, int pilhaK)
{
    int j;
    if (pilhaKCheia (mp, pilhaK)) { //!
        for(j = NP-1; j > pilhaK; j--) paraDireita(mp, j);
        if (pilhaKCheia(mp, pilhaK)) return;
    }
    
    mp->topo[pilhaK]++;
    mp->A[mp->topo[pilhaK]].num = inputNum;

    return;
}

void popPilha (MULT_PILHAS *mp, int pilhaK)
{
    if (pilhaK < 0 || pilhaK >= NP){
        printf("Pilha Invalida\n");
        return;
    } 

    if (! (mp->topo[pilhaK] >= mp->base[pilhaK])) {
        printf("Pilha Nao Iniciada\n");
        return;
    }
    
    mp->topo[pilhaK]--;
    return;
}

void reinicarPilhas (MULT_PILHAS *mp) 
{
    inicarPilhas (mp);
}

void exibirPilha (MULT_PILHAS *mp, int pilhaK)
{
    if (pilhaK < 0 || pilhaK >= NP) return;

    int i;

    printf("Elementos da Pilha %d:\n", pilhaK);

    for (i = mp->topo[pilhaK]; i >= mp->base[pilhaK]; i--) {
        printf("%d\n", mp->A[i].num);
    }

    return;
}

int main (void)
{

    MULT_PILHAS minhasPilhas;
    inicarPilhas(&minhasPilhas);

    pushPilha(&minhasPilhas, 10, 0);
    pushPilha(&minhasPilhas, 20, 0);
    pushPilha(&minhasPilhas, 30, 0);

    pushPilha(&minhasPilhas, 40, 1);
    pushPilha(&minhasPilhas, 50, 1);
    pushPilha(&minhasPilhas, 60, 1);

    pushPilha(&minhasPilhas, 70, 2);
    pushPilha(&minhasPilhas, 80, 2);
    pushPilha(&minhasPilhas, 90, 2);

    printf("Imprimindo:\n");
    exibirPilha(&minhasPilhas, 0);
    printf("\n");
    exibirPilha(&minhasPilhas, 1);
    printf("\n");
    exibirPilha(&minhasPilhas, 2);
    printf("\n");


    printf("Pop:\n");
    popPilha(&minhasPilhas, 0);
    exibirPilha(&minhasPilhas, 0);

    reinicarPilhas(&minhasPilhas);
    printf("\n");
    printf("Reset:\n");
    exibirPilha(&minhasPilhas, 0);
    exibirPilha(&minhasPilhas, 1);
    exibirPilha(&minhasPilhas, 2);


    return 0;
}
