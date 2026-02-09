#include <stdio.h>

int soma0(int a, int b)
{
  int n; // nota: este 'n' não é o 'n' da main
  n = a + b;
  return n;
}

int soma1(int a, int b)
{
  a += b; // nota: não altera o 'a' da main 
  return a;
}

int somaR(unsigned int a, unsigned int b)
{
  if(a == 0)
    return b;
  return 1 + somaR(a-1, b);
}

int main(void)
{
  int n, a, b;
  n = soma0(10,20);
  printf("n = soma0(10,20); => n=%d\n", n);
  
  //
  a = b = 1; // novidade
  n = soma1(a, b);
  printf("n = soma1(a, b); => n=%d, a=%d, b=%d\n",
         n, a, b);
  
  //
  a = 10; b = 5;
  n = somaR(a, b);
  printf("n = somaR(a, b); => n=%d, a=%d, b=%d\n",
         n, a, b);
  return 0;
}
