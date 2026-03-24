#include <stdio.h>
#include <stdlib.h> // malloc // man 3 malloc
#include <assert.h>

// Motivação:
//
// No ficheiro anterior observamos arrays locais com tamanho fixo.
//
// Neste ficheiro:
//  - vamos criar um array cujo tamanho é "escolhido" durante a
//    execução do programa.
//
// Para isso usamos a função malloc, que permite reservar memória
// dinamicamente. Ao consultar 'man 3 malloc', podemos observar:
//
// - void *malloc(size_t size);
//
// Intuições:
//
// - o tamanho do array pode ser escolhido pelo utilizador
//   (directa ou indirectamente)
//
// - a memória reservada com malloc tem de ser libertada
//   explicitamente através de uma chamada à função free
//
// Ao consultar 'man 3 free', podemos observar:
//
// - void free(void *ptr);
//
// Notas:
//  O conteúdo inicial da memória devolvida por malloc
//  não está, garantidamente, inicializado:
//
// - se, numa certa execução, parecer que o array ficou "cheio
//   de zeros", isso é apenas um acaso e não uma garantia da
//   linguagem C.
//
// - noutras execuções, noutro compilador, noutro sistema, ou
//   até no mesmo programa, essa mesma memória pode conter
//   outros valores.
//
// - por isso, não devemos assumir que a memória devolvida por
//   malloc está inicializada.
//
// - se precisarmos de memória inicializada a zero, devemos
//   usar calloc (ver exemplo seguinte), ou então escrever
//   explicitamente os valores pretendidos antes de ler o array.
//
  



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
// Descrição:
// - ler o tamanho pretendido
// - reservar memória para n inteiros
// - verificar se a alocação correu bem
// - preencher e imprimir o array
// - libertar a memória no fim
//
int main(void)
{
  int n;
  int *v;

  n = ler_tamanho();

  if(n <= 0)
  { printf("O numero de elementos deve ser positivo.\n");
    return 1;
  }

  //
  // De forma simplificada, existem duas zonas de memória frequentemente
  // referidas em C:
  //
  //   - a stack, usada tipicamente para variáveis locais e para
  //     dados com tempo de vida automático
  //
  //   - a heap, usada para memória alocada dinamicamente,
  //     normalmente através de 'malloc', 'calloc' e 'realloc'
  //
  // A diferença principal, neste contexto, é a forma como a memória
  // é gerida:
  //
  //   - a memória associada a variáveis locais (stack) é gerida
  //     automaticamente e deixa de existir quando a função termina;
  //
  //   - a memória na heap continua a existir até ser libertada
  //     explicitamente com free.
  //
  // Neste exemplo, 'malloc' reserva, na heap, memória suficiente
  // para guardar 'n' inteiros.
  //
  // - 'sizeof(int)' indica quantos bytes ocupa um inteiro numa
  //   determinada máquina; assim, 'n * sizeof(int)' é o número
  //   total de bytes que queremos alocar.
  //
  // O valor devolvido por 'malloc' corresponde o endereço inicial
  // da zona de memória reservada.
  //
  // Esse endereço fica guardado em 'v', que é um apontador para inteiros.
  //
  v = malloc(n * sizeof(int));

  // se malloc devolver NULL, significa que a alocação de memória falhou
  // (por exemplo, o sistema não tem memória disponível)
  if(v == NULL)
  { printf("Erro: nao foi possivel alocar memoria.\n");
    return 1;
  }

  preencher_array(v, n);
  imprimir_array(v, n);

  // como a região de memória apontada por 'v' foi alocada
  // dinamicamente (através de malloc), temos de a libertar
  // explicitamente com 'free' quando já não for necessária.
  //
  // se isso não for feito, ocorre um memory leak:
  // o programa "perde" essa memória no sentido em que deixa
  // de a reutilizar, mas ela continua reservada até ao fim
  // do processo.
  //
  // num programa pequeno isto pode não ser visível, mas em
  // programas maiores ou de longa duração, vários memory leaks
  // podem fazer o consumo de memória crescer continuamente,
  // podendo degradar o desempenho ou até levar à terminação
  // do processo (por falta de memória).
  //
  // dependendo do sistema, memory leaks podem provocar falhas
  // noutros programas e até levar à terminação forçada de
  // processos pelo sistema operativo.
  
  // nota: experimente comentar a seguinte linha, compilar o
  //       programa, e correr o programa com o valgrind. Por exemplo:
  //         valgrind --leak-check=full ./malloc_array0
  //       observe o resultado com e sem chamada à função free
  free(v);

  return 0;
}
