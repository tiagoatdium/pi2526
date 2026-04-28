#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// queue.c
//
// Implementação do módulo das queues.
// A queue usa os mesmos nodos das listas ligadas, mas guarda também
// o apontador para o último nodo para inserir no fim em O(1).

void initQueue(Queue *q)
{
  q->inicio = NULL;
  q->fim = NULL;
}

int isEmptyQueue(Queue q)
{
  return q.inicio == NULL;
}

int enqueue(Queue *q, int x)
{
  LInt novo;

  novo = newLInt(x, NULL);

  if(novo == NULL)
  { return 1; }

  if(q->inicio == NULL)
  {
    // Caso especial: a queue estava vazia.
    // O novo nodo é simultaneamente o início e o fim.
    q->inicio = novo;
    q->fim = novo;
  }
  else
  {
    // Caso geral: ligamos o antigo último nodo ao novo nodo
    // e actualizamos o apontador para o fim.
    q->fim->prox = novo;
    q->fim = novo;
  }

  return 0;
}

int dequeue(Queue *q, int *x)
{
  LInt aux;

  if(q->inicio == NULL)
  { return 1; }

  aux = q->inicio;

  if(x != NULL)
  { *x = aux->valor; }

  q->inicio = aux->prox;

  // Se removemos o último elemento, a queue ficou vazia.
  // Nesse caso, o apontador fim também tem de passar a NULL.
  if(q->inicio == NULL)
  { q->fim = NULL; }

  free(aux);

  return 0;
}

int frontQueue(Queue q, int *x)
{
  if(q.inicio == NULL)
  { return 1; }

  if(x != NULL)
  { *x = q.inicio->valor; }

  return 0;
}

void freeQueue(Queue *q)
{
  if(q != NULL)
  {
    freeList(q->inicio);
    q->inicio = NULL;
    q->fim = NULL;
  }
}

void printQueue(Queue q)
{
  printf("inicio -> ");
  printList(q.inicio);
  printf(" <- fim\n");
}
