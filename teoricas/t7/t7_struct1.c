#include <stdio.h>

// com a seguinte forma de declaração evitamos ter de escrever
// "struct Ponto" sempre que queremos utilizar um Ponto (ler
// t7_struct0.c);
//
// apesar da seguinte declaração de Ponto estar escrita em
// multiplas linhas, poderia também ser escrita da seguinte
// forma, obtendo-se igual efeito:
//
//   typedef struct { int x; int y; } Ponto;
//
// de forma análoga ao exemplo de 'typedef int Idade' (ler
// t7_typedef.c), em que sempre que escrevemos 'Idade',
// estamos, na prática, a utilizar um 'int', aqui, sempre
// que escrevemos 'Ponto', estamos a utilizar a definição
// da struct correspondente.
//
// note também o seguinte pormenor: em t7_struct0.c, usamos
// a seguinte declaração:
//
//   struct Ponto { int x; int y; };
//
// note que entre 'struct' e '{' existia um nome (Ponto) que
// entretanto foi removido neste exemplo (pois neste exemplo
// não é necessário):
//
//   struct { int x; int y; }
//
// tipicamente esse nome é necessário quando precisamos de
// referenciar a struct dentro da própria struct (mais à frente,
// no exemplo, t7_struct_self.c).
//
// todavia, poder-se-ia declarar também da seguinte forma (mas
// para o exemplo deste ficheiro, este nome não é muito útil,
// e, como tal, removeu-se).
//
//   typedef struct ponto { int x; int y; } Ponto;
//
// note também que nada impede que seja utilizado o mesmo nome,
// por exemplo:
//
//   typedef struct Ponto { int x; int y; } Ponto;
//
// este tipo de decisão depende do estilo ou das convenções
// de código utilizadas em cada projecto/organização/empresa.

typedef struct
{
 int x;
 int y;
} Ponto;

// função que soma dois pontos
Ponto somar_pontos(Ponto p1, Ponto p2)
{
  Ponto resultado;

  resultado.x = p1.x + p2.x;
  resultado.y = p1.y + p2.y;

  printf("endereço p1 (somar_pontos) = %p\n", (void*)&p1);
  printf("endereço p2 (somar_pontos) = %p\n", (void*)&p2);
  printf("endereço resultado (somar_pontos) = %p\n", (void*)&resultado);

  return resultado;
}

int main(void)
{
  Ponto p1;
  Ponto p2;
  Ponto p3;

  p1.x = 3; p1.y = 5;
  p2.x = 2; p2.y = 1;

  p3 = somar_pontos(p1, p2);

  printf("p1 = (%d, %d)\n", p1.x, p1.y);
  printf("p2 = (%d, %d)\n", p2.x, p2.y);
  printf("p3 = p1 + p2 = (%d, %d)\n\n", p3.x, p3.y);

  printf("sizeof(Ponto) = %zu\n\n", sizeof(Ponto));

  printf("endereço p1 (main) = %p\n", (void*)&p1);
  printf("endereço p2 (main) = %p\n", (void*)&p2);
  printf("endereço p3 (main) = %p\n", (void*)&p3);

  return 0;
}
