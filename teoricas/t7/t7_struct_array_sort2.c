#include <stdio.h>

// este ficheiro não aparece indexado no README.md correspondente
// de forma propositada.
//
// resolução do problema anterior:
// - queremos evitar duplicação de código nas funções de ordenação
// - a única diferença entre elas é o critério de comparação
//
// solução:
// - passar a função de comparação como argumento
// - assim, o algoritmo de ordenação é escrito apenas uma vez

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


// funções de comparação (devolvem 1 se a deve aparecer antes de b)

int cmp_nota_final(pAluno a, pAluno b)
{
  return calcular_nota_final(a) > calcular_nota_final(b);
}

int cmp_nota_teorica(pAluno a, pAluno b)
{
  return a->nota_teorica > b->nota_teorica;
}

int cmp_nota_pratica(pAluno a, pAluno b)
{
  return a->nota_pratica > b->nota_pratica;
}

void trocar(pAluno *a, pAluno *b)
{
  pAluno temp = *a;
  *a = *b;
  *b = temp;
}


// bubble sort genérico
// recebe uma função de comparação como argumento
void bubble_sort(pAluno alunos[],
                 int n,
                 int (*comparar)(pAluno, pAluno))
{
  int i, j;

  for(i = 0; i < n - 1; i++)
  { for(j = 0; j < n - i - 1; j++)
    { if(!comparar(alunos[j], alunos[j + 1]))
      { trocar(&alunos[j], &alunos[j + 1]);
      }
    }
  }
}

void inicializar_indice(pAluno indice[], Aluno alunos[], int n)
{
  int i;

  for(i = 0; i < n; i++)
  { indice[i] = &alunos[i];
  }
}

void imprimir_indice(pAluno alunos[], int n)
{
  int i;

  for(i = 0; i < n; i++)
  {
    printf("%d - %s - pratica: %.2f - teorica: %.2f - final: %.2f\n",
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
  {
    {1001, "Ana",   15.0, 16.0},
    {1002, "Bruno", 12.0, 14.0},
    {1003, "Carla", 18.0, 17.0},
    {1004, "Diogo", 14.0, 13.0}
  };

  pAluno idx_final[N_ALUNOS];
  pAluno idx_teorica[N_ALUNOS];
  pAluno idx_pratica[N_ALUNOS];

  inicializar_indice(idx_final, alunos, N_ALUNOS);
  inicializar_indice(idx_teorica, alunos, N_ALUNOS);
  inicializar_indice(idx_pratica, alunos, N_ALUNOS);

  // usar a mesma função bubble_sort mas passamos 
  // a função de comparação que pretendemos
  bubble_sort(idx_final, N_ALUNOS, cmp_nota_final);
  bubble_sort(idx_teorica, N_ALUNOS, cmp_nota_teorica);
  bubble_sort(idx_pratica, N_ALUNOS, cmp_nota_pratica);

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
