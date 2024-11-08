#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para conter os dados do registro
typedef struct dados
{
    /* data */
    char *nome;
    int dtNasc;
    char *endereco;
    float salario;
} dados;

// Nó que será um elemento da Lista
struct No
{
    /* data */
    dados Dado;
    struct No *next;
};

// Criar uma lista de dados
struct No *criarLista()
{
    struct No * lista = (struct No *)malloc(sizeof(struct No));
    lista->next = NULL;
    return lista;
}

// incluir um elemento na lista criada
void incluirElementoLista( dados _dados_, struct No *lista)
{
    struct No *ptTmp = (struct No *)malloc(sizeof(struct No));

    // Se a lista está vazia inclui o elemento
    if (lista->next == NULL)
    {
        lista = ptTmp;
        lista->Dado = _dados_;
        lista->next = NULL;
        return;
    }

    incluirElementoLista(_dados_, ptTmp);
    return;
}

int main()
{
    struct No *lstD = criarLista(); // Lista simples
    dados tmpDados;

    tmpDados.dtNasc = 20241107;
    tmpDados.endereco = "rua das flores";
    tmpDados.nome = "Maria das Dores";
    tmpDados.salario =23000.00;

    incluirElementoLista(tmpDados, lstD);

    printf("Ola");
    printf("Lista %p\n", lstD);
    //printf(" lista Proximo %p", (lstD==NULL? 0: lstD->next));

    //incluirElementoLista(tmpDados, lstD);

    printf("Lista %p, proximo %p \n", *lstD, lstD->next );

    incluirElementoLista(tmpDados, lstD);

    printf("Ola");
    printf("Lista %p\n", lstD);

    printf("Lista %p, proximo %p \n", *lstD, &lstD->next );

}