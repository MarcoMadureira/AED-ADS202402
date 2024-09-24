/*
 Estrutura de Dados Estática é uma estrutura de dados que possui um tamanho fixo e pré-definido em tempo de compilação.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[50];
    int idade;
    float peso;
} Pessoa;

Pessoa pessoas[MAX];
int n = 0;

void insere_pessoa(char *nome, int idade, float peso) {
    if (n == MAX) {
        printf("Vetor cheio\n");
        return;
    }
    strcpy(pessoas[n].nome, nome);
    pessoas[n].idade = idade;
    pessoas[n].peso = peso;
    n++;
}

void imprime_pessoas() {
    for (int i = 0; i < n; i++) {
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Peso: %.2f\n", pessoas[i].peso);
    }
}

int main() {
    insere_pessoa("João", 25, 70.5);
    insere_pessoa("Maria", 30, 60.0);
    imprime_pessoas();
    return 0;
}
