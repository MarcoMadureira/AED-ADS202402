#include <stdio.h>
#include <stdlib.h>

struct No
{
    int ID;
    struct No *proximo;
    struct No *anterior;
};

// Listar os elementos da lista
void listar(struct No *ptLista)
{
    if (ptLista == NULL)
    {
        printf("\nLista Esta vazia!\n");
    }
    else
    {
        while (ptLista != NULL)
        {
            printf("\nNumero := %d", ptLista->ID);
            printf("\nLista := %p, ", ptLista);
            printf("Anterior := %p, ", ptLista->anterior);
            printf("ID := %d, ", ptLista->ID);
            printf("Proximo := %p\n", ptLista->proximo);
            ptLista = ptLista->proximo;
        }
    }
    return;
}

// Incluir um elemento na lista
void incluir(int dado, struct No **ptLista)
{
    struct No* ptNew = (struct No*)malloc(sizeof(struct No));
    ptNew->anterior = (*ptLista);
    ptNew->ID = dado;
    ptNew->proximo = NULL;
    // se a lista esta vazia
    if ((*ptLista) == NULL)
    {
        (*ptLista) = ptNew;
    }
    else
    {
        // Incluir elementos na lista
        struct No* ptTMP = (*ptLista);
        while (ptTMP->proximo != NULL)
        {
            ptNew->anterior = ptTMP;
            ptTMP = ptTMP->proximo;
        }
        ptTMP = ptNew;
    }

    return;
}

// void incluir(int dado, struct No **ptLista)
// {
//     struct No* ptNew = (struct No*)malloc(sizeof(struct No));
//     ptNew->ID = dado;
//     ptNew->proximo = NULL;

//     if ((*ptLista) == NULL)
//     {
//         ptNew->anterior = NULL;
//         (*ptLista) = ptNew;
//     }
//     else
//     {
//         struct No* ptTMP = *ptLista;
//         while (ptTMP->proximo != NULL)
//         {
//             ptTMP = ptTMP->proximo;
//         }
//         ptTMP->proximo = ptNew;
//         ptNew->anterior = ptTMP;
//     }
// }


int main()
{
    struct No *Lista=NULL;
    int num = 10;

    listar(Lista);

    incluir(num, &Lista);

    listar(Lista);

    incluir(20, &Lista);

    listar(Lista);

    incluir(30, &Lista);

    listar(Lista);
}