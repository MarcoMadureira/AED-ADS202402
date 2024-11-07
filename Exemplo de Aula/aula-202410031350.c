#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Definimos um tamanho máximo para simplificar (ou podemos usar realloc para aumentar a lista)

typedef struct {
    int *dados;     // Ponteiro para armazenar os dados (lista dinâmica)
    int tamanho;    // Número de elementos na lista
    int capacidade; // Capacidade máxima atual da lista
} ListaTAD;

// Função para inicializar a lista
ListaTAD* criar_lista() {
    ListaTAD* lista = (ListaTAD*) malloc(sizeof(ListaTAD));
    lista->dados = (int*) malloc(MAX * sizeof(int));  // Alocando espaço inicial para a lista
    lista->tamanho = 0;
    lista->capacidade = MAX;
    return lista;
}

// Função para adicionar um elemento no final da lista
void adicionar(ListaTAD* lista, int elemento) {
    if (lista->tamanho >= lista->capacidade) {
        printf("Erro: lista cheia. Não é possível adicionar mais elementos.\n");
        return;
    }
    lista->dados[lista->tamanho] = elemento;
    lista->tamanho++;
}

// Função para remover o último elemento da lista
int remover(ListaTAD* lista) {
    if (lista->tamanho == 0) {
        printf("Erro: lista vazia. Não é possível remover elementos.\n");
        return -1;  // Retorna um valor de erro
    }
    int elemento_removido = lista->dados[lista->tamanho - 1];
    lista->tamanho--;
    return elemento_removido;
}

// Função para acessar um elemento por índice
int acessar(ListaTAD* lista, int indice) {
    if (indice < 0 || indice >= lista->tamanho) {
        printf("Erro: índice fora dos limites.\n");
        return -1;  // Retorna um valor de erro
    }
    return lista->dados[indice];
}

// Função para verificar se a lista está vazia
int esta_vazia(ListaTAD* lista) {
    return lista->tamanho == 0;
}

// Função para listar todos os elementos
void listar(ListaTAD* lista) {
    if (lista->tamanho == 0) {
        printf("A lista está vazia.\n");
    } else {
        printf("Elementos na lista: ");
        for (int i = 0; i < lista->tamanho; i++) {
            printf("%d ", lista->dados[i]);
        }
        printf("\n");
    }
}

// Função para liberar memória da lista
void liberar_lista(ListaTAD* lista) {
    free(lista->dados); // LIBERA DOS DADOS DA LISTA. APAGA O VETOR DE NUMEROS
    free(lista);        // LIBERA A LISTA.
}

int main() {
    // Criando uma instância do TAD Lista
    ListaTAD* minha_lista = criar_lista();

    // Adicionando elementos
    adicionar(minha_lista, 10);
    adicionar(minha_lista, 20);
    adicionar(minha_lista, 30);

    // Listando elementos
    listar(minha_lista);

    // Acessando o elemento do índice 1
    int valor = acessar(minha_lista, 1);
    if (valor != -1) {
        printf("Elemento no índice 1: %d\n", valor);
    }

    // Removendo o último elemento
    int removido = remover(minha_lista);
    if (removido != -1) {
        printf("Elemento removido: %d\n", removido);
    }

    // Verificando se a lista está vazia
    if (esta_vazia(minha_lista)) {
        printf("A lista está vazia.\n");
    } else {
        printf("A lista não está vazia.\n");
    }

    // Listando novamente os elementos após a remoção
    listar(minha_lista);

    // Liberar memória
    liberar_lista(minha_lista);

    return 0;
}
