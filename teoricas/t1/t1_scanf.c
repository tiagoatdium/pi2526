#include <stdio.h>

int main(void)
{
  int a, b, soma;

  printf("Introduza o primeiro numero inteiro: ");

  if (scanf("%d", &a) != 1) {
    return 0;
  }

  scanf("%d", &a);              // Lê um inteiro e guarda em 'a';
  // O '&' que precede 'a' será explorado
  // com mais detalhe nas aulas seguintes

  printf("Introduza o segundo numero inteiro: ");
  scanf("%d", &b);              // Lê um inteiro e guarda em 'b'

  soma = a + b;

  printf("A soma de %d e %d é igual a %d\n", a, b, soma);

  return 0;
}
