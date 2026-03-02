#include <stdio.h>

// neste ficheiro exemplo, passamos (em comparação com o ficheiro t5_matrix1.c)
// de "matrix[MLINES][MCOLS]" para "matrix[][MCOLS]"
//
// notas:
// - na solução "matrix1[MLINES][MCOLS]", utilizada no ficheiro t5_matrix1.c, devem
//   ser conhecidos ambos os tamanhos (sucintamente, devem ser conhecidos em tempo
//   de compilação)
//
// - neste ficheiro dado que é utilizado "matrix[][MCOLS]", apenas o número de colunas
//   necessita de ser conhecido (durante a compilação); 
//
// - a vantagem é que o código passa a ser (ligeiramente) mais genérico:
//   - a mesma função permite operar sobre matrizes com um número de linhas diferente
//
// nota: uma matriz matrix[MLINES][MCOLS] pode ser vista 

#define MCOLS 6

void init_matrix(int matrix[][MCOLS], size_t lines)
{
  size_t i, j;
  int c;

  c = 0;
  for(i=0; i < lines; i++)
  { for(j=0; j < MCOLS; j++, c++)
    { matrix[i][j] = c; }
  }
}

void print_matrix(int matrix[][MCOLS], size_t lines)
{
  size_t i, j;

  for(i=0; i < lines; i++)
  { for(j=0; j < MCOLS; j++)
    { printf("%2d ", matrix[i][j]); }
    putchar('\n');
  }
}

int main(void)
{
  int matrix0[3][MCOLS] = {0};
  int matrix1[5][MCOLS] = {0};

  init_matrix(matrix0, 3);
  init_matrix(matrix1, 5);
   
  print_matrix(matrix0, 3);
  putchar('\n');
  print_matrix(matrix1, 5);

  return 0;
}
