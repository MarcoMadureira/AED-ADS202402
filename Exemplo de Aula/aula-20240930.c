#include <stdio.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} DATA;

typedef struct 
{
    int codigo;
    char *nome;
    char *endereco;
    DATA dtnasc;
} AGENDA;

int main()
{
    AGENDA agenda[3];

    agenda[0].codigo = 100;
    agenda[0].nome = "Marco Aurelio";
    agenda[0].endereco = "R. Cinco, 23 - Centro";
    agenda[0].dtnasc.dia = 10;
    agenda[0].dtnasc.mes = 10;
    agenda[0].dtnasc.ano = 1966;

    agenda[1].codigo = 101;
    agenda[1].nome = "Maria Aurelia";
    agenda[1].endereco = "R. Cinco, 24 - Centro";
    agenda[1].dtnasc.dia = 11;
    agenda[1].dtnasc.mes = 10;
    agenda[1].dtnasc.ano = 1966;

    agenda[2].codigo = 102;
    agenda[2].nome = "Mario Aurelio";
    agenda[2].endereco = "R. Cinco, 25 - Centro";
    agenda[2].dtnasc.dia = 12;
    agenda[2].dtnasc.mes = 10;
    agenda[2].dtnasc.ano = 1966;

    for (int i = 0; i < 3; i++)
    {
        printf("%d\t", agenda[i].codigo);
        printf("%s\t", agenda[i].nome);
        printf("%s\t", agenda[i].endereco);
        printf("%d\\\t", agenda[i].dtnasc.dia);
        printf("%d\\\t", agenda[i].dtnasc.mes);
        printf("%d\n", agenda[i].dtnasc.ano);
    }

    FILE *ptrFile = fopen("agenda.txt", "w");

    if (ptrFile == NULL)
    {
        printf("Erro de Acesso ao Arquivo");
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            fprintf(ptrFile, "%d\t", agenda[i].codigo);
            fprintf(ptrFile, "%s\t", agenda[i].nome);
            fprintf(ptrFile, "%s\t", agenda[i].endereco);
            fprintf(ptrFile, "%d\\", agenda[i].dtnasc.dia);
            fprintf(ptrFile, "%d\\", agenda[i].dtnasc.mes);
            fprintf(ptrFile, "%d\n", agenda[i].dtnasc.ano);
        }
        fclose(ptrFile);
    }
    

    printf("final");
    return 0;
}
