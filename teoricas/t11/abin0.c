#include <stdio.h>
#include <stdlib.h>

// Uma árvore binária é uma estrutura de dados em que cada nó pode ter
// (até) dois "filhos": um à esquerda e outro à direita.
//
// Ao contrário das listas ligadas, que avançam sempre numa única direcção,
// as árvores permitem organizar a informação de forma hierárquica.
//
// As árvores aparecem em muitos contextos:
// - sistemas de ficheiros e pastas
// - expressão aritméticas
// - dicionários e tabelas de pesquisa
// - estruturas internas de compiladores e bases de dados
//
// Uma das grandes vantagens das árvores é que várias operações podem ser
// feitas de forma mais eficiente do que em listas ligadas, desde que a
// árvore esteja razoavelmente equilibrada. Por exemplo, procurar um valor
// pode obrigar a visitar muito menos nós.
//
// Além disso, as árvores são um excelente exemplo de estrutura recursiva:
// cada árvore é formada por uma raiz e por duas subárvores, que são também
// elas árvores. Por isso, muitas funções sobre árvores escrevem-se de forma
// natural com recursão.

// Árvore binária: cada nó guarda um valor e dois apontadores,
// um para a subárvore esquerda e outro para a subárvore direita.
typedef struct abin_no {
  int valor;
  struct abin_no *esq;
  struct abin_no *dir;
} *abin;

// Cria uma nova raiz com valor x e com as subárvores 'e' e 'd'.
abin mkroot(int x, abin e, abin d)
{
  abin new = malloc(sizeof(struct abin_no));
  if(new == NULL)
  { return NULL; }

  new->valor = x;
  new->esq = e;
  new->dir = d;
  return new;
}

#if 0
 Constrói uma árvore (para a esquerda).

 Exemplo para v = [10, 20, 30, 40]:

           40
          /  \
         30  NULL
        /  \
       20  NULL
      /  \
     10  NULL
    /  \
 NULL  NULL

 Esta versão é útil para contrastar com a construção balanceada.

#endif

abin fromArrayLeft(int v[], int N)
{
  int i;
  abin a = NULL;

  for(i = 0; i < N; i++)
  { a = mkroot(v[i], a, NULL); }

  return a;
}


// ////////////////////////////////////////////////////////////////////////////


// propostas de exercícios:
// - implemente e teste a função fromArrayRight
// - implemente uma versão da função fromArrayLeft mas na ordem inversa (no exemplo anterior, primeiro nó é 10)



// A seguinte função constrói uma árvore balanceada ("começa" no elemento do meio),
// utilizaremos arrays ordenados
//
// A ideia é:
// - o elemento do meio fica na raiz
// - a metade esquerda do array fica na subárvore esquerda
// - a metade direita do array fica na subárvore direita
//
// Esta função produz uma árvore equilibrada em forma.
//
abin fromArrayBalanced(int v[], int N)
{
  abin a, esq, dir;
  int meio;

  if(N == 0)
  { return NULL; }

  meio = N / 2;

  esq = fromArrayBalanced(v, meio);
  dir = fromArrayBalanced(v + meio + 1, N - meio - 1);

  a = mkroot(v[meio], esq, dir);

  return a;
}


// ////////////////////////////////////////////////////////////////////////////


// A seguinte função calcula o número de elementos (nós) de uma árvore
int size(abin a)
{
  if(a == NULL)
  { return 0; }

  return 1 + size(a->esq) + size(a->dir);
}



//
// A seguinte função calcula a profundidade máxima da árvore.
//
// Algumas notas:
// - uma árvore vazia tem profundidade 0
// - árvore com um único nó tem profundidade 1
//
/*
   - profundidade 4:

               40
              /  \
             30  NULL
            /  \
           20  NULL
          /  \
         10  NULL
        /  \
     NULL  NULL
*/

int depth(abin a)
{
  int p_esq;
  int p_dir;

  if(a == NULL)
  { return 0; }

  p_esq = depth(a->esq);
  p_dir = depth(a->dir);

  if(p_esq > p_dir)
  { return 1 + p_esq; }
  else
  { return 1 + p_dir; }
}


// ////////////////////////////////////////////////////////////////////////////

// print in order: esquerda, raiz, direita.
void print_in_order(abin a)
{
  if(a == NULL)
  { return; }

  print_in_order(a->esq);
  printf("%d ", a->valor);
  print_in_order(a->dir);
  
  return;
}

// print pre order: raiz, esquerda, direita.
void print_pre_order(abin a)
{
  if(a == NULL)
  { return; }
  
  printf("%d ", a->valor);
  print_pre_order(a->esq);
  print_pre_order(a->dir);
}

// Percurso post order: esquerda, direita, raiz.
void print_post_order(abin a)
{
  if(a == NULL)
  { return; }

  print_post_order(a->esq);
  print_post_order(a->dir);
  printf("%d ", a->valor);
}


// ////////////////////////////////////////////////////////////////////////////

// liberta toda a memória ocupada pela árvore.
void free_abin(abin a)
{
  if(a == NULL)
  { return; }

  free_abin(a->esq);
  free_abin(a->dir);
  free(a);
}


// ////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////

#include "dot.c"

void test_fromArrayLeft(void)
{
  int v[] = {10, 20, 30, 40};
  int N = 4;
  abin arv = fromArrayLeft(v, N);
  exportDOT(arv, "from_array_left.dot");

  free_abin(arv);
}



void test_fromArrayBalanced(void)
{
  int v[] = {10, 20, 30, 40, 50, 60, 70, 80};
  int N = 8;
  abin arv = fromArrayBalanced(v, N);
  exportDOT(arv, "from_array_balanced.dot");

  free_abin(arv);
}



void test_size_depth(void)
{
  int v[] = {10, 20, 30, 40, 50};
  int N = 5;

  abin arv1 = fromArrayBalanced(v, N);
  abin arv2 = fromArrayLeft(v, N);

  printf("test_size_depth: arv1: size: %d (expected value: %d)\n", size(arv1), N);
  printf("test_size_depth: arv2: size: %d (expected value: %d)\n", size(arv2), N);

  printf("test_size_depth: arv1: depth: %d (expected value: %d)\n", depth(arv1), 3);
  printf("test_size_depth: arv2: depth: %d (expected value: %d)\n", depth(arv2), 5);

  exportDOT(arv1, "size_depth_balanced.dot");
  exportDOT(arv2, "size_depth_left.dot");

  free_abin(arv1);
  free_abin(arv2);
}


void test_print_order(void)
{
  int v[] = {10, 20, 30, 40, 50, 60};
  int N = 6;
  abin arv1 = fromArrayBalanced(v, N);

  puts("in_order: "); print_in_order(arv1); putchar('\n');
  puts("pre_order: "); print_pre_order(arv1); putchar('\n');
  puts("post_order: "); print_post_order(arv1); putchar('\n');

  exportDOT(arv1, "print_order.dot");
  free_abin(arv1);
}

int main(void)
{
  test_fromArrayLeft();
  test_fromArrayBalanced();
  test_size_depth();
  test_print_order();
  return 0;
}

