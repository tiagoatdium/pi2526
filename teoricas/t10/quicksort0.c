#include <stdio.h>

// A ideia principal do quicksort é a seguinte:
//
// 1. escolhemos um elemento especial, chamado pivot
//
// 2. reorganizamos o array de forma a que:
//
//    - os elementos menores ou iguais ao pivot fiquem à esquerda
//    - os elementos maiores do que o pivot fiquem à direita
//
// 3. depois desta reorganização, o pivot fica na sua posição
//    final no array ordenado
//
// 4. nesta fase, repetimos o mesmo processo, recursivamente, para a parte
//    da esquerda e para a parte da direita
//
//
// Neste ficheiro:
//
// - o pivot é o último elemento do segmento (sub array)
// - a função partition devolve o índice final do pivot
//
// Exemplo:
//
//   array inicial:
//     7 2 9 4 3
//
//   escolhemos pivot = 3
//
//   depois da partição, podemos obter algo como:
//     2 3 9 4 7
//
// O importante nao é que a parte da direita já esteja ordenada.
// O importante é que:
//
// - tudo à esquerda de 3 é <= 3
// - tudo à direita de 3 é > 3
//
// Depois aplicamos o mesmo raciocínio recursivamente às duas
// partes do array.
//
// ------------------------------------------------------------
// Compilação:
//
//   gcc -Wall -Wextra -pedantic -std=c99 quicksort0.c -o quicksort0
//
// Execução:
//   ./quicksort
//


// Troca os elementos v[i] e v[j].
//
// Esta função auxiliar é usada pela partição para reorganizar
// o array.
void swap(int v[], int i, int j)
{
  int temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}



// Imprime um array de inteiros.
void imprimir_array(int v[], int n)
{
  int i;

  for(i = 0; i < n; i++)
  {
    printf("%d ", v[i]);
  }

  printf("\n");
}



// Reorganiza o segmento v[left..right] em torno de um pivot.
//
// Convenção usada:
//
// - escolhemos como pivot o último elemento do segmento:
//     pivot = v[right]
//
// Objetivo da função:
//
// - no fim, o pivot fica colocado na sua posição final
// - todos os elementos <= pivot ficam à esquerda
// - todos os elementos > pivot ficam à direita
//
// A função devolve o índice final do pivot.
//
// ------------------------------------------------------------
// Ideia das variáveis:
//
// - 'j' percorre o segmento da esquerda para a direita,
//   desde 'left' até 'right - 1'
//
// - 'i' indica a primeira posição onde ainda pode ser colocado
//   um elemento <= pivot
//
// Durante a execução do ciclo, mantemos a seguinte ideia:
//
//   v[left .. i-1]    contem elementos <= pivot
//   v[i .. j-1]       contem elementos > pivot
//   v[j .. right-1]   ainda nao foi analisado
//
// Ou seja, à medida que 'j' avança:
//
// - se v[j] <= pivot, esse elemento deve ir para a zona da
//   esquerda, e por isso trocamo-lo com v[i] e aumentamos 'i'
//
// - se v[j] > pivot, nao fazemos nada; esse elemento fica,
//   para já, na zona da direita
//
// ------------------------------------------------------------
// No fim do ciclo:
//
// - todos os elementos de left até i-1 são <= pivot
// - todos os elementos de i até right-1 são > pivot
// - o pivot ainda está em v[right]
//
// Falta apenas colocar o pivot entre essas duas zonas.
// Para isso fazemos:
//
//   swap(v, i, right);
//
// Depois dessa troca:
//
//   v[left .. i-1]  <= pivot
//   v[i]            == pivot
//   v[i+1 .. right] > pivot
//
// Logo, 'i' é a posição final do pivot.

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



// Ordena recursivamente o segmento v[left..right].
//
// Estratégia:
//
// 1. aplicar partition ao segmento atual
// 2. obter a posição final do pivot
// 3. ordenar recursivamente a parte da esquerda
// 4. ordenar recursivamente a parte da direita
//
// Caso base:
//
// - se left >= right, o segmento tem 0 ou 1 elementos
// - nesse caso, já está ordenado
//
// ------------------------------------------------------------
// Estrutura conceptual:
//
//   quicksort(v, left, right)
//   {
//     se houver pelo menos 2 elementos:
//       p = partition(...)
//       quicksort(parte esquerda)
//       quicksort(parte direita)
//   }
//
// ------------------------------------------------------------
// Exemplo:
//
//   [7, 2, 9, 4, 3, 8, 1, 6]
//
// primeira partição:
//   pivot = 6
//
// após partition:
//   [2, 4, 3, 1, 6, 8, 9, 7]
//
// agora:
//
// - 6 já está no lugar certo
// - ordenamos recursivamente:
//   - [2, 4, 3, 1]
//   - [8, 9, 7]
void quicksort_aux(int v[], int left, int right)
{
  int p;

  if(left < right)
  {
    p = partition(v, left, right);

    quicksort_aux(v, left, p - 1);
    quicksort_aux(v, p + 1, right);
  }
}



// Versão auxiliar que ordena um array completo.
//
// Esta função existe apenas para tornar a chamada mais simples
// na função main.
void quicksort(int v[], int n)
{
  if(n > 0)
  {
    quicksort_aux(v, 0, n - 1);
  }
}



int main(void)
{
  int v[] = {7, 2, 9, 4, 3, 8, 1, 6};
  int n = 8;


  printf("Array inicial:\n");
  imprimir_array(v, n);

  quicksort(v, n);

  printf("\nArray ordenado:\n");
  imprimir_array(v, n);

  return 0;
}
