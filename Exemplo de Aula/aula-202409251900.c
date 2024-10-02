#include <stdio.h>
#include <string.h>

struct DATA 
{
    int dia, mes, ano;
};

struct AGENDA
{
    int codigo;
    char *nome;
    char *telefone;
    struct DATA dt_nasc;
};

int main()
{

    struct AGENDA agenda;

    agenda.codigo = 100;
    agenda.nome = "Marco";
    agenda.telefone = "(38)99131-1600";
    agenda.dt_nasc.ano = 1966;
    agenda.dt_nasc.mes = 10;
    agenda.dt_nasc.dia = 10;

    
    lerDados(&agenda);

    mostrarDados(&agenda);

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