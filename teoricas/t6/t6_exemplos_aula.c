#include <stdio.h>

// ver 'man 3 strcpy'; implementada com os tipos reportados no manual
char* my_strcpy(char *dest, const char *src)
{
  size_t i = 0;

  while(src[i] != '\0')
  {
    dest[i] = src[i];
    i++;
  }

  dest[i] = '\0';

  return dest;
}

// ver 'man 3 strlen'
size_t my_strlen(const char s[])
{
  size_t len = 0;

  while(s[len] != '\0')
  { len ++; }

  return len;
}

// ver 'man 3 strcat'
char *my_strncat(char *dest, const char *src, size_t n)
{
  size_t l_dest = my_strlen(dest);
  size_t i = 0;

  while(  i < n && src[i] != '\0' )
  { dest[l_dest + i] = src[i];
    i++;
  }

  dest[l_dest + i] = '\0';

  return dest;
}



// ////////////////////////////////////////////////////////
// algumas funções com pequenos testes

void test_strcpy(void)
{
  char src[] = "programacao";
  char dest[20];

  char *d = my_strcpy(dest, src);

  printf("[test_strcpy] origem:  %s\n", src);
  printf("[test_strcpy] destino: %s\n", dest);
  printf("[test_strcpy] %p == %p = %d\n\n", d, dest, d==dest);
}

void test_strlen(void)
{
  char s1[] = "programacao";
  char s2[] = "imperativa";

  size_t s1l = my_strlen(s1);
  size_t s2l = my_strlen(s2);

  printf("[test_strlen] s1: %s has length %zu\n", s1, s1l);
  printf("[test_strlen] s2: %s has length %zu\n\n", s2, s2l);
}

void test_strncat(void)
{
  char s1[100] = "programacao"; // algum espaço a mais...
  char s2[] = "imperativa";

  char *d = my_strncat(s1, s2, 100);
  printf("[test_strncat] s1: %s\n", s1);
  printf("[test_strncat] %p == %p = %d\n\n", d, s1, d==s1);

  // reset
  s1[11] = '\0';
  d = my_strncat(s1, s2, 3);

  printf("[test_strncat] s1: %s\n", s1);
  printf("[test_strncat] %p == %p = %d\n\n", d, s1, d==s1);

}

int main(void)
{
  test_strcpy();
  test_strlen();
  test_strncat();

  return 0;
}

