/*
Leitura e escrita de dados em arquivos é uma operação comum em muitos programas. 
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
    FILE *arq = fopen("pessoas.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    char nome[50];
    int idade;
    float peso;
    while (fscanf(arq, "%s %d %f", nome, &idade, &peso) == 3) {
        insere_pessoa(cria_pessoa(nome, idade, peso));
    }
    fclose(arq);
    imprime_pessoas();
    libera_pessoas();
    return 0;
}

