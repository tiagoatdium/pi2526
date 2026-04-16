#include <stdio.h>
#include <assert.h>


int funcao(int x)
{
	int r = 0;

  switch(x)
  {
    case 1:
      r = 10;
      break;
    case 2:
      r = 20;
      break;
    case 3:
      r = 30;
      break;
    default:
      r = -1;
  }
  
  return r;
}

int main(void)
{
  
  int r = funcao(2);
  printf("%d\n", r);

  return 0;
}
