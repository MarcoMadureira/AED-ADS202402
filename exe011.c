#include <stdio.h>

// Função para reorganizar um subárvore em Max-Heap
void heapify(int arr[], int n, int i) {
    int largest = i; // Inicializa o maior como raiz
    int left = 2 * i + 1; // Filho esquerdo
    int right = 2 * i + 2; // Filho direito

    // Se o filho esquerdo for maior que a raiz
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Se o filho direito for maior que o maior atual
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Se o maior não for a raiz
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursivamente aplica o heapify na subárvore afetada
        heapify(arr, n, largest);
    }
}

// Função principal para implementar o Heap Sort
void heapSort(int arr[], int n) {
    // Constrói o Max-Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrai elementos do heap um por um
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o final
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Aplica o heapify na raiz
        heapify(arr, i, 0);
    }
}

// Função para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array is \n");
    printArray(arr, n);
    return 0;
}
