#include <stdio.h>
#include <stdlib.h>

// exercício: estude e compreenda o código da função seguinte:
void print_array(int *a, size_t s)
{ while(s--)
  { printf("%2d ",*a++); }
  putchar('\n');
}

void init1_array(int *a, size_t s)
{
  size_t i;
  for(i=0; i<s; i++)
  { a[i] = (int) i; }
}

int main(void)
{
  int i;

  // ////////////////////////////////////////////
  // Declaração de um array 'a' com 5 elementos
  // do tipo inteiro. Inicialização com ciclo for.

  int a[5];
  for(i=0; i<5; i++)
  { a[i] = 5-i; }
  print_array(a, 5);

  // ////////////////////////////////////////////
  // Declaração de um array 'b' com 5 elementos
  // do tipo inteiro. Inicialição através de
  // chamada a uma função

  int b[5];
  init1_array(b, 5);
  print_array(b, 5);

  return 0;
}


