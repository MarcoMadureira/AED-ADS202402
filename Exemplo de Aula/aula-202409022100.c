/*
    Descrição: Entrada e Saída simples de dados
    Autor: Marco Aurélio
    Data:
    Parâmetros:
*/
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int idade = 0;
    char* nome = "";

    printf("Digite seu nome: ");
    scanf("%s \n", &nome);
    printf("Digite sua idade: ");
    scanf("%d \n", &idade);
}
