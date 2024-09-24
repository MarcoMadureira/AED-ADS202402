/*
Algoritmo de ordenação por seleção (Selection Sort) em C
O algoritmo de ordenação por seleção é um algoritmo de ordenação simples e eficiente. Ele é in-place, ou seja, não requer memória extra, e é estável, ou seja, não altera a ordem de elementos iguais. O algoritmo de ordenação por seleção é um algoritmo de comparação, ou seja, ele compara os elementos do array para ordená-los.
*/
#include <stdio.h>

// Função para trocar dois elementos de posição
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Função para implementar o Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // Move o limite do array um por um
    for (i = 0; i < n - 1; i++) {
        // Encontra o menor elemento no array não ordenado
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Troca o menor elemento com o primeiro elemento
        swap(&arr[min_idx], &arr[i]);
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}


