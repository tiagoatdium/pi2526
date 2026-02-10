#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int nota = 0, count = 0;
  srand(time(NULL));
  while(1)
  {
    nota = rand() % 101;
    if(nota > 90)
      break;
    else
    { printf("%d\n", nota);
      count += 1;
    }
  }

  printf("Eu vou tirar boa nota a PI: %d %%.\n", nota);
  printf("Mas precisei de %d tentativas.\n", count);
  return 0;
}
