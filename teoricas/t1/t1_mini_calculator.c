#include <stdio.h>

int main(void)
{
  /*
   * Variaveis:
   *  - a e b guardam os numeros introduzidos pelo utilizador
   *  - op guarda a operacao escolhida (+ ou -)
   *  - resultado guarda o valor calculado
   */
  int a, b, resultado;
  char op;

  printf("Introduza o primeiro numero inteiro: ");
  scanf("%d", &a);

  printf("Introduza o segundo numero inteiro: ");
  scanf("%d", &b);

  /*
   * Ler a operacao
   * O espaco antes de %c faz o scanf ignorar espacos ou '\n'
   */
  printf("Introduza a operacao (+ ou -): ");
  scanf(" %c", &op);

  if (op == '+') {
    resultado = a + b;
    printf("Resultado: %d\n", resultado);

  } else if (op == '-') {
    resultado = a - b;
    printf("Resultado: %d\n", resultado);

  } else {
    printf("Operacao invalida: foi lido ++%c++\n", op);
  }

  return 0;
}
