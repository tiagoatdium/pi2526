#include <stdio.h>
#include "list.h"
#include "stack.h"
#include "queue.h"

// main.c
//
// Programa pequeno para testar os módulos list, stack e queue.
// A ideia é mostrar que cada módulo tem o seu ficheiro .h e .c,
// e que o programa principal apenas precisa de incluir os .h.

void testList(void)
{
  int valores[] = {10, 20, 30, 40};
  int n = 4;
  int i;
  int x;
  LInt l = NULL;

  printf("=== Lista ligada ===\n");

  for(i = 0; i < n; i++)
  { l = pushFrontList(l, valores[i]); }

  printf("lista: ");
  printList(l);
  printf("\n");

  printf("comprimento: %d\n", length(l));

  if(popFrontList(&l, &x) == 0)
  { printf("removido da cabeça: %d\n", x); }

  printf("lista depois de remover: ");
  printList(l);
  printf("\n\n");

  freeList(l);
}

void testStack(void)
{
  int valores[] = {1, 2, 3, 4};
  int n = 4;
  int i;
  int x;
  Stack s;

  printf("=== Stack ===\n");

  initStack(&s);

  for(i = 0; i < n; i++)
  {
    if(push(&s, valores[i]) != 0)
    { printf("erro ao inserir %d na stack\n", valores[i]); }
  }

  printStack(s);

  if(top(s, &x) == 0)
  { printf("topo: %d\n", x); }

  while(pop(&s, &x) == 0)
  { printf("pop: %d\n", x); }

  printf("stack vazia? %d\n\n", isEmptyStack(s));

  freeStack(&s);
}

void testQueue(void)
{
  int valores[] = {1, 2, 3, 4};
  int n = 4;
  int i;
  int x;
  Queue q;

  printf("=== Queue ===\n");

  initQueue(&q);

  for(i = 0; i < n; i++)
  {
    if(enqueue(&q, valores[i]) != 0)
    { printf("erro ao inserir %d na queue\n", valores[i]); }
  }

  printQueue(q);

  if(frontQueue(q, &x) == 0)
  { printf("primeiro: %d\n", x); }

  while(dequeue(&q, &x) == 0)
  { printf("dequeue: %d\n", x); }

  printf("queue vazia? %d\n", isEmptyQueue(q));

  freeQueue(&q);
}

int main(void)
{
  testList();
  testStack();
  testQueue();

  return 0;
}
