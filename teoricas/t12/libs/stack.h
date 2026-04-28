#ifndef STACK_H
#define STACK_H

#include "list.h"

// stack.h
//
// Interface do módulo das stacks.
// Uma stack é uma estrutura LIFO:
// o último elemento a entrar é o primeiro a sair.
//
// Nesta versão, a stack é implementada usando uma lista ligada.
// Como só precisamos de inserir e remover à cabeça, uma lista ligada
// simples é suficiente.

typedef LInt Stack;

// Inicializa uma stack vazia.
void initStack(Stack *s);

// Testa se a stack está vazia.
int isEmptyStack(Stack s);

// Insere um elemento no topo da stack.
// Devolve 0 se conseguiu inserir, ou 1 se falhou a alocação.
int push(Stack *s, int x);

// Remove o elemento do topo da stack.
// Devolve 0 se conseguiu remover, ou 1 se a stack estava vazia.
int pop(Stack *s, int *x);

// Consulta o elemento no topo da stack sem o remover.
// Devolve 0 se existe topo, ou 1 se a stack estava vazia.
int top(Stack s, int *x);

// Liberta toda a memória ocupada pela stack.
void freeStack(Stack *s);

// Imprime a stack, começando pelo topo.
void printStack(Stack s);

#endif
