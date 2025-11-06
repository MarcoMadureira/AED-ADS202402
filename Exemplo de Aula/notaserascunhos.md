´´´
#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó
struct Node {
    int data;            // Dado armazenado
    struct Node* next;   // Ponteiro para o próximo nó
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para imprimir a lista
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Função para adicionar um nó ao final da lista
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Função principal
int main() {
    struct Node* head = NULL;
    
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);

    printList(head);

    return 0;
}

// Função para adicionar um nó ao início da lista
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

´´´