#include <stdio.h>

int main(void)
{
  /*
   * Operadores de comparação (o resultado é verdadeiro (1) ou falso (0) ):
   *   <   menor que
   *   <=  menor ou igual a
   *   >   maior que
   *   >=  maior ou igual a
   *   ==  igual a
   *   !=  diferente de
   */

  /*
   * Operadores lógicos em C (em condições / if):
   *
   *   &&   AND  (e)
   *   ||   OR   (ou)
   *   !    NOT  (negação)
   *
   * Em C, o resultado de uma condição, conceptualmente, 
   * é "verdadeiro" ou "falso":
   *   - falso corresponde a 0
   *   - verdadeiro corresponde a 1
   */

  int nota_teste = 11;          // 0..20
  int nota_projeto = 14;        // 0..20
  int presencas_pct = 75;       // 0..100

  printf("Dados:\n");
  printf("  nota_teste    = %d\n", nota_teste);
  printf("  nota_projeto  = %d\n", nota_projeto);
  printf("  presencas_pct = %d\n\n", presencas_pct);

  printf("Exemplos de operadores logicos:\n");

  printf("(nota_teste >= 10) = %d\n", (nota_teste >= 10));

  printf("(nota_projeto >= 10) = %d\n", (nota_projeto >= 10));

  printf("(nota_teste >= 10 && nota_projeto >= 10) = %d\n",
         (nota_teste >= 10 && nota_projeto >= 10));

  printf("(nota_teste >= 10 || nota_projeto >= 10) = %d\n",
         (nota_teste >= 10 || nota_projeto >= 10));

  printf("(presencas_pct >= 80) = %d\n", (presencas_pct >= 80));

  printf("!(presencas_pct >= 80) = %d\n", !(presencas_pct >= 80));

  printf("!!(presencas_pct >= 80) = %d\n", !!(presencas_pct >= 80));

  /*
   * if ... else if ... else
   *
   * Exemplo:
   *
   * - Para aprovar:
   *     (nota_final >= 10) E (presenças >= 75)
   * - Mas há uma regra adicional:
   *     se nota_teste < 8, reprova automaticamente
   *
   * Isto mostra bem o "paradigma imperativo":
   * - calculamos valores
   * - tomamos decisões
   * - executamos blocos diferentes consoante as condições
   */

  double peso_teste = 0.60;
  double peso_projeto = 0.40;

  double nota_final = peso_teste * nota_teste +
      peso_projeto * nota_projeto;

  printf("Calculo:\n");
  printf("  nota_final = %.2f\n\n", nota_final);

  if (nota_teste < 8) {
    printf("Regra: nota_teste < 8 -> REPROVADO automaticamente.\n");
  } else if (nota_final >= 10 && presencas_pct >= 75) {
    printf("Aprovado: nota_final >= 10 E presencas_pct >= 75.\n");
  } else {
    printf("Reprovado: nao cumpre os criterios.\n");
  }

  /*
   * Nota importante:
   * C faz "short-circuit" em && e ||:
   * - em (A && B), se A for falso, B não é avaliado
   * - em (A || B), se A for verdadeiro, B não é avaliado
   *
   */
  return 0;
}
