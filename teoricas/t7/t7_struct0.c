#include <stdio.h>

// struct: uma struct é um tipo de dados definido pelo
//         utilizador que permite agrupar várias
//         variáveis diferentes numa única estrutura.

// definição da estrutura (ainda sem typedef; como irá observar,
// é pouco conveniente pois é necessário escrever struct antes
// do nome da estrutura, neste caso Ponto; ver próximos exemplos,
// em concreto, t7_typedef.c e t7_struct1.c)

// definição da estrutura
struct Ponto
{
  int x;
  int y;
};

// função que soma dois pontos
struct Ponto somar_pontos(struct Ponto a, struct Ponto b)
{
  struct Ponto resultado;

  resultado.x = a.x + b.x;
  resultado.y = a.y + b.y;

  printf("endereço a (somar_pontos) = %p\n", (void*)&a);
  printf("endereço b (somar_pontos) = %p\n", (void*)&b);
  printf("endereço resultado (somar_pontos) = %p\n", (void*)&resultado);

  return resultado;
}

int main(void)
{
  struct Ponto p1;
  struct Ponto p2;
  struct Ponto p3;

  // atribuição de valores para inicializar p1
  p1.x = 3;
  p1.y = 5;

  // inicialização de p2
  p2.x = 2;
  p2.y = 1;

  //
  // de seguida, invoca-se a função somar pontos
  // - note que somar_pontos imprime os endereços das
  //   suas variáveis de tipo Ponto para que, posteriormente,
  //   possa comparar com os endereços de p1, p2, e p3, e assim
  //   observar que são criadas "cópias" -- o que motiva a utilização
  //   de apontadores, em particular no caso em que as struct contém
  //   muitos campos e o seu tamanho é "grande": em cenários onde
  //   a eficiência é crucial, devemos ter todos os aspectos em
  //   consideração, incluido cópias, pois incrementam o
  //   tempo de processamento consumo de memória
  //
  p3 = somar_pontos(p1, p2);

  // imprimir resultados: note que acedemos aos campos através com '.'
  // por exemplo: p1.x para obter o x correspondente.

  printf("\np1 = (%d, %d)\n", p1.x, p1.y);
  printf("p2 = (%d, %d)\n", p2.x, p2.y);
  printf("p3 = p1 + p2 = (%d, %d)\n\n", p3.x, p3.y);

  // de seguida, imprime-se o tamanho da estrutura (que consiste na
  // soma dos tamanhos dos seus elementos)
  printf("sizeof(struct Ponto) = %zu\n\n", sizeof(struct Ponto));

  // de seguida imprimem-se os endereços de p1, p2, e p3 (ver nota
  // anterior sobre a chamada à função somar_pontos
  printf("endereço p1 = %p\n", (void*)&p1);
  printf("endereço p2 = %p\n", (void*)&p2);
  printf("endereço p3 = %p\n", (void*)&p3);

  return 0;
}

