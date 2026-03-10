#include <stdio.h>

int my_strncmp(const char *s1, const char *s2, size_t n)
{
  // intuição: avançamos enquanto
  // - n > 0 (até atingir o número máximo de comparações
  // - *s1 != '\0' (semelhante a s1[i] != '\0', onde vamos incrementando 'i', e não incrementamos os apontadores s1 e s2)
  // - *s2 != '\0' (ver anterior)
  while(n > 0 && *s1 != '\0' && *s2 != '\0')
  { 
    // se forem diferentes, então retornamos a sua diferença
    if (*s1 != *s2)
    { return (unsigned char)*s1 - (unsigned char)*s2; }

    // caso contrário (no caso dos caracteres serem iguais)
    // incrementamos os apontadores e decrementamos n
    s1++;
    s2++;
    n--;
  }

  // se chegamos a este ponto então sabemos que:
  // n é 0 ou uma das strings terminou

  // se n é 0, então é porque são iguais para os primeiros n elementos
  // - senão fosse esse o caso, teria acontecido um return da diferença na linha acima (dentro do loop)
  // - como tal, podemos retornar 0
  if (n == 0)
  { return 0; }

  // se uma das strings terminou (ou até ambas simultaneamente) podemos retornar a diferença:
  // - se forem iguais, o valor retornado será 0
  // - senão, "é o que é".
  return (unsigned char)*s1 - (unsigned char)*s2;
}

int main(void)
{
  char a[] = "banana";
  char b[] = "bandana";

  size_t n = 4; // alterar valor
  int r = my_strncmp(a, b, n);

  printf("comparar \"%s\" e \"%s\" (%zu caracteres)\n", a, b, n);
  printf("resultado: %d\n", r);

  return 0;
}
