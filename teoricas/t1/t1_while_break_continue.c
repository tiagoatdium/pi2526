#include <stdio.h>

int main(void)
{
  /*
   * Este programa mostra como funcionam:
   *   - break    -> termina imediatamente o ciclo
   *   - continue -> salta para a próxima iteração do ciclo
   */

  int i = 0;

  while (i < 10)                // O ciclo iria normalmente de 0 até 9
  {
    i++;                        // Actualização da variável de controlo

    /*
     * Exemplo de continue:
     * Se i for par, ignoramos o resto do corpo do ciclo
     * e passamos imediatamente para a próxima iteração.
     */
    if (i % 2 == 0) {
      continue;
    }

    /*
     * Exemplo de break:
     * Se i for maior que 7, terminamos o ciclo.
     */
    if (i > 7) {
      break;
    }

    printf("i = %d\n", i);
  }

  /*
   * O ciclo termina:
   *  - quando a condição while fica falsa, OU
   *  - quando encontramos um break
   */

  printf("Fim do ciclo.\n");

  return 0;
}
