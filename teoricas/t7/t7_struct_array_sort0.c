#include <stdio.h>

// mais uma evolução do exemplo anterior:
//
// - em vez de procurar apenas o aluno com melhor nota, queremos
//   agora ordenar todos os alunos por nota final
//
// - tal como no exemplo anterior, vamos trabalhar com apontadores
//   para structs (pAluno), evitando cópias desnecessárias dos alunos
//
// - a ordenação será feita sobre um array de apontadores;
//   assim, os alunos originais não são movidos em memória:
//   apenas mudamos a ordem dos apontadores

// definição da struct Aluno e do tipo pAluno
typedef struct
{
  int numero;
  char nome[50];
  float nota_pratica;
  float nota_teorica;
} Aluno, *pAluno;

// função para calcular a nota final
// recebe um apontador para Aluno
float calcular_nota(pAluno a)
{
  return (a->nota_pratica + a->nota_teorica) / 2.0;
}

// função de troca de apontadores (note que pAluno *a, correponde a Aluno **a)
void trocar(pAluno *a, pAluno *b)
{
  pAluno temp = *a;
  *a = *b;
  *b = temp;
}

// bubble sort (ordena por nota final decrescente)
void bubble_sort_aluno_nota_final(pAluno alunos[], int n)
{
  int i, j;

  for(i = 0; i < n - 1; i++)
  { for(j = 0; j < n - i - 1; j++)
    { if (calcular_nota(alunos[j]) < calcular_nota(alunos[j + 1]))
      { 
        // exercício: 1. comente a seguinte linha e faça a troca sem invocar uma função
        // 2. de seguida apague a função trocar e tente entender (utilizando desenhos e
        //    papel, por exemplo) a necessidade de se precisar de pAluno * (que é 
        //    equivalente a Aluno **) para se realizar essa troca no contexto de uma
        //    função.
        // 3. Quando entender, implemente a função novamente.
        trocar(&alunos[j], &alunos[j + 1]);
      }
    }
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

  // array de apontadores para alunos
  pAluno pAlunos[N_ALUNOS];
  int i;

  // exercício: implemente uma função que inializa o array pAlunos
  // e substitua o loop seguinte por uma chamada a essa função
  for (i = 0; i < N_ALUNOS; i++)
  { pAlunos[i] = &alunos[i]; }

  // ordenar apontadores por nota final
  bubble_sort_aluno_nota_final(pAlunos, N_ALUNOS);


  printf("Alunos ordenados por nota final:\n");
  for (i = 0; i < N_ALUNOS; i++)
  {
    printf("%d - %s - nota: %.2f\n",
           pAlunos[i]->numero,
           pAlunos[i]->nome,
           calcular_nota(pAlunos[i]));
  }

  return 0;

  #undef N_ALUNOS
}
