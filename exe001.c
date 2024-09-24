/*
leitura de dados
*/
#include <stdio.h>

int main() {
    int idade;
    float peso;
    char nome[50];

    printf("Digite seu nome: ");
    scanf("%s", nome);
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Digite seu peso: ");
    scanf("%f", &peso);

    printf("Nome: %s\n", nome);
    printf("Idade: %d\n", idade);
    printf("Peso: %.2f\n", peso);

    return 0;
}