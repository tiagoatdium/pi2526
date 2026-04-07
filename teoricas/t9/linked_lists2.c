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

// a seguinte função retorna a última célula da lista (percorre a lista enquanto
// houver "próximos")
Lista ultima_celula(Lista l)
{
  if(l == NULL)
  { return NULL; }

  while(l->prox != NULL)
  { l = l->prox; }

  return l;
}

// a seguinte função insere no fim da lista. No exemplo apresentado:
//  - recebe a lista actual (que pode ser NULL se estiver vazia) e o valor para colocar na nova célula
//
// E o que deve retornar a função? Vamos analizar caso a caso para tentarmos perceber melhor o contexto 
// do problema a resolver.
//
//  1. se 'l' for NULL, então a lista encontra-se vazia. Como tal, devemos retornar o apontador da nova
//     célula (utilizando a função criar célula).
//
//  2. se 'l' é diferente de NULL, então a lista tem pelo menos um elemento. Neste caso podemos utilizar
//     a função anterior (ultima_celula) para identificar a última célula, que podemos chamar de 'ult', 
//     e assim indicar que 'ult->prox' deverá agora conter o endereço da nova célula criada. E o que
//     devemos retornar? Bem, considerando o ponto 1), em que decidimos que a função retorna Lista, então
//     neste caso podemos/devemos retornar 'l' (a lista original) para sermos consistentes no tipo de retorno.
//
//  3. falta ainda considerar um outro caso: e se a chamada à função malloc (que ocorre na função criar_celula)
//     falhar e retornar NULL (porque, por exemplo, não havia memória disponível)? Para tratar este caso,
//     podemos seguir o padrão implementado pela função realloc (ver ficheiro t8/realloc.c e consultar o manual
//     com, por exemplo, man 3 realloc). Resumidamente, a função realloc pode: retornar o mesmo apontador caso 
//     a reallocação seja possível de realizar no "mesmo espaço de memória"; retornar um novo apontador caso
//     seja preciso "mover" para outro lado; NULL caso "corra mal". Como tal, podemos adoptar a mesma convenção
//     e retornar também NULL. Depois (e de forma semelhante à utilização da função realloc) não devemos reescrever
//     o apontador antigo de imediato (por exemplo, evitar 'l = inserir_fim(l, 10)') pois caso a criação da célula
//     falhe (e a função inserir_fim retornar NULL) perdemos o 'l' antigo (e como tal não podemos "fazer free" para
//     libertar a memória)
//
// Note que a situação descrita em 3. também ocorre no contexto de inserir_inicio. 

Lista inserir_fim(Lista l, int valor)
{
  Lista nova;
  Lista ult;

  // começamos por criar uma célula com o valor correspondente
  nova = criar_celula(valor);

  // note que se a alocação de memória falhar, a função criar_celula retorna NULL
  // - de acordo com a discussão anterior, retornamos NULL para assinalar este facto
  if(nova == NULL)
  { return NULL; }

  // neste ponto de execução sabemos que 'nova' é diferente de NULL. Se a lista 'l'
  // dada como argumento for vazia, então 'nova' é o único elemento e pode ser retornado
  if(l == NULL)
  { return nova; }

  // se chegamos a este ponto de execução da função, então sabemos que a alocação de 'nova'
  // teve sucesso e a lista tem pelo menos um elemento. Como tal, identificamos a última célula,
  // e definimos o próximo da última célula como a nova.

  ult = ultima_celula(l);
  ult->prox = nova;

  return l;
}



int main(void)
{
  Lista l = NULL;

  // ler comentários da função inserir_fim
  l = inserir_inicio(l, 10);
  l = inserir_inicio(l, 20);
  l = inserir_inicio(l, 30);

  imprimir_lista(l);
  printf("Comprimento da lista: %zu\n", comprimento_lista(l));

  // ler comentários da função inserir_fim
  l = inserir_fim(l, 5);
  l = inserir_fim(l, 0);

  imprimir_lista(l);

  l = libertar_lista(l);
  return 0;
}

