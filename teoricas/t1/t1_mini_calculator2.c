#include <stdio.h>

int soma(int a, int b)
{
  int soma;
  soma = a + b;
  return soma;
}

int subtrai(int a, int b)
{
  int sub;
  sub = a - b;
  return sub;
}

int ler_inteiro(void)
{
  int a;
  printf("Introduza um numero inteiro: ");
  scanf("%d", &a);
  return a;
}

char ler_operacao(void)
{
  char op;
  printf("Introduza a operacao (+ ou -): ");
  scanf(" %c", &op);
  return op;
}

int calcula(int a, int b, char op)
{
  int r;

  if (op == '+') {
    r = soma(a, b);

  } else if (op == '-') {
    r = subtrai(a, b);

  } else {
    r = -1;                     // faz sentido??
  }

  return r;
}

int main(void)
{
  int a, b, r;
  char op;

  a = ler_inteiro();
  b = ler_inteiro();
  op = ler_operacao();
  r = calcula(a, b, op);
  printf("Resultado: %d\n", r);

  return 0;
}
