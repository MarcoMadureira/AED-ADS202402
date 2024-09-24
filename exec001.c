/*
* Descrição: Primeiro programa em C
* 
* Data: 2024/08/23
* Autor: Marco Aurelio 
*/
#include <stdio.h>


// Protótipo da função
int fatorial (int n);

// Prototipo da função somar
int somar (int a, int b);

// Prototipo da função subtrair
int subtrair (int a, int b);

// Prototipo da função multiplicar
int multiplicar (int a, int b);

// Prototipo da função dividir
int dividir (int a, int b);

// Função principal
int main () {
    int a, b;
    printf("Digite dois números inteiros: ");
    scanf("%d %d", &a, &b);
    printf("A soma de %d e %d é %d\n", a, b, somar(a, b));
    printf("A subtração de %d e %d é %d\n", a, b, subtrair(a, b));
    printf("A multiplicação de %d e %d é %d\n", a, b, multiplicar(a, b));
    printf("A divisão de %d e %d é %d\n", a, b, dividir(a, b));
    return 0;
}   

// Função que soma dois números inteiros
int somar (int a, int b) {
    return a + b;
}

// Função que subtrai dois números inteiros
int subtrair (int a, int b) {
    return a - b;
}

// Função que multiplica dois números inteiros
int multiplicar (int a, int b) {
    return a * b;
}

// Função que divide dois números inteiros
int dividir (int a, int b) {
    return a / b;
}

// Função que calcula o fatorial de um número
int fatorial (int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}

// Fim do arquivo exec001.c