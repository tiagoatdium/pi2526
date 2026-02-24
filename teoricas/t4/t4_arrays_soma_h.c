#include <stdio.h>
#include <stddef.h>

// função que imprime os elementos de um array
void print_array(int *a, size_t s)
{ while(s--)
  { printf("%d ",*a++); }
  putchar('\n');
}

// tamanho do array com tipo 'int':
// - tipo mais adequado 'size_t' (definido em stddef.h
//   mas também pode ser providenciado (indirectamente)
//   via stdio.h)
//
// - por simplicidade, e num contexto de introdução,
//   utilizou-se o tipo 'int'
//
int soma(int a[], int s)
{
  int i, t = 0;

  for(i=0; i<s; i++)
  { t += a[i]; }

  return t;
}

int main(void)
{
  int a[5] = {1,2,3,4,5};
  int r;

  r = soma(a, 5);

  print_array(a, 5);
  printf("soma: %d\n", r);

  return 0;
}

