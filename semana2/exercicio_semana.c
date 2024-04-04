// Dada a lista sequencial aprendida neste semestre, considerando a implementação na qual os elementos não estão ordenados em relação a sua chave (cujos códigos estão copiados a seguir). Implemente uma função de ordenação que recebe como parâmetro o endereço de uma lista e ordena os registros do arranjo A de forma crescente (lembre-se que a quantidade de registros válidos [a serem ordenados] nesta estrutura está armazenada no campo nroElem. 


#include <stdio.h>
#define MAX 50
#define ERRO -1
#define true 1
#define false 0
typedef int bool;

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX+1];
    int nroElem;
} LISTA;

void inicializarLista(LISTA* l){
    l->nroElem = 0;
}
void exibirLista(LISTA* l){
    int i;
    printf("Lista: \" ");
    for (i=0; i < l->nroElem; i++)
    printf("%i ", l->A[i].chave);
    printf("\"\n");
}


void ordenar(LISTA* arranjo) {
  int i, j;
  for (i = 0; i < arranjo->nroElem - 1; i++) {
    for (j = 0; j < arranjo->nroElem - i - 1; j++) {
      if (arranjo->A[j].chave > arranjo->A[j + 1].chave) {
        REGISTRO temp = arranjo->A[j];
        arranjo->A[j] = arranjo->A[j + 1];
        arranjo->A[j + 1] = temp;

      }
    }
  }
}