#include <stdio.h>

// neste segundo exemplo introduzem-se funções que operam sobre matrizes:
// - são apresentadas duas funções: init_matrix e print_matrix
// - a primeira função, init_matrix, inicializa uma matriz com alguns valores (0,1,2,... --- entenda como funciona)
// - a segunda função, print_matrix, imprime uma matrix no terminal

// de notar que neste exemplo, ao contrário do anterior, o número de linhas e colunas difere.


#define MLINES 3
#define MCOLS 6

void init_matrix(int matrix[MLINES][MCOLS])
{
  size_t i, j;
  int c;

  c = 0;
  for(i=0; i < MLINES; i++)
  { for(j=0; j < MCOLS; j++, c++)
    { matrix[i][j] = c; }
  }
}

void print_matrix(int matrix[MLINES][MCOLS])
{
  size_t i, j;

  for(i=0; i < MLINES; i++)
  { for(j=0; j < MCOLS; j++)
    { printf("%2d ", matrix[i][j]); }
    putchar('\n');
  }
}

int main(void)
{
  int matrix[MLINES][MCOLS] = {0};

  init_matrix(matrix);

  print_matrix(matrix);

  return 0;
}
