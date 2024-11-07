#include <stdio.h>
#include <string.h>

// Estrutura para conter os dados do registro
typedef struct
{
    /* data */
    char *nome;
    int dtNasc;
    char *endereco;
    float salario;
} dados;

// Nó que será um elemento da Lista
typedef struct 
{
    /* data */
    dados Dado;
    no * next;
} no;


// Criar uma lista de dados
no *criarLista(){
    return (no*)malloc(sizeof(no));
}

//incluir um elemento na lista criada
// void incluirElementoLista(dados _dados_, dados* lista){
//    if(lista==NULL) return;
//    else if(lista->next == NULL){
//     // insere o novo elemento
//    } else {
//     // procura o próximo elemento até o último
//     while(lista->next != NULL) lista++;
//    }
   

   

// }



int main(){
    no* lstD = criarLista(); // Lista simples
    
    printf("Lista %p", lstD);

}