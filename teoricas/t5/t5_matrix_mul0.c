#include <stdio.h>

#define D1 2
#define D2 3
#define D3 4

void mul(int C[D1][D3], int A[D1][D2], int B[D2][D3])
{
	size_t i, j, k;

  for(i=0; i<D1; i++)
  { for(k=0; k < D2; k++)
    { for(j=0; j < D3; j++)
      { C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

void print_matrix(int *m, size_t line, size_t cols)
{
  size_t i, j;

  for(i=0; i < line; i++)
  { for(j=0; j < cols; j++)
    { printf("%2d ", *m); m++; }
    putchar('\n');
  }
  putchar('\n');
}

int main(void)
{
    int a[D1][D2] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int b[D2][D3] = {
        { 7,  8,  9, 10},
        {11, 12, 13, 14},
        {15, 16, 17, 18}
    };

    int c[D1][D3] = { 0 };

    print_matrix((int *)a, D1, D2);
    print_matrix((int *)b, D2, D3);

    mul(c, a, b);

    print_matrix((int *)c, D1, D3);

    return 0;
  
  return 0;
}
