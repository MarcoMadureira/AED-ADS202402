#include <stdio.h> // funções padrão
#include <string.h>

// Função imprimir o numero binário
char *binario(int dividendo)
{
    char resultado[8];
    int divisor = 2,
        quociente = (dividendo / divisor),
        resto = (dividendo % divisor);
    resultado[0]=resto;

    for(int i=7; i>0; i--){
        resultado[i] = (char)resto;
    }

    return resultado;
    
}

//char vetor[10];

// código executável
void main()
{
    printf("\nImprimindo a tabela ASCII\n");

    // loop símbolos
    for (int i = 0; i <= 255; i++)
    {
        printf("\nDecimal: %d | Hexadecimal: %x | Octal: %o | Símbolo\t", i, i, i);
        printf("%s", binario(i));
    }

    printf("\n\n\a\a\a<<< FIM DO ARQUIVO >>>");
}
