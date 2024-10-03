**Código comentado**
Este código é responsável pelo cadastro de até 100 dados de uma pessoa com o seguinte formato:
- id
- nome
- endereço
- sexo
- data de nascimento

Este código utiliza a função main para chamar as opções de CRUD para esses dados.

```
#include <stdio.h>     // Biblioteca de I/O de dados
#include <stdlib.h>    // Biblioteca de apoio
#include <string.h>    // Biblioteca de tratamento de Strings

#define MAX 100 // Número máximo de registros

// Estrutura para armazenar os dados do registro
typedef struct {
    int id;
    char nome[50];
    char dataNascimento[11];
    char sexo[10];
    char endereco[100];
} Registro;

// Variáveis globais
Registro registros[MAX];
int contador = 0;

// Função para criar um novo registro
void criarRegistro() {
    if (contador < MAX) {
        printf("Digite o ID: ");
        scanf("%d", &registros[contador].id);
        getchar(); // Limpar buffer

        printf("Digite o nome: ");
        fgets(registros[contador].nome, 50, stdin);
        registros[contador].nome[strcspn(registros[contador].nome, "\n")] = '\0'; // Remove o \n

        printf("Digite a data de nascimento (dd/mm/aaaa): ");
        fgets(registros[contador].dataNascimento, 11, stdin);
        registros[contador].dataNascimento[strcspn(registros[contador].dataNascimento, "\n")] = '\0';

        printf("Digite o sexo: ");
        fgets(registros[contador].sexo, 10, stdin);
        registros[contador].sexo[strcspn(registros[contador].sexo, "\n")] = '\0';

        printf("Digite o endereco: ");
        fgets(registros[contador].endereco, 100, stdin);
        registros[contador].endereco[strcspn(registros[contador].endereco, "\n")] = '\0';

        contador++;
        printf("\nRegistro criado com sucesso!\n");
    } else {
        printf("\nLimite de registros atingido!\n");
    }
}

// Função para ler (listar) todos os registros
void listarRegistros() {
    if (contador == 0) {
        printf("\nNenhum registro encontrado.\n");
    } else {
        for (int i = 0; i < contador; i++) {
            printf("\nID: %d\n", registros[i].id);
            printf("Nome: %s\n", registros[i].nome);
            printf("Data de Nascimento: %s\n", registros[i].dataNascimento);
            printf("Sexo: %s\n", registros[i].sexo);
            printf("Endereco: %s\n", registros[i].endereco);
        }
    }
}

// Função para atualizar um registro pelo ID
void atualizarRegistro() {
    int id, encontrado = -1;
    printf("Digite o ID do registro a ser atualizado: ");
    scanf("%d", &id);
    getchar(); // Limpar buffer

    for (int i = 0; i < contador; i++) {
        if (registros[i].id == id) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) {
        printf("Digite o novo nome: ");
        fgets(registros[encontrado].nome, 50, stdin);
        registros[encontrado].nome[strcspn(registros[encontrado].nome, "\n")] = '\0';

        printf("Digite a nova data de nascimento (dd/mm/aaaa): ");
        fgets(registros[encontrado].dataNascimento, 11, stdin);
        registros[encontrado].dataNascimento[strcspn(registros[encontrado].dataNascimento, "\n")] = '\0';

        printf("Digite o novo sexo: ");
        fgets(registros[encontrado].sexo, 10, stdin);
        registros[encontrado].sexo[strcspn(registros[encontrado].sexo, "\n")] = '\0';

        printf("Digite o novo endereco: ");
        fgets(registros[encontrado].endereco, 100, stdin);
        registros[encontrado].endereco[strcspn(registros[encontrado].endereco, "\n")] = '\0';

        printf("\nRegistro atualizado com sucesso!\n");
    } else {
        printf("\nRegistro não encontrado.\n");
    }
}

// Função para excluir um registro pelo ID
void excluirRegistro() {
    int id, encontrado = -1;
    printf("Digite o ID do registro a ser excluído: ");
    scanf("%d", &id);

    for (int i = 0; i < contador; i++) {
        if (registros[i].id == id) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) {
        for (int i = encontrado; i < contador - 1; i++) {
            registros[i] = registros[i + 1]; // Sobrescreve o registro
        }
        contador--;
        printf("\nRegistro excluído com sucesso!\n");
    } else {
        printf("\nRegistro não encontrado.\n");
    }
}

// Função principal - Menu do programa
int main() {
    int opcao;
    do {
        printf("\n*** MENU ***\n");
        printf("1. Criar registro\n");
        printf("2. Listar registros\n");
        printf("3. Atualizar registro\n");
        printf("4. Excluir registro\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar buffer

        switch (opcao) {
            case 1:
                criarRegistro();
                break;
            case 2:
                listarRegistros();
                break;
            case 3:
                atualizarRegistro();
                break;
            case 4:
                excluirRegistro();
                break;
            case 5:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 5);

    return 0;
}

```