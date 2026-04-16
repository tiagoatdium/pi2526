#include <stdio.h>
#include <stdlib.h>
#include <assert.h> // relembrar NDEBUG

// ============================================================
//
// Numa lista simplesmente ligada, cada célula guarda:
//
// - a informação
// - um apontador para a célula seguinte
//
// Isso permite percorrer a lista da esquerda para a direita,
// mas nao permite recuar diretamente.
//
// Numa lista duplamente ligada, cada célula guarda:
//
// - a informação
// - um apontador para a célula seguinte
// - um apontador para a célula anterior
//
// Assim, cada célula "conhece" os seus dois vizinhos.
//
// Vantagens:
//
// - podemos percorrer a lista nos dois sentidos
// - algumas remoções e inserções tornam-se mais naturais
// - se tivermos apontador para a última célula, é fácil
//   percorrer a lista de trás para a frente
//
// Custo:
//
// - cada célula passa a ocupar mais memória
// - temos mais apontadores para manter consistentes
//
// Neste ficheiro usamos também uma struct 'Lista' para guardar
// meta-informação:
//
// - nelems: número de elementos
// - first: primeira célula
// - last: última célula
//
// Invariante pretendida:
//
// - se nelems == 0, então first == NULL e last == NULL
// - se nelems > 0, então first != NULL e last != NULL
// ============================================================


// Cada célula guarda:
//
// - valor
// - apontador para a célula anterior
// - apontador para a célula seguinte
//
// Diagrama:
//
//   NULL <- [10] <-> [20] <-> [30] -> NULL
typedef struct celula
{
  int valor;
  struct celula *ant;
  struct celula *prox;
} Celula;


// A lista guarda informação global sobre a estrutura.
typedef struct
{
  size_t nelems;
  Celula *first;
  Celula *last;
} Lista;



// Inicializa uma lista vazia.
void lista_init(Lista *l)
{
  assert(l != NULL);

  l->nelems = 0;
  l->first = NULL;
  l->last = NULL;
}



// Cria uma nova célula isolada.
//
// A nova célula começa com:
//
// - ant = NULL
// - prox = NULL
//
// Isto significa que, neste momento, ainda nao está ligada
// a nenhuma lista.
Celula *criar_celula(int valor)
{
  Celula *nova;

  nova = malloc(sizeof(Celula));

  if(nova == NULL)
  {
    return NULL;
  }

  nova->valor = valor;
  nova->ant = NULL;
  nova->prox = NULL;

  return nova;
}



// Insere um novo valor no início da lista.
//
// Casos:
//
// 1. lista vazia
// 2. lista com um ou mais elementos
//
// Exemplo. Antes:
//
//   first -> [10] <-> [20] <-> [30]
//
// Depois de inserir 5 no início:
//
//   first -> [ 5] <-> [10] <-> [20] <-> [30]
//
// Ideia importante:
//
// - a nova célula passa a apontar para a antiga primeira
// - a antiga primeira passa a apontar para a nova
//
int inserir_inicio(Lista *l, int valor)
{
  Celula *nova;

  assert(l != NULL);

  nova = criar_celula(valor);

  if(nova == NULL)
  { return 0; }

  nova->prox = l->first;

  if(l->first != NULL)
  {
    l->first->ant = nova;
  }
  else
  {
    // Se a lista estava vazia, a nova célula é também a última.
    l->last = nova;
  }

  l->first = nova;
  l->nelems++;

  return 1;
}



// Insere um novo valor no fim da lista.
//
// Exemplo. Antes:
//
//   last -> [10] <-> [20] <-> [30]
//
// Depois de inserir 40 no fim:
//
//   last -> [10] <-> [20] <-> [30] <-> [40]
//
// Ideia importante:
//
// - a nova célula passa a apontar para a antiga última
//   através de 'ant'
// - a antiga última passa a apontar para a nova através
//   de 'prox'
int inserir_fim(Lista *l, int valor)
{
  Celula *nova;

  assert(l != NULL);

  nova = criar_celula(valor);

  if(nova == NULL)
  { return 0; }

  nova->ant = l->last;

  if(l->last != NULL)
  {
    l->last->prox = nova;
  }
  else
  {
    // Se a lista estava vazia, a nova célula é também a primeira.
    l->first = nova;
  }

  l->last = nova;
  l->nelems++;

  return 1;
}



// Imprime a lista.
//
// Padrão:
//
// - começamos em first
// - seguimos os apontadores 'prox'
void imprimir_frente(const Lista *l)
{
  Celula *atual;

  assert(l != NULL);

  printf("Frente: ");

  atual = l->first;

  while(atual != NULL)
  {
    printf("%d ", atual->valor);
    atual = atual->prox;
  }

  printf("\n");
}



// Imprime a lista da direita para a esquerda.
//
// Este é um dos aspetos mais característicos de uma lista
// duplamente ligada:
//
// - começamos em last
// - seguimos os apontadores 'ant'
void imprimir_tras(const Lista *l)
{
  Celula *atual;

  assert(l != NULL);

  printf("Tras:   ");

  atual = l->last;

  while(atual != NULL)
  {
    printf("%d ", atual->valor);
    atual = atual->ant;
  }

  printf("\n");
}



// Remove o primeiro elemento da lista.
//
// Casos:
//
// 1. lista vazia
// 2. lista com um elemento
// 3. lista com dois ou mais elementos
//
// Este exemplo é útil para mostrar como atualizar:
//
// - first
// - eventualmente last
// - o apontador 'ant' da nova primeira célula
int remover_inicio(Lista *l)
{
  Celula *temp;

  assert(l != NULL);

  if(l->first == NULL) // lista vazia, nada a fazer
  { return 0; }

  temp = l->first;
  l->first = temp->prox;

  if(l->first != NULL) // acertar o 'ant' do novo primeiro (o antigo segundo):
  {
    l->first->ant = NULL;
  }
  else
  {
    // A lista ficou vazia.
    l->last = NULL;
  }

  free(temp);
  l->nelems--;

  return 1;
}



// Remove o último elemento da lista.
//
// Este exemplo mostra a simetria com remover_inicio:
//
// - atualizamos last
// - eventualmente first
// - o apontador 'prox' da nova última célula
int remover_fim(Lista *l)
{
  Celula *temp;

  assert(l != NULL);

  if(l->last == NULL)
  {
    return 0;
  }

  temp = l->last;
  l->last = temp->ant;

  if(l->last != NULL)
  {
    l->last->prox = NULL;
  }
  else
  {
    // A lista ficou vazia.
    l->first = NULL;
  }

  free(temp);
  l->nelems--;

  return 1;
}



// Liberta toda a memória ocupada pela lista.
//
// Tal como numa lista simplesmente ligada, percorremos célula
// a célula e libertamos uma de cada vez.
//
// Aqui usamos os apontadores 'prox' para percorrer.
void lista_destroy(Lista *l)
{
  Celula *atual;
  Celula *temp;

  assert(l != NULL);

  atual = l->first;

  while(atual != NULL)
  {
    temp = atual->prox;
    free(atual);
    atual = temp;
  }

  lista_init(l);
}



// Verifica algumas invariantes simples da lista.
//
// Esta função é útil apenas para reforçar a ideia de que,
// quando manipulamos muitos apontadores, convém confirmar
// que a estrutura continua coerente.
void verificar_invariantes(const Lista *l)
{
  assert(l != NULL);

  if(l->nelems == 0)
  {
    assert(l->first == NULL);
    assert(l->last == NULL);
  }
  else
  {
    assert(l->first != NULL);
    assert(l->last != NULL);
    assert(l->first->ant == NULL);
    assert(l->last->prox == NULL);
  }
}


void verificar_invariantes_ordenada(const Lista *l)
{
  Celula *atual;

  assert(l != NULL);

  if(l->nelems == 0)
  {
    assert(l->first == NULL);
    assert(l->last == NULL);
    return;
  }

  assert(l->first != NULL);
  assert(l->last != NULL);
  assert(l->first->ant == NULL);
  assert(l->last->prox == NULL);

  atual = l->first;

  while(atual->prox != NULL)
  {
    // verifica que a ligação para a frente e para trás
    // está consistente
    assert(atual->prox->ant == atual);

    // verifica que a lista está ordenada por ordem crescente
    assert(atual->valor <= atual->prox->valor);

    atual = atual->prox;
  }

  // no fim do ciclo, 'atual' deve estar na última célula
  assert(atual == l->last);
}

// Insere um novo valor na lista, mantendo a ordenação crescente.
//
// Casos a tratar:
//
// 1. lista vazia
// 2. inserção no início
// 3. inserção no meio
// 4. inserção no fim
//
// Estratégia:
//
// - percorremos a lista enquanto os valores atuais forem
//   menores do que o valor a inserir
//
// - no fim do ciclo, 'atual' aponta para:
//
//   - a primeira célula com valor >= valor, ou
//   - NULL, se chegámos ao fim da lista
//
// A função devolve:
//
// - 1 em caso de sucesso
// - 0 em caso de erro de alocação
int inserir_ordenado(Lista *l, int valor)
{
  Celula *nova;
  Celula *atual;
  Celula *anterior;

  nova = criar_celula(valor);

  if(nova == NULL)
  {
    return 0;
  }

  atual = l->first;
  anterior = NULL;

  while(atual != NULL && atual->valor < valor)
  {
    anterior = atual;
    atual = atual->prox;
  }

  // Caso 1:
  // inserção no início da lista
  if(anterior == NULL)
  {
    nova->prox = l->first;

    if(l->first != NULL)
    {
      l->first->ant = nova;
    }
    else
    {
      // A lista estava vazia; a nova célula é também a última.
      l->last = nova;
    }

    l->first = nova;
    l->nelems++;

    return 1;
  }

  // Caso 2 e 3:
  // inserção depois de 'anterior'
  nova->ant = anterior;
  nova->prox = atual;
  anterior->prox = nova;

  if(atual != NULL)
  {
    // Inserção no meio.
    atual->ant = nova;
  }
  else
  {
    // Inserção no fim.
    l->last = nova;
  }

  l->nelems++;

  return 1;
}




// Demonstra algumas operações básicas sobre a lista.
//
// Sequência:
//
// - inserir no início
// - inserir no fim
// - imprimir nos dois sentidos
// - remover no início
// - remover no fim
void demonstrar_lista_dupla0(void)
{
  Lista l;

  lista_init(&l);
  verificar_invariantes(&l);

  printf("========================================\n");
  printf("DEMONSTRACAO: lista duplamente ligada\n");
  printf("========================================\n\n");

  printf("Inserir 20 no inicio.\n");
  assert(inserir_inicio(&l, 20));
  verificar_invariantes(&l);
  imprimir_frente(&l);
  imprimir_tras(&l);
  printf("nelems = %zu\n\n", l.nelems);

  printf("Inserir 10 no inicio.\n");
  assert(inserir_inicio(&l, 10));
  verificar_invariantes(&l);
  imprimir_frente(&l);
  imprimir_tras(&l);
  printf("nelems = %zu\n\n", l.nelems);

  printf("Inserir 30 no fim.\n");
  assert(inserir_fim(&l, 30));
  verificar_invariantes(&l);
  imprimir_frente(&l);
  imprimir_tras(&l);
  printf("nelems = %zu\n\n", l.nelems);

  printf("Inserir 40 no fim.\n");
  assert(inserir_fim(&l, 40));
  verificar_invariantes(&l);
  imprimir_frente(&l);
  imprimir_tras(&l);
  printf("nelems = %zu\n\n", l.nelems);

  printf("Remover no inicio.\n");
  assert(remover_inicio(&l));
  verificar_invariantes(&l);
  imprimir_frente(&l);
  imprimir_tras(&l);
  printf("nelems = %zu\n\n", l.nelems);

  printf("Remover no fim.\n");
  assert(remover_fim(&l));
  verificar_invariantes(&l);
  imprimir_frente(&l);
  imprimir_tras(&l);
  printf("nelems = %zu\n\n", l.nelems);

  lista_destroy(&l);
  verificar_invariantes(&l);

  printf("Lista libertada.\n");
}

void demonstrar_lista_dupla1(void)
{
  Lista l;

  lista_init(&l);
  verificar_invariantes_ordenada(&l);

  printf("========================================\n");
  printf("DEMONSTRACAO 1: insercao ordenada\n");
  printf("========================================\n\n");

  printf("Inserir 40.\n");
  assert(inserir_ordenado(&l, 40));
  verificar_invariantes_ordenada(&l);

  printf("Inserir 20.\n");
  assert(inserir_ordenado(&l, 20));
  verificar_invariantes_ordenada(&l);

  printf("Inserir 10.\n");
  assert(inserir_ordenado(&l, 10));
  verificar_invariantes_ordenada(&l);

  printf("Inserir 30.\n");
  assert(inserir_ordenado(&l, 30));
  verificar_invariantes_ordenada(&l);

  printf("\nLista percorrida da frente para tras:\n");
  imprimir_frente(&l);

  printf("Lista percorrida de tras para a frente:\n");
  imprimir_tras(&l);

  printf("nelems = %zu\n\n", l.nelems);

  lista_destroy(&l);
  verificar_invariantes_ordenada(&l);
}



// Programa principal.
int main(void)
{
  //demonstrar_lista_dupla();
  demonstrar_lista_dupla1();
  return 0;
}
