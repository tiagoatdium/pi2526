#include <stdio.h>

// evolução do exemplo anterior:
//  - em vez de trabalhar diretamente com structs, passamos a usar
//   apontadores para structs (pAluno)
//
// isto permite:
//  - evitar cópias desnecessárias de structs ao passar para funções
//  - preparar para o uso de estruturas mais complexas (listas, etc.)
//
// adicionalmente, a lógica de cálculo do máximo foi isolada numa
//   função, tornando o programa mais modular

typedef struct
{
  int numero;
  char nome[50];
  float nota_pratica;
  float nota_teorica;
} Aluno, *pAluno;

// função para calcular a nota final
// recebe agora um apontador para Aluno
// - como tal, utiliza-se '->' ao invés de '.'
float calcular_nota(pAluno a)
{
  return (a->nota_pratica + a->nota_teorica) / 2.0;
}

// devolve o índice do aluno com melhor nota
int index_aluno_max(pAluno alunos[], int n)
{
  int i;
  int index_max;
  float nota, nota_max;

  // assumir que o primeiro aluno tem a melhor nota
  nota_max = calcular_nota(alunos[0]);
  index_max = 0;

  // percorrer os restantes alunos
  for(i = 1; i < n; i++)
  { nota = calcular_nota(alunos[i]);

    if (nota > nota_max)
    { nota_max = nota;
      index_max = i;
    }
  }

  return index_max;
}

int main(void)
{
  #define N_ALUNOS 4

  // array principal de alunos
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
  int index_max;

  // inicializar array de apontadores
  for (i = 0; i < N_ALUNOS; i++)
  { pAlunos[i] = &alunos[i]; }

  // calcular o índice do aluno com melhor nota
  index_max = index_aluno_max(pAlunos, N_ALUNOS);

  // imprimir o resultado
  printf("(versão pAluno) Aluno com a melhor nota:\n");
  printf("  Numero: %d\n", pAlunos[index_max]->numero);
  printf("  Nome: %s\n", pAlunos[index_max]->nome);
  printf("  Nota: %.2f\n", calcular_nota(pAlunos[index_max]));

  return 0;

  #undef N_ALUNOS
}
