// Inclui o ficheiro de cabeçalho da biblioteca padrão de entrada/saída.

// Permite usar funções como printf, scanf, getchar, etc.

// onde encontrar o ficheiro stdio.h: 
// $ find /usr/ -name "stdio.h"
// /usr/include/stdio.h
//
// $ man stdio
// ...
// printf(3) formatted output conversion
// ... 
//
// $ man 3 printf
//
// consulta a entrada correspondente a printf na secção 3 do manual (Library functions (printf, fopen, …)
//
// para sair, prima 'q'
#include <stdio.h>


/*
Função principal do programa
 - função main é o ponto de entrada: a execução começa aqui.

 - 'int' indica que a função devolve um valor inteiro (ao sistema operativo)

 -'void' indica que a função não recebe argumentos (boa prática incluir void para ser explícito)
*/

int main(void)
{
  // Chama a função printf para escrever texto no ecrã.
  // "Hello, world!" é a string a imprimir.
  // '\n' é um carácter de nova linha.
  printf("Hello, world!\n");

  // Termina a função main e devolve 0 ao sistema operativo.
  // 0 significa que o programa terminou com sucesso.
  // um valor diferente de zero informa o SO que houve um erro.                   
  return 0;
}
