#include <stdio.h>

// exemplo de struct com auto-referência (self-reference)
//
// uma struct pode conter um apontador para outra struct do mesmo tipo,
// permitindo criar ligações entre variáveis (ex: listas, árvores, etc.).
//
// para isso, é necessário dar um nome à struct logo no início ("struct ponto"),
// pois esse nome será usado dentro da própria definição.

typedef struct ponto
{
  int x;
  int y;

  // apontador para outro ponto
  // isto cria uma ligação para outra variável com o mesmo tipo
  //
  // experimente remover o '*' e compilar, por exemplo:
  //   struct ponto origem;
  //
  // reflexão: se fosse possível a struct ficaria com tamanho infinito
  // o erro emitido pelo compilador deverá ser uma mensagem semelhante à
  // seguinte:
  //   t7_struct_self.c:LINE_NUMBER:COLUMN_NUMBER: error: field ‘origem’ has incomplete type
   //
  // a intuição sobre o erro: como a struct ainda não está totalmente definida 
  // neste ponto, o compilador não conhece o seu tamanho e características. 
  struct ponto *origem;

} Ponto;

int main(void)
{
  Ponto p1;
  Ponto p2;

  // inicializar p1 (sem origem)
  p1.x = 1;
  p1.y = 2;
  p1.origem = NULL; // NULL indica um apontador nulo (ou a ausência 
                    // de ligação a outro ponto se preferir)

  // inicializar p2 com origem em p1
  p2.x = 3;
  p2.y = 4;
  p2.origem = &p1; // '&p1' é o endereço de p1

  // imprimir p2
  printf("p2 = (%d, %d)\n", p2.x, p2.y);

  // imprimir origem de p2
  if (p2.origem != NULL)
  {
    // NOTA1: como 'origem' é um apontador, usamos '->' em vez de '.'
    // NOTA2: p2.origem->x é equivalente a (*p2.origem).x
    printf("p2.origem = (%d, %d)\n",
           p2.origem->x,
           p2.origem->y);

    printf("p2.origem = (%d, %d)\n",
           (*p2.origem).x,
           (*p2.origem).y);

  }

  return 0;
}
