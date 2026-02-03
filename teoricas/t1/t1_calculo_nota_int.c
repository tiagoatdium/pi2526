#include <stdio.h>

/*
 * Operadores disponíveis para valores inteiros:
 *
 * Operadores aritméticos:
 *   +   soma
 *   -   subtracção
 *   *   multiplicação
 *   /   divisão inteira (a parte decimal é descartada)
 *   %   resto da divisão inteira (módulo)
 *
 * Operadores de comparação (o resultado é verdadeiro ou falso):
 *   <   menor que
 *   <=  menor ou igual a
 *   >   maior que
 *   >=  maior ou igual a
 *   ==  igual a
 *   !=  diferente de
 *
 * Operadores de atribuição (e actualização):
 *   =    atribuição
 *   +=   soma e atribuição
 *   -=   subtracção e atribuição
 *   *=   multiplicação e atribuição
 *   /=   divisão e atribuição
 *   %=   resto e atribuição
 *
 * Nota:
 *  - A divisão entre inteiros perde a parte decimal.
 *  - O operador % só existe para tipos inteiros.
 */

int main(void)
{
  /*
   * Este programa faz o mesmo cálculo, mas usando apenas inteiros.
   *
   * Truque: trabalhar com valores multiplicados por 100
   * para preservar duas casas decimais.
   */

  /*
   * Notas em escala 0..20, mas multiplicadas por 100.
   * Ex.: 14.5  -> 1450
   */
  int projeto = 1450;
  int teste = 1100;
  int participacao = 1800;

  /*
   * Pesos em percentagem inteira.
   * 40% -> 40
   */
  int peso_projeto = 40;
  int peso_teste = 50;
  int peso_participacao = 10;

  /*
   * Cálculo da nota final.
   *
   * Atenção à ordem:
   * - primeiro multiplicamos
   * - só no fim dividimos
   *
   */
  int nota_final_escalada =
      peso_projeto * projeto
      + peso_teste * teste + peso_participacao * participacao;

  /*
   * Até aqui:
   * - projeto está em x100
   * - pesos estão em percentagem
   *
   * Logo o resultado está em x100 * 100.
   * Dividimos por 100 para voltar a x100.
   */
  nota_final_escalada = nota_final_escalada / 100;

  /*
   * Converter para impressão:
   * - parte inteira
   * - parte decimal
   */
  int nota_inteira = nota_final_escalada / 100;
  int nota_decimal = nota_final_escalada % 100;

  printf("=== Calculo com inteiros (escala x100) ===\n");
  printf("Nota final: %d.%02d\n", nota_inteira, nota_decimal);

  /*
   * Decisão: comparar com 9.5 -> 950 em escala x100
   */
  if (nota_final_escalada >= 950) {
    printf("Resultado: APROVADO\n");
  } else {
    printf("Resultado: REPROVADO\n");
  }

  return 0;
}
