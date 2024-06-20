/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2022                           **/
/**   Turma 03 - Prof. Luciano Digiampietri                         **/
/**                                                                 **/
/**   Segundo Exercicio-Programa                                    **/
/**                                                                 **/
/**   <nome do(a) aluno(a)>                   <numero USP>          **/
/**                                                                 **/
/*********************************************************************/

//// tamanho
//// inserirAluno
//// buscarAluno
//// excluirAluno
//// inserirNotaRecuperacao

// Duplamente Ligada: Cada nó na lista possui referências tanto para o nó anterior quanto para o próximo nó na sequência.
// Ordenada: Os elementos são mantidos em ordem crescente ou decrescente com base em um critério específico (como valores numéricos, por exemplo).
// Circular: O último nó da lista aponta de volta para o nó-cabeça, formando um ciclo contínuo. Isso permite percorrer a lista de maneira circular, ou seja, após o último nó, volta-se para o primeiro nó da lista.
// Nó-Cabeça: É um nó especial que não contém dados do domínio principal, mas facilita a manipulação da lista. Geralmente, o nó-cabeça é utilizado para apontar para o primeiro e o último nó da lista, além de conter informações adicionais como o tamanho da lista ou ponteiros relevantes.


#include "turma.h"

/* Funcao usada em testes da correcao automatica - NAO APAGAR OU MODIFICAR */
void print123(){
	/* Funcao utilizada pelo sistema de correcao automatia
	   Nao apague ou modifique esta funcao                 */
}



/* IMPLEMENTE FUNCOES EXTRAS/AUXILIARES SE JULGAR NECESSARIO */



/* Funcao que retorna o numero de alunos da turma cujo endereco foi passado
   como parametro de entrada (deve somar os alunos das tres listas). */
int tamanho(TURMA* turma){
	int tam = 0;
	PONT atual;
	int i;

	// todo COMPLETE/IMPLEMENTE SEU CODIGO AQUI 
	for (i = 0; i < 3; i++) 
	{
		atual = turma->LISTAS[i]->prox; // Primeiro é o nó cabeça
		while (atual != turma->LISTAS[i])
		{
			tam++;
			atual = atual->prox;
		}		

	}

	return tam;
}


/* Funcao que recebe o endereco de uma turma e um numero USP e retorna 
   NULL caso nao exista um aluno com o respectivo numero USP na turma ou
   o endereco de memoria do ELEMENTO que contem o respectivo aluno, caso
   ele esteja presente na turma. */
PONT buscarAluno(TURMA* turma, int nusp){
	int i;
	PONT walk;
	for (i = 0; i < 3 ; i++) 
	{
		walk = turma->LISTAS[i]->prox;
		while (walk != turma->LISTAS[i])
		{
			if (walk->aluno.nusp == nusp) 
				return walk;
			walk = walk->prox;
		}
	}
	
	return NULL;
}



/* Funcao que recebe o endereco de uma turma e o numero USP, nota e 
   frequencia de um aluno e deve: Retornar false caso:
   o numero USP seja menor do que zero, ou a nota seja menor do que zero ou
   maior do que cem ou a frequencia seja menor do que zero ou maior do que cem;
   Deve, tambem, retornar false se a turma ja contiver um aluno com o 
   mesmo numero USP.
   Caso contrario, esse novo aluno devera ser inserido na turma e a funcao 
   devera retornar true. A insercao na turma contem as seguintes atividades
   (lembre-se que todas as listas sao ordenadas de acordo com o numero 
   USP do aluno):
     1a) alocacao dinamica de memoria de uma estrutura do tipo ELEMENTO.
         Os campos do aluno do respectivo elemento deverao ser preenchidos 
         com os valores recebidos como parâmetro pela funcao.
     2a) este novo elemento devera ser inserido na lista ligada correta, 
         de acordo com a nota e a frequencia do aluno
         (LISTAS[0] para alunos aprovados; LISTAS[1] para alunos em
         recuperacao; e LISTAS[2] para alunos reprovados).
     3a) por fim, a função deverá retornar true.
*/
bool inserirAluno(TURMA* turma, int nusp, int nota, int frequencia){

	// Retornar false caso o número USP seja menor do que zero, ou a nota seja menor do que zero ou maior do que cem ou a frequência seja menor do que zero ou maior do que cem
	if (nusp < 0 || nota < 0 || nota > 100 || frequencia < 0 || frequencia > 100 )
		return false;

	
	// Deve, também, retornar false se a turma já contiver um aluno com o mesmo número USP.
	if (buscarAluno(turma, nusp) != NULL) 
		return false;


	// Caso contrário, esse novo aluno deverá ser inserido na turma e a função deverá retornar  true. A inserção na turma contém as seguintes atividades 
	// 1a) alocação dinâmica de memória de uma estrutura do tipo ELEMENTO. Os campos do aluno do respectivo elemento deverão ser preenchidos com os valores recebidos como parâmetro pela função.
	PONT novoAluno = (PONT) malloc (sizeof (ELEMENTO));
    if (novoAluno == NULL) return false;

	novoAluno->aluno.nota = nota;
	novoAluno->aluno.nusp = nusp;
	novoAluno->aluno.freq = frequencia;


	// 2a) este novo elemento deverá ser inserido na lista ligada correta, de acordo com a nota e a frequência do aluno (LISTAS[0] para alunos aprovados; LISTAS[1] para alunos em recuperação; e LISTAS[2] para alunos reprovados).
	int tipoTurma;

	// Lista 0 -> (nota≥50 e frequência≥70)
	if (nota >= 50 && frequencia >= 70) 
		tipoTurma = 0;
	// Lista 1 -> (nota≥30 e nota<50 e frequência≥70)
	else if (nota >= 30 && nota < 50 && frequencia >= 70)
		tipoTurma = 1;
	// (frequência<70  ou [nota<30 antes da recuperação ou nota<50 depois da recuperação]).
	else 
		tipoTurma = 2;


	
	// (lembre-se que todas as listas são ordenadas de acordo com o número USP do aluno):
	// 3a) por fim, a função deverá retornar true
	PONT atual = turma->LISTAS[tipoTurma]->prox;
	PONT anterior = turma->LISTAS[tipoTurma];

	while (atual->aluno.nusp < nusp && atual != turma->LISTAS[tipoTurma])
	{
		anterior = atual;
		atual = atual->prox;
	}

	novoAluno->prox = atual;
	novoAluno->ant = anterior;
	anterior->prox = novoAluno;
	atual->ant = novoAluno;

	return true;
	
	
}


/* Funcao que recebe o endereco de uma turma e um numero USP e deve:
   Retornar false se a turma nao possuir um aluno com esse numero USP.
   Caso contrario, esse aluno devera ser excluido da turma e a função devera
   retornar true. A exclusao na turma contem as seguintes atividades:
     1a) remocao do elemento que aponta para o respectivo aluno na lista
         correta (nao esqueca de acertar os ponteiros).
     2a) liberacao da memoria do elemento da lista que apontava para o
         respectivo aluno.
     3a) por fim, a funcao devera retornar true.
*/
bool excluirAluno(TURMA* turma, int nusp){

	PONT alunoExcluir = buscarAluno(turma, nusp);
	if (alunoExcluir == NULL) return false;

	//Acertar ponteiros
	alunoExcluir->ant->prox = alunoExcluir->prox;
	alunoExcluir->prox->ant =  alunoExcluir->ant;

	// Remoção do elemento
	free(alunoExcluir);
	return true; 
}

/* Funcao que recebe o endereco de uma turma, o numero USP e a nota de 
   um aluno e deve: Retornar false caso este aluno nao esteja presenta na
   lista de alunos em recuperacao (LISTAS[1]).
   Caso contrario, esse aluno devera ter sua nota atualizada com o valor 
   passado como parametro, ser retirado da lista de recuperação e inserido
   na lista correta, ordenada pelo numero USP. A lista correta dependera da
   nota do aluno: se maior ou igual que 50 devera ir para a lista de aprovados
   (LISTAS[0]), caso contrario, para a lista de reprovados (LISTAS[2]).
   Apos a remocao do aluno da lista de alunos em recuperacao e insercao na 
   lista correta (de acordo com o desempenho na recuperacao),
   a funcao devera retornar true. */

bool verificarRecuperacao (TURMA* turma, int nusp) 
{
	PONT walkRecuperacao = turma->LISTAS[1]->prox;
	while (walkRecuperacao != turma->LISTAS[1])
	{
		if (walkRecuperacao->aluno.nusp == nusp) 
			return true;
		walkRecuperacao = walkRecuperacao->prox;
	}
	return false;
}

bool inserirNotaRecuperacao(TURMA* turma, int nusp, int nota){

	PONT alunoRecuperacao = buscarAluno(turma, nusp);
	if (alunoRecuperacao == NULL)
		return false;
	
	
	// Retornar false caso este aluno nao esteja presenta na lista de alunos em recuperacao (LISTAS[1]).
	if (!verificarRecuperacao(turma, nusp)) return false;


	// Caso contrario, esse aluno devera ter sua nota atualizada com o valor passado como parametro
	alunoRecuperacao->aluno.nota = nota;
	
	//, ser retirado da lista de recuperação e 
	// excluirAluno(turma, alunoRecuperacao->aluno.nusp);
	// inserido na lista correta, ordenada pelo numero USP.
	int freq = alunoRecuperacao->aluno.freq;
	if (!excluirAluno(turma, nusp)) 
		return false;

	return inserirAluno(turma, nusp, nota, freq);
}


/* Funcao que cria e retorna uma TURMA.
   Neste EP, uma turma contem tres listas duplamente ligadas de ELEMENTOS,
   estas listas sao circulares e possuem no-cabeca
*/
TURMA inicializaTurma(){
	TURMA t1;

	// criacao de um aluno ficticio que poder ser usado como sentinela
	ALUNO ficticio;
	ficticio.nusp = -1;
	ficticio.nota = -1;
	ficticio.freq = -1;

	// criacao dos tres nos-cabeca
	int c;
	for (c=0; c<3; c++){
		t1.LISTAS[c] = (PONT) malloc(sizeof(ELEMENTO));
		t1.LISTAS[c]->aluno = ficticio;
		t1.LISTAS[c]->prox = t1.LISTAS[c];
		t1.LISTAS[c]->ant = t1.LISTAS[c];
	}
	return t1;
}



/* Funcao que reinicia (ou limpa) a TURMA passada como parametro.
   To dos os elementos, exceto os nos-cabeca, sao apagamos e a TURMA fica
   da mesma forma como se ela tivesse sido recem criada.
*/
void reinicializaTurma(TURMA* turma){
	PONT atual, apagar;
	
	// apagar todos os elementos, exceto o cabeca, da LISTAS[0]
	atual = turma->LISTAS[0]->prox;
	while (atual != turma->LISTAS[0]){
		apagar = atual;
		atual = apagar->prox;
		free(apagar);
	}
	atual->prox = atual;
	atual->ant = atual;
	
	// apagar todos os elementos, exceto o cabeca, da LISTAS[1]
	atual = turma->LISTAS[1]->prox;
	while (atual != turma->LISTAS[1]){
		apagar = atual;
		atual = apagar->prox;
		free(apagar);
	}
	atual->prox = atual;
	atual->ant = atual;

	// apagar todos os elementos, exceto o cabeca, da LISTAS[2]
	atual = turma->LISTAS[1]->prox;
	while (atual != turma->LISTAS[1]){
		apagar = atual;
		atual = apagar->prox;
		free(apagar);
	}
	atual->prox = atual;
	atual->ant = atual;
	
	
}

/* Funcao que exibe todos os alunos da turma referenciada como parametro.
   Exibe os alunos das tres listas. */
void exibirTurma(TURMA* turma){
	PONT atual;
	ALUNO aluno;
	printf("\n###### Exibindo lista [%i aluno(s)] ######\n", tamanho(turma));
	printf("   Alunos Aprovados:");
	atual = turma->LISTAS[0]->prox;
	while (atual != turma->LISTAS[0]){
		aluno = atual->aluno;
		printf(" (%4i, %3i, %3i)", aluno.nusp, aluno.nota, aluno.freq);
		atual = atual->prox;
	}
	printf("\n");
	
	printf("   Alunos em Recuperacao:");
	atual = turma->LISTAS[1]->prox;
	while (atual != turma->LISTAS[1]){
		aluno = atual->aluno;
		printf(" (%4i, %3i, %3i)", aluno.nusp, aluno.nota, aluno.freq);
		atual = atual->prox;
	}
	printf("\n");
	atual = turma->LISTAS[2]->prox;
	printf("   Alunos Reprovados:");
	while (atual != turma->LISTAS[2]){
		aluno = atual->aluno;
		printf(" (%4i, %3i, %3i)", aluno.nusp, aluno.nota, aluno.freq);
		atual = atual->prox;
	}
	printf("\n");

	printf("\n###### EXIBINDO OS ALUNOS EM ORDEM INVERSA ######\n");
	printf("   Alunos Aprovados:");
	atual = turma->LISTAS[0]->ant;
	while (atual != turma->LISTAS[0]){
		aluno = atual->aluno;
		printf(" (%4i, %3i, %3i)", aluno.nusp, aluno.nota, aluno.freq);
		atual = atual->ant;
	}
	printf("\n");
	
	printf("   Alunos em Recuperacao:");
	atual = turma->LISTAS[1]->ant;
	while (atual != turma->LISTAS[1]){
		aluno = atual->aluno;
		printf(" (%4i, %3i, %3i)", aluno.nusp, aluno.nota, aluno.freq);
		atual = atual->ant;
	}
	printf("\n");
	atual = turma->LISTAS[2]->ant;
	printf("   Alunos Reprovados:");
	while (atual != turma->LISTAS[2]){
		aluno = atual->aluno;
		printf(" (%4i, %3i, %3i)", aluno.nusp, aluno.nota, aluno.freq);
		atual = atual->ant;
	}
	printf("\n\n");	
}


