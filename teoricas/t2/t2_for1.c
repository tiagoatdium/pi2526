/*
p.ex.


6 

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

int main(void)
{
  int n = 3, i;
  linha_cheia(n);
  for(i=1; i<n-1; i++)
    linha_vazia(n);
  linha_cheia(n);
  return 0;
}



