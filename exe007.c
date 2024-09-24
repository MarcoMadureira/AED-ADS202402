/*
Algoritmo de Ordenação é um algoritmo que organiza os elementos de uma lista de acordo com um critério de ordenação. 
Ordenação Bubble Sort é um algoritmo de ordenação que percorre a lista várias vezes, comparando elementos adjacentes e trocando-os de posição se estiverem na ordem errada.
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

void bubble_sort() {
    No *p = inicio;
    while (p != NULL) {
        No *q = p->prox;
        while (q != NULL) {
            if (strcmp(p->pessoa->nome, q->pessoa->nome) > 0) {
                Pessoa *aux = p->pessoa;
                p->pessoa = q->pessoa;
                q->pessoa = aux;
            }
            q = q->prox;
        }
        p = p->prox;
    }
}

int main() {
    insere_pessoa(cria_pessoa("Maria", 25, 60.0));
    insere_pessoa(cria_pessoa("João", 30, 70.0));
    insere_pessoa(cria_pessoa("Ana", 20, 50.0));
    insere_pessoa(cria_pessoa("Pedro", 35, 80.0));
    insere_pessoa(cria_pessoa("Carla", 22, 55.0));
    insere_pessoa(cria_pessoa("José", 28, 65.0));
    insere_pessoa(cria_pessoa("Mariana", 33, 75.0));
    insere_pessoa(cria_pessoa("Carlos", 24, 58.0));
    insere_pessoa(cria_pessoa("Paula", 29, 68.0));
    insere_pessoa(cria_pessoa("Ricardo", 32, 78.0));
    imprime_pessoas();
    bubble_sort();
    printf("\n");
    imprime_pessoas();
    libera_pessoas();
    return 0;
}
