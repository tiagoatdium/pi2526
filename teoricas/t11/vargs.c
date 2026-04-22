#include <stdio.h>
#include <stdarg.h> // novo header file para número de argumentos variáveis

// Argumentos variáveis (vargs):
//
// Em C, uma função pode receber um número variável de argumentos
// usando "..." na lista de parâmetros.
//
// Para percorrer esses argumentos, usamos as definições de
// <stdarg.h>. As principais são:
//
// - va_list
//   Tipo usado para guardar o estado da leitura dos argumentos variáveis
//
// - va_start(ap, ultimo)
//   Inicializa a variável "ap" para começar a ler os argumentos que vêm
//   depois do último parâmetro fixo da função
//
// - va_arg(ap, tipo)
//   Lê o próximo argumento, assumindo que ele tem o tipo indicado.
//   Neste exemplo, usamos int * porque cada argumento variável é um array
//   passado sob a forma de apontador para int.
//
// - va_end(ap)
//   Termina o uso dos argumentos variáveis.
//
// Atenção:
// - a função não sabe "sozinha" quantos argumentos extra recebeu;
//   por isso, normalmente passamos esse número num parâmetro fixo
//   (neste caso, "n_arrays").
// - também não há verificação automática de tipos nos argumentos
//   variáveis; se passarmos um tipo errado, o comportamento pode
//   ser incorrecto.

void print_array(int v[], int N)
{
  int i;
  printf("[");
  for(i = 0; i < N; i++)
  { printf("%d", v[i]);
    if(i + 1 < N)
    { printf(", "); }
  }
  printf("]\n");
}

// Soma vários arrays, elemento a elemento.
//
// Parâmetros:
// - r: array resultado
// - N: número de posições de cada array
// - n_arrays: quantos arrays vão ser somados
// - ...: os próprios arrays (cada um é int *)
//
// Exemplo de chamada:
// soma_arrays(r, 4, 3, a, b, c);
//
// Depois da chamada:
// r[i] = a[i] + b[i] + c[i]
void soma_arrays(int r[], int N, int n_arrays, ...)
{
  int i, k;
  va_list ap;

  // inicializar o resultado a 0
  for(i = 0; i < N; i++)
  { r[i] = 0; }

  // preparar leitura dos argumentos variáveis.
  va_start(ap, n_arrays);

  // ler os n_arrays apontadores para int e somar
  for(k = 0; k < n_arrays; k++)
  {
    int *v = va_arg(ap, int *);
    for(i = 0; i < N; i++)
    { r[i] += v[i]; }
  }

  // terminar a utilização de vargs
  va_end(ap);
}

int main(void)
{
  int a[] = {1, 2, 3, 4};
  int b[] = {10, 20, 30, 40};
  int c[] = {100, 200, 300, 400};
  int d[] = {-1, -2, -3, -4};

  int r1[4];
  int r2[4];

  printf("a  = ");
  print_array(a, 4);

  printf("b  = ");
  print_array(b, 4);

  printf("c  = ");
  print_array(c, 4);

  printf("d  = ");
  print_array(d, 4);

  printf("\n");

  soma_arrays(r1, 4, 2, a, b);
  printf("a + b       = ");
  print_array(r1, 4);

  soma_arrays(r2, 4, 4, a, b, c, d);
  printf("a + b + c + d = ");
  print_array(r2, 4);

  return 0;
}
