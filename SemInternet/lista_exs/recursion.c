#include <stdio.h>

// 2) Imagine a como um vetor de inteiros. Apresente algoritmos recursivos para calcular: 

// a) O elemento máximo do vetor; 
// b) O elemento mínimo do vetor;
// c) a soma dos elementos do vetor;
// d) o produto dos elementos do vetor;
// e)  a média dos elementos do vetor.

int maxElem (int vetor[], int n) {
    // Só temum elemento;
    if (n == 1) 
        return vetor[0];
    

    int max_rest = maxElem (vetor, n-1);

    if (vetor[n-1] > max_rest)
        return vetor[n-1];
    else 
        return max_rest;
}

int minElem (int vetor[], int n)
{
    if (n == 1)
        return vetor[0];

    int min_res = minElem (vetor, n-1);

    if (vetor[n-1] < min_res)
        return vetor[n-1];
    else 
        return min_res;
}

int SumAll (int vetor[], int n)
{
    if (n == 1) 
        return vetor [0];
    return vetor[n - 1] + SumAll (vetor, n - 1);
}

int productAll (int vetor[], int n)
{
    if (n == 1)
        return vetor[0];
    return vetor[n - 1] * productAll(vetor, n - 1);
}

float AVG  (int vetor[], int n)
{
    return (float) SumAll (vetor, n) / n;
}

int binarySearch (int arr[], int high, int low, int chave)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == chave) 
            return mid;

        
        if (arr[mid] > chave)
            return binarySearch(arr, mid - 1, low, chave); 
        
        return binarySearch(arr, high, mid + 1, chave); 
    }

    return -1;
}

int main (void)
{
    int nums[] = {10, 20, 10};
    int bin[] = { 1, 3, 7, 15, 21, 36, 78, 95, 106};

    int max = maxElem (nums, 3);
    int min = minElem (nums, 3);
    int soma = SumAll (nums, 3);
    int prod = productAll (nums, 3);
    float media = AVG (nums, 3);

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    printf("Soma: %d\n", soma);
    printf("Produto: %d\n", prod);
    printf("Media: %.2f\n", media);

    int achou = binarySearch (bin, 9, 0, 78);
    printf("Achou: %d", achou);
    // if (achou != -1) {
    // }



    return 0;
}