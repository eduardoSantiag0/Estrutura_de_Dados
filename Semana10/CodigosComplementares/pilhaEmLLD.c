/******************************************************************************
     pilhaEmLLD.c
  Este programa gerencia pilhas implementas em listas lineares ligadas 
    (implementacao dinamica). O topo da pilha (nesta implementação) é o início 
	da lista.    
  As pilhas gerenciadas podem ter um numero arbitrario de elementos.
  Não usaremos sentinela nesta estrutura.
******************************************************************************/
#include "listaLigadaD.c"

typedef LISTA PILHA;

/* Inicialização da pilha (a pilha jah esta criada e eh apontada 
pelo endereco em p) */
void inicializarPilha(PILHA* p){
     inicializarLista(p);
} /* inicializarPilha */

/* Exibição da lista (pilha invertida) */
void exibirPilha(PILHA* p){
  exibirLista(p);
} /* exibirLista */ 

/* Retornar o tamanho da pilha (numero de elementos) */
int tamanhoPilha(PILHA* p) {
  return tamanho(p);
} /* tamanho */

/* Retornar o tamanho em bytes da pilha. Neste caso, isto depende do numero
   de elementos que estao sendo usados.   */
int tamanhoEmBytesPilha(PILHA* p) {
  return tamanhoEmBytes(p);
} /* tamanhoEmBytes */

/* Busca Pilha - retorna primeira chave da pilha */
PONT2 buscaPilha(PILHA* p){
  return p->inicio;
} /* buscaPilha */

/* Destruição da pilha
   libera a memoria de todos os elementos da pilha*/
void destruirPilha(PILHA* p) {
     destruirLista(p);
} /* destruirPilha */

/* inserirElementoPilha - insere elemento no "topo" da pilha   */
bool inserirElementoPilha(REGISTRO reg, PILHA* p){
     PONT2 novo = (PONT2) malloc(sizeof(REGISTRO));
     *novo = reg;
     novo->prox = p->inicio;
     p->inicio = novo;
     return true;
} /* inserirElementoPilha */

void push(void* pont, PILHA* p){
  REGISTRO temp;
  temp.chave=pont;
  inserirElementoPilha(temp,p);
}

/* excluirElementoPilha - retorna e exclui o topo da pilha (no caso, o primeiro
  elemento da lista. Retorna false se nao houver elemento a ser retirado */
bool excluirElementoPilha(PILHA* p, REGISTRO* reg){
   if (p->inicio == NULL) return false;
   PONT2 excluir = p->inicio;
   p->inicio = p->inicio->prox;
   *reg = *(excluir);
   free(excluir);
   return true;
} /* excluirElementoPilha */

TIPOCHAVE2 pop(PILHA* p){
   REGISTRO temp;
   temp.chave = NULL;
   excluirElementoPilha(p, &temp);
   return temp.chave;
}

bool isEmpty(PILHA* p){
     if (p->inicio == NULL) return true;
     return false;
}

PONT2 retornarTopoPilha(PILHA *p, TIPOCHAVE2 * ch){
     if (p->inicio == NULL) return NULL;
     *ch = p->inicio->chave;
     return p->inicio;
}
