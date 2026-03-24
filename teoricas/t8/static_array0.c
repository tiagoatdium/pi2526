#include <stdio.h>

//
// Motivação:
//
// Antes de estudar alocação dinâmica de memória (malloc, calloc,
// realloc), vamos recordar como funcionam os arrays "normais"
// (os utilizados até agora) em C.
//
// Neste ficheiro usamos um array local, com tamanho fixo,
// declarado dentro da função main:
//
//   int v[TAMANHO];
//
// Este tipo de array:
//
// - tem tamanho definido no código
//
// - ocupa memória automática (normalmente chamada "stack")
//
// - existe apenas enquanto a função onde foi declarado estiver
//   a executar
//
// A ideia é usar este exemplo como ponto de partida:
// mais à frente, vamos comparar este array fixo com arrays
// criados dinamicamente, cujo tamanho pode ser decidido
// durante a execução do programa.




// A seguinte função preenche o array com valores "simples",
// apenas para termos dados para observar e imprimir.
void preencher_array(int v[], int n)
{
  int i;

  for(i = 0; i < n; i++)
  { v[i] = i; }
}




// A seguinte função imprime os elementos do array
void imprimir_array(int v[], int n)
{
  int i;

  for(i = 0; i < n; i++)
  { printf("%d ", v[i]); }
  printf("\n");
}




//
// Na seguinte função (main) declaramos um array local com tamanho fixo:
//
// - este tamanho é conhecido à partida e não pode ser alterado
//   depois da declaração.
//
// - esta é uma das limitações dos arrays "normais" (os que 
//   utilizamos até agora):
//    - se quisermos um tamanho, por exemplo, escolhido pelo
//      utilizador então teremos de recorrer a alocação dinâmica
//      de memória
//
// Nota:
//
// - em C também existem VLAs (Variable Length Arrays), isto é,
//   arrays locais cujo tamanho pode depender de uma variável
//   (ver ficheiro t5/t5_matrix_VLA_C99.c)
//
// - no entanto, os VLAs não fazem parte do C90; foram introduzidos
//   no C99 e, em versões posteriores da norma, o seu suporte pode 
//   não ser obrigatório, pelo que podem trazer problemas de 
//   compatibilidade/portabilidade entre compiladores
//
// - além disso, mesmo quando usamos um VLA, continuamos a ter
//   um array local com tempo de vida automático:
//   não foi criado com malloc e deixa de existir quando a função
//   termina
//
// - adicionalmente, considere consultar o seguinte link: 
//    - https://lkml.org/lkml/2018/3/7/621
//   e verifique os comentários do autor sobre a utilização de VLAs
//

#define TAMANHO 5

int main(void)
{
  int v[TAMANHO];

  preencher_array(v, TAMANHO);
  imprimir_array(v, TAMANHO);

  return 0;
}
