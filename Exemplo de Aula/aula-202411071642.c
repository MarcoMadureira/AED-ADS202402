#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

// Estrutura para conter os dados do registro
typedef struct dados
{
    /* data */
    char *nome;
    int dtNasc;
    char *endereco;
    float salario;
} dados;

struct No
{
    /* data */
    dados Dado;
    struct No *next;
};

// Criar uma lista de dados
struct No *criarLista()
{
    return NULL;
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

// incluir um elemento no inicio da lista
void incluirNoFimLista(dados _dados_, struct No **lista)
{
    // Reservar a memoria e incluir os dados
    struct No *newNo = (struct No *)malloc(sizeof(struct No));
    if (newNo == NULL)
    {
        printf("\nErro de alocação de memória.\n");
        return;
    }
    else
    {
        newNo->Dado = _dados_;
        newNo->next = NULL;
    }

    // Lista está vazia, incluir o primeiro elemento
    if (*lista == NULL)
    {
        (*lista) = newNo;
    }
    else
    {
        struct No *tmpNo = *lista;
        while (tmpNo->next != NULL)
        {
            tmpNo = tmpNo->next;
        }
        tmpNo->next = newNo;
    }
    return;
}

// incluir um elemento na lista criada
void incluirNoInicioLista(dados _dados_, struct No **lista)
{
    struct No *newNoInicio = (struct No *)malloc(sizeof(struct No));
    if (newNoInicio == NULL)
    {
        printf("\nErro de alocação de memória.\n");
        return;
    }
    else
    {
        newNoInicio->Dado = _dados_;
        newNoInicio->next = NULL;
    }
    if (*lista == NULL)
        *lista = newNoInicio;
    else
    {
        newNoInicio->next = *lista;
        *lista = newNoInicio;
    }
    return;
}

void imprimirLista(struct No *lista)
{
    struct No *tmpNo = lista;
    if (tmpNo == NULL)
    {
        printf("\nLista está vazia!\n");
    }
    else
        while (tmpNo != NULL)
        {
            // printf("\nLista %p\n", &Atual);
            printf("----------------------------------------------");
            printf("Nome: %s \n", tmpNo->Dado.nome);
            printf("Endereço: %s\n", tmpNo->Dado.endereco);
            printf("DtNasc: %d\n", tmpNo->Dado.dtNasc);
            printf("Salario: %f\n", tmpNo->Dado.salario);
            printf("----------------------------------------------");
            tmpNo = tmpNo->next;
        }
    return;
}

// Função para remover um nó com um dado específico
void removeNo(dados _dados_, struct No **head)
{
    struct No *temp = *head;

    // Se o nó a ser removido é o nó cabeça
    // Procura pelo nó a ser removido, guardando o nó anterior
    while (temp != NULL && temp->Dado.nome != _dados_.nome)
    {
        *head = (*head)->next;
    }
    // Se o dado não está presente na lista
    if (*head == NULL)
    {
        printf("Nome não encontrado!");
    }
    else if ((*head)->Dado.nome == _dados_.nome)
    {
        temp = (*head);
        *head = (*head)->next; // Muda o ponteiro da cabeça
        free(temp);            // Libera a memória
    }
    return;
}

int main()
{
    struct No *lstD = criarLista();
    dados tmpDados;

    imprimirLista(lstD);

    tmpDados.dtNasc = 20241107;
    tmpDados.endereco = "rua das flores\0";
    tmpDados.nome = "Maria das Dores\0";
    tmpDados.salario = 23000.00;

    incluirNoFimLista(tmpDados, &lstD);
    imprimirLista(lstD);

    tmpDados.dtNasc = 20241109;
    tmpDados.endereco = "rua das borboletas\0";
    tmpDados.nome = "João das Flores\0";
    tmpDados.salario = 21000.00;

    incluirNoFimLista(tmpDados, &lstD);
    imprimirLista(lstD);

    tmpDados.dtNasc = 20241111;
    tmpDados.endereco = "rua dos canteiros\0";
    tmpDados.nome = "Ana Botafogo\0";
    tmpDados.salario = 25000.00;

    incluirNoFimLista(tmpDados, &lstD);
    imprimirLista(lstD);

    tmpDados.nome = "João das Flores\0";
    removeNo(tmpDados, &lstD);
    imprimirLista(lstD);

    liberarLista(lstD);
}
