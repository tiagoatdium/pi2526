#include <stdio.h>
#include <stddef.h>

size_t my_strlen(char *s)
{
  size_t n = 0;

  while (s[n] != '\0')
  { n++; }

  return n;
}

int main(void)
{
  char s[] = "imperativa";

  size_t len = my_strlen(s);

  printf("string: %s\n", s);
  printf("comprimento: %zu\n", len);

  return 0;
}
