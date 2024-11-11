#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do nó
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para adicionar um nó ao início da lista
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Função para remover um nó com um dado específico
void removeNode(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // Se o nó a ser removido é o nó cabeça
    if (temp != NULL && temp->data == data) {
        *head = temp->next; // Muda o ponteiro da cabeça
        free(temp); // Libera a memória
        return;
    }

    // Procura pelo nó a ser removido, guardando o nó anterior
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // Se o dado não está presente na lista
    if (temp == NULL) return;

    // Remove o nó da lista
    prev->next = temp->next;
    free(temp);
}

// Função para liberar a memória da lista
void freeNodes(struct Node *head)
{
    struct Node *atual = head;
    struct Node *proximo;

    while (atual != NULL)
    {
        proximo = atual->next;
        free(atual);
        atual = proximo;
    }

    head = NULL;
    printf("Memória liberada.\n");
}

// Função para imprimir a lista
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Função principal
int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 40);
    insertAtBeginning(&head, 50);
    insertAtBeginning(&head, 60);
    insertAtBeginning(&head, 70);
    insertAtBeginning(&head, 80);
    insertAtBeginning(&head, 90);

    printf("Lista após inserção:\n");
    printList(head);

    removeNode(&head, 20);

    printf("Lista após remoção de 20:\n");
    printList(head);

    freeNodes(head);

    return 0;
}
