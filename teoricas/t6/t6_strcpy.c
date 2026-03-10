#include <stdio.h>

char *my_strcpy(char *dest, char *src)
{
  char *d = dest;

  while (*src != '\0')
  { *d = *src;
    d++;
    src++;
  }

  *d = '\0';

  return dest;
}

int main(void)
{
  char src[] = "programacao";
  char dest[20];

  my_strcpy(dest, src);

  printf("origem: %s\n", src);
  printf("destino: %s\n", dest);

  return 0;
}
