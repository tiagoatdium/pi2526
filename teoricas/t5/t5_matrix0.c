#include <stdio.h>

// primeiro exemplo sobre matrizes; de notar que
// - MSIZE não é uma variável, é uma macro, o que é em tudo equivalente
//   a ter uma constante "inplace". Por exemplo, a seguinte sequência:
// ```
// #define M 3
// int m[M][M] = { {1,2,3}, {4,5,6}, {7,8,9} };
// ```
//
//   é equivalente a:
// ```
// int m[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
// ```
//
// sobre a vantagem de utilizar macros:
// - dado que o valor em concreto (neste caso 3) é definido pelo "define" (e apenas uma vez)
//   a utilização de macros permite alterar de forma fácil o valor correspondente (sem ser
//   preciso alterar "muitas" linhas de código)
//
// nota: este primeiro exemplo sobre matrizes utiliza o mesmo tamanho para linhas e colunas, mas tal
// não é estritamente necessário (o número de linhas e colunas pode diferir)

#define MSIZE 3

int main(void)
{
  size_t i, j;

	// declaração de um array para efeitos de comparação
  // int array[MSIZE] = {1,2,3};
  
  int matrix0[MSIZE][MSIZE] =
  { {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  int matrix1[MSIZE][MSIZE] = { {1}, {4}, {7} };
    
  int matrix2[MSIZE][MSIZE] = { {1} };

	// imprimir matrix0
  for(i=0; i < MSIZE; i++)
  { for(j=0; j < MSIZE; j++)
    { printf("%d ", matrix0[i][j]);
    }
    putchar('\n');
  }
  
  // imprimir matrix1
	putchar('\n');
  for(i=0; i < MSIZE; i++)
  { for(j=0; j < MSIZE; j++)
    { printf("%d ", matrix1[i][j]);
    }
    putchar('\n');
  }
  
  // imprimir matrix1
	putchar('\n');
  for(i=0; i < MSIZE; i++)
  { for(j=0; j < MSIZE; j++)
    { printf("%d ", matrix2[i][j]);
    }
    putchar('\n');
  }
  
  

  return 0;
}
