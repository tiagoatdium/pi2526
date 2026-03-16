#include <stdio.h>

// troque por DEBUG 0 para diminuir o número de impressões no terminal
#define DEBUG 1

void print_array(int A[], int d, int n)
{
  for (int i = 0; i < n; i++)
  { if(i == d) printf("| ");
    printf("%d ", A[i]);
  }
  printf("\n");
}

// //////////////////////////////////////////////////////////////////
// insertion_sort: ordena um array usando o algoritmo insertion sort
//
// intuição do algoritmo:
//
// - a ideia é semelhante a ordenar cartas na mão
//
// - começamos com o primeiro elemento
//   (um único elemento já está ordenado)
//
// - depois pegamos no elemento seguinte
//   e colocamo-lo na posição correta entre os anteriores
//
// - repetimos este processo para todos os elementos
//
// exemplo para {5, 1, 4, 2, 8}
//
//   5 | 1 4 2 8
//   1 5 | 4 2 8
//   1 4 5 | 2 8
//   1 2 4 5 | 8
//
// o símbolo "|" separa:
// - a parte esquerda: já ordenada
// - a parte direita: ainda por ordenar

// //////////////////////////////////////////////////////////////////

// Funções auxiliares do insertion sort
//
// Em vez de escrever todo o algoritmo de uma só vez,
// podemos dividi-lo em tarefas mais pequenas.
//
// No exemplo:
//
//   5 | 1 4 2 8
//   1 5 | 4 2 8
//   1 4 5 | 2 8
//   1 2 4 5 | 8
//
// em cada passo fazemos sempre a mesma ideia:
//
// - escolher o próximo elemento a inserir
// - abrir espaço na parte já ordenada
// - colocar o elemento na posição correta
//
// Estas tarefas correspondem às funções auxiliares:
//
// - shift_right(...):
//   desloca para a direita os elementos maiores,
//   para abrir espaço ao elemento que queremos inserir
//
// - insert_element(...):
//   pega num elemento do array e insere-o na posição
//   correta dentro da parte já ordenada
//
// - insertion_sort(...):
//   repete este processo para todos os elementos,
//   fazendo crescer a parte ordenada do array

// //////////////////////////////////////////////////////////////////

// shift_right: desloca elementos maiores que key para a direita
//
// Começa na posição j e continua enquanto:
// - ainda estamos dentro do array (j >= 0)
// - o elemento atual (A[j]) é maior que key
//
// Cada elemento é movido uma posição para a direita.
//
int shift_right(int A[], int j, int key)
{
  while (j >= 0 && A[j] > key)
  {
    A[j + 1] = A[j];
    j--;
  }

  return j;
}


// insert_element: insere um elemento na parte já ordenada do array
//
// Passos:
// - guardar o valor a inserir (key)
// - deslocar elementos maiores para a direita
// - colocar key na posição correta

void insert_element(int A[], int i)
{
  int key = A[i];
  int j = i - 1;

  j = shift_right(A, j, key);

  A[j + 1] = key;
}

void insertion_sort(int A[], int n)
{
  for (int i = 1; i < n; i++)
  {
    #if DEBUG
      printf("    "); print_array(A, i, n);
    #endif

    insert_element(A, i);
  }
}

// /////////////////////////////////////////////
// test

void test_len6(void)
{
  int A[] = {5, 1, 4, 2, 8};
  int n = 5;

  printf("tlen%d:\n", n);
  insertion_sort(A, n);
  putchar('\n');
}

int main()
{
  test_len6();
  return 0;
}

