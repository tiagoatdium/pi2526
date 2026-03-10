#include <stdio.h>

char *my_strncat(char *dest, char *src, size_t n)
{
  char *d = dest;

  // encontrar o fim da string dest
  while (*d != '\0')
  { d++; }

  // copiar no máximo n caracteres de src
  while(*src != '\0' && n > 0)
  { 
    *d = *src; // copiar um char de src para d (dest)
    d++; // incrementar ambos os apontadores
    src++;
    n--; // contabilizar a cópia realizada
  }

  *d = '\0';

  return dest;
}

int main(void)
{
    char s1[20] = "ola ";
    char s2[] = "alunos";

    my_strncat(s1, s2, 2);

    printf("resultado: %s\n", s1);

    return 0;
}
