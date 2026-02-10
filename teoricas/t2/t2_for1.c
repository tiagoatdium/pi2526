/*
implemente a função box que desenhe o seguinte.
Por exemplo box(6):

######
#    #
#    #
#    #
#    #
######

Para ficar mais claro, adiciona-se alguns números:

   012345
0  ######
1  #    #
2  #    #
3  #    #
4  #    #
5  ######
*/

#include <stdio.h>

void linha_cheia(int n)
{
  for(int i=0; i<n; i++)
    putchar('#');
  putchar('\n');
}

void linha_vazia(int n)
{
  putchar('#');

  for(int i=1; i<n-1; i++)
    putchar(' ');

  putchar('#');
  putchar('\n');
}

void box(int n)
{
  linha_cheia(n);
  for(int i=1; i<n-1; i++)
    linha_vazia(n);
  linha_cheia(n);
}

int main(void)
{
  int n = 3;
  box(n);
  return 0;
}

