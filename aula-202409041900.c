#include <stdio.h>

// assinatura de função
int lernum();

// função main
void main(){
    int variavel=0;
    int maior=-1;
    int num1 = lernum();
    int num2 = lernum();

    // printf("Digite um numero: ");
    // scanf("%d", &variavel);
    // printf("Minha variável é: %d \n\n", variavel);

    // Mostrar o maior numero
    maior = (num1 > num2 ? num1 : num2);
    printf("o numero %d é Maior\n", maior);

    //((maior%2)==0 ? printf("Este numero %d é par\n", maior) : printf("Este numero %d é impar\n", maior));
    printf("Este numero %d é %s\n", maior, ((maior%2)==0 ? "par":"impar"));
    if((maior%2)==0){
        printf("O numero %d é par\n", maior);
    }

}

// Função ler num
int lernum(){
    int var=0;
    printf("\ndigite um numero\t");
    scanf("%d", &var);
    return var;
}