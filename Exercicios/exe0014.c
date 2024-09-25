/*
Algortimo para tratamento de registros de pessoas com nome, idade e sexo.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa {
    char nome[50];
    int idade;
    char sexo;
};

int main() {
    struct pessoa p[3];
    int i;

    for (i = 0; i < 3; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        gets(p[i].nome);
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &p[i].idade);
        printf("Digite o sexo da pessoa %d: ", i + 1);
        scanf(" %c", &p[i].sexo);
        getchar();
    }

    for (i = 0; i < 3; i++) {
        printf("Nome: %s\n", p[i].nome);
        printf("Idade: %d\n", p[i].idade);
        printf("Sexo: %c\n", p[i].sexo);
    }

    return 0;
}

// Para compilar (Linux):
// gcc exe0014.c -o exe0014
// Para executar (Linux):
// ./exe0014
