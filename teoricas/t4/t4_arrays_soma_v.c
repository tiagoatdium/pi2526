#include <stdio.h>
#include <stddef.h>

// função que imprime os elementos de um array
void print_array(int *a, size_t s)
{ while(s--)
  { printf("%d ",*a++); }
  putchar('\n');
}



void print_pointers(char *s, int *r, int *a, int *b)
{
  // necessário converter o apontador para void* (apontador genérico)
  // - correspondente ao, por exemplo, (void*)a
  printf("%s: r: %p\n", s, (void*)r);
  printf("%s: a: %p\n", s, (void*)a);
  printf("%s: b: %p\n", s, (void*)b);
}



// escreve 0's no array
void set0(int *r, size_t s)
{
  size_t i;
  for(i=0; i<s; i++)
  { r[i] = 0; }
}



// soma 'a' com 'b' (inteiros) e coloca o resultado em *r
// - o propósito desta função neste ficheiro é para comparar
//   com as funções soma_arrays*
void soma_variaveis(int *r, int a, int b)
{
  *r = a + b;
  // note que não tem return (tipo de retorno void)
}



// soma_arrays0 versão 0 c/ 'int var[]' e tipo de retorno void
void soma_arrays0(int r[], int a[], int b[], size_t s)
{
  // imprime apontadores
  print_pointers("soma_arrays0", r, a, b);

  size_t i;
  for(i=0; i<s; i++)
  { r[i] = a[i] + b[i]; }

  // note que não tem return (tipo de retorno void)
  // escreve "directamente" em 'r'
}



// soma_arrays1 versão 0 c/ 'int *var' (na prática igual à anterior) e tipo de retorno void
void soma_arrays1(int *r, int *a, int *b, size_t s)
{
  // imprime apontadores
  print_pointers("soma_arrays1", r, a, b);

  size_t i;
  for(i=0; i<s; i++)
  { r[i] = a[i] + b[i]; }
}

int main(void)
{
  int a[5] = {1,2,3,4,5};
  int b[5] = {10,20,30,40,50};
  int r[5] = {0};

  print_pointers("main", r, a, b);

  // //////////////////////////////////////////////////////
  // soma arrays 0
  soma_arrays0(r, a, b, 5);
  print_array(r, 5);

  // //////////////////////////////////////////////////////
  // soma arrays 1 (igual à anterior)
  printf("\n\n"); // duas linhas vazias para ser mais fácil distinguir o output
  set0(r, 5); // reinicializar r com zeros
  print_array(r, 5); // verificar que se encontra "a zero"

  soma_arrays1(r, a, b, 5);
  print_array(r, 5);

  return 0;
}

