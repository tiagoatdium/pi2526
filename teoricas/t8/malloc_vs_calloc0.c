#include <stdio.h>
#include <stdlib.h>
#include <assert.h> // assert // consultar man 3 assert

// No exemplo anterior utilizamos 'malloc' para alocar
// memória (dinamicamente) para um array de inteiros.
//
// Notas importantes:
//
// - 'malloc' aloca a memória, mas não inicializa o seu conteúdo
//
// - 'calloc' também aloca memória, mas inicializa essa memória
//   a zero
//
// Ao consultar 'man 3 calloc', podemos observar:
//
// - void *calloc(size_t nmemb, size_t size);
//
// Esta diferença é importante porque, em C, não devemos ler
// o conteúdo de memória não inicializada
//
// Neste exemplo vamos:
//
// - alocar um array com malloc
//
// - alocar outro array com calloc
//
// - observar que o array criado com calloc começa com zeros
//
// - explicar porque é que não devemos imprimir o conteúdo do
//   array criado com malloc antes de o inicializar
//
// - inicializar ambos os arrays e verificar que, depois disso,
//   os dois podem ser usados normalmente




// A seguinte função lê do utilizador o número de elementos
// que o array deve ter. A função retorna este valor.
int ler_tamanho(void)
{
  int r, n;

  printf("Numero de elementos: ");
  r = scanf("%d", &n);
	assert(r == 1);

  return n;
}




// A seguinte função preenche o array com valores "simples",
// apenas para termos dados para observar e imprimir.
void preencher_array(int v[], int n)
{
  int i;

  for(i = 0; i < n; i++)
  { v[i] = i; }
}




// A seguinte função imprime os elementos do array
void imprimir_array(int v[], int n)
{
  int i;

  for(i = 0; i < n; i++)
  { printf("%d ", v[i]); }
  printf("\n");
}







//
// Na seguinte função 'main', criamos dois arrays dinâmicos com o mesmo
// tamanho:
//
// - um com malloc
// - outro com calloc
//
// Depois, comparamos o comportamento de cada um.
//

int main(void)
{
  int n;
  int *v_malloc;
  int *v_calloc;

  n = ler_tamanho();

  if(n <= 0)
  { printf("O numero de elementos deve ser positivo.\n");
    return 1;
  }
  
  //
  // - 'malloc' reserva memória para 'n' inteiros
  //
  // - essa memória fica alocada, mas o seu conteúdo inicial
  //   é indeterminado
  //
  // - isto significa que não devemos ler estes valores antes
  //   de escrever lá alguma coisa
  //
  v_malloc = malloc(n * sizeof(int));

  if(v_malloc == NULL)
  { printf("Erro: nao foi possivel alocar memoria com malloc.\n");
    return 1;
  }

  //
  // - 'calloc' também reserva memória para 'n' inteiros
  //
  // - além disso, inicializa a memória a zero.
  //
  // - por isso, neste caso, podemos observar imediatamente
  //   o conteúdo do array
  //
  v_calloc = calloc(n, sizeof(int));

  if(v_calloc == NULL)
  { printf("Erro: nao foi possivel alocar memoria com calloc.\n");
    free(v_malloc); // libertamos o espaço de memória previamente alocado 
                    // for forma a evitar uma memory leak (boa prática)
    return 1;
  }


  //
  // Sugestão de pequeno experimento em relação ao seguinte código
  // que se encontra comentado (impressão dos elementos do array 
  // alocado com 'malloc' antes da sua inicialização):
  //
  // - podem descomentar o código seguinte e executar
  //   o programa com valgrind para observar o problema:
  //   (valgrind ./malloc_vs_calloc)
  //
  // - a ideia é que o array criado com malloc ainda não foi
  //   inicializado; por isso, ao tentar imprimi-lo, estamos a
  //   ler valores indefinidos
  //
  // - o valgrind deverá assinalar essa situação, indicando que
  //   o programa está a usar valores não inicializados
  //
  // - isto ajuda a confirmar que, mesmo que por acaso apareçam
  //   zeros no ecrã, esses valores não são fiáveis nem podem
  //   ser assumidos como corretos

  // printf("\n");
  // printf("malloc (antes inicialização): ");
  // imprimir_array(v_malloc, n);
  
  printf("\n");
  printf("calloc (antes inicialização): ");
  imprimir_array(v_calloc, n);

	//
 
  preencher_array(v_malloc, n);
  preencher_array(v_calloc, n);

	//
	
  printf("\n");
  printf("malloc (após inicialização): ");
  imprimir_array(v_malloc, n);
  
  printf("\n");
  printf("calloc (após inicialização): ");
  imprimir_array(v_calloc, n);

  //
  // - como ambos os arrays foram alocados dinamicamente,
  //   temos de libertar explicitamente a memória com free.
  //
  free(v_malloc);
  free(v_calloc);

  return 0;
}
