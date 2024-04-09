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
  int out_pos = -1;
  
  //* esq = min 
  int esq = 0;
  //* dir = max
  int dir = arranjo->numElem - 1;
  //* meio = range de possíveis numeros
  int meio;

  while (esq <= dir) 
  {
    meio = esq + (esq + dir) / 2;

    // caso o item do meio seja o item procurado
    if (arranjo->A[meio].chave == input_buscar) {
      out_pos = meio;
      break;
    }
    
    if (arranjo->A[meio].chave < input_buscar)
      esq = meio + 1;
    else 
      dir = meio -1; 

  }

  return out_pos;

}


int recursivaBuscaBinaria (LISTA* arranjo, int in_busca, int esq, int dir) {
  if (dir >= esq) {
    int meio = esq + (esq + dir) / 2;

    if (arranjo->A[meio].chave == in_busca) 
      return meio;

    // Right Half
    if (arranjo->A[meio].chave > in_busca)
      return recursivaBuscaBinaria(arranjo, in_busca, esq, meio - 1);

    // Left Half
    if (arranjo->A[meio].chave < in_busca)
      return recursivaBuscaBinaria(arranjo, in_busca, meio + 1, dir);

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
    REGISTRO reg5 = {325};
    REGISTRO reg6 = {225};
    REGISTRO reg7 = {112};
    REGISTRO reg8 = {45};
    REGISTRO reg9 = {22};
    REGISTRO reg10 = {77};
    // Add Elemento
    adicionarElemento (&lista, reg1, 0);
    adicionarElemento (&lista, reg2, 1);
    adicionarElemento (&lista, reg4, 2);
    adicionarElemento (&lista, reg3, 2);
    adicionarElemento (&lista, reg5, 2);
    adicionarElemento (&lista, reg6, 2);
    adicionarElemento (&lista, reg7, 2);
    adicionarElemento (&lista, reg8, 2);
    adicionarElemento (&lista, reg9, 2);
    adicionarElemento (&lista, reg10, 2);

    int i;

    printf("\t Inicial\n");
    Log(&lista);


    printf("\t Exclusao\n");
    excluirElemento(&lista, 1);
    Log(&lista);


    printf("\t QuickSort\n");
    quickSort(&lista);
    Log(&lista);

    printf("\t Busca Binaria\n");
    int busca = 225;
    int out = buscaBinaria(&lista, busca);
    printf("%d na posicao  %d\n",busca, out);

    printf("\t Recursiva - Busca Binaria\n");
    int out_recursiva = recursivaBuscaBinaria(&lista, busca, 0, lista.numElem - 1);
    printf("%d na posicao  %d\n",busca, out_recursiva);




    return 0;
}