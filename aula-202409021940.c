/*
Descrição do código:
Autor:
Data do código:
Parametros:
*/
#include <stdio.h>   // Biblioteca para suporte de IO.
#include <stdbool.h> // Biblioteca para suporte de tipos booleanos.

// Função principal, onde o código é executado
void main()
{
    int A = 10,  // descrição da variável
        B = 'a', // coerção de tipos 'a' => 97
        soma = 0;
    char leta = "a",
         letb = "b";
    bool verdade = true, falso = false;

    printf("Expressões\n");
    printf("Expressão Literal => Impressa como escrita \n");
    printf("soma=A+B - soma=%d\n", soma = A + B);
    printf("Operadores e Operandos\n");
    printf("Operadores numéricos => + - * / div mod \n");
    printf("%d mod %d = %d\n", soma, 2, soma % 2);
    printf("Operadores Relacionais : > >= < <= != == \n");
    printf("%d >= %d = %d\n", A, B, A >= B);
    printf("Operadores Lógicos :  ou -> |  e -> &  \n");
    printf("Não(not) -> ! %d = %d = %d\n", verdade, !verdade, A <= B);
    printf("OU(or) ->  %d | %d = %d\n", verdade, verdade, verdade | verdade);
    printf("OU(or) ->  %d | %d = %d\n", verdade, falso, verdade | falso);
    printf("E(e) ->  %d & %d = %d\n", verdade, verdade, verdade & verdade);
    printf("E(e) ->  %d & %d = %d\n", falso, verdade, falso & verdade);
    // printf("%s + %s = %s\n", &leta, &letb, "ab");
}
