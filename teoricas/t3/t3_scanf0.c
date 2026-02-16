// nota: em princípio deverá observar os seguintes warnings:
//
// t3_scanf0.c: In function ‘main’:
// t3_scanf0.c:29:9: warning: ignoring return value of ‘scanf’ declared with attribute ‘warn_unused_result’ [-Wunused-result]
// 	 29 |         scanf("%d", ap);
// 	    |         ^~~~~~~~~~~~~~~
// t3_scanf0.c:30:9: warning: ignoring return value of ‘scanf’ declared with attribute ‘warn_unused_result’ [-Wunused-result]
// 	 30 |         scanf("%d", bp);
// 	    |         ^~~~~~~~~~~~~~~
// t3_scanf0.c:31:9: warning: ignoring return value of ‘scanf’ declared with attribute ‘warn_unused_result’ [-Wunused-result]
// 	 31 |         scanf("%d", cp);
//
// o warning indica:
// - ignoring return value of ‘scanf’
//
// porque a função scanf retorna (de forma simples --- consultar man 3 scanf para mais detalhes) o número de "items" lidos com sucesso

#include <stdio.h>

int main(void)
{
  int a, b, c;
  int *ap, *bp, *cp;

	ap = &a;
	bp = &b;
	cp = &c;

	scanf("%d", &a);
	scanf("%d", bp);
	scanf("%d", cp);

  printf("a=%d ", a);
  printf("b=%d ", b);
  printf("c=%d\n", c);

  return 0;
}
