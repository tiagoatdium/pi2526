#include <stdio.h>

// print_array: imprime todos os elementos de um array
void print_array(int A[], int n)
{
  for (int i = 0; i < n; i++)
  { printf("%d ", A[i]);
  }
  printf("\n");
}

int search(int A[], int n, int x)
{
  int i;

  // percorrer o array da posição 0 até n-1
  for(i = 0; i < n; i++)
  {
    // verificar se encontrámos o elemento procurado
    if (A[i] == x)
    { // devolver o índice onde o elemento foi encontrado
      return i;
    }
  }

  // se chegarmos aqui, o elemento não existe no array
  return -1;
}

int main(void)
{
  int A[] = {4, 7, 2, 9, 5};
  int n = 5;
  int x, index; 

  // procurar x no array
  x = 9;
  index = search(A, n, x);

  // imprimir o array
  print_array(A, n);

  // verificar se o elemento foi encontrado
  if (index != -1)
  { printf("'%d' encontrado na posição: %d\n", x, index); }
  else
  { printf("Elemento não encontrado\n"); }

  return 0;
}
