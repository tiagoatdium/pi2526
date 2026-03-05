// compilar com gcc -std=c90 -O2 -g -Wall -Wextra -Wpedantic  -o t5_matrix_VLA_C99 t5_matrix_VLA_C99.c
// e observar os warnings
//
// nota: ao invés de -std=c11 o comando anterior indica ao gcc que se pretende utilizar o standard C90 através da opção -std=c90;


#include <stdio.h> // printf()
#include <time.h> // time()
#include <stdlib.h> // rand() e srand() // consulte o manual com o comando man 3 rand
#include <string.h>

void init(size_t lines, size_t cols, int m[lines][cols])
{
  size_t i, j;

  for(i=0; i < lines; i++)
  { for(j=0; j < cols; j++)
    { m[i][j] = rand() % 101; }
  }
}

void print_m(size_t lines, size_t cols, int m[lines][cols])
{
  size_t i, j;

  for(i=0; i < lines; i++)
  { for(j=0; j < cols; j++)
    { printf("%3d ", m[i][j]); }
    putchar('\n');
  }
  putchar('\n');
}

void print_a(int *a, size_t lines)
{
  size_t i;

  for(i=0; i < lines; i++)
  { printf("%3d\n", a[i]); }
  putchar('\n');
}

void addlines(int *r, size_t lines, size_t cols, int a[lines][cols])
{
	size_t i, j;

	for(i=0; i<lines; i++)
	{ r[i] = 0;
	  for(j=0; j<cols; j++)
	  { r[i] += a[i][j]; }
	}
}

int main(void)
{
	size_t lines, cols;
	
	printf("insert lines: ");
	if( scanf("%zu", &lines) != 1 )
  { return -1; }
  
	printf("insert cols: ");
  if( scanf("%zu", &cols) != 1 )
  { return -1; }

  int m1[lines][cols];
  int s1[lines];
  
  memset(m1, 0, sizeof(int) * lines * cols);
  memset(s1, 0, sizeof(int) * lines);  

  init(lines, cols, m1);
  addlines(s1, lines, cols, m1);

  print_m(lines, cols, m1);
  print_a(s1, lines);

  return 0;
}

