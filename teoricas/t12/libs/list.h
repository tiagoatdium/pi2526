#ifndef LIST_H
#define LIST_H

// list.h
//
// Este ficheiro é a interface do módulo das listas ligadas.
// Aqui ficam os tipos e os protótipos das funções que outros
// ficheiros podem usar.

// Lista ligada simples de inteiros.
typedef struct llig
{
  int valor;
  struct llig *prox;
} *LInt;

// Cria um novo nó com valor x e próximo nó prox.
LInt newLInt(int x, LInt prox);

// Liberta todos os nós da lista.
void freeList(LInt l);

// Calcula o número de elementos da lista.
int length(LInt l);

// Imprime a lista no formato [1, 2, 3].
void printList(LInt l);

// Acrescenta um elemento à cabeça da lista.
// Devolve a nova cabeça da lista, ou NULL se a alocação falhar.
LInt pushFrontList(LInt l, int x);

// Remove o primeiro elemento da lista.
// Devolve 0 se conseguiu remover, ou 1 se a lista estava vazia.
int popFrontList(LInt *l, int *x);

#endif
