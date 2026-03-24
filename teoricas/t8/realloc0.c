#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Nos exemplos anteriores vimos como usar 'malloc' e 'calloc'
// para criar arrays dinâmicos.
//
// No entanto, nesses casos, a capacidade máxima do array é decidido
// no momento da alocação e mantêm-se fixo até ao fim da 
// execução do programa.
//
//
// Neste ficheiro introduzimos a função 'realloc':
//
// - alocamos com um array dinâmico "pequeno"
//
// - vamos acrescentando valores à medida que o utilizador os
//   introduz
//
// - quando o array fica "cheio", usamos 'realloc' para aumentar
//   a capacidade máxima do array (o número máximo de elementos
//   que podem ser guardados)
//
//
//
// Este é um cenário que ocorre frequentemente em cenários mais
// complexos, nomeadamente:
//
// - não sabemos à partida quantos elementos serão necessários
//
// - por isso, começamos com um tamanho inicial
//
// - sempre que necessário, aumentamos essa capacidade
//
//
// Ideias principais:
//
// - nelem: número de elementos atualmente guardados no array
//
// - size: número máximo de elementos que "cabem" no array
//         antes de ser necessário aumentar a memória ("reallocar")
//
// - realloc: permite "redimensionar" uma zona de memória já alocada
//
//

// //////////////////////////////////////////////////////////////////
// Ao consultar 'man 3 realloc' podemos ler:
//
//  0. void *realloc(void *ptr, size_t size);
//
//  1. The realloc() function changes the size of the
//     memory block pointed to by 'ptr' to size bytes.
//
//  2. The contents will be unchanged in the range from
//     the start of the region up to the minimum of the
//     old and new sizes.
//
//  3. If the new size is larger than the old size, the
//     added memory **will not be initialized**. 
//
//  4. If 'ptr' is NULL, then the call is equivalent to
//     malloc(size), for all values of size
//
//  5. if size is equal to zero, and 'ptr' is not NULL,
//     then the call is equivalent to 'free(ptr)'.
//
//  6. Unless 'ptr' is NULL, it must have been returned by
//     an earlier call to malloc(), calloc(), or realloc().
//
//  7. If the area pointed to was moved, a 'free(ptr)' is done.

// Na secção do manual correspondente aos return values,
// encontra-se a seguinte informação:
//
//  1. The realloc() function returns a pointer to the newly
//     allocated memory, which is suitably aligned for any 
//     built-in type, or NULL if the request failed.
//
//  2. The returned pointer may be the same as 'ptr' if the
//     allocation was not moved (e.g., there was room to
//     expand the allocation in-place), or different from
//     'ptr' if the allocation was moved to a new address.
//
//  3. If size was equal to 0, either NULL or a pointer
//     suitable to be passed to free() is returned. If
//     realloc() fails, the original block is left 
//     untouched; it is not freed or moved.


// Notas mais importantes que podemos retirar da leitura do 
// manual (todavia, recomenda-se a leitura atenta do manual):
//
// - 'realloc' pode devolver o mesmo endereço ou um endereço
//   diferente
//
// - tipicamente, é boa prática guardar o resultado num apontador
//   temporário antes de substituir o apontador "original":
//   - se realloc falhar e devolver NULL, a memória antiga
//     continua válida; por isso, não devemos perder o apontador
//     original.




#define INITIAL_SIZE 3
#define EXIT_VALUE -1




int ler_valor(void)
{
  int r, valor;

  printf("Introduza um valor (%d para terminar): ", EXIT_VALUE);
  r = scanf("%d", &valor);
  assert(r == 1);

  return valor;
}




void imprimir_array(int v[], int n)
{
  int i;

  for(i = 0; i < n; i++)
  { printf("%d ", v[i]); }
  printf("\n");
}




// Tenta criar um array dinâmico inicial com a capacidade pedida.
// A função devolve o endereço inicial da memória alocada, ou
// NULL se a alocação falhar.
int *criar_array(int capacidade)
{
  return malloc(capacidade * sizeof(int));
}




// Tenta aumentar a capacidade de um array dinâmico.
//
// A função usa realloc para pedir uma nova região de memória
// com espaço para 'nova_capacidade' inteiros.
//
// Se a operação correr bem, devolve o novo endereço.
// Se falhar, devolve NULL.
//
// Notas importantes:
//
// - "quem" chama esta função não deve substituir 
//    imediatamente o apontador original
//
// - deve primeiro verificar se o resultado é diferente de NULL
//   (caso seja retornado NULL, significa que aconteceu um erro)
//
int *aumentar_capacidade(int v[], int nova_capacidade)
{
  return realloc(v, nova_capacidade * sizeof(int));
}





// Intuição:
//
// - começamos com uma capacidade pequena
//
// - vamos lendo valores e guardando-os no array
//
// - quando o array fica cheio, duplicamos a capacidade com
//   realloc
//
// - no fim, mostramos os elementos guardados e libertamos a
//   memória

int main(void)
{
  int *v;
  int *temp;
  
  int nelem;
  
  int size;
  int new_size;
  
  int valor;

  size = INITIAL_SIZE;
  nelem = 0;

  v = criar_array(size);

  if(v == NULL)
  { printf("Erro: nao foi possivel alocar memoria.\n");
    return 1;
  }

  printf("Capacidade inicial: %d elementos\n", size);
  valor = ler_valor();

  while(valor != EXIT_VALUE)
  { if(nelem == size)
    {
      // array encontra-se "cheio"
      // vamos tentar duplicar a sua capacidade
      // guardamos o resultado em 'temp' e nao diretamente em 'v'

      new_size = size * 2;
      temp = aumentar_capacidade(v, new_size);

      if(temp == NULL)
      { printf("Erro: nao foi possivel aumentar a capacidade.\n");
        free(v);
        return 1;
      }

      v = temp;
      size = new_size;

      printf("Capacidade aumentada para %d elementos.\n", size);
    }

    v[nelem] = valor;
    nelem++;

    valor = ler_valor();
  }

  printf("\n");
  printf("Numero de elementos guardados: %d\n", nelem);
  printf("Capacidade final do array: %d\n", size);
  printf("\n");

  imprimir_array(v, nelem);

  free(v);

  return 0;
}
