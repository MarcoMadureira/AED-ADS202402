#include <stdio.h>

struct endereco_aluno
{
    char logradouro[50];
    char numero[5];
    char bairro[30];
    char cep[8];
    char uf[2];
};


struct ficha_de_aluno
{
    char nome[50];        // nome do aluno
    char disciplina[30]; // nome da disciplina
    struct endereco_aluno endereco; // endereço do aluno
    float nota_prova1;   // nota da prova 1
    float nota_prova2;   // nota da prova 2
};

int main()
{
    struct ficha_de_aluno aluno1;
    struct endereco_aluno endereco;

    // Inicializando os membros da estrutura
    strcpy(aluno1.nome, "João");
    strcpy(aluno1.disciplina, "Matemática");
    strcpy(aluno1.endereco.logradouro, "Rua das Perdidas");
    aluno1.nota_prova1 = 8.5;
    aluno1.nota_prova2 = 9.0;

    // Acessando e imprimindo os membros da estrutura
    printf("Nome: %s\n", aluno1.nome);
    printf("Disciplina: %s\n", aluno1.disciplina);
    printf("Disciplina: %s\n", aluno1.endereco.logradouro);
    printf("Nota Prova 1: %.2f\n", aluno1.nota_prova1);
    printf("Nota Prova 2: %.2f\n\n", aluno1.nota_prova2);

    return 0;
}