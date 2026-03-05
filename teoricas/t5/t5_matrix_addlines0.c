// gcc -std=c11 -O2 -g -Wall -Wextra -Wpedantic -DLINES=2 -DCOLS=2 -o t5_matrix_addlines t5_matrix_addlines.c

#include <stdio.h> // printf()
#include <time.h> // time()
#include <stdlib.h> // rand() e srand() // consulte o manual com o comando man 3 rand
#include <limits.h> // INT_MAX

#ifndef LINES
#define LINES 4
#endif

#ifndef COLS
#define COLS 4
#endif

void init(int m[LINES][COLS])
{
  size_t i, j;

  for(i=0; i < LINES; i++)
  { for(j=0; j < COLS; j++)
    { m[i][j] = rand() % 101; }
  }
}

void print_m(int m[LINES][COLS])
{
  size_t i, j;

  for(i=0; i < LINES; i++)
  { for(j=0; j < COLS; j++)
    { printf("%3d ", m[i][j]); }
    putchar('\n');
  }
  putchar('\n');
}

void print_a(int a[LINES])
{
  size_t i;

  for(i=0; i < LINES; i++)
  { printf("%3d\n", a[i]); }
  putchar('\n');
}

void addlines(int r[LINES], int a[LINES][COLS])
{
	size_t i, j;

	for(i=0; i<LINES; i++)
	{ r[i] = 0;
	  for(j=0; j<COLS; j++)
	  { r[i] += a[i][j]; }
	}
}

int main(void)
{
  int m1[LINES][COLS] = {0};
  int s1[LINES] = {0};
  
  //
  srand(time(NULL));
	printf("rand_max: %d // int_max: %d // equal: %d\n\n",
	  RAND_MAX, INT_MAX, RAND_MAX==INT_MAX);

	//

  init(m1);
  addlines(s1, m1);
  
  print_m(m1);
  print_a(s1);

  return 0;
}
