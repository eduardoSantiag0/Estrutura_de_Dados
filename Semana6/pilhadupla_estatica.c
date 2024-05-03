#include <stdio.h>

//// Iniciar Lista
//// Retornar elementos válidos
//// Inserir elementos - Push
//// Exibir elementos 
//todo Excluir elementos - Pop
//// Reiniciar lista

#define MAX 5

typedef struct 
{
    int num;
}ELEMENTO;

typedef struct 
{
    int topo1;
    int topo2;
    ELEMENTO PILHA[MAX];

} DUPLA_PILHA;
 

void inicarPilhas(DUPLA_PILHA *dp) 
{
    dp->topo1 = -1;
    dp->topo2 = MAX;
    printf("Pilha Iniciada\n");
}

void pushNum (DUPLA_PILHA *dp, int inNum  ,int inPilha) 
{

    //Numero da Pilha nao valido
    if (inPilha  < 1 || inPilha > 2) {
        printf("Insira uma pilha valida\n");
        return;
    }

    // Lista Cheia
    if (dp->topo1 + 1 == dp->topo2) {
        printf("Pilha Cheia\n");
        return;
    }
    
    if (inPilha == 1) {
        dp->topo1 ++;
        dp->PILHA[dp->topo1].num = inNum; 
    } else {
        dp->topo2 --;
        dp->PILHA[dp->topo2].num = inNum; 
    }

    printf("%d adicionado na Pilha %d\n", inNum, inPilha);

    return;
}


void imprimirPilhas(DUPLA_PILHA* dp, int inPilha) 
{

    int walk;

    if (inPilha == 1) {
        for (walk = dp->topo1; walk >= 0 ; walk--) {
            printf("%d\n", dp->PILHA[walk].num);
        }
    } else {
        for (walk = dp->topo2; walk < MAX; walk++) {
            printf("%d\n", dp->PILHA[walk].num);
        }
    }

    printf("Pilha completa\n");
    return;
}

int tamanhoPilha (DUPLA_PILHA *dp) 
{
    return dp->topo1 + MAX - dp->topo2;
}

void reinicarPilhas (DUPLA_PILHA *dp)
{
    inicarPilhas(dp);
    return;
}

void popNum (DUPLA_PILHA *dp, int inPilha)
{
    if (dp->topo1 == -1 || dp->topo2 == MAX) {
        printf("Pilhas estao vazias\n");
        return;
    }

    if (inPilha == 1) {
        dp->topo1--;
    } else {
        dp->topo2++;
    }

}

int main (void) 
{
    DUPLA_PILHA minhaPilha;

    inicarPilhas(&minhaPilha);
    // printf("\tTopo 1: %d, Topo 2: %d\n", minhaPilha.topo1, minhaPilha.topo2);

    pushNum(&minhaPilha, 1, 1);
    pushNum(&minhaPilha, 3, 1);
    pushNum(&minhaPilha, 5, 1);

    pushNum(&minhaPilha, 4, 2);
    pushNum(&minhaPilha, 2, 2);


    printf("\n Pilha 1 \n");
    popNum(&minhaPilha, 1);
    imprimirPilhas(&minhaPilha, 1);

    printf("\n Pilha 2 \n");
    imprimirPilhas(&minhaPilha, 2);



    return 0;
}
