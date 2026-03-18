#include <stdio.h>

// struct simples que representa um ponto
typedef struct {
  int x;
  int y;
} Ponto;

int main(void)
{
  // inicialização direta (x = 3, y = 5)
  Ponto p1 = {3, 5};

  // apontador para Ponto
  Ponto *ptr;

  // ptr guarda o endereço de p1
  ptr = &p1;

  // aceder via apontador
  // '->' é usado quando temos um apontador para struct
  printf("ler com 'ptr':\n");
  printf("  x = %d\n", ptr->x);
  printf("  y = %d\n", ptr->y);

  // equivalente usando desreferenciação
  // (*ptr) é a variável apontada; depois usa-se '.'
  printf("\nler com '(*ptr)':\n");
  printf("  x = %d\n", (*ptr).x);
  printf("  y = %d\n", (*ptr).y);

  // modificar através do apontador altera a variável "original"
  ptr->x = 10;
  ptr->y = 20;

  printf("\napos modificar via apontador:\n");
  printf("  x = %d\n", p1.x);
  printf("  y = %d\n", p1.y);

  // ptr guarda exatamente o mesmo endereço que &p1
  printf("\nendereço p1 e valor de ptr = %p, %p\n",
         (void*)&p1, (void*)ptr);

  // comparação de endereços (1 = verdadeiro)
  printf("  sao iguais? %d\n", (void*)&p1 == ptr);

  return 0;
}
