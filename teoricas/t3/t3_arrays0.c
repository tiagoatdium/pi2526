#include <stdio.h>

int main(void)
{
	int i;
	int n[5];

  for (i=0; i<5; i++)
  { n[i] = i; }

	// print the array
	printf("n = ");
  for (i=0; i<5; i++)
  { printf("%d ", n[i]); }
  printf("\n");
  
  printf("n[0] = %d\n", n[0]);
  printf("n[1] = %d\n", n[1]);  
  printf("n[5] = %d\n", n[4]); // substitua 4 por 5: tem problema !?

	////////////////////////////
	int *a = n;

	printf("a = ");
  for (i=0; i<5; i++)
  { printf("%d ", a[i]); }
  printf("\n");

	a += 1;
  printf("a[0] after +1 = %d\n", a[0]);
  
 	a += 2;
  printf("a[0] after +1+2 = %d\n", a[0]);
  
  a -= 3;
  *(a + 4) = 10;
  printf("n[4] = %d\n", n[4]);
  
  printf("%zu == %zu * 5\n", sizeof(n), sizeof(n[0]) );
  printf("length = %zu / %zu = %zu\n", sizeof(n), sizeof(n[0]), sizeof(n) / sizeof(n[0]));

  return 0;
}
