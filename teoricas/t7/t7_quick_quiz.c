#include <stdio.h>

int main(void)
{
  // experimentar também com char *s = "Eu (...)";
  char s[] = "Eu vou tirar boa nota!";
  
  printf("%s\n", s);
  *(s+3) -= 32;
  printf("%s\n", s+3);

  return 0;
}
