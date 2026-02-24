#include <stdio.h>
#include <stdlib.h>

// exercício: estude e compreenda o código da função seguinte:
void print_array(int *a, size_t s)
{ while(s--)
  { printf("%2d ",*a++); }
  putchar('\n');
}

int main(void)
{
  // declaração de um array de inteiros (int) s/ inicialização
  int a[5];

  // declaração de um array de inteiros (int) c/ inicialização
  int b[5] = {1,2,3,4,5};

  // declaração de um array de inteiros (int) c/ inicialização parcial:
  // - inicializam-se 3 elementos; qual o valor dos restantes? 0.
  int c[5] = {1,2,3}; // {}

  // declaração de um array de inteiros (int) c/ inicialização
  // de todos os elementos a zero:
  // - define-se o primeiro elemento como zero, o que obriga a que o resto
  //   da inicialização seja realizada (a zero).
  int d[5] = {0};

  // declaração de um array de inteiros s/ indicação explícita do seu tamanho:
  int e[] = {1,2,3,4,5};

  // declaração de um array com os valores {0, 0, 10, 0, 20}
  // - suportado apartir de C99; (NÃO suportado em ANSI C/C90)
  int f[5] = {[2] = 3, [4] = 5};

  print_array(a,5); // NOTA: imprimir um array não inicializado enquadra-se
                    // na categoria de UB (undefined behaviour)
  print_array(b,5);
  print_array(c,5);
  print_array(d,5);
  print_array(e,5);
  print_array(f,5);

  return 0;
}


