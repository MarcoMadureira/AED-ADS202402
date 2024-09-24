/*
Algoritmo de Ordenação é um algoritmo que organiza os elementos de uma lista de acordo com um critério de ordenação.
Ordenação Quick Sort é um algoritmo de ordenação que escolhe um elemento como pivô e divide a lista em duas partes, uma com elementos menores que o pivô e outra com elementos maiores que o pivô.
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

void quick_sort(No *inicio, No *fim) {
    if (inicio == NULL || inicio == fim || inicio->prox == fim) {
        return;
    }
    No *pivo = inicio;
    No *i = inicio;
    No *j = inicio->prox;
    while (j != NULL) {
        if (j->pessoa->idade < pivo->pessoa->idade) {
            i = i->prox;
            Pessoa *aux = i->pessoa;
            i->pessoa = j->pessoa;
            j->pessoa = aux;
        }
        j = j->prox;
    }
    Pessoa *aux = i->pessoa;
    i->pessoa = pivo->pessoa;
    pivo->pessoa = aux;
    quick_sort(inicio, i);
    quick_sort(i->prox, fim);
}

int main() {
    Pessoa *p1 = cria_pessoa("João", 25, 70.5);
    Pessoa *p2 = cria_pessoa("Maria", 20, 60.0);
    Pessoa *p3 = cria_pessoa("José", 30, 80.0);
    insere_pessoa(p1);
    insere_pessoa(p2);
    insere_pessoa(p3);
    printf("Antes da ordenação:\n");
    imprime_pessoas();
    quick_sort(inicio, NULL);
    printf("Depois da ordenação:\n");
    imprime_pessoas();
    libera_pessoas();
    return 0;
}

