#include <stdio.h>

void print5(char*s, int*n)
{ printf("%s: ", s);
	for(int i=0;i<5;i++)
	{ printf("%d ", n[i]); }
	printf("\n");
}

int main(void)
{
	int n0[5];               // not initialized (depends on compiler and flags if it is zeroized or not)
	int n1[5] = {0,1,2,3,4}; // full array initialization
	int n2[]  = {5,6,7,8,9}; // full array init but you let the compiler do the counting
	int n3[5] = {0,1,2};     // partial array init (remaining values will be initialized as zero)
	int n4[5] = {0};         // partial array init (in practice all values will be zero)
	
	print5("n0", n0);
	print5("n1", n1);
	print5("n2", n2);
	print5("n3", n3);
	print5("n4", n4);

	return 0;
}
