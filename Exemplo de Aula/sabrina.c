//Sabrina Santos Sousa
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;          
    struct Node* next;  
};


void incluirInicio(struct Node** head, int valor) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->data = valor;
    novoNo->next = *head;
    *head = novoNo;  
}


void incluirFim(struct Node** head, int valor) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->data = valor;
    novoNo->next = NULL;
    
    if (*head == NULL) {
        *head = novoNo;  
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;  
        }
        temp->next = novoNo;  
    }
}


void excluirInicio(struct Node** head) {
    if (*head == NULL) {
        printf("A lista já está vazia.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;  
    free(temp);  
}


void excluirFim(struct Node** head) {
    if (*head == NULL) {
        printf("A lista já está vazia.\n");
        return;
    }
    
    if ((*head)->next == NULL) {
        free(*head);  
        *head = NULL; 
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next && temp->next->next != NULL) {
        temp = temp->next;  
    }
    free(temp->next);  
    temp->next = NULL;  
}


void imprimirLista(struct Node* head) {
    if (head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;  
    
   
    incluirInicio(&head, 10); 
    incluirFim(&head, 20);     
    incluirFim(&head, 30);     
    imprimirLista(head);       
    
    excluirInicio(&head);      
    imprimirLista(head);     
    
    excluirFim(&head);        
    imprimirLista(head);       
    
    excluirFim(&head);         
    imprimirLista(head);       
    
    return 0;
}