// return by reference (pointer of pointers in some cases if you will)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct abin_no {
  int valor;
  struct abin_no *esq;
  struct abin_no *dir;
} *abin;

// ////////////////////////////////////////////////////////////////////////////

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

void mkroot_ref(int x, abin e, abin d, abin *r)
{
  abin new = malloc(sizeof(struct abin_no));
  if(new == NULL)
  { *r = NULL; return; }

  new->valor = x;
  new->esq = e;
  new->dir = d;

  *r = new;
}

// ////////////////////////////////////////////////////////////////////////////

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
  // nota: o que acontece se o malloc de mkroot falhar? 
  // em deployments reais, deve existir código de tratamento
  // de erros (tais como falhas na alocação de memória).
}

void fromArrayBalanced_ref(int v[], int N, abin *r)
{
  abin esq, dir;
  int meio;
  if(N == 0)
  { *r = NULL; return; }
  meio = N / 2;
  fromArrayBalanced_ref(v, meio, &esq);
  fromArrayBalanced_ref(v + meio + 1, N - meio - 1, &dir);
  mkroot_ref(v[meio], esq, dir, r);
  
  // o mesmo comentário da função anterior
}

// ////////////////////////////////////////////////////////////////////////////

int size(abin a)
{
  if(a == NULL)
  { return 0; }

  return 1 + size(a->esq) + size(a->dir);
}

void size_ref(abin a, int *r)
{
  int n_esq, n_dir;

  if(a == NULL)
  { *r = 0; return; }

  size_ref(a->esq, &n_esq);
  size_ref(a->dir, &n_dir);

  *r = 1 + n_esq + n_dir;
}

// ////////////////////////////////////////////////////////////////////////////

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

void depth_ref(abin a, int *r)
{
  int p_esq, p_dir;

  if(a == NULL)
  { *r = 0; return; }

  depth_ref(a->esq, &p_esq);
  depth_ref(a->dir, &p_dir);

  if(p_esq > p_dir)
  { *r = 1 + p_esq; }
  else
  { *r = 1 + p_dir; }
}

// ////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	abin a = ...
	... 
	a = free_abin(a);
	
}
*/

abin free_abin(abin a)
{
  if(a == NULL)
  { return NULL; }

  free_abin(a->esq);
  free_abin(a->dir);
  free(a);
  return NULL;
}

void free_abin_ref(abin *a)
{
  if(a == NULL || *a == NULL)
  { return; }

  free_abin_ref(&((*a)->esq));
  // porquê '&((*a)->esq)':
  //  a->esq (não funciona porque 'a' é 'abin *' e não 'abin' 
  // '(*a)' já é 'abin'; como tal: (*a)->esq :: abin 
  // como a função recebe 'abin *', então &((*a)->esq)
  
  free_abin_ref(&((*a)->dir));

  free(*a);
  *a = NULL;
}

// ////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////

#include "dot.c"

void t1_non_ref(void)
{
  int v[] = {10, 20, 30, 40,   50, 60, 70, 80,   90};
  int N = 9;

  // non ref
  abin arv1 = NULL;
  int size_arv1, depth_arv1;
  
  arv1 = fromArrayBalanced(v, N);
  size_arv1 = size(arv1);
  depth_arv1 = depth(arv1);

  printf("Versão não ref(erence):\n");
  printf("  size  = %d\n", size_arv1);
  printf("  depth = %d\n", depth_arv1);
  
  arv1 = free_abin(arv1);
}

void t2_ref(void)
{
  int v[] = {10, 20, 30, 40,   50, 60, 70, 80,   90};
  int N = 9;

  // non ref
  abin arv1 = NULL;
  int size_arv1, depth_arv1;
  
  fromArrayBalanced_ref(v, N, &arv1);
  size_ref(arv1, &size_arv1);
  depth_ref(arv1, &depth_arv1);

  printf("Versão ref(erence):\n");
  printf("  size  = %d\n", size_arv1);
  printf("  depth = %d\n", depth_arv1);
  
  free_abin_ref(&arv1);
}

int main(void)
{
	t1_non_ref();
	t2_ref();
  return 0;
}
