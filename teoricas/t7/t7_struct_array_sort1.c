#include <stdio.h>

// no exemplo anterior ordenamos alunos por um critério (nota final),
// utilizando uma função de ordenação (bubble sort).
//
// no entanto, neste exemplo queremos ordenar os mesmos alunos segundo
// vários critérios diferentes:
//   - nota final
//   - nota teórica
//   - nota prática
//
// uma abordagem possível será escrever várias funções de ordenação:
//
//   bubble_sort_nota_final(...)
//   bubble_sort_nota_teorica(...)
//   bubble_sort_nota_pratica(...)
//
// mas estas funções seriam praticamente iguais, mudando apenas
// a forma como comparamos dois alunos.
//
// isto leva a:
//   - duplicação de código
//   - código mais difícil de manter
//
// idealmente, gostaríamos de escrever o algoritmo de ordenação
// apenas uma vez, e variar apenas o critério de comparação.
//
// este problema motiva a necessidade de passar comportamento
// (neste caso, a comparação) como argumento para funções,
// algo que veremos mais à frente. Para já, estude bem o problema
// seguinte.

// definição da struct Aluno e do tipo pAluno
typedef struct
{
  int numero;
  char nome[50];
  float nota_pratica;
  float nota_teorica;
} Aluno, *pAluno;


float calcular_nota_final(pAluno a)
{
  return (a->nota_pratica + a->nota_teorica) / 2.0;
}

void trocar(pAluno *a, pAluno *b)
{
  pAluno temp = *a;
  *a = *b;
  *b = temp;
}


// três versões de bubble sort (observe como são muito semelhantes)

// ordena por nota final (decrescente); exercício: altere para crescente
void bubble_sort_nota_final(pAluno alunos[], int n)
{
  int i, j;

  for(i = 0; i < n - 1; i++)
  { for(j = 0; j < n - i - 1; j++)
    { if (calcular_nota_final(alunos[j]) < calcular_nota_final(alunos[j + 1]))
      { trocar(&alunos[j], &alunos[j + 1]);
      }
    }
  }
}

// ordena por nota teórica (decrescente)
void bubble_sort_nota_teorica(pAluno alunos[], int n)
{
  int i, j;

  for(i = 0; i < n - 1; i++)
  { for(j = 0; j < n - i - 1; j++)
    { if (alunos[j]->nota_teorica < alunos[j + 1]->nota_teorica)
      { trocar(&alunos[j], &alunos[j + 1]);
      }
    }
  }
}

// ordena por nota prática (decrescente)
void bubble_sort_nota_pratica(pAluno alunos[], int n)
{
  int i, j;

  for(i = 0; i < n - 1; i++)
  { for(j = 0; j < n - i - 1; j++)
    { if (alunos[j]->nota_pratica < alunos[j + 1]->nota_pratica)
      { trocar(&alunos[j], &alunos[j + 1]);
      }
    }
  }
}


// inicializar índice (array de apontadores)
void inicializar_indice(pAluno indice[], Aluno alunos[], int n)
{
  int i;

  for(i = 0; i < n; i++)
  { indice[i] = &alunos[i]; }
}

void imprimir_indice(pAluno alunos[], int n)
{
  int i;

  for(i = 0; i < n; i++)
  { printf("%d - %s - pratica: %.2f - teorica: %.2f - final: %.2f\n",
           alunos[i]->numero,
           alunos[i]->nome,
           alunos[i]->nota_pratica,
           alunos[i]->nota_teorica,
           calcular_nota_final(alunos[i]));
  }
}


int main(void)
{
  #define N_ALUNOS 4

  Aluno alunos[N_ALUNOS] =
  { {1001, "Ana",   15.0, 16.0},
    {1002, "Bruno", 12.0, 14.0},
    {1003, "Carla", 18.0, 17.0},
    {1004, "Diogo", 14.0, 13.0}
  };

  // três índices para os mesmos alunos
  pAluno idx_final[N_ALUNOS];
  pAluno idx_teorica[N_ALUNOS];
  pAluno idx_pratica[N_ALUNOS];

  // inicializar índices
  inicializar_indice(idx_final, alunos, N_ALUNOS);
  inicializar_indice(idx_teorica, alunos, N_ALUNOS);
  inicializar_indice(idx_pratica, alunos, N_ALUNOS);

  // ordenar cada índice com um critério diferente
  bubble_sort_nota_final(idx_final, N_ALUNOS);
  bubble_sort_nota_teorica(idx_teorica, N_ALUNOS);
  bubble_sort_nota_pratica(idx_pratica, N_ALUNOS);

  printf("Ordenado por nota final:\n");
  imprimir_indice(idx_final, N_ALUNOS);
  printf("\n");

  printf("Ordenado por nota teorica:\n");
  imprimir_indice(idx_teorica, N_ALUNOS);
  printf("\n");

  printf("Ordenado por nota pratica:\n");
  imprimir_indice(idx_pratica, N_ALUNOS);
  printf("\n");

  return 0;

  #undef N_ALUNOS
}
