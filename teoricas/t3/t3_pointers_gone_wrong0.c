// para evitar que o compilador denuncie logo à partida o problema, compilar com
// $ gcc -o t3_pointers_gone_wrong0 t3_pointers_gone_wrong0.c 

#include <stdio.h>

static int* f1(int a, int b)
{
	int r;
	r = a + b;
	return &r; // undefined behavior... (usar opção -fsanitize=undefined)
}

static int f2(int a, int b)
{
	int c; // podia ser 'r' mas escrevemos 'c' para evitar confusões
	c = a + b;
	return c;
}

int main()
{
	int a, b, c;
	int *p;
	
	a = 10;
	b = 20;
	
	p = f1(a,b);
	printf("f1 res=%d\n", *p); // será que funciona?

	c = f2(a,b);
	printf("f2 res=%d\n", c);
	
	printf("f1 res after f2=%d\n", *p);

	return 0;
}
