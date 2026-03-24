#include <stdio.h>
#include <stdlib.h>

#define N_EXEMPLO 5

//
// Erros frequentes com memória dinâmica
//
// Ideias gerais deste ficheiro:
//
// - conter um pequeno conjunto de exemplos curtos que reflitam erros comuns
//
// - utilização: descomentar apenas UMA chamada de cada vez na função main
//   (e compilar e correr sem valgrind em cada experiência)
//
// - observar o comportamento do programa
//
// - depois repetir com valgrind
//
// Compilacao:
//
//   gcc -Wall -Wextra -pedantic -std=c99 -o common_mistakes0 common_mistakes0.c
//
// Execucao com valgrind:
//
//   valgrind ./common_mistakes0
//
// Notas:
//
// - alguns destes erros podem parecer "funcionar"
// - mas isso nao significa que o codigo esteja correto




// Aloca um array dinamico simples (com malloc), e inicializado de forma explícita
// Nota: devolve NULL em caso de problemas na alocação
int *criar_array_exemplo(int n)
{
  int *v;
  int i;

  v = malloc(n * sizeof(int));

  if(v == NULL)
  { return NULL; }

  for(i = 0; i < n; i++)
  { v[i] = i*11; }

  return v;
}




void imprimir_array(int v[], int n)
{
  int i;
  for(i = 0; i < n; i++)
  { printf("%d ", v[i]); }
  printf("\n");
}




// Exemplo 1:
// - leitura de memoria alocada com malloc antes de inicialização
// - este erro é útil para comparar com o exemplo de calloc
//
void demonstrar_leitura_nao_inicializada(void)
{
  int *v;

  printf("=== leitura de memoria nao inicializada ===\n");

  v = malloc(N_EXEMPLO * sizeof(int));

  if(v == NULL)
  { printf("Erro ao alocar memoria.\n");
    return;
  }

  // Erro:
  // a memoria foi alocada, mas ainda nao foi inicializada
  printf("Conteudo lido antes de inicializar:\n");
  imprimir_array(v, N_EXEMPLO);

  free(v);
}




// Exemplo 2:
// - escrita fora dos limites do array
// - o array tem espaco para N_EXEMPLO inteiros, logo os índices
//   válidos vao de 0 ate N_EXEMPLO - 1
void demonstrar_escrita_fora_dos_limites(void)
{
  int *v;
  int i;

  printf("=== escrita fora dos limites ===\n");

  v = criar_array_exemplo(N_EXEMPLO);

  if(v == NULL)
  {
    printf("Erro ao alocar memoria.\n");
    return;
  }

  // Erro:
  // este ciclo escreve tambem na posicao N_EXEMPLO (note o <=),
  // que se encontra fora dos limites válidos
  for(i = 0; i <= N_EXEMPLO; i++)
  { v[i] = 100 + i; }

  imprimir_array(v, N_EXEMPLO);
  free(v);
}




// Exemplo 3:
// - memory leak por perda do apontador para a memória
// - aqui o primeiro bloco de memoria fica inacessível

void demonstrar_memory_leak(void)
{
  int *v;

  printf("=== memory leak ===\n");

  v = criar_array_exemplo(N_EXEMPLO);

  if(v == NULL)
  { printf("Erro ao alocar memoria.\n");
    return;
  }

  // Erro:
  // - o apontador original perde-se antes de fazer free
  v = malloc(2 * N_EXEMPLO * sizeof(int));

  if(v == NULL)
  { printf("Erro ao alocar segunda regiao.\n");
    return;
  }

  printf("Foi alocada uma segunda regiao.\n");
  printf("A primeira ficou perdida: memory leak.\n");

  free(v);
}




// Exemplo 4:
// - uso de memoria depois de free (use-after-free)
// - depois de free, a região de memória deixa de poder ser utilizada
//
void demonstrar_use_after_free(void)
{
  int *v;

  printf("=== use after free ===\n");

  v = criar_array_exemplo(N_EXEMPLO);

  if(v == NULL)
  {
    printf("Erro ao alocar memoria.\n");
    return;
  }

  free(v);

  // Erro:
  // - a memoria ja foi libertada
  printf("Primeiro elemento depois de free: %d\n", v[0]);
}




// Exemplo 5:
// - uso incorreto de realloc
// - se realloc falhar e devolver NULL, o bloco antigo continua
//   válido. O problema é escrever diretamente:
//
//   v = realloc(v, ...);
//
// porque, em caso de falha, perde-se o apontador antigo
//
void demonstrar_realloc_incorreto(void)
{
  int *v;
  size_t novo_n;

  printf("=== realloc incorreto ===\n");

  v = criar_array_exemplo(N_EXEMPLO);

  if(v == NULL)
  {
    printf("Erro ao alocar memoria.\n");
    return;
  }

  // Tentativa de pedir uma quantidade absurdamente grande,
  // apenas para aumentar a probabilidade de falha
  novo_n = ((size_t)-1) / sizeof(int);
  printf("novo_n = %zu\n", novo_n);

  // Erro:
  // - se realloc devolver NULL, perdemos o apontador antigo
  v = realloc(v, novo_n * sizeof(int));

  if(v == NULL)
  {
    printf("realloc falhou.\n");
    printf("O bloco antigo continua alocado, mas o apontador perdeu-se.\n");
    printf("Resultado: memory leak.\n");
    return;
  }

  free(v);
}




//
// Notas:
//
// - descomentar apenas UMA chamada de cada vez
// - executar primeiro normalmente
// - depois executar com valgrind e observar o output
//
int main(void)
{
  // demonstrar_leitura_nao_inicializada();
  // demonstrar_escrita_fora_dos_limites();
  // demonstrar_memory_leak();
  // demonstrar_use_after_free();
  // demonstrar_realloc_incorreto();

  printf("Descomente um dos exemplos em main.\n");

  return 0;
}
