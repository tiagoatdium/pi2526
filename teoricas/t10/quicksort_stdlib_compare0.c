#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Programa para comparar:
// - qsort da biblioteca standard
// - uma implementação própria de quicksort
// - bubble sort
//
// O vector tem 1 000 000 de elementos e é alocado dinamicamente.
//
// Para compilar:
// gcc -O2 -Wall -Wextra -o benchmark benchmark.c
//
// Para executar:
// ./benchmark

#define N 30000

// Troca dois elementos do vector
void swap(int v[], int i, int j)
{
  int temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

// Partição no estilo de Lomuto.
// Escolhemos o último elemento como pivot.
// No fim:
// - os elementos <= pivot ficam à esquerda
// - os elementos > pivot ficam à direita
// - a função devolve a posição final do pivot
int partition(int v[], int left, int right)
{
  int pivot;
  int i;
  int j;

  pivot = v[right];
  i = left;

  for(j = left; j < right; j++)
  {
    if(v[j] <= pivot)
    {
      swap(v, i, j);
      i++;
    }
  }

  swap(v, i, right);

  return i;
}

// Implementação recursiva de quicksort
void my_quicksort(int v[], int left, int right)
{
  int p;

  if(left >= right)
  {
    return;
  }

  p = partition(v, left, right);

  my_quicksort(v, left, p - 1);
  my_quicksort(v, p + 1, right);
}

// Função de comparação para qsort
int compare_ints(const void *a, const void *b)
{
  int x;
  int y;

  x = *(const int *) a;
  y = *(const int *) b;

  if(x < y)
  {
    return -1;
  }
  if(x > y)
  {
    return 1;
  }

  return 0;
}


// 

void bs_swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int bs_pass(int A[], int n)
{
  int swapped = 0;

  for (int i = 0; i < n - 1; i++)
  { if (A[i] > A[i + 1])
    { bs_swap(&(A[i]), &(A[i + 1]));
      swapped = 1;
    }
  }

  return swapped;
}

void bubble_sort(int A[], int n)
{
  int pass = 0;
  int swapped = 1;

  while (pass < n - 1 && swapped == 1)
  { swapped = bs_pass(A, n - pass);
    pass++;
  }
}

// Verifica se o vector está ordenado por ordem crescente
int is_sorted(int v[], int n)
{
  int i;

  for(i = 1; i < n; i++)
  {
    if(v[i - 1] > v[i])
    {
      return 0;
    }
  }

  return 1;
}

// Gera valores pseudo-aleatórios
void fill_random(int v[], int n)
{
  int i;

  for(i = 0; i < n; i++)
  {
    v[i] = rand();
  }
}

// Mede tempo em segundos entre dois instantes de clock()
double elapsed_seconds(clock_t start, clock_t end)
{
  return (double) (end - start) / (double) CLOCKS_PER_SEC;
}

int main(void)
{
  int *original;
  int *a1;
  int *a2;
  int *a3;
  clock_t start;
  clock_t end;
  double time_my_qs;
  double time_stdlib_qs;
  double time_my_bs;

  srand((unsigned int) time(NULL));

  // Alocamos 4 vectores:
  // - original: dados aleatórios
  // - a1: cópia para o quicksort próprio
  // - a2: cópia para o qsort da stdlib
  // - a3: cópia para o bubble sort
  original = (int *) malloc(sizeof(int) * N);
  a1 = (int *) malloc(sizeof(int) * N);
  a2 = (int *) malloc(sizeof(int) * N);
  a3 = (int *) malloc(sizeof(int) * N);

  if(original == NULL || a1 == NULL || a2 == NULL || a3 == NULL)
  {
    printf("Erro: falha na alocação de memória.\n");
    free(original);
    free(a1);
    free(a2);
    free(a3);
    return 1;
  }

  fill_random(original, N);

  // Fazemos duas cópias iguais para que os dois algoritmos
  // ordenem exactamente os mesmos dados.
  memcpy(a1, original, sizeof(int) * N);
  memcpy(a2, original, sizeof(int) * N);
  memcpy(a3, original, sizeof(int) * N);

  // Benchmark do quicksort próprio
  start = clock();
  my_quicksort(a1, 0, N - 1);
  end = clock();
  time_my_qs = elapsed_seconds(start, end);

  // Benchmark do qsort da stdlib
  start = clock();
  qsort(a2, N, sizeof(int), compare_ints);
  end = clock();
  time_stdlib_qs = elapsed_seconds(start, end);
  
  // Benchmark do bubble sort próprio
  start = clock();
  bubble_sort(a3, N);
  end = clock();
  time_my_bs = elapsed_seconds(start, end);
  

  printf("Número de elementos: %d\n", N);
  printf("\n");

  printf("my_quicksort: %.6f segundos\n", time_my_qs);
  printf("qsort       : %.6f segundos\n", time_stdlib_qs);
  printf("bubble sort : %.6f segundos\n", time_my_bs);
  printf("\n");

  printf("my_quicksort ordenou bem? %s\n", is_sorted(a1, N) ? "sim" : "não");
  printf("qsort ordenou bem?        %s\n", is_sorted(a2, N) ? "sim" : "não");
  printf("bubble sort ordenou bem?  %s\n", is_sorted(a3, N) ? "sim" : "não");

  free(original);
  free(a1);
  free(a2);
  free(a3);

  return 0;
}
