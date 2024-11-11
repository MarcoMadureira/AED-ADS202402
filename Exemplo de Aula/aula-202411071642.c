#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

// Estrutura para conter os dados do registro
struct dados
{
    /* data */
    char *nome;
    int dtNasc;
    char *endereco;
    float salario;
};

struct No
{
    /* data */
    struct dados Dado;
    struct No* next;
};

// Criar uma lista de dados
struct No *criarLista()
{
    struct No *newNo = NULL;
    return newNo;
}

// Criar um elemento da lista
struct No *criarNo(struct dados _dados_)
{
    struct No *newNo = (struct No*)malloc(sizeof(struct No));
    if (newNo == NULL)
    {
        printf("\nErro de alocação de memória.\n");
        return NULL;
    }
    newNo->Dado = _dados_;
    newNo->next = NULL;
    return newNo;
}

// Função para liberar a memória da lista
void liberarLista(struct No *head)
{
    struct No *Atual = head;
    struct No *Proximo;

    while (Atual != NULL)
    {
        Proximo = Atual->next;
        free(Atual);
        Atual = Proximo;
    }

    head = NULL;
    printf("Memória liberada.\n");
}

// incluir um elemento na lista criada
void incluirElementoLista(struct dados _dados_, struct No **lista)
{
    struct No *Atual = *lista;
    struct No *Proximo;
    if(*lista == NULL) *lista = criarNo(_dados_) ;
    else if( *lista != NULL)
    {
        // próximo elemento
        while ((*lista)->next != NULL)
        {
            //Proximo = (*lista)->next;
            (*lista) = (*lista)->next;// Proximo;
        }   
        (*lista) = criarNo(_dados_);     
    }
    
    return;
}

void imprimirLista(struct No *lista)
{
     struct No *Atual = lista;
     struct No *next;

    if (Atual == NULL)
    {
        printf("\nLista está vazia!\n");
    }
    else
    {
        while (Atual->next != NULL)
        {
            //printf("\nLista %p\n", &Atual);
            printf("Nome: %s \n", Atual->Dado.nome);
            printf("Endereço: %s\n", Atual->Dado.endereco);
            printf("DtNasc: %d\n", Atual->Dado.dtNasc);
            printf("Salario: %f\n", Atual->Dado.salario);
            next = Atual->next;
            Atual = next;
        }
    }

    return;
}

int main()
{
    struct No *lstD = NULL; // Lista simples
    struct dados tmpDados;

    imprimirLista(lstD);

    tmpDados.dtNasc = 20241107;
    tmpDados.endereco = "rua das flores\0";
    tmpDados.nome = "Maria das Dores\0";
    tmpDados.salario = 23000.00;

    incluirElementoLista(tmpDados, &lstD);
    imprimirLista(lstD);

    tmpDados.dtNasc = 20241109;
    tmpDados.endereco = "rua das borboletas\0";
    tmpDados.nome = "João das Flores\0";
    tmpDados.salario = 21000.00;

    incluirElementoLista(tmpDados, &lstD);
    imprimirLista(lstD);

    tmpDados.dtNasc = 20241111;
    tmpDados.endereco = "rua dos canteiros\0";
    tmpDados.nome = "Ana Botafogo\0";
    tmpDados.salario = 25000.00;

    incluirElementoLista(tmpDados, &lstD);

    imprimirLista(lstD);

    liberarLista(lstD);
}
