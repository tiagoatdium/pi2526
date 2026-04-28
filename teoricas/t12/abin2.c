#include <stdio.h>
#include <stdlib.h>

typedef struct abin_no {
  int valor;
  struct abin_no *esq;
  struct abin_no *dir;
} *abin;

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

int size(abin a)
{
  if(a == NULL)
  { return 0; }

  return 1 + size(a->esq) + size(a->dir);
}

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

abin free_abin(abin a)
{
  if(a == NULL)
  { return NULL; }

  free_abin(a->esq);
  free_abin(a->dir);
  free(a);
  return NULL;
}

// ////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////

// exhaustive search; recursive
abin search_ex_r(int x, abin a)
{
  abin r;

  if(a == NULL)
    return NULL;

  if(a->valor == x)
    return a;

  r = search_ex_r(x, a->esq);
  if(r == NULL)
    return search_ex_r(x, a->dir);

  return r;
}

// binary search tree; recursive
abin search_bst_r(int x, abin a)
{
  if(a == NULL)
    return NULL;

  if(a->valor == x)
    return a;

  if(a->valor > x)
    return search_bst_r(x, a->esq);
  else
    return search_bst_r(x, a->dir);
}

// binary search tree; iterative
abin search_bst_it(int x, abin a)
{
  while(a != NULL && a->valor != x)
  {
    if(x < a->valor)
      a = a->esq;
    else
      a = a->dir;
  }

  return a;
}

// ////////////////////////////////////////////////////////////////////////////

abin insert(int x, abin a)
{
  abin ant = NULL;
  abin aux = a;
  abin new;

  while(aux != NULL)
  {
    ant = aux;
    if(aux->valor == x) return a;

    if(aux->valor > x)
      aux = aux->esq;
    else
      aux = aux->dir;
  }

  new = mkroot(x, NULL, NULL);

  if(ant == NULL) // prev. vazia (se ant é NULL então não entrou no ciclo)
    a = new;
  else if(ant->valor > x)
    ant->esq = new;
  else
    ant->dir = new;

  return a;
}

// ////////////////////////////////////////////////////////////////////////////
// remoção em BST
//
// casos:
// 1) nó folha
// 2) nó com um filho
// 3) nó com dois filhos
//
// no caso 3, substituímos pelo menor valor da subárvore direita
// ////////////////////////////////////////////////////////////////////////////

int min_bst(abin a)
{
  while(a->esq != NULL)
  { a = a->esq; }

  return a->valor;
}

abin remove_bst(int x, abin a)
{
  int m;
  abin aux;

  if(a == NULL)
  { return NULL; }

  if(x < a->valor)
  { a->esq = remove_bst(x, a->esq);
    return a;
  }

  if(x > a->valor)
  { a->dir = remove_bst(x, a->dir);
    return a;
  }

  // "chegámos" ao nó a remover

  // caso 1: folha
  if(a->esq == NULL && a->dir == NULL)
  {
    free(a);
    return NULL;
  }

  // caso 2a: só tem filho à direita
  if(a->esq == NULL)
  {
    aux = a->dir;
    free(a);
    return aux;
  }

  // caso 2b: só tem filho à esquerda
  if(a->dir == NULL)
  {
    aux = a->esq;
    free(a);
    return aux;
  }

  // caso 3: nó com dois filhos
	//
	// Substituímos o valor deste nó pelo menor valor da subárvore direita.
	// Esse valor é o "sucessor" do nó atual: é o próximo valor por ordem.
	//
	// Depois removemos esse valor da subárvore direita, porque ele foi
	// copiado para a raiz desta subárvore.
  m = min_bst(a->dir);
  a->valor = m;
  a->dir = remove_bst(m, a->dir);

  return a;
}

// ////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////

#include "dot.c"

#if 0
 árvore de teste:

           50
         /    \
       30      70
      /  \    /  \
    20   40  60   80
         /      \
        35      65
#endif

void imprimeArvoreAux(abin a, int espacos)
{
  int i;

  if(a == NULL)
  { return; }
  imprimeArvoreAux(a->dir, espacos + 4);
  for(i = 0; i < espacos; i++)
  { printf(" "); }
  printf("%d\n", a->valor);
  imprimeArvoreAux(a->esq, espacos + 4);
}

void imprimeArvore(abin a)
{
  if(a == NULL)
  { printf("(arvore vazia)\n"); }
  else
  { imprimeArvoreAux(a, 0); }
}

abin mk_test_bst(void)
{
  int v[] = {50, 30, 70, 20,  40, 60, 80, 35,  65};
  int i;
  int N = 9;
  abin a = NULL;

  for(i = 0; i < N; i++)
  { a = insert(v[i], a); }

  return a;
}




void test_remove_leaf(void)
{
  abin a = mk_test_bst();

	printf("================================");
  printf("\nTeste 1: remover folha (20)\n");
  printf("  antes: size = %d, depth = %d\n", size(a), depth(a));
  exportDOT(a, "remove_leaf_before.dot");

  a = remove_bst(20, a); // remover o 20

  printf("  depois: size = %d, depth = %d\n", size(a), depth(a));
  exportDOT(a, "remove_leaf_after.dot");
  printf("\n");

  a = free_abin(a);
}

void test_remove_one_child(void)
{
  abin a = mk_test_bst();

	printf("================================");
  printf("\nTeste 2: remover nó com um filho (40)\n");
  printf("  antes: size = %d, depth = %d\n", size(a), depth(a));
  exportDOT(a, "remove_one_child_before.dot");

  a = remove_bst(40, a);

  printf("  depois: size = %d, depth = %d\n", size(a), depth(a));
  exportDOT(a, "remove_one_child_after.dot");
  printf("\n");

  a = free_abin(a);
}

void test_remove_two_children(void)
{
  abin a = mk_test_bst();

	printf("================================");
  printf("\nTeste 3: remover nó com dois filhos (70)\n");
  printf("  antes: size = %d, depth = %d\n", size(a), depth(a));
  exportDOT(a, "remove_two_children_before.dot");

  a = remove_bst(70, a);

  printf("  depois: size = %d, depth = %d\n", size(a), depth(a));
  exportDOT(a, "remove_two_children_after.dot");
  printf("\n");

  a = free_abin(a);
}

void test_remove_root(void)
{
  abin a = mk_test_bst();

	printf("================================");
  printf("\nTeste 4: remover a raiz (50)\n");
  printf("  antes: size = %d, depth = %d\n", size(a), depth(a));
  exportDOT(a, "remove_root_before.dot");

	imprimeArvore(a);	
  a = remove_bst(50, a);

  printf("  depois: size = %d, depth = %d\n", size(a), depth(a));
  exportDOT(a, "remove_root_after.dot");
  printf("\n");

	imprimeArvore(a);
  a = free_abin(a);
}

void test_remove_missing(void)
{
  abin a = mk_test_bst();

	printf("================================");
  printf("\nTeste 5: remover valor inexistente (999)\n");
  printf("  antes: size = %d, depth = %d\n", size(a), depth(a));
  exportDOT(a, "remove_missing_before.dot");

  a = remove_bst(999, a);

  printf("  depois: size = %d, depth = %d\n", size(a), depth(a));
  exportDOT(a, "remove_missing_after.dot");
  printf("\n");

  a = free_abin(a);
}

int main(void)
{
  test_remove_leaf();
  test_remove_one_child();
  test_remove_two_children();
  test_remove_root();
  test_remove_missing();

  return 0;
}
