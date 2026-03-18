#include <stdio.h>

// definição da estrutura
typedef struct
{
  int numero;
  char nome[50];
  float nota_pratica;
  float nota_teorica;
} Aluno;

// função para calcular a média
float calcular_media(Aluno a)
{
  return (a.nota_pratica + a.nota_teorica) / 2.0;
}

int main(void)
{
  #define N_ALUNOS 4

  // array de alunos (inicialização direta)
  Aluno alunos[N_ALUNOS] =
  {
    {1001, "Ana",   15.0, 16.0},
    {1002, "Bruno", 12.0, 14.0},
    {1003, "Carla", 18.0, 17.0},
    {1004, "Diogo", 14.0, 13.0}
  };

  int i;
  int idx_max = 0;

  // guardar média do melhor aluno (evita recomputações)
  float media_max = calcular_media(alunos[0]);

  // procurar aluno com maior média
  for (i = 1; i < N_ALUNOS; i++)
  {
    float media = calcular_media(alunos[i]);

    if (media > media_max)
    {
      media_max = media;
      idx_max = i;
    }
  }

  // resultado
  printf("Aluno com melhor media:\n");
  printf("  Numero: %d\n", alunos[idx_max].numero);
  printf("  Nome: %s\n", alunos[idx_max].nome);
  printf("  Media: %.2f\n", media_max);

  return 0;

  #undef N_ALUNOS
}
