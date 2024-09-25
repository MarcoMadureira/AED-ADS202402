/*
Tipo Abstrato de Dados (TAD) é um tipo de dado definido pelo usuário, que é implementado em termos de operações sobre esses dados.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float peso;
} Pessoa;

Pessoa *cria_pessoa(char *nome, int idade, float peso) {
    Pessoa *p = (Pessoa *) malloc(sizeof(Pessoa));
    if (p == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    strcpy(p->nome, nome);
    p->idade = idade;
    p->peso = peso;
    return p;
}

void imprime_pessoa(Pessoa *p) {
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
    printf("Peso: %.2f\n", p->peso);
}

void libera_pessoa(Pessoa *p) {
    free(p);
}

int main() {
    Pessoa *p = cria_pessoa("João", 25, 70.5);
    imprime_pessoa(p);
    libera_pessoa(p);
    return 0;
}


