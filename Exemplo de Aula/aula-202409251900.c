#include <stdio.h>

struct AGENDA
{
    int codigo;
    char *nome;
    char *telefone;
    char *dt_nasc;
};

int main()
{

    struct AGENDA agenda;

    agenda.codigo = 100;
    agenda.nome = "Marco";
    agenda.telefone = "(38)99131-1600";
    agenda.dt_nasc = "10/10/1966";

    printf("%d\t", agenda.codigo);
    printf("%s\t", agenda.nome);
    printf("%s\t", agenda.telefone);
    printf("%s\n", agenda.dt_nasc);

    lerDados(&agenda);


    mostrarDados(&agenda);


    // FILE *ptrFile = fopen("agenda.txt");

    // if (ptrFile == NULL)
    // {
    //     fprintf(ptrFile, agenda.codigo);
    //     fprintf(ptrFile, agenda.nome);
    //     fprintf(ptrFile, agenda.telefone);
    //     fprintf(ptrFile, agenda.dt_nasc);
    // }
    // else
    // {
    //     printf("Erro de Acesso ao Arquivo");
    // }

    return 0;
};


// leitura de dados
void lerDados(struct AGENDA *agenda){

    printf("Digite o nome: ");
    scanf("%s", &agenda->nome);
    printf("Digite seu telefone: ");
    scanf("%s", &agenda->telefone);
    printf("Digite sua data de nascimento: ");
    scanf("%s", &agenda->dt_nasc);
    
}

// Mostrar dados
void mostrarDados(struct AGENDA *agenda){

    printf("Codigo: %d", agenda->codigo);
    printf("Nome: %s", agenda->nome);
    printf("Telefone: %s", agenda->telefone);
    printf("Data de nascimento: %s\n", agenda->dt_nasc);
    
}