#include <stdio.h>

#define N 3

void init_matrix(int matrix[N][N])
{
  int i, j, c;

  c = 0;
  for(i=0; i < N; i++)
  { for(j=0; j < N; j++, c++)
    { matrix[i][j] = c; }
  }
}

void print_matrix(int matrix[N][N])
{
  int i, j;

  for(i=0; i < N; i++)
  { for(j=0; j < N; j++)
    { printf("%d ", matrix[i][j]); }
    printf("\n");
  }
}

int main(void)
{
  int matrix[N][N] = {0};

  init_matrix(matrix);

  print_matrix(matrix);

  return 0;
}
