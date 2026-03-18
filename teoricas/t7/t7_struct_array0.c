#include <stdio.h>

// objetivo deste exemplo:
// - aprender a lidar com arrays de structs e funções, 
//   percorrendo os dados para calcular valores (neste
//   caso, será a nota final de um aluno) e encontrar
//   um resultado.
//
// - neste programa, teremos um conjunto de alunos, cada
//   um com duas notas, uma teórica e uma prática.
//
// - o objetivo é calcular a nota final de cada aluno e
//   identificar o aluno com a melhor nota final


// definição da struct Aluno
typedef struct
{
  int numero;
  char nome[50];
  float nota_pratica;
  float nota_teorica;
} Aluno;

// função para calcular a nota final (ambas as componentes de
// avaliação tem o mesmo peso)

float calcular_nota(Aluno a)
{
  return (a.nota_pratica + a.nota_teorica) / 2.0;
}

int main(void)
{
  #define N_ALUNOS 4

  // array de alunos (note a forma como é inicializado o array)
  Aluno alunos[N_ALUNOS] =
  {
    {1001, "Ana",   15.0, 16.0},
    {1002, "Bruno", 12.0, 14.0},
    {1003, "Carla", 18.0, 17.0},
    {1004, "Diogo", 14.0, 13.0}
  };

  int i;
  int index_max;
  float nota, nota_max;

  // o objectivo é encontrar o aluno com a melhor nota final;
  // relembre a intuição para o algoritmo que encontra o valor
  // máximo num array: 
  // - começamos por "dizer" que o valor máximo é o do primeiro
  //   índice (linha de código seguinte)
  // - depois, percorremos os restantes elementos do array e
  //   vamos actualizando caso se encontre um valor (nota) maior
  //   que o actual

  nota_max = calcular_nota(alunos[0]);
  index_max = 0;

  for(i = 1; i < N_ALUNOS; i++)
  {
    nota = calcular_nota(alunos[i]);

    if(nota > nota_max)
    { nota_max = nota;
      index_max = i;
    }
  }

  // imprimir o resultado
  printf("Aluno com a melhor nota:\n");
  printf("  Numero: %d\n", alunos[index_max].numero);
  printf("  Nome: %s\n", alunos[index_max].nome);
  printf("  Nota: %.2f\n", nota_max);

  return 0;

  #undef N_ALUNOS
}
