/*
    Estrutura básica de um arquivo em C.
    Definição e atribuição de variáveis.
    Funções de entrada e saída.

*/
#include <stdio.h>

int main() {
    // Declaração de variáveis
    int a = 10;
    int b = 20;
    int c;

    // Atribuição de valores
    c = a + b;

    // Saída de dados
    printf("Soma de %d + %d = %d\n", a, b, c);

    return 0;
}

// Compilação
// gcc aula-202409021900.c -o aula-202409021900

// Execução
// ./aula-202409021900

// Saída
// Soma de 10 + 20 = 30

// Fim do arquivo

