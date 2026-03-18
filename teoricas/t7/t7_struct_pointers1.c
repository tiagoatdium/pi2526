#include <stdio.h>

typedef struct {
  int x;
  int y;
} Ponto;

// pPonto é correponde agora a "Ponto *"
typedef Ponto* pPonto;

int main(void)
{
  // inicialização direta
  Ponto p1 = {3, 5};

  // ptr é um apontador para Ponto, equivalente a escrever Ponto *ptr;
  pPonto ptr;

  // ptr passa a apontar para p1
  ptr = &p1;

  // acesso via apontador
  // '->' é usado quando temos um apontador para struct
  printf("ler com 'ptr':\n");
  printf("  x = %d\n", ptr->x);
  printf("  y = %d\n", ptr->y);

  // equivalente usando desreferenciação explícita
  // (*ptr) é a variável; depois usa-se '.'
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
