// este ficheiro apenas contém comentários para as funções apresentadas no dia 21/04;
// consulte o ficheiro abin0.c para mais detalhes

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
  
  if (a == NULL) return NULL;  
  if (a->valor == x) return a;
  
  r = search_ex_r(x, a->esq);
  if (r == NULL) return search_ex_r(x, a->dir);
  
  return r;
}


// binary search tree; recursive
abin search_bst_r(int x, abin a)
{
  if (a == NULL) return NULL;
  if (a->valor == x) return a;
  
  if (a->valor > x) return search_bst_r(x, a->esq);
  else return search_bst_r(x, a->dir);
}

// binary search tree; iterative
abin search_bst_it(int x, abin a)
{
  while (a != NULL && a->valor != x)
  { 
    if (a->valor > x) a = a->esq;
    else a = a->dir;
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
  
  if (ant == NULL) a = new; // se ant. é NULL, ciclo nunca executou (o que implica que a == NULL)
  else if (ant->valor > x) ant->esq = new; // se ant é maior, então o novo fica à esquerda 
  else ant->dir = new; // senão fica à direita

  return a;
}

// ////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////

#include "dot.c"


int main(void)
{
  // TODO
  return 0;
}

