#include <stdio.h>

void main(){
    //Estrutura sequencial
    int num=10;
    float numv=10.10;
    char letra='S';


    printf("Ola mundo! \n");

    printf("%d \n",num);
    printf("%f \n",numv);
    printf("%c \n",letra);

    printf("Digite um numero:");
    scanf("%d", &num);

    //Estrutura Seletiva Simples
    if((num%2)==0){
       printf("\nO numero e %d ",num);
    }

    //Estrutura Seletiva composta
    if((num%2)==0){
       printf(" este %d numero é par. \n", num);
    } else {
       printf(" este %d numero é impar. \n", num);
    }

    //Estrutura Seletiva Encadeada
    if(letra=='A'){
        printf("%c", letra);
    } else if (letra=='B'){
        printf("%c", letra);
    } else if(letra=='C'){
        printf("%c", letra);
    }else printf("Uma letra");
    
    switch (letra)
    {
    case 'A':
    case 'a':{
        printf("Letra Aa");
        break;}
    case 'B':
    case 'b':{
        printf("Letra Bb");
        break;}

    case 'C':
    case 'c':{
        printf("Letra Cc");
        break;
    }
    default:
    printf(" %c", letra);
        break;
    }


    // Estrutura Repetitiva
    do{
        printf("digite uma letra: ");
        scanf("%c",&letra);
        printf("letra foi %c \n", letra);

    }while(letra!='S');
    
    while(letra!='S'){
    printf("digite uma letra: ");
    scanf("%c",&letra);
    printf("letra foi %c \n", letra);
    }



}

