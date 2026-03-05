// gcc -std=c11 -O2 -g -Wall -Wextra -Wpedantic -DLINES=2 -DCOLS=2 -o t5_matrix_addlines t5_matrix_addlines.c

#include <stdio.h> // printf()
#include <time.h> // time()
#include <stdlib.h> // rand() e srand() // consulte o manual com o comando man 3 rand

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
  { printf("%3d ", a[i]); }
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

// overflow? escreva uma versão alternativa deste ficheiro que garantidamente 
// não incorre em overflows

int add_array0(int a[LINES])
{
  size_t i;
  int r = 0;
	for(i=0; i<LINES; i++)
	{ r += a[i]; }
	return r;
}

int add_array(int *a, size_t s)
{
  size_t i;
  int r = 0;
	for(i=0; i<s; i++)
	{ r += a[i]; }
	return r;
}

// ////////////////////////////////////////////////////////

void addlines_new0(int r[LINES], int a[LINES][COLS])
{
	size_t i;

	for(i=0; i<LINES; i++)
	{ r[i] = add_array( &(a[i][0]), COLS); }
}


// ////////////////////////////////////////////////////////

void addlines_new1(int r[LINES], int a[LINES][COLS])
{
	size_t i;

	for(i=0; i<LINES; i++)
	{ r[i] = add_array((int*)(a + i), COLS); }
}

// ////////////////////////////////////////////////////////

void addlines_new2(int r[LINES], int a[LINES][COLS])
{
	size_t i;
	int *ptr = (int*) a;

	for(i=0; i<LINES; i++, ptr += COLS)
	{ r[i] = add_array(ptr, COLS); }
}

int main(void)
{
  int m1[LINES][COLS] = {0};
  int s1[LINES] = {0};
  int s2[LINES] = {0};
  int s3[LINES] = {0};
  int s4[LINES] = {0};
  
  srand(time(NULL));

  init(m1);
  
  addlines(s1, m1);
  addlines_new0(s2, m1);
  addlines_new1(s3, m1);  
  addlines_new2(s4, m1);  
  
  print_m(m1);

  printf("addlines:      "); print_a(s1);
  printf("addlines_new0: "); print_a(s2);
  printf("addlines_new1: "); print_a(s3);
  printf("addlines_new2: "); print_a(s4);

  return 0;
}
