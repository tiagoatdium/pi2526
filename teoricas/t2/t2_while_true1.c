#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int i, nota, count;
  double media;
  srand(time(NULL));  
  
  i = 0;
  media = 0.0;
  while(i < 579)
  {
    count = 0;
    while(1)
    {
      nota = rand() % 101;
      if(nota > 90)
        break;
      else
        count += 1;
    }
    media += (double) count;
    i += 1;
  }
  
  media = media / 579.0;
  
  printf("Número médio de tentativas %.2lf.\n", media);
  return 0;
}
