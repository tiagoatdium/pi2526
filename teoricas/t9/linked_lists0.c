#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//
// Listas ligadas são estruturas de dados formadas por células
// "encadeadas" por apontadores, em que cada célula guarda 
// "alguma informação" e uma referência/apontador para a célula
// seguinte.
//
// Vamos estudar alguns conceitos básicos utilizando listas "simples"
// de inteiros. Concretamente:
//
// - o que é uma célula
// - como representar uma lista ligada vazia
// - como percorrer uma lista ligada
// - como inserir no início de uma lista ligada
// - como inserir no fim de uma lista ligada
// - como libertar a memória associada a uma lista ligada
//

// Cada célula (definida como 'struct') guarda:
// - um valor inteiro
// - um apontador para a célula seguinte
//
// O tipo 'Lista' representa um apontador para uma célula (por vezes, 
// também é utilizado o nome nó para denotar o mesmo conceito).
//
// Exemplo "gráfico" (simplificado) de uma lista ligada para construir 
// alguma intuição sobre o assunto em estudo:
//
//   +-------+-------+    +-------+-------+
//   | valor | prox  | -> | valor | prox  | -> NULL
//   +-------+-------+    +-------+-------+
//
//
typedef struct celula
{
  int valor;
  struct celula *prox;
} *Lista;



// A função seguinte cria uma nova célula (malloc) inicializada com 
// 'valor' (argumento da função).
// - nota: esta nova célula será inicializada com 'prox = NULL', ou seja,
//   inicialmente, não terá "nenhum próximo".
//
// Retorna:
// - o endereço da nova célula, em caso de sucesso
// - NULL, em caso de erro na alocação de memória (malloc)
// - nota: Lista é um apontador (o tipo foi declarado como *Lista)

Lista criar_celula(int valor)
{
  Lista nova;

  // pergunta: porque é utilizada a expressão "sizeof(struct celula)"?
  nova = malloc(sizeof(struct celula));

  // é importante verificar o valor de retorno de malloc: caso 
  // não seja possível alocar a memória pedida
  if(nova == NULL)
  {
    return NULL;
  }

  nova->valor = valor;
  nova->prox = NULL;

  return nova;
}


// A seguinte função insere um elemento no início da lista
//
// Intuição:
// - cria-se uma nova célula
// - a nova célula passa a apontar para a lista antiga
// - a nova célula passa a ser a nova cabeça da lista
//
Lista inserir_inicio(Lista l, int valor)
{
  Lista nova;

  nova = criar_celula(valor);

  if(nova == NULL)
  {
    return NULL;
  }

  nova->prox = l;
  return nova;
}


// A seguinte função imprime todos os elementos da lista.
void imprimir_lista(Lista l)
{
  // pergunta: a variável aux é estritamente necessária neste contexto? 
  //   - de outra forma: pode-se substituir 'aux' por 'l' no código
  //     seguinte sem afectar a funcionalidade da função? 
  //   - resposta: Sim. Sugestão: realize essa alteração, teste, e procure
  //     entender bem porquê. Notas 'Lista l' é um apontador; como 'l' é uma 
  //     variável local, alterar o valor de l (não os valores apontados por l
  //     mas sim 'l') não tem repercusões/efeito no local da chamada a esta função
  //     neste caso a função 'main', definida mais à frente. 
  
  Lista aux = l;

  printf("Lista: ");

  while(aux != NULL)
  {
    printf("%d ", aux->valor);
    aux = aux->prox;
  }

  printf("\n");
}


int main(void)
{
  Lista l = NULL;

  // note que neste ponto da execução l é NULL; verifique os detalhes sobre
  // o porquê de funcionar de forma atenta
  l = inserir_inicio(l, 10);
  l = inserir_inicio(l, 20);
  l = inserir_inicio(l, 30);

  imprimir_lista(l);

  // nota importante: antes de terminarmos a execução do programa
  // devemos libertar (chamar a função free) todos as células
  // alocadas com malloc. Recorde-se: para cada malloc (ou calloc, ...)
  // deve existir uma chamada a free. 
  //
  // para verificar que efectivamente existe memória não libertada 
  // pode executar o programa com o valgrind, por exemplo:
  // $ valgrind ./linked_lists0

  return 0;
}


