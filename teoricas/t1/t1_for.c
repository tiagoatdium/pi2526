#include <stdio.h>

int main(void)
{
  int i;

  for (i = 0; i < 2; i++) {
    printf("%d ", i);
  }

#if 0
  unsigned int n = 3;

  for (i = 0; i < 32; i++) {
    if (n % 2 == 1) {
      putchar('1');
    } else {
      putchar('0');
    }
    n = n / 2;
  }
  printf("\n");
#endif
  return 0;
}
