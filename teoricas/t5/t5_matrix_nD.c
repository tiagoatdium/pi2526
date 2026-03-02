#include <stdio.h>

// neste exemplo, demonstram-se arrays com mais do que 2 dimensões (4)

#define D1 3
#define D2 6
#define D3 9
#define D4 12

void init_matrix(int matrix[D1][D2][D3][D4])
{
  size_t i, j, k, l;
  int c;

  c = 0;
  for(i=0; i < D1; i++)
  { for(j=0; j < D2; j++)
    { for(k=0; k < D3; k++)
      { for(l=0; l < D4; l++, c++)
        { matrix[i][j][k][l] = c;
        }
      }
    }
  }
}

void print_matrix(int matrix[D1][D2][D3][D4])
{
  size_t i, j, k, l;
  int c;

  c = 0;
  for(i=0; i < D1; i++)
  { for(j=0; j < D2; j++)
    { printf("%2zu, %2zu:\n", i, j);
      for(k=0; k < D3; k++)
      { printf("   ");
        for(l=0; l < D4; l++, c++)
        { printf("%4d ", matrix[i][j][k][l]); // será equivalente a "*(*(*(*(matrix + i) + j) + k) + l)"? experimente.
        }
        putchar('\n');
      }
    }
  }
}

int main(void)
{
  int matrix[D1][D2][D3][D4] = { 0 };
  init_matrix(matrix);
  print_matrix(matrix);
  return 0;
}
