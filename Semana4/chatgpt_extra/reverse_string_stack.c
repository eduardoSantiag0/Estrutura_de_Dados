#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Implement a C program to reverse a string using a stack data structure.

#define MAX 100

typedef struct aux 
{
    char letra;
    struct aux* prox;

}ELEMENTO;


typedef struct 
{
    ELEMENTO* topo;
}PILHA;

void push(PILHA *stack, char data) {

    ELEMENTO *newElement = (ELEMENTO *)malloc(sizeof(ELEMENTO));
    if (newElement == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newElement->letra = data;

    newElement->prox = stack->topo;

    stack->topo = newElement;
}

void reverseStringHeap (PILHA* p) {
    ELEMENTO *prev = NULL;
    ELEMENTO *current = p->topo;
    ELEMENTO *next = NULL;

    while (p->topo != NULL)
    {
        next = current->prox;

        current->prox = prev;

        prev = current;
        current = next;
    }
    
    p->topo = prev;
}

int main (void) {

    char palavra[MAX];

    printf("Entre com uma palavra: ");
    fgets(palavra, MAX, stdin); 


    PILHA reverse;
    reverse.topo = NULL;

    for (int i = 0; i < strlen(palavra); i++) {
        if (palavra[i] != '\n') {
            push(&reverse, palavra[i]);
        }
    }

    reverseStringHeap (&reverse);

    // Print the reversed string
    printf("String invertida: ");
    while (reverse.topo != NULL) {
        printf("%c", reverse.topo->letra);
        reverse.topo = reverse.topo->prox;
    }
    printf("\n");

    return 0;
}