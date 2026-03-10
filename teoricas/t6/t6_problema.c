#include <stdio.h>

int string_compare(char s1[], char s2[], size_t i)
{
  size_t n = 0;

  while( s1[i] != '\0' &&
         s2[n] != '\0' &&
         s1[i] == s2[n] )
  {
    i++;
    n++;
  }

  if(s2[n] == '\0')
  { return 1; }

  return 0;
}


int e_uma_letra(char c)
{
  if( (c >= 'A' && c <= 'Z') ||
      (c >= 'a' && c <= 'z')  ) 
  { return 1; } 

  return 0;
}

int e_uma_palavra(char s1[], size_t len, size_t i, size_t wordlen)
{
   int is_ok_before = 0;
   int is_ok_after = 0;

   if(i == 0)
   { is_ok_before = 1; }
   else
   { is_ok_before = ! e_uma_letra(s1[i-1]); }

    if(len == i + wordlen)
   { is_ok_after = 1; }
    else
   { is_ok_after = ! e_uma_letra(s1[i+wordlen+1]); }

   return (is_ok_before && is_ok_after);
}


int main(void)
{
  #if 0
  char s1[] = "o rato roeu a rolha";
  char s2[] = "rato";
  int r = string_compare(s1, s2, 2); // expected 1;
  printf("%s -> %s at %d == %d\n", s1, s2, 2, r);
  #endif

  #if 0
  printf("%d\n", e_uma_letra('a') );
  printf("%d\n", e_uma_letra(' ') );
  printf("%d\n", e_uma_letra('.') );
  printf("%d\n", e_uma_letra('Z') );
  #endif

  // alguns testes para a função e_uma_palavra
  printf("%d\n", e_uma_palavra("gato", 4, 0, 4) );                  // expected: 1 / true;  computed 1 - OK
  printf("%d\n", e_uma_palavra("a casa esta a arder", 15, 2, 4) );  // expected: 1 / true;  computed 0 - PROBLEM!
  printf("%d\n", e_uma_palavra("a casao esta a arder", 15, 2, 4) ); // expected: 0 / false; computed 1 - PROBLEM!


  return 0;
}











