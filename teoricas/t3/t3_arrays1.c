#include <stdio.h>
#include <stdlib.h> // srand
#include <time.h>

// questão: qual a melhor alternativa?
// - 'int s' ou 'size_t s'?

// note que int n[] <=> int *n (ver t3_arrays2.c)
void init(int n[], int s)
{
	for(int i=0; i<s; i++)
	{ n[i] = rand() % 100; }
}

void print(int n[], int s)
{
  for(int i=0; i<s; i++)
	{ printf("%d ", n[i]); }
  printf("\n");
}

int main(void)
{
	int n[5];
  srand(time(NULL));

  init(n, 5);
  print(n, 5);
  
  return 0;
}
