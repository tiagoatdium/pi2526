#include <stdio.h>

int main(void)
{
  int r;
  int a, b, c;
  int *ap, *bp, *cp;

	ap = &a;
	bp = &b;
	cp = &c;

	r = scanf("%d", &a);
	  printf("lidos c/ sucesso: %d\n", r);

	r = scanf("%d %d", &b, &c);
	  printf("lidos c/ sucesso: %d\n", r);
	
  printf("a=%d ", a);
  printf("b=%d ", b);
  printf("c=%d\n", c);

  return 0;
}
