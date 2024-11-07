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
typedef struct No
{
    /* data */
    dados Dado;
    dados * next;
} No;


// Criar uma lista de dados
No *criarLista(){
    return NULL;
}

//incluir um elemento na lista criada
void incluirElementoLista(dados _dados_, No* lista){
    No *ptTmp = (No*)malloc(sizeof(No));  

    // Se a lista está vazia inclui o elemento
    if(lista==NULL){
      lista  = ptTmp;
      lista->Dado = _dados_;
      lista->next = NULL;
      return;      
    }    
    else if(lista->next == NULL)
    {
     // insere o novo elemento
     ptTmp->Dado = _dados_;
     ptTmp->next = NULL;
     lista->next = ptTmp;
     return;
    } else {
        // procurar o ultimo elemento da lista antes de incluir
    }
   

   

// }



int main(){
    No* lstD = criarLista(); // Lista simples
    
    printf("Lista %p", lstD);
    printf(" lista Proximo %p", lstD->next);

}