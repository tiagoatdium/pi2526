#include <stdio.h>

// troque por DEBUG 0 para diminuir o número de impressões no terminal
#define DEBUG 1

// print_array: imprime todos os elementos de um array
void print_array(int A[], int n, char term)
{
  for (int i = 0; i < n; i++)
  { printf("%d ", A[i]);
  }
  putchar(term);
}

// Intuição do algoritmo (binary search):
//
// - o array deve estar ordenado (ordem crescente)
//
// - em vez de procurar sequencialmente, procuramos
//   sempre no elemento do meio do intervalo atual
//
// - se A[mid] == x, encontrámos o elemento
//
// - se A[mid] < x, então x só pode estar na metade direita
//   do array (onde estão os maiores)
//
// - se A[mid] > x, então x só pode estar na metade esquerda
//   do array (onde estão os menores)
//
// - a cada passo reduzimos o intervalo de procura para
//   sensivelmente metade: A[left .. right]
//
// - quando left > right, sabemos que o elemento não 
//   existe no array
// 
int binary_search(int A[], int n, int x)
{
  // limites do intervalo de procura no array

  int left = 0;      // left corresponde ao início
  int right = n - 1; // right corresponde ao fim
  int mid;

  // continuar enquanto o intervalo não estiver vazio
  while (left <= right)
  {
    // posição intermédia do intervalo atual
    mid = (left + right) / 2;

    #if DEBUG
      printf("    ");
      print_array(A+left, right-left+1, ' ');
      printf(" --- mid=%d, A[mid]=%d\n", mid, A[mid]);
    #endif

    // verificar se encontrámos o elemento
    if (A[mid] == x)
    { return mid; }

    // decidir em que metade continuar a procura
    if (A[mid] < x) 
    { left = mid + 1; } // procurar na metade direita
    else
    { right = mid - 1; } // procurar na metade esquerda
  }

  // o elemento não existe no array
  return -1;
}

int main(void)
{
  int A[] = {1,3,7,16, 20,30,35,45, 50,100};
  int n = 10;
  int x, index; 

  // procurar 1 no array
  x = 1;
  index = binary_search(A, n, x);
  printf("binary_search: '%d' devolveu: %d\n\n", x, index);

  // procurar 100 no array
  x = 100;
  index = binary_search(A, n, x);
  printf("binary_search: '%d' devolveu: %d\n\n", x, index);

  // procurar 35 no array
  x = 35;
  index = binary_search(A, n, x);
  printf("binary_search: '%d' devolveu: %d\n\n", x, index);




  return 0;
}
