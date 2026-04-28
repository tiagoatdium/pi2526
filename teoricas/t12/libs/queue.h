#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

// queue.h
//
// Interface do módulo das queues.
// Uma queue é uma estrutura FIFO:
// o primeiro elemento a entrar é o primeiro a sair.
//
// Para tornar enqueue eficiente, guardamos dois apontadores:
// - inicio: primeiro elemento da queue;
// - fim: último elemento da queue.

typedef struct queue
{
  LInt inicio;
  LInt fim;
} Queue;

// Inicializa uma queue vazia.
void initQueue(Queue *q);

// Testa se a queue está vazia.
int isEmptyQueue(Queue q);

// Insere um elemento no fim da queue.
// Devolve 0 se conseguiu inserir, ou 1 se falhou a alocação.
int enqueue(Queue *q, int x);

// Remove o elemento do início da queue.
// Devolve 0 se conseguiu remover, ou 1 se a queue estava vazia.
int dequeue(Queue *q, int *x);

// Consulta o primeiro elemento da queue sem o remover.
// Devolve 0 se existe primeiro elemento, ou 1 se a queue estava vazia.
int frontQueue(Queue q, int *x);

// Liberta toda a memória ocupada pela queue.
void freeQueue(Queue *q);

// Imprime a queue do início para o fim.
void printQueue(Queue q);

#endif
