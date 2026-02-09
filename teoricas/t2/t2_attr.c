#include <stdio.h>

int main(void)
{
  int x = 0, y;
  
  y = x;
  printf("\nx=0; y=x; => y=%d, x=%d\n\n", y, x); // 0, 0

  // uncomment as we go...
  
  // x = 0 
  y = x++; // y = x; x = x + 1
  printf("y=x++; => y=%d, x=%d\n\n", y, x); // 0, 1

  x = 0;
  y = ++x; // x = x + 1; y = x
  printf("x=0; y=++x; => y=%d, x=%d\n\n", y, x); //

  x = 1;
  y = ++x; // y = 2 // x = 2
  printf("x=1; y=++x; => ++y=%d, x=%d\n", y++, x); //

  printf("%d\n", y);
  
  return 0;
}
