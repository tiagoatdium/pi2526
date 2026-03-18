#include <stdio.h>

// struct com typedef (tal como apresentado em t7_struct1.c)
typedef struct
{
  int x;
  int y;
} Ponto;

// o seguinte exemplo mostra que uma struct pode conter
// variáveis com tipo definido atráves de struct:
// 'PontoComOrigem' é composto por dois 'Ponto's
// o objectivo é demonstrar que é possível construir 
// structs mais complexas a partir de structs mais simples.
typedef struct
{
  Ponto p;        // o ponto principal
  Ponto origem;   // o ponto origem
} PontoComOrigem;

// função que soma dois pontos
Ponto somar_pontos(Ponto a, Ponto b)
{
  Ponto resultado;

  resultado.x = a.x + b.x;
  resultado.y = a.y + b.y;

  return resultado;
}

int main(void)
{

  // inicialização "directa" de structs
  // os valores dentro de { } são atribuídos aos campos pela ordem
  // em que foram declarados na struct:
  //
  //   typedef struct
  //   {
  //     int x;
  //     int y;
  //   } Ponto;
  //
  // assim:
  //   {3, 5}  →  x = 3, y = 5
  //   {2, 1}  →  x = 2, y = 1
  //
  // é equivalente a:
  //
  //   Ponto p1;
  //   p1.x = 3;
  //   p1.y = 5;

  Ponto p1 = {3, 5};
  Ponto p2 = {2, 1};
  PontoComOrigem pc;
  Ponto soma;

  pc.p = p1;
  pc.origem = p2;

  // somar os dois pontos
  soma = somar_pontos(pc.p, pc.origem);

  // note, no exemplo seguinte, o acesso encadeado a campos (uso de
  // "." várias vezes)
  //
  // quando uma struct contém outra struct, usamos "." para aceder
  // sucessivamente aos campos internos.
  //
  // pc é uma variável do tipo PontoComOrigem:
  //
  //   pc.p        -> acede a 'p', que tem o tipo Ponto
  //   pc.p.x      -> acede a 'x', que está dentro de 'p', que está dentro de 'pc'
  //
  //   pc.origem   -> acede a 'origem', que tem o tipo Ponto
  //   pc.origem.y -> acede a 'y', que está dentro de 'origem', que está dentro de 'pc'
  //
  // intuitivamente: cada "." “entra” mais um nível dentro da estrutura.

  printf("pc.p = (%d, %d)\n", pc.p.x, pc.p.y);
  printf("pc.origem = (%d, %d)\n", pc.origem.x, pc.origem.y);
  printf("soma = (%d, %d)\n\n", soma.x, soma.y);


  // recorde que sizeof devolve o número de bytes que um tipo ocupa
  //
  // Ponto -> tamanho de um ponto (2 inteiros, tipicamente 4+4)
  // PontoComOrigem -> contém duas variáveis com o tipo 'Ponto' (tipicamente, 8+8)
  //   - o tamanho em concreto é precedido da palavra "tipicamente", pois, tal
  //     como referido em aulas anteriores, é frequente o caso em que um 'int'
  //     tem tamanho '4'

  // também convém explicar agora, que sizeof(Tipo) pode ser, efectivamente, 
  // superior à soma dos seus tamanhos individuais: ver exemplo extra (t7_struct_sizeof.c)
  printf("sizeof(Ponto) = %zu\n", sizeof(Ponto));
  printf("sizeof(PontoComOrigem) = %zu\n\n", sizeof(PontoComOrigem));

  printf("endereço pc = %p\n", (void*)&pc);
  printf("endereço pc.p = %p\n", (void*)&pc.p);
  printf("endereço pc.origem = %p\n", (void*)&pc.origem);

  return 0;
}
