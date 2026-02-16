#include <stdio.h>

void plus1(unsigned int *x)
{
	*x = *x + 1;
}

int main()
{
  unsigned int a, b, c;
  unsigned int *ap, *bp, *cp;
  
  a = b = c = 0;
  ap = &a; bp = &b; cp = &c;
  
	plus1(ap);
	plus1(bp);
  plus1(cp);
  
  plus1(&a);
  plus1(&b);
  plus1(&c);

  printf("a=%d ", a);
  printf("b=%d ", b);
  printf("c=%d\n", c);

  return 0;
}
