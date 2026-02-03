#include <stdio.h>

int main(void)
{
  /*
   * Um ciclo while executa um bloco de código repetidamente
   * enquanto uma condição for verdadeira.
   *
   * A condição é avaliada ANTES de cada iteração.
   */

  int i = 0;                    // Inicialização da variável de controlo do ciclo

  while (i < 5) {               // Condição: enquanto i for menor que 5
    printf("i = %d\n", i);      // Corpo do ciclo: instrução executada repetidamente
    i = i + 1;                  // Actualização: altera o estado para evitar ciclo infinito
  }

  /*
   * Quando i atinge o valor 5:
   *  - a condição (i < 5) torna-se falsa
   *  - o corpo do ciclo deixa de ser executado
   */

  return 0;
}
