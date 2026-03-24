#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INITIAL_SIZE 3
#define EXIT_VALUE -1

typedef struct
{
  int *data;
  int nelem;
  int size;
} DArrayInt;




int ler_valor(void)
{
  int r, valor;
  printf("Introduza um valor (%d para terminar): ", EXIT_VALUE);
  r = scanf("%d", &valor);
  assert(r == 1);
  return valor;
}




//
// A função seguinte retorna:
// - 1 em caso de sucesso
// - 0 em caso de erro
//
int array_init(DArrayInt *a, int capacidade_inicial)
{
  assert(a != NULL);
  assert(capacidade_inicial > 0);

  a->data = malloc(capacidade_inicial * sizeof(int));

  if(a->data == NULL)
  { a->nelem = 0;
    a->size = 0;
    return 0;
  }

  a->nelem = 0;
  a->size = capacidade_inicial;

  return 1;
}




//
// Depois da execução da seguinte função:
// - a memória apontada por a->data deixa de estar disponível;
// - os campos da struct são colocados num estado "vazio".
//
void array_destroy(DArrayInt *a)
{
  assert(a != NULL);

  free(a->data);

  a->data = NULL;
  a->nelem = 0;
  a->size = 0;
}




//
// Imprime os elementos atualmente guardados no array.
// Apenas imprime os primeiros 'nelem' elementos.
//
void array_print(const DArrayInt *a)
{
  int i;
  assert(a != NULL);
  for(i = 0; i < a->nelem; i++)
  { printf("%d ", a->data[i]); }
  printf("\n");
}




// A função seguinte tenta aumentar a capacidade do array dinâmico.
// Neste exemplo, a nova capacidade é o dobro da capacidade atual.
//
// A função devolve:
// - 1 em caso de sucesso
// - 0 em caso de erro
//
// Nota importante:
// - usa-se um apontador temporário para guardar o resultado
//   de realloc
// - se realloc falhar, a memória antiga continua válida;
//   por isso, não devemos perder o apontador original
//
int array_expand(DArrayInt *a)
{
  int *temp;
  int nova_capacidade;

  assert(a != NULL);
  assert(a->data != NULL);
  assert(a->size > 0);

  nova_capacidade = a->size * 2;
  temp = realloc(a->data, nova_capacidade * sizeof(int));

  if(temp == NULL)
  { return 0; }

  a->data = temp;
  a->size = nova_capacidade;

  return 1;
}




//
// Acrescenta um novo valor no fim do array dinâmico
//
int array_push_back(DArrayInt *a, int valor)
{
  assert(a != NULL);
  assert(a->data != NULL);
  assert(a->nelem >= 0);
  assert(a->size > 0);
  assert(a->nelem <= a->size);

  if(a->nelem == a->size) // capacidade máxima atingida
  { if(!array_expand(a))
    { return 0; } // 0 => falhou
  }

  a->data[a->nelem] = valor;
  a->nelem++;

  return 1; // 1 => OK
}




//
// Mostra alguma informação de estado sobre o array.
//
void array_info(const DArrayInt *a)
{
  assert(a != NULL);

  printf("   numero de elementos guardados: %d\n", a->nelem);
  printf("   capacidade atual: %d\n", a->size);
}




int main(void)
{
  DArrayInt a;
  int valor;

	// questão: porquê &a? quais as vantagens
  if(array_init(&a, INITIAL_SIZE) == 0)
  { printf("Erro: nao foi possivel alocar memoria.\n");
    return 1;
  }
  printf("Capacidade inicial: %d elementos\n", a.size);


  valor = ler_valor();

  while(valor != EXIT_VALUE)
  { if(!array_push_back(&a, valor))
    { printf("Erro: nao foi possivel aumentar a capacidade.\n");
      array_destroy(&a);
      return 1;
    }

    array_info(&a);
    valor = ler_valor();
  }

  printf("\n");
  printf("Estado final do array:\n");
  array_info(&a);
  printf("\n");

  array_print(&a);
  array_destroy(&a);

  return 0;
}
