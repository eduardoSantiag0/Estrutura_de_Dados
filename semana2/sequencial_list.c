#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef int bool;
typedef int TIPOCHAVE;

typedef struct{
  TIPOCHAVE chave;
} REGISTRO;

typedef struct {
  REGISTRO A[MAX+1];
  int numElem;
} LISTA;

void inicializarLista(LISTA* arranjo) {
    arranjo->numElem = 0;
}

int adicionarElemento(LISTA* arranjo, REGISTRO inputNum, int input_Pos) 
{
    int tam_atual = arranjo->numElem;
    if (tam_atual >= MAX || inputNum.chave < 0 || input_Pos > tam_atual) 
        return -1;

    int j;
    for (j = tam_atual; j > input_Pos ; j--) {
      // Desloca para a esquerda
        arranjo->A[j] = arranjo->A[j - 1]; //! PORQUE -3
    }

    arranjo->A[input_Pos] = inputNum;

    arranjo->numElem++;
    return 0;
}

int excluirElemento (LISTA* arranjo, int input_excluir_pos) 
{
  if (input_excluir_pos >= arranjo->numElem) 
    return -1;

  int j;
  for (j = input_excluir_pos; j < arranjo->numElem - 1; j++) {
    arranjo->A[j] = arranjo->A[j + 1]; //! PORQUE +
  }

  arranjo->numElem--;
  return 0;
}

void quickSort (LISTA* arranjo) 
{
  int i, j;
  for (i = 0; i < arranjo->numElem - 1; i++) {
    for (j = 0; j < arranjo->numElem - i - 1; j++) {
      if (arranjo->A[j].chave > arranjo->A[j + 1].chave) {
        REGISTRO temp = arranjo->A[j];
        arranjo->A[j] = arranjo->A[j + 1];
        arranjo->A[j + 1] = temp;

      }
    }
  }
}


int buscaBinaria (LISTA* arranjo, int input_buscar) 
{
  int out_pos;
  int j = 0;
  
  //* esq = min 
  int esq = 0;
  //* dir = max
  int dir = arranjo->numElem - 1;
  //* meio = range de possíveis numeros
  int meio;
  
  while (arranjo->A[j].chave != input_buscar || arranjo->A[j].chave >= arranjo->numElem) 
  {
    //? while (esq <= dir)
    //? Como atualizar esq e dir
    meio = (esq + dir) / 2; 

    if (arranjo->A[j].chave == input_buscar) {
      out_pos = j;
      return out_pos;
    }


    j++;
  }

  return -1;

}

void Log (LISTA* arranjo) {
  int i;
  for (i = 0 ; i < arranjo->numElem -1; i++) {
    printf("%d\n", arranjo->A[i]);
  }
}

int main (void) {

    LISTA lista;
    // Iniciar lista
    inicializarLista(&lista);


    REGISTRO reg1 = {100};
    REGISTRO reg2 = {20};
    REGISTRO reg3 = {30};
    REGISTRO reg4 = {400};
    // Add Elemento
    adicionarElemento (&lista, reg1, 0);
    adicionarElemento (&lista, reg2, 1);
    adicionarElemento (&lista, reg4, 2);
    adicionarElemento (&lista, reg3, 2);

    int i;

    printf("\t Inicial\n");
    Log(&lista);


    printf("\t Exclusao\n");
    excluirElemento(&lista, 1);
    Log(&lista);


    printf("\t QuickSort\n");
    quickSort(&lista);
    Log(&lista);


    return 0;
}