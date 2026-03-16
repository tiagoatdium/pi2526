#include <stdio.h>

// troque por DEBUG 0 para diminuir o número de impressões no terminal
#define DEBUG 1

// swap: troca os valores de dois inteiros
//
// recebe dois apontadores para inteiros e troca 
// os valores guardados nesses endereços de memória.
//
// passos:
// - guardar temporariamente o valor do primeiro inteiro
// - copiar o valor do segundo para o primeiro
// - copiar o valor guardado temporariamente para o segundo
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}


// print_array: imprime todos os elementos de um array
void print_array(int A[], int n)
{
  for (int i = 0; i < n; i++)
  { printf("%d ", A[i]);
  }
  printf("\n");
}


// bubble_pass: executa uma passagem do algoritmo bubble sort
//
// ideia desta função:
// - percorrer o array uma vez
// - comparar cada elemento com o seguinte
// - trocar os dois elementos se estiverem fora de ordem
//
// durante uma passagem:
// - os elementos maiores "sobem" gradualmente para a direita
// - no final da passagem, o **maior elemento da parte analisada
//   ficará na última posição dessa parte do array**
//
// valor devolvido:
// - devolve 1 se ocorreu pelo menos uma troca
// - devolve 0 se não ocorreu nenhuma troca
//
// se nenhuma troca ocorrer, significa que o array já está ordenado.
int bubble_pass(int A[], int n)
{
  int swapped = 0;

  for (int i = 0; i < n - 1; i++)
  {
    if (A[i] > A[i + 1])          // comparar dois elementos adjacentes
    { swap(&(A[i]), &(A[i + 1])); // se estiverem fora de ordem, trocá-los
      swapped = 1;                // registar que ocorreu uma troca
    }
  }

  return swapped;
}


// bubble_sort: ordena um array usando o algoritmo bubble sort
//
// descrição do algoritmo:
//
// - repetir várias passagens sobre o array
//
// - em cada passagem:
//     - comparar elementos adjacentes
//     - trocar os elementos se estiverem fora de ordem
//
// - após cada passagem:
//     - o maior elemento move-se para o final do array
//
// - parar quando:
//     - não ocorrer nenhuma troca numa passagem
//       (isto significa que o array já está ordenado)
//
// nota:
// - em cada nova passagem podemos ignorar o último elemento,
//   porque ele já estará na posição correta.
//
void bubble_sort(int A[], int n)
{
  int pass = 0;
  int swapped = 1;

  while (pass < n - 1 && swapped == 1) // pergunta, é preciso o == 1?
  {
    // imprime os estados intermédios do Array A se DEBUG for 1
    #if DEBUG
      printf("    "); print_array(A, n);
    #endif

    // realizar uma passagem do bubble sort sobre um "subarray de A":
    //
    // - na primeira passagem é considerado o array completo (A[0 .. n - 1]):
    //   - ou seja, o tamanho dado à função bubble_pass é n ('n - pass' com 'pass = 0', é 'n')
    //
    // - na segunda passagem consideramos menos um elemento:
    //   - o maior elemento já ficou na posição final A[n-1]
    //
    swapped = bubble_pass(A, n - pass);
    pass++;
  }
}

// /////////////////////////////////////////////
// test
void test_len1(void)
{
  int A[] = {5};
  int n = 1;

  bubble_sort(A, n);
  printf("tlen%d: ", n);
  print_array(A, n);
}

void test_len2(void)
{
  int A[] = {5,1};
  int n = 2;

  bubble_sort(A, n);
  printf("tlen%d: ", n);
  print_array(A, n);
}

void test_len3(void)
{
  //int A[] = {1,2,3};
  //int A[] = {5,2,1};
  int A[] = {2,1,5};
  int n = 3;

  bubble_sort(A, n);
  printf("tlen%d: ", n);
  print_array(A, n);
}

void test_len6(void)
{
  int A[] = {4,5,6,1,2,3};
  int n = 6;

  bubble_sort(A, n);
  printf("tlen%d: ", n);
  print_array(A, n);
}

int main()
{
  test_len1();
  test_len2();
  test_len3();
  test_len6();
  return 0;
}
