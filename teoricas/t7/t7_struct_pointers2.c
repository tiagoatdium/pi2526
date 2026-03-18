#include <stdio.h>

// nesta declaração criamos dois "nomes":
//   Ponto  -> a struct
//   pPonto -> apontador para essa struct
//
// importante: o '*' está associado ao nome (pPonto),
// ou seja, pPonto é equivalente a Ponto*
//
// isto tem implicações importantes nas declarações:
//
//   Ponto *a, b;
//     -> a é apontador para Ponto
//     -> b é um Ponto (não é apontador)
//
// porque o '*' aplica-se apenas à variável 'a'
//
// mas com typedef:
//
//   pPonto a, b;
//     -> a e b são ambos apontadores para Ponto
//
// pois o '*' já faz parte do tipo pPonto
//
// uma última nota:
//
//   pPonto *a, *b;
//     -> a e b são apontadores para pPonto
//     -> ou seja: Ponto ** (apontador para apontador)
//
// resumo:
//   Ponto *a, b;     -> mistura tipos ('a' é apontador e 'b' é Ponto)
//   pPonto a, b;     -> ambos apontadores
//   pPonto *a, *b;   -> apontadores para apontadores
//
typedef struct {
  int x;
  int y;
} Ponto, *pPonto;

// exercício: explore o seguinte formato de typedef "typedef int Inteiro, *pInteiro;"
// num ficheiro .c (crie um exemplo para observar como funciona).

int main(void)
{
  // inicialização direta
  Ponto p1 = {3, 5};

  // ptr é um apontador para Ponto
  // isto é equivalente a: Ponto *ptr;
  pPonto ptr;

  // ptr passa a apontar para p1
  ptr = &p1;

  // acesso via apontador
  // '->' é usado quando temos um apontador para struct
  printf("ler com 'ptr':\n");
  printf("  x = %d\n", ptr->x);
  printf("  y = %d\n", ptr->y);

  // equivalente usando desreferenciação explícita
  // (*ptr) significa: "o variável apontada por ptr"
  // depois usamos '.' para aceder aos campos
  printf("\nler com '(*ptr)':\n");
  printf("  x = %d\n", (*ptr).x);
  printf("  y = %d\n", (*ptr).y);

  // modificar via apontador altera a variável original
  ptr->x = 10;
  ptr->y = 20;

  printf("\napos modificar via apontador:\n");
  printf("  x = %d\n", p1.x);
  printf("  y = %d\n", p1.y);

  // ptr guarda o mesmo endereço que &p1
  printf("\nendereco p1 e valor de ptr = %p, %p\n",
         (void*)&p1, (void*)ptr);

  // comparação de endereços (1 = verdadeiro)
  printf("  sao iguais? %d\n", (void*)&p1 == ptr);

  return 0;
}
