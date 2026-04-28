#include <stdio.h>
#include "stack.h"

// stack.c
//
// Implementação do módulo das stacks.
// Repare que este ficheiro inclui stack.h, que por sua vez inclui list.h.
// Assim, podemos reutilizar o tipo LInt e a função newLInt.

void initStack(Stack *s)
{
  *s = NULL;
}

int isEmptyStack(Stack s)
{
  return s == NULL;
}

int push(Stack *s, int x)
{
  LInt novo;

  novo = newLInt(x, *s);

  if(novo == NULL)
  { return 1; }

  *s = novo;

  return 0;
}

int pop(Stack *s, int *x)
{
  return popFrontList(s, x);
}

int top(Stack s, int *x)
{
  if(s == NULL)
  { return 1; }

  if(x != NULL)
  { *x = s->valor; }

  return 0;
}

void freeStack(Stack *s)
{
  if(s != NULL)
  {
    freeList(*s);
    *s = NULL;
  }
}

void printStack(Stack s)
{
  printf("topo -> ");
  printList(s);
  printf("\n");
}
