/*
Algoritmo arvore binária de busca em C 
Uma árvore binária de busca é uma árvore binária em que os elementos são organizados de forma que os elementos menores que a raiz são colocados à esquerda e os elementos maiores que a raiz são colocados à direita. Isso permite que a busca, inserção e remoção de elementos sejam feitas de forma eficiente. Neste exemplo, implementamos uma árvore binária de busca em C.
*/
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da árvore
typedef struct No {
    int chave;
    struct No *esq, *dir;
} No;

// Função para criar um novo nó
No *novoNo(int chave) {
    No *novo = (No *) malloc(sizeof(No));
    novo->chave = chave;
    novo->esq = novo->dir = NULL;
    return novo;
}

// Função para inserir um novo nó na árvore
No *insere(No *raiz, int chave) {
    // Se a árvore estiver vazia, retorna um novo nó
    if (raiz == NULL) return novoNo(chave);

    // Caso contrário, percorre a árvore para encontrar a posição correta
    if (chave < raiz->chave)
        raiz->esq = insere(raiz->esq, chave);
    else if (chave > raiz->chave)
        raiz->dir = insere(raiz->dir, chave);

    // Retorna a raiz inalterada
    return raiz;
}

// Função para percorrer a árvore em ordem
void emOrdem(No *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        emOrdem(raiz->dir);
    }
}

// Função principal
int main() {
    No *raiz = NULL;
    raiz = insere(raiz, 50);
    insere(raiz, 30);
    insere(raiz, 20);
    insere(raiz, 40);
    insere(raiz, 70);
    insere(raiz, 60);
    insere(raiz, 80);

    printf("Árvore em ordem: ");
    emOrdem(raiz);
    printf("\n");

    return 0;
}
