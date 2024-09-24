/*
Algoritmo de Ordenação é um algoritmo que organiza os elementos de uma lista de acordo com um critério de ordenação. 
Ordenção Merge Sort é um algoritmo de ordenação que divide a lista em duas metades, ordena cada metade e depois combina as duas metades ordenadas.
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

void merge(No *inicio, No *meio, No *fim) {
    No *p = inicio;
    No *q = meio->prox;
    No *aux = NULL;
    No *inicio2 = NULL;
    No *fim2 = NULL;
    No *novo = NULL;
    while (p != meio->prox && q != fim->prox) {
        if (p->pessoa->idade < q->pessoa->idade) {
            novo = (No *) malloc(sizeof(No));
            if (novo == NULL) {
                printf("Erro ao alocar memória\n");
                exit(1);
            }
            novo->pessoa = p->pessoa;
            novo->prox = NULL;
            if (inicio2 == NULL) {
                inicio2 = novo;
            } else {
                fim2->prox = novo;
            }
            fim2 = novo;
            p = p->prox;
        } else {
            novo = (No *) malloc(sizeof(No));
            if (novo == NULL) {
                printf("Erro ao alocar memória\n");
                exit(1);
            }
            novo->pessoa = q->pessoa;
            novo->prox = NULL;
            if (inicio2 == NULL) {
                inicio2 = novo;
            } else {
                fim2->prox = novo;
            }
            fim2 = novo;
            q = q->prox;
        }
    }
    while (p != meio->prox) {
        novo = (No *) malloc(sizeof(No));
        if (novo == NULL) {
            printf("Erro ao alocar memória\n");
            exit(1);
        }
        novo->pessoa = p->pessoa;
        novo->prox = NULL;
        if (inicio2 == NULL) {
            inicio2 = novo;
        } else {
            fim2->prox = novo;
        }
        fim2 = novo;
        p = p->prox;
    }
    while (q != fim->prox) {
        novo = (No *) malloc(sizeof(No));
        if (novo == NULL) {
            printf("Erro ao alocar memória\n");
            exit(1);
        }
        novo->pessoa = q->pessoa;
        novo->prox = NULL;
        if (inicio2 == NULL) {
            inicio2 = novo;
        } else {    
            fim2->prox = novo;
        }
        fim2 = novo;
        q = q->prox;
    }

    p = inicio;

    while (inicio2 != NULL) {
        p->pessoa = inicio2->pessoa;
        aux = inicio2;
        inicio2 = inicio2->prox;
        free(aux);
        p = p->prox;
    }

    free(fim2);
}

void merge_sort(No *inicio, No *fim) {
    if (inicio == fim) {
        return;
    }
    No *meio = inicio;
    No *fim1 = inicio;
    while (fim1 != fim && fim1->prox != fim) {
        meio = meio->prox;
        fim1 = fim1->prox->prox;
    }
    merge_sort(inicio, meio);
    merge_sort(meio->prox, fim);
    merge(inicio, meio, fim);
}

int main() {
    Pessoa *p1 = cria_pessoa("João", 25, 70.5);
    insere_pessoa(p1);
    Pessoa *p2 = cria_pessoa("Maria", 30, 60.0);
    insere_pessoa(p2);
    Pessoa *p3 = cria_pessoa("José", 20, 80.0);
    insere_pessoa(p3);
    Pessoa *p4 = cria_pessoa("Ana", 35, 55.5);
    insere_pessoa(p4);
    Pessoa *p5 = cria_pessoa("Carlos", 40, 90.0);
    insere_pessoa(p5);
    imprime_pessoas();
    merge_sort(inicio, NULL);
    printf("\n");
    imprime_pessoas();
    libera_pessoas();
    return 0;
}
