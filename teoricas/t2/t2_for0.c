#include <stdio.h>

int main(void)
{
  int i, j;

  //
  for(i=1; i<5; i++) // 1, ...
    putchar('#');
  putchar('\n');

  /**/ putchar('\n'); /**/

  //
  for(i=0; i<5; i++) // 1, ...
  { for(j=0; j<5; j++)
      putchar('#');
    putchar('\n');
  }

  /**/ putchar('\n'); /**/

  for(i=0; i<5; i++) // 0, 1, 2, 3, 4
  {
    for(j=0; j<5; j++) // 0, 1, 2, 3, 4
    {
      if(i==j)
      { putchar('1'); }
      else
      { putchar('0'); }
    }
    putchar('\n');
  }

  return 0;
}







