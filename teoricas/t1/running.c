// ficheiro de exemplo da aula (nota: não contém todas as variações estudadas).

#include <stdio.h>

int main(void)
{
  int i = 0;
  while (i < 4) {
    printf("%d\n", i);
    i += 1;
  }

  return 0;
}

#if 0
int main(void)
{
  int a = 10;
  int b = 11;
  int c = (a < b) * 100;

  printf("%d\n", c);

  return 0;
}

int main(void)
{
  unsigned char d = 0;
  printf("%d\n", d);

  d -= 2;
  printf("%d\n", d);

  return 0;
}
#endif
