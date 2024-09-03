# AED-ADS202402
 Algoritmos e Estrutura de Dados em C

## INTRODUÇÃO

Este repositório está relacionados as aulas de AED da turma ADS 2024 /02 do IFNMG - Campus Almenara. A primeira parte da disciplina será voltada para a compreensão da construção de algoritmos utilizando a linguagem C, no ambiente Linux Mint e editor VS Code.


## História e Origem
__Criador__: Dennis Ritchie
__Ano de Criação__: 1972
__Origem__: Desenvolvida nos laboratórios Bell Labs como uma evolução da linguagem B, que por sua vez derivava da linguagem BCPL.

## Características Principais
__Linguagem de Propósito Geral__: Utilizada para o desenvolvimento de sistemas operacionais, softwares de aplicação, e outras tarefas que requerem alta performance.
__Linguagem de Baixo Nível__: Embora seja considerada uma linguagem de alto nível, C fornece controle direto sobre a memória e recursos do sistema, semelhante a uma linguagem de montagem.
__Estruturada__: Suporta a decomposição de problemas em funções, facilitando a manutenção e a organização do código.
__Tipos Estáticos__: As variáveis têm que ser declaradas com um tipo específico, o que permite a verificação de tipos em tempo de compilação.
__Portabilidade__: Código em C pode ser compilado e executado em diferentes plataformas com poucas modificações.
__Bibliotecas Padrão__: Possui uma biblioteca padrão rica, mas relativamente simples, que fornece funções para manipulação de strings, operações matemáticas, entrada/saída, etc.

## Uso Típico
__Desenvolvimento de Sistemas Operacionais__: O Unix foi originalmente escrito em C.
__Programação de Sistemas Embarcados__: Devido ao controle sobre hardware.
__Desenvolvimento de Software__: Amplamente utilizada em softwares de desktop e servidores.
__Desvantagens__
__Gerenciamento Manual de Memória__: O programador é responsável pela alocação e liberação de memória, o que pode levar a erros como vazamento de memória.
__Ausência de Orientação a Objetos__: C não suporta nativamente programação orientada a objetos, o que pode dificultar a modelagem de problemas complexos.

## Características
1. __Baixo Nível de Abstração__: C oferece controle direto sobre o hardware, semelhante a uma linguagem de montagem, permitindo manipulação de memória e registros.
2. __Procedural__: C é uma linguagem procedural, o que significa que o código é organizado em funções e procedimentos.
3. __Portabilidade__: Código escrito em C pode ser compilado em diversas plataformas com poucas modificações.
4. __Tipos Estáticos__: As variáveis precisam ser declaradas com um tipo específico, com verificação de tipos em tempo de compilação.
5. __Biblioteca Padrão Simples__: A linguagem vem com uma biblioteca padrão que fornece funções básicas para manipulação de strings, I/O, e operações matemáticas.
6. __Gerenciamento Manual de Memória__: O programador é responsável por alocar e liberar memória manualmente, usando funções como `malloc()` e `free()`.

## Principais Bibliotecas
1. __`stdio.h` (Standard Input/Output Library)__ Fornece funções para entrada e saída padrão, como `printf()`, `scanf()`, `fopen()`, `fclose()`, `fread()`, `fwrite()`, entre outras.
2. __`stdlib.h` (Standard Library)__ Inclui funções para alocação de memória (`malloc()`, `free()`), controle de processos (`exit()`, `system()`), e operações de conversão de tipos (`atoi()`, `atof()`).
3. __`string.h`__ Contém funções para manipulação de strings, como `strlen()`, `strcpy()`, `strcat()`, `strcmp()`, `memset()`, `memcpy()`.
4. __`math.h`__ Fornece funções matemáticas básicas como `sin()`, `cos()`, `tan()`, `sqrt()`, `pow()`, `log()`.
5. __`time.h`__ Oferece funções para manipulação de tempo e data, como `time()`, `clock()`, `difftime()`, `strftime()`.
6. __`ctype.h`__ Inclui funções para manipulação de caracteres, como `toupper()`, `tolower()`, `isdigit()`, `isalpha()`.
7. __`errno.h`__ Define macros para o tratamento de erros, permitindo o uso de variáveis como `errno` para detectar e manipular erros durante a execução.
8. __`stdbool.h`__ A biblioteca stdbool.h em C é uma inclusão relativamente recente (introduzida no padrão C99) que oferece uma maneira padrão e mais legível de trabalhar com valores booleanos (verdadeiro ou falso). Antes do stdbool.h, os programadores em C geralmente usavam inteiros (int) para representar valores booleanos, onde 0 significava "falso" e qualquer outro valor significava "verdadeiro".
### Características Principais
__Tipo bool__: O stdbool.h define um novo tipo de dado, bool, que é essencialmente um alias para int. Isso permite que os programadores usem bool para declarar variáveis booleanas em vez de usar int.

__Constantes true e false__: A biblioteca também define as constantes true e false, que são equivalentes a 1 e 0, respectivamente. Isso facilita a leitura e compreensão do código.

__Compatibilidade__: O uso de stdbool.h não interfere na funcionalidade do código legado, onde inteiros eram usados para representar valores booleanos.