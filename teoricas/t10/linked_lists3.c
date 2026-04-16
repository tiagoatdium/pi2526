#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#define MAX_NOME 100
#define MAX_LINHA 256

#define INSERIR_ERRO 0
#define INSERIR_OK 1
#define INSERIR_DUPLICADO 2


// neste exemplo, cada célula representa um aluno.
typedef struct celula
{
  unsigned int numero;
  char nome[MAX_NOME];
  float nota;
  struct celula *prox;
} Celula; // repare que em contraste com os exemplos anteriores, aqui
          // não se coloca *Celula (serve isto para demonstrar diferentes
          // estratégias de implementação)


// Neste exemplo, 'Lista' representa a lista como "um todo".
// Em vez de representar a lista apenas por um apontador,
// guardamos também meta-informação:
//
// - nelems: número de elementos
// - first: primeira célula
// - last: última célula
// 
// Poderiamos também incluir mais informação. Por exemplo, se 
// a média fosse frequentemente utilizada poderia ser benéfico
// em termos de performance incluir um campo 'media' que seria
// actualizado sempre que necessário/justificado (para evitar
// recalcular a média frequentemente). Outros exemplos: contadores
// de aprovados/reprovados que seriam actualizados a cada inserção
// ou remoção; etc. De forma geral, podemos pensar em programas
// como sendo artefactos/ferramentas/automatismos que consideram as
// características de um determinado problema de forma eficaz e eficiente.

typedef struct
{
  size_t nelems;
  Celula *first;
  Celula *last;
} Lista;



// Inicializa uma lista vazia.
// - se nelems == 0, então first == NULL e last == NULL
void lista_init(Lista *l)
{
  assert(l != NULL);
  l->nelems = 0;
  l->first = NULL;
  l->last = NULL;
}

// Cria uma nova célula dado um numero, nome e uma nota.
// Retorna:
// - apontador para a nova célula, em caso de sucesso
// - NULL, em caso de erro de alocação
//
Celula *criar_celula(unsigned int numero, const char nome[], float nota)
{
  Celula *nova;
  assert(nome != NULL); // ler ficheiro t8/assert0.c 

  nova = malloc(sizeof(Celula));

  if(nova == NULL)
  { return NULL; }

  nova->numero = numero;
  snprintf(nova->nome, MAX_NOME, "%s", nome); // pergunta para tempo de estudo: porque não strncpy? quais as vantagens desvantagens? (strncpy pode criar uma string que não é "null-terminated")
  nova->nota = nota;
  nova->prox = NULL;

  return nova;
}


// liberta a memória ocupada pelas celulas da lista
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



// imprime a lista num formato legível.
void imprimir_lista(const Lista *l)
{
  Celula *atual;

  assert(l != NULL);

  // o '-' denota alinhamento à esquerda
  printf("Numero de elementos: %zu\n", l->nelems);
  printf("---------------------------------------------\n");
  printf("%-10s %-20s %-5s\n", "Numero", "Nome", "Nota");
  printf("---------------------------------------------\n");

  atual = l->first;

  while(atual != NULL)
  {
    printf("%-10u %-20s %2.1f\n",
           atual->numero,
           atual->nome,
           atual->nota);

    atual = atual->prox;
  }

  printf("---------------------------------------------\n");
}



// insere um novo aluno de forma ordenada por número.
//
// a lista mantém-se sempre ordenada por número crescente.
//
// casos a tratar:
//
// 1. lista vazia
// 2. inserção no início
// 3. inserção no meio
// 4. inserção no fim
//
// Se já existir um aluno com o mesmo número, a função
// nao insere nada e retorna INSERIR_DUPLICADO.
//
// Valor de retorno:
//
// - INSERIR_OK
// - INSERIR_DUPLICADO
// - INSERIR_ERRO
int inserir_ordenado(Lista *l, unsigned int numero, const char nome[], float nota)
{
  Celula *ant;
  Celula *atual;
  Celula *nova;

  assert(l != NULL);
  assert(nome != NULL);

  ant = NULL;
  atual = l->first;

  while(atual != NULL && atual->numero < numero)
  {
    ant = atual;
    atual = atual->prox;
  }

  // se chegamos a uma célula com o mesmo número,
  // entao consideramos que há duplicação.
  if(atual != NULL && atual->numero == numero)
  { return INSERIR_DUPLICADO;
  }

  nova = criar_celula(numero, nome, nota);

  if(nova == NULL)
  { return INSERIR_ERRO;
  }

  // caso 1:
  // lista vazia ou inserção no início
  if(ant == NULL)
  {
    nova->prox = l->first;
    l->first = nova;

    if(l->last == NULL)
    { l->last = nova; }

    l->nelems++;
    return INSERIR_OK;
  }

  // caso 2:
  // inserção depois de 'ant'
  nova->prox = atual;
  ant->prox = nova;

  // Se 'atual' for NULL, "inserimos no fim"
  if(atual == NULL)
  { l->last = nova;
  }

  l->nelems++;
  return INSERIR_OK;
}


// Remove o '\n' ou '\r\n' do fim de uma linha, se existir.
void remover_newline(char s[])
{
  size_t n;

  assert(s != NULL);

  // man 3 strcspn :
  //  - size_t strcspn(const char *s, const char *reject);
  //
  //  - The strcspn() function calculates the length of the initial
  //    segment of s which consists entirely of bytes not in reject.

  n = strcspn(s, "\r\n");
  s[n] = '\0';
}


// verifica se uma linha é vazia ou contém apenas espaços.
int linha_vazia(const char s[])
{
  size_t i;

  assert(s != NULL);

  // man 3 isspace:
  // - The values returned are nonzero if the character c falls into the tested class, and zero if not.
  for(i = 0; s[i] != '\0'; i++)
  {
    if(!isspace((unsigned char) s[i]))
    {
      return 0;
    }
  }

  return 1;
}



// verifica se a linha corresponde ao cabeçalho esperado.
int linha_e_cabecalho(const char s[])
{
  assert(s != NULL);

  return strcmp(s, "numero,nome,nota") == 0;
}


// Extrai os campos de uma linha CSV simples.
//
// Formato esperado:
//
//   numero,nome,nota
//
// assume que:
// - o nome não contém vírgulas
// - a linha já não contém '\n'
//
// Retorna:
// - 1 em caso de sucesso
// - 0 em caso de erro
int extrair_campos_csv(const char linha[],
                       unsigned int *numero,
                       char nome[],
                       float *nota)
{
  int lidos;

  assert(linha != NULL);
  assert(numero != NULL);
  assert(nome != NULL);
  assert(nota != NULL);

  lidos = sscanf(linha, "%u,%99[^,],%f", numero, nome, nota);

  return lidos == 3;
}


// guarda a lista num ficheiro CSV já aberto.
//
// esta função escreve:
// - uma linha de cabeçalho
// - uma linha por cada aluno da lista
//
// Retorna:
// - 1 em caso de sucesso
// - 0 em caso de erro de escrita
//
int guardar_lista_csv(FILE *f, const Lista *l)
{
  Celula *atual;

  assert(f != NULL);
  assert(l != NULL);

  if(fprintf(f, "numero,nome,nota\n") < 0)
  {
    return 0;
  }

  atual = l->first;

  while(atual != NULL)
  {
    if(fprintf(f, "%u,%s,%.1f\n",
               atual->numero,
               atual->nome,
               atual->nota) < 0)
    {
      return 0;
    }

    atual = atual->prox;
  }

  return 1;
}


// abre um ficheiro e guarda a lista em formato CSV
//
// retorna:
// - 1 em caso de sucesso
// - 0 em caso de erro
int guardar_lista_csv_ficheiro(const char nome_ficheiro[], const Lista *l)
{
  FILE *f;
  int ok;

  assert(nome_ficheiro != NULL);
  assert(l != NULL);

  f = fopen(nome_ficheiro, "w");

  if(f == NULL)
  { return 0;
  }

  ok = guardar_lista_csv(f, l);

  if(fclose(f) != 0)
  { return 0;
  }

  return ok;
}


// carrega uma lista a partir de um ficheiro CSV já aberto
// esta função assume que a lista recebida está vazia
//
// estratégia:
// - lê uma linha de cada vez com fgets
// - ignora linhas vazias
// - ignora o cabeçalho
// - extrai os campos
// - insere cada aluno na lista por ordem de número
//
// em caso de erro:
// - a lista é libertada
// - a função devolve 0
//
// em caso de sucesso:
// - a lista fica carregada e ordenada
// - a função devolve 1

int carregar_lista_csv(FILE *f, Lista *l)
{
  char linha[MAX_LINHA];
  unsigned int numero;
  char nome[MAX_NOME];
  float nota;
  int res;

  assert(f != NULL);
  assert(l != NULL);
  assert(l->nelems == 0);
  assert(l->first == NULL);
  assert(l->last == NULL);

  while(fgets(linha, MAX_LINHA, f) != NULL)
  {
    remover_newline(linha);

    if(linha_vazia(linha))
    {
      continue;
    }

    if(linha_e_cabecalho(linha))
    {
      continue;
    }

    if(!extrair_campos_csv(linha, &numero, nome, &nota))
    {
      lista_destroy(l);
      return 0;
    }

    res = inserir_ordenado(l, numero, nome, nota);

    if(res != INSERIR_OK)
    {
      lista_destroy(l);
      return 0;
    }
  }

  return 1;
}



// abre um ficheiro e carrega a lista
// a lista deve estar vazia antes da chamada.
//
// retorna:
// - 1 em caso de sucesso
// - 0 em caso de erro
int carregar_lista_csv_ficheiro(const char nome_ficheiro[], Lista *l)
{
  FILE *f;
  int ok;

  assert(nome_ficheiro != NULL);
  assert(l != NULL);

  f = fopen(nome_ficheiro, "r");

  if(f == NULL)
  {
    return 0;
  }

  ok = carregar_lista_csv(f, l);

  if(fclose(f) != 0)
  {
    return 0;
  }

  return ok;
}


// Programa principal.
// 1. carregar o CSV para a lista
// 2. imprimir a lista já ordenada por número
// 3. guardar a lista ordenada noutro ficheiro
// 4. libertar a memória
//
int main(void)
{
  Lista l;

  lista_init(&l);

  if(!carregar_lista_csv_ficheiro("alunos.csv", &l))
  {
    printf("Erro: nao foi possivel carregar a lista a partir do CSV.\n");
    lista_destroy(&l);
    return 1;
  }

  printf("Lista carregada do ficheiro alunos.csv:\n");
  printf("(a lista fica ordenada por numero)\n\n");
  imprimir_lista(&l);

  if(!guardar_lista_csv_ficheiro("alunos_output.csv", &l))
  {
    printf("Erro: nao foi possivel guardar a lista em CSV.\n");
    lista_destroy(&l);
    return 1;
  }

  printf("\n");
  printf("A lista foi guardada em alunos_output.csv\n");

  lista_destroy(&l);

  return 0;
}
