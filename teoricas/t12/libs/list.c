#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// list.c
//
// Implementação das funções declaradas em list.h.

LInt newLInt(int x, LInt prox)
{
  LInt novo = malloc(sizeof(struct llig));

  if(novo != NULL)
  {
    novo->valor = x;
    novo->prox = prox;
  }

  return novo;
}

void freeList(LInt l)
{
  LInt aux;

  while(l != NULL)
  {
    aux = l;
    l = l->prox;
    free(aux);
  }
}

int length(LInt l)
{
  int r = 0;

  while(l != NULL)
  {
    r++;
    l = l->prox;
  }

  return r;
}

void printList(LInt l)
{
  printf("[");

  while(l != NULL)
  {
    printf("%d", l->valor);

    if(l->prox != NULL)
    { printf(", "); }

    l = l->prox;
  }

  printf("]");
}

LInt pushFrontList(LInt l, int x)
{
  return newLInt(x, l);
}

int popFrontList(LInt *l, int *x)
{
  LInt aux;

  if(l == NULL || *l == NULL)
  { return 1; }

  aux = *l;

  if(x != NULL)
  { *x = aux->valor; }

  *l = aux->prox;
  free(aux);

  return 0;
}
