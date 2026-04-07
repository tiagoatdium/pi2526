#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct celula
{ int valor;
  struct celula *prox;
} *Lista;

Lista criar_celula(int valor)
{
  Lista nova;
  nova = malloc(sizeof(struct celula));

  if(nova == NULL)
  { return NULL; }

  nova->valor = valor;
  nova->prox = NULL;

  return nova;
}

Lista inserir_inicio(Lista l, int valor)
{
  Lista nova;

  nova = criar_celula(valor);

  if(nova == NULL)
  { return NULL; }

  nova->prox = l;
  return nova;
}

void imprimir_lista(Lista l)
{
  printf("Lista: ");
  while(l != NULL)
  {
    printf("%d ", l->valor);
    l = l->prox;
  }
  printf("\n");
}

// a seguinte função liberta (free) as células de uma lista
Lista libertar_lista(Lista l)
{
  Lista temp;

  while(l != NULL)
  {
    temp = l->prox;
    free(l);
    l = temp;
  }

  return NULL;
}

// a seguinte função calcula o comprimento de uma lista
size_t comprimento_lista(Lista l)
{
  size_t n = 0;

  while(l != NULL)
  {
    n++;
    l = l->prox;
  }

  return n;
}

int main(void)
{
  Lista l = NULL;

  // no ficheiro seguinte, linked_lists2.c, existe uma discussão mais completa
  // sobre o padrão seguinte de utilização (l = inserir_inicio(l, 10);) onde 
  // reescrevemos o apontador sem verificar se a inserção ocorreu como esperado.
  // - por uma questão de simplicidade de apresentação/introdução, "para já fica
  //   assim", mas faça questão de aprofundar o seu conhecimento sobre o assunto 
  //   pelo que se recomenda a leitura do ficheiro seguinte com a merecida atenção
  l = inserir_inicio(l, 10);
  l = inserir_inicio(l, 20);
  l = inserir_inicio(l, 30);

  imprimir_lista(l);
  printf("Comprimento da lista: %zu\n", comprimento_lista(l));

  l = libertar_lista(l); // porquê o return de NULL da função libertar_lista?

  // correr este programa com o valgrind para verificar que 
  // a memória é correctamente libertada:
  // $ valgrind ./linked_lists1

  return 0;
}
