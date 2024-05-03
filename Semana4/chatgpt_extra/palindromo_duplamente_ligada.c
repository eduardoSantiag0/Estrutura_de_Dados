#include <stdio.h>
#include <stdlib.h>

typedef struct aux {
    struct aux* proximo;
    struct aux* anterior;
    char letra;
} ELEMENTO;

typedef struct {
    ELEMENTO* start;
    ELEMENTO* ultimo;
} LISTA;

typedef ELEMENTO* PONT;

void iniciarLista(LISTA* l) {
    l->start = NULL;
    l->ultimo = NULL;
}


void adicionar(LISTA* palavra, char inLetra) {
    ELEMENTO* novaLetra = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    novaLetra->anterior = NULL;
    novaLetra->letra = inLetra;
    novaLetra->proximo = NULL;

    if (palavra->start == NULL) {
        palavra->start = novaLetra;
        palavra->ultimo = novaLetra;
        return;
    }

    ELEMENTO* walk = palavra->start;
    while (walk->proximo != NULL) {
        walk = walk->proximo;
    }

    walk->proximo = novaLetra;
    novaLetra->anterior = walk;
    palavra->ultimo = novaLetra;
}



int checaPalindromo(LISTA* l) {
    ELEMENTO* esquerda = l->start;
    ELEMENTO* direita = l->ultimo;

    // Condições de parada: 
    // Os nós serem diferentes
    // Direita ou Esquerda chegarem ao fim
    while (esquerda != direita && direita != NULL) {
        if (esquerda->letra != direita->letra) {
            return 0;
        }

        esquerda = esquerda->proximo;
        direita = direita->anterior;
    }

    return 1;
}

int main(void) {
    // char palavra[] = "arara";
    char palavra[50] ;
    
    printf("Palavra: \n");
    scanf("%s", palavra);


    LISTA minhaLista;
    iniciarLista(&minhaLista);

    int i = 0;
    while (palavra[i] != '\0') {
        adicionar(&minhaLista, palavra[i]);
        i++;
    }

    if (checaPalindromo(&minhaLista)) 
        printf("Palindromo!\n");
    else 
        printf("Num eh\n");

    return 0;
}
