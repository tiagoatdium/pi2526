#include <stdio.h>

// troque por DEBUG 0 para diminuir o número de impressões no terminal
#define DEBUG 1

void print_array(int A[], int n)
{
  for (int i = 0; i < n; i++)
  { printf("%d ", A[i]);
  }
  printf("\n");
}

// intuição do algoritmo (selection sort):
//
// - o algoritmo divide o array em duas partes:
//   - uma parte já ordenada à esquerda
//   - uma parte ainda por ordenar à direita
//
// - em cada passagem procuramos o menor elemento
//   da parte ainda não ordenada
//
// - depois trocamos esse elemento com o primeiro
//   elemento dessa parte
//
// - assim, a parte ordenada cresce uma posição
//   em cada passagem
//
// - após i passagens, os primeiros i elementos
//   do array já estão nas posições finais

// notas:
// - static: limita a visibilidade da função ao ficheiro atual (permite mais otimizações por parte do compilador)
// - inline: sugere ao compilador substituir a chamada da função pelo seu código (mais eficiente; o compilador pode decidir não realizar o inline)

static inline int min_index(int A[], int left, int right)
{
  int i, min;

  // assumir que o mínimo está na primeira posição do intervalo
  min = left;

  // percorrer o subarray A[left .. right]
  for(i = left + 1; i <= right; i++)
  {
    if (A[i] < A[min])
    { min = i; }
  }

  // devolver o índice do menor elemento encontrado
  return min;
}

static inline void swap(int A[], int i, int j)
{
  int tmp;

  // trocar os elementos A[i] e A[j] (se i != j)
  if( i != j )
  { tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
  }
}

void selection_sort(int A[], int n)
{
  int i, min;

  for(i = 0; i < n - 1; i++)
  {
    #if DEBUG
      printf("    "); print_array(A, n);
    #endif

    // encontrar o índice do menor elemento em A[i .. n-1]
    min = min_index(A, i, n - 1);

    // trocar A[i] com o menor elemento encontrado (note que se i != min 
    swap(A, i, min);
  }

  #if DEBUG
    printf("    "); print_array(A, n);
  #endif
}

// /////////////////////////////////////////////
// test
void test_len1(void)
{
  int A[] = {5};
  int n = 1;

  printf("tlen%d:\n", n);
  selection_sort(A, n);
  putchar('\n');
}

void test_len2(void)
{
  int A[] = {5,1};
  int n = 2;

  printf("tlen%d:\n", n);
  selection_sort(A, n);
  putchar('\n');
}

void test_len3(void)
{
  //int A[] = {1,2,3};
  //int A[] = {5,2,1};
  int A[] = {2,1,5};
  int n = 3;

  printf("tlen%d:\n", n);
  selection_sort(A, n);
  putchar('\n');
}

void test_len6(void)
{
  int A[] = {4,5,6,1,2,3};
  int n = 6;

  printf("tlen%d:\n", n);
  selection_sort(A, n);
  putchar('\n');
}

int main()
{
  test_len1();
  test_len2();
  test_len3();
  test_len6();
  return 0;
}


