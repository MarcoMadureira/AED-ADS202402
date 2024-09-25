#include <stdio.h>

int main()
{
    int *num1, *num2, *num3;
    int nvar1 = 10, nvar2 = 20;
    num1 = &nvar1;
    int letra[4] = {65, 66, 67, 68};
    int numero[4] = {1,2,3,4};
    num2 = &letra[0];
    num3 = &numero[0];



    // printf("\033[A");
    printf("\nNumero: %p", (void*)num1);
    printf("\nNum: %d \n", nvar1);

    for (int i = 0; i < 4; i++)
    {
        printf("\n Letra %c ", letra[i]);
        printf("\n %c", *num2);
        printf("\n Numero %d ", numero[i]);
        printf("\n %d", *num3);
        num2++;
        num3++;
    }
    printf("\n");
    return 0;

    // printf("digite um numero: ");
    // scanf("%d", &numero);
}