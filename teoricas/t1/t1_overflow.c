#include <stdio.h>
#include <limits.h>

int main(void)
{
  /*
   * Armadilhas com unsigned:
   *
   * Tipos unsigned:
   *  - não representam valores negativos
   *  - quando fazem underflow (ex.: 0 - 1), "dão a volta" ao intervalo
   *
   * Isto é "bem definido" para unsigned em C: aritmética módulo 2^N.
   */

  unsigned int u = 0;

  printf("=== Unsigned: underflow ===\n");
  printf("u inicial = %u\n", u);

  u = u - 1;                    // underflow: 0 - 1 -> UINT_MAX
  printf("u = u - 1 -> %u (é UINT_MAX)\n", u);
  printf("UINT_MAX = %u (como %%d)\n", UINT_MAX);
  printf("UINT_MAX = %d (como %%u)\n", UINT_MAX);
  printf("u == UINT_MAX = %d\n", u == UINT_MAX);
  printf("!(u == UINT_MAX) = %d\n", !(u == UINT_MAX));
  printf("(u != UINT_MAX) = %d\n\n", (u != UINT_MAX));

  /*
   * Comparações "perigosas" com unsigned:
   * Exemplo clássico: escrever um ciclo a contar para baixo.
   */

  printf("=== Ciclo a contar para baixo com unsigned (armadilha) ===\n");

  /*
   * Este ciclo NÃO termina como se esperaria:
   * quando i chega a 0 e fazemos i--, ele passa para UINT_MAX.
   *
   * Por isso, aqui limitamos o número de iterações para não ficar infinito.
   */
  unsigned int i = 3;
  int passos = 0;

  while (i >= 0 && passos < 6) {        // "i >= 0" é sempre verdadeiro em unsigned!
    printf("i = %u\n", i);
    i--;                        // i = i - 1;
    passos++;                   // passos = passos + 1; // passos += 1
  }

  printf("Nota: em unsigned, (i >= 0) e' sempre verdadeiro.\n\n");

  /*
   * Forma segura de contar para baixo com unsigned:
   * usar a condição "i > 0" e tratar o 0 à parte, ou usar um do/while.
   */

  printf("=== Forma 'segura' de contar para baixo com unsigned ===\n");
  i = 3;

  while (i > 0) {
    printf("i = %u\n", i);
    i--;
  }
  printf("i = %u\n\n", i);      // imprime 0

  /*
   * Overflow observável
   *
   * Para unsigned, overflow é bem definido (módulo 2^N).
   * Para signed, overflow é comportamento indefinido (UB -- undefined behavior)
   * e deve ser evitado.
   *
   * Por isso, demonstramos overflow com unsigned.
   */

  printf("=== Overflow em unsigned ===\n");
  unsigned char uc = UCHAR_MAX;

  printf("unsigned char max = %u\n", (unsigned int) uc);

  uc = uc + 1;                  // overflow: 255 + 1 -> 0 (assumindo 8 bits)
  printf("depois de uc + 1 -> %u\n\n", (unsigned int) uc);

  /*
   * Nota:
   * Este exemplo assume que UCHAR_MAX corresponde ao "máximo" típico de 8 bits.
   * Mesmo se a plataforma for diferente, a ideia de "dar a volta" mantém-se.
   */

  return 0;
}
