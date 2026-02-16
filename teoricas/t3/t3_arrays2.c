#include <stdio.h>
#include <stdlib.h> // srand
#include <time.h>

// questão: qual a melhor alternativa?
// - 'int s' ou 'size_t s'?

void init0(int *n, size_t s)
{
	for(size_t i=0; i<s; i++)
	{ n[i] = rand() % 100; }
}

void init1(int *n, size_t s)
{
	for(size_t i=0; i<s; i++)
	{ *(n + 1) = rand() % 100; } // n[i] <=> *(n + i)
}

void print(int *n, size_t s)
{
  for(size_t i=0; i<s; i++)
	{ printf("%d ", n[i]); }
  printf("\n");
}

int main(void)
{
	int n[5];
	
  srand(time(NULL));
  init0(n, 5);
  print(n, 5);
  
  // experimente remover o seguinte comentário para que a segunda
  // chamada a srand aconteça e observe o efeito que tem
  srand(time(NULL)); 
  init0(n, 5);
  print(n, 5);
  
  return 0;
}
