#include <stdio.h>

int square(int x)
{
  return x * x;
}

int times2(int x)
{
  return 2 * x;
}

int negate(int x)
{
  return -x;
}

void map(int r[], int n, int (*f)(int))
{
  int i;

  for(i = 0; i < n; i++)
  {
    r[i] = f(r[i]);
  }
}

void print_array(int v[], int n)
{
  int i;

  printf("[");
  for(i = 0; i < n; i++)
  { printf("%d", v[i]);
    if(i < n - 1)
    { printf(", "); }
  }
  printf("]\n");
}

int main(void)
{
  int values[5] = {1, 2, 3, 4, 5};

  printf("original: ");
  print_array(values, 5);

  map(values, 5, square);
  printf("square:   ");
  print_array(values, 5);

  map(values, 5, times2);
  printf("double:   ");
  print_array(values, 5);

  map(values, 5, negate);
  printf("negate:   ");
  print_array(values, 5);

  return 0;
}
