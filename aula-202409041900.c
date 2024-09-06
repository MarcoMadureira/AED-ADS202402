/*
   Descrição: exercicio de verificação de definição de tipos, entrada e saída de dados.
   - Estruturas de controle:
    -- scanf("%<formato>", &variável); //
    -- printf(" texto formatado", <lista de variáveis>)
   - Operadores:
    -- & operador de referência de memória
    -- ( <condição> ? <resultado para .true.> : <resultado para .false.>) operador ternário
   - Definição de funções internas
    -- assinatura da função
    -- código da função

*/

#include <stdio.h>

// função
int lernum();

void main()
{
    int variavel = 0;
    int A, B;

    // solicita um número
    printf("Digite um número: ");
    scanf("%d", &variavel);

    // Verifica se o numero é par ou impar
    if ((variavel % 2) == 0)
    {
        printf("O número %d é par!\n");
    }
    else
    {
        printf("O número %d é impar!\n");
    }

    // Solicita dois numeros
    A = lernum();
    B = lernum();

    // Escreve o maior deles
    printf("O número %d é o maior\n", ((A > B) ? A : B));
    printf("")
}

//
int lernum()
{
    int resultado = 0;
    printf("digite um numero: ");
    scanf("%d", &resultado);
    return resultado;
}