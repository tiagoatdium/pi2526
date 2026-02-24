#include <stdio.h>
#include <stddef.h>
#include <string.h>

// função que imprime os elementos de um array
void print_array(int *a, size_t s)
{ while(s--)
  { printf("%d ",*a++); }
  putchar('\n');
}

void print_array_in_hex(int *a, size_t s)
{ while(s--)
  { printf("%08x ",*a++); }
  putchar('\n');
}


// inicializa 'a', com tamanho 's', com o valor
// correspondente ao seu índice (poderia ser outro
// valor...); repare no cast: (int) i;
// - porque é que é necessário?
void init_array(int *a, size_t s)
{
  size_t i;
  for(i=0; i<s; i++)
  { a[i] = (int) i; }
}

///////////////////////////////////////////////////////////

// o statement seguinte define a constante simbólica N com o valor 3:
// - o pré-processador substitui N por 3 em todo o
//   código antes da compilação
//
// - experimente: coloque o seguinte código (entre /* */ num ficheiro,
//   por exemplo, define.c):
/*
#define N 3
#define N2 (N*N)

int f(int a[N2])
{ return a[N2-1]; }
*/
// - corra o seguinte comando no terminal: gcc -E define.c
//   e observe o resultado. Se consultar o manual do gcc,
//   por exemplo, através do comando man gcc, deverá encontrar
//   a seguinte documentação (ou bastante semelhante dependendo
//   da versão do seu compilador) sobre a opção -E:
//   """-E  Stop after the preprocessing stage; do not run the
//      compiler proper. The output is in the form of preprocessed
//      source code, which is sent to the standard output"""
#define N 3

void soma1(int r[N], int a[N], int b[N])
{
  int i;
  for(i=0;i<N;i++)
  { r[i] = a[i] + b[i]; }
}

void soma2(int *r, int *a, int *b, size_t s)
{
  size_t i;
  for(i=0; i<s; i++)
  { r[i] = a[i] + b[i]; }
}


int main(void)
{
  int r[N] = {0}; // ver ficheiro t4_arrays_init0.c para entender o que {0} significa
  int a[N] = {0};
  int b[N] = {0};

  init_array(a, N);
  init_array(b, N);

  soma1(r,a,b);
  print_array(r, N);

  memset(r, 1, sizeof(r)); // man memset; estude o que esta função faz;
                           // comece por observar o resultado do seguinte print_array
  print_array(r, N);
  print_array_in_hex(r, N);

  soma2(r,a,b,N); // funciona para qq array de tamanho diferente de N
  print_array(r, N);

  return 0;
}
