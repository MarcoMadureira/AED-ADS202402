#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main()
{
    // char *ch = "(-|-)-"; // Caractere a ser deslocado
    char *ch = "-\\|/."; // Caractere a ser deslocado
    int pos =0;

    // loop de impressão do caracter
    for (int i = 0; i < 80; i++)
    { // 80 é a largura típica do console
        // limpar tela terminal
        printf("\033[H\033[J");
        
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        printf("%c", ch[pos=(pos>=4?0:++pos)]);
        
        (i<79?printf("\n"): printf("\b\b-#\n\n"));


        usleep(100000);
    }
    //printf("\033[F");   // sobe uma linha da tela do terminal
    //printf("\b\b-#\n\n");

    return 0;
}
