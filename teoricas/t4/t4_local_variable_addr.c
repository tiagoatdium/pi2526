#include <stdio.h>

int* soma(int a, int b)
{
  int r;
  r = a + b;
  return &r; // posso fazer isto? (não.)
}

int main(void)
{
  int* r;
  r = soma(10,20);
  printf("%d\n", *r);
  return 0;
}

