#include <stdio.h>

/* n = 4
####
#  #
#  #
####
*/

void meio(int n)
{
  putchar('#');
  for(int i=1; i<n-1; i++) // i=0; i<n-2
    putchar(' ');
  putchar('#');
 	putchar('\n');
}

void linha(int n)
{
	int i;
 	for(i=0; i<n; i++) // 0, 1, 2, 3
 	  putchar('#');
 	putchar('\n');
}

int main(void)
{
	int n=10;
	linha(n);
	for(int i=1; i<n-1; i++)
	  meio(n);
	linha(n);
	return 0;
}

