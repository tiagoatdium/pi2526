#include <stdio.h>

// troque por DEBUG 0 para diminuir o número de impressões no terminal
#define DEBUG 1

// print_array: imprime os elementos de um array
void print_array(int A[], int n)
{
  for (int i = 0; i < n; i++)
  { printf("%d ", A[i]);
  }
  printf("\n");
}

// ////////////////////////////////////////////////////////
//
// merge_sort: ordena um array usando merge sort
//
// intuição do algoritmo:
//
// - um elemento sozinho já está ordenado
//
// - começamos por considerar que o array é composto por
//   vários blocos ordenados de tamanho 1
//
// - depois juntamos blocos adjacentes para formar
//   blocos ordenados maiores
//
// - primeiro juntamos blocos de tamanho 1
//   para formar blocos de tamanho 2
//
// - depois juntamos blocos de tamanho 2
//   para formar blocos de tamanho 4
//
// - depois juntamos blocos de tamanho 4
//   para formar blocos de tamanho 8
//
// - continuamos este processo até que todo o array
//   seja um único bloco ordenado
//
// exemplo:
//
//   array inicial
//   5 1 4 2 10
//
//   blocos de tamanho 1
//   [5][1] [4][2] [10]
//
//   juntar blocos de tamanho 1 -> blocos de tamanho 2
//   [1 5] [2 4] [10]
//
//   juntar blocos de tamanho 2 -> blocos de tamanho 4
//   [1 2 4 5] [10]
//
//   juntar blocos de tamanho 4 -> bloco final
//   [1 2 4 5 10]


// ////////////////////////////////////////////////////////

// um dos 'problemas' a resolver é juntar blocos. Podemos
// então implementatar uma função merge que junta dois 
// blocos (ordenados) do array
//
// dois blocos podem ser definidos como:
// - A[left .. mid-1]
// - A[mid  .. right-1]
//
//
// o processo de merge pode ser resumido da seguinte forma:
// - comparamos os primeiros elementos de cada bloco
// - copiamos o menor para um array (temporário)
// - avançamos no bloco de onde veio esse elemento
// - repetimos este processo enquanto ambos os blocos
//   ainda tiverem elementos
//
// quando um dos blocos termina:
//
// - copiamos todos os elementos restantes do outro bloco
//
// No final, o array temporário contém todos os elementos
// dos dois blocos em ordem crescente.
//
// exemplo:
//   1 5 | 2 4
//
// comparar:
//   1 vs 2 -> copiar 1
//   5 vs 2 -> copiar 2
//   5 vs 4 -> copiar 4
//
// copiar o elemento restante:
//
//   1 2 4 5
//
void merge(int A[], int temp[], int left, int mid, int right)
{
  int i = left;
  int j = mid;
  int k = left;

  while (i < mid && j < right)
  {
    if (A[i] <= A[j]) // se A[i] <= A[j] então copia A[i]
    { temp[k] = A[i];
      i++;
    }
    else
    { temp[k] = A[j];
      j++;
    }

    k++;
  }

  while (i < mid)
  { temp[k] = A[i];
    i++;
    k++;
  }

  while (j < right)
  { temp[k] = A[j];
    j++;
    k++;
  }
}

// /////////////////////////////////////////////

void merge_sort(int A[], int n)
{
  int temp[n];

  for (int size = 1; size < n; size = size * 2)
  {
    for (int left = 0; left < n; left += 2 * size)
    {
      int mid = left + size;
      int right = left + 2 * size;

      if (mid > n)
      { mid = n; }

      if (right > n)
      { right = n; }

      merge(A, temp, left, mid, right);
    }

    for (int i = 0; i < n; i++)
    { A[i] = temp[i]; }
    
    #if DEBUG
      printf("    "); print_array(A, n);
    #endif
  }
}


// /////////////////////////////////////////////
// test
void test_len1(void)
{
  int A[] = {5};
  int n = 1;

  printf("tlen%d:\n", n);
  merge_sort(A, n);
  putchar('\n');
}

void test_len2(void)
{
  int A[] = {5,1};
  int n = 2;

  printf("tlen%d:\n", n);
  merge_sort(A, n);
  putchar('\n');
}

void test_len3(void)
{
  //int A[] = {1,2,3};
  //int A[] = {5,2,1};
  int A[] = {2,1,5};
  int n = 3;

  printf("tlen%d:\n", n);
  merge_sort(A, n);
  putchar('\n');
}

void test_len6(void)
{
  int A[] = {4,5,6,1,2,3};
  int n = 6;

  printf("tlen%d: ", n); print_array(A, n);
  merge_sort(A, n);
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


