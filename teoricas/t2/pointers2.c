#include <stdio.h>
#include <stdlib.h>

// nota: em relação à impressão de apontadores, ler as notas correspondentes
// no início do ficheiro pointers1.c (relativamente à utilização de '(void *)'

// a seguinte função soma recebe 3 argumentos:
// - um apontador para um inteiro ('rp'): onde o resultado da computação (soma)
//   será colocado
//
// - dois inteiros 'a' e 'b' para serem somados
void soma(int *rp, int a, int b)
{
  // para efeitos ilustrativos, sempre que a função é executada, vamos imprimir
  // os seus argumentos
  printf("soma: rp=%p a=%d b=%d\n", (void*)rp, a, b);
  
  // o seguinte statement pode-se ler da seguinte forma: o valor apontado por 'rp'
  // (*rp) será igual à soma de 'a' e 'b' (a+b)
  *rp = a + b;
}

int main(void)
{
  int r = 0, a, b;
  int *rp;
  
  rp = &r; // 'rp' passa a conter o endereço de 'r' (&r) -- "onde 'r' está na memória"
  a = 10;  // a variável 'a' é inicializada com o valor 10
  b = 20;  // a variável 'b' é inicializada com o valor 20
  
  // antes de invocar a função soma, vamos imprimir o estado actual das variáveis
  printf("main: rp=%p r=%d a=%d b=%d\n", (void*)rp, r, a, b);
  
  soma(rp, a, b); // A função 'soma' recebe o apontador para 'r' (rp), a e b;
                  // A função 'soma' calcula a soma entre 'a' e 'b' e coloca
                  // o resultado em 'r' (via 'rp')
  
  // observe e compare o resultado deste "print" com o anterior (apenas 'r'
  // muda -- o que é o esperado)
  printf("main: rp=%p r=%d a=%d b=%d\n", (void*)rp, r, a, b);

  // vamos chamar a função de uma forma ligeiramente diferente (tal como
  // mostrado no "running example durante a aula") para efeitos ilustrativos
  //
  // repare nos valores impressos pela função soma (em particular o valor do
  // endereço que deverá ser o mesmo)
  soma(&r, 30, 20);

  // e um último printf para observarmos que o valor da variável 'r' foi
  // alterado
  printf("main: r=%d\n", r);


  // e uma última experiência: (experimente algumas variações para entender
  // bem o que é um apontador)
  a = 10;
  soma(&a, a, a);
  printf("main: a=%d\n", a);
  
  return 0;
}
