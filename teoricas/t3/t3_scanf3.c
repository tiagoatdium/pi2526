// TODO: testar inserindo "123abc" num dos inteiros pedidos ao utilizador

#include <stdio.h>  // printf // scanf
#include <stdlib.h> // exit e EXIT_FAILURE (também existe EXIT_SUCCESS)

void limpar_input_buffer(void)
{
	int c, n = 0;
  while( (c = getchar()) != '\n' && c != EOF)
  { putchar(c); n++; }
  if(n)
  { printf("--\n"); }
}

void ler_int(const char message[], int *ap)
{
	int r;
	printf("%s", message);
	r = scanf("%d", ap);

  if(r != 1)
  { printf("[erro] ler_int: %d\n", r);
  	exit(EXIT_FAILURE);
  }
  
  limpar_input_buffer();
}

int main(void)
{
	int a, b, c;

	ler_int("insira inteiro 1: ", &a);
	ler_int("insira inteiro 2: ", &b);
	ler_int("insira inteiro 3: ", &c);

  printf("a=%d b=%d c=%d\n", a, b, c);

  return 0;
}
