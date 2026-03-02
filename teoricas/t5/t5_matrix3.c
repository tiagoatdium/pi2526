#include <stdio.h>

// neste ficheiro exemplo, passamos de "matrix[][MCOLS]" para "(*matrix)[MCOLS]"
// - são equivalentes; os parenteses são necessários --- sem pararenteses passa a ser
//   um array de apontadores para inteiros --- se sentir que quer estudar algo mais
//   pesquise por "malloc matrices in C (array of pointers)"

#define MCOLS 6

void init_matrix(int (*matrix)[MCOLS], size_t lines)
{
  size_t i, j;
  int c;

  c = 0;
  for(i=0; i < lines; i++)
  { for(j=0; j < MCOLS; j++, c++)
    { matrix[i][j] = c; }
  }
}

void print_matrix(int (*matrix)[MCOLS], size_t lines)
{
  size_t i, j;

  for(i=0; i < lines; i++)
  { for(j=0; j < MCOLS; j++)
    { printf("%2d ", matrix[i][j]); }
    putchar('\n');
  }
}

int main(void)
{
  int matrix0[3][MCOLS] = {0};
  int matrix1[5][MCOLS] = {0};

  init_matrix(matrix0, 3);
  init_matrix(matrix1, 5);
   
  print_matrix(matrix0, 3);
  putchar('\n');
  print_matrix(matrix1, 5);

  return 0;
}
