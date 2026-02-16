#include <stdio.h>

int main()
{
  unsigned int a, b, c;
  unsigned int *ap, *bp, *cp;
  
  // a = b = c = 0;
  a = 0;
  b = 0;
  c = 0;
  
  ap = &a;
  bp = &b;
  cp = &c;
  
  *ap = 1;
  *bp = 2;
  *cp = 3;

  printf("a=%d ", a);
  printf("b=%d ", b);
  printf("c=%d\n", c);
  
  return 0;
}
