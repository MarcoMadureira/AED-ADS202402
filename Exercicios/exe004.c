/*
Estrutura de Dados Dinâmica é uma estrutura de dados que possui um tamanho variável e é alocada em tempo de execução. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float peso;
} Pessoa;

typedef struct No {
    Pessoa *pessoa;
    struct No *prox;
} No;

No *inicio = NULL;

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

void insere_pessoa(Pessoa *p) {
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    novo->pessoa = p;
    novo->prox = inicio;
    inicio = novo;
}

void imprime_pessoas() {
    No *p = inicio;
    while (p != NULL) {
        printf("Nome: %s\n", p->pessoa->nome);
        printf("Idade: %d\n", p->pessoa->idade);
        printf("Peso: %.2f\n", p->pessoa->peso);
        p = p->prox;
    }
}

void libera_pessoas() {
    No *p = inicio;
    while (p != NULL) {
        No *aux = p;
        p = p->prox;
        free(aux->pessoa);
        free(aux);
    }
}

int main() {
    Pessoa *p1 = cria_pessoa("João", 25, 70.5);
    Pessoa *p2 = cria_pessoa("Maria", 30, 60.0);
    insere_pessoa(p1);
    insere_pessoa(p2);
    imprime_pessoas();
    libera_pessoas();
    return 0;
}

