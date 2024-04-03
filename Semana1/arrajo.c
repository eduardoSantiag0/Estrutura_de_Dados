#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void imprimir (int* a) {
    int i;
    for (i = 0; i < SIZE; i++) {
        printf("%d\n", &a[i]);
    }
}

int main (void) {

    int arranjo[SIZE];
    int i;
    for (i = 0; i < SIZE; i++) {
        arranjo[i] = i * 10;
    }

    int* heap = (int*) malloc (sizeof(int) * SIZE);
    for (i = 0; i < SIZE; i++) {
        heap[i] = i * 2;
    }

    int arraay2 

    printf("Stack\n");
    imprimir(arranjo);

    printf("\n");
    
    printf("Heap:\n");
    imprimir(heap);
    free(heap);

    return 0;
}