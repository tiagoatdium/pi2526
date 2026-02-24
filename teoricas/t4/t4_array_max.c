#include <stdio.h>

int max_array(int *max_res, int *a, size_t s)
{
  size_t i;
  int max;

  // e se... pointers forem NULL?

  if(s == 0)
    return -1;

  max = a[0];
  for(i=1; i<s; i++)
    if(max < a[i])
      max = a[i];

  *max_res = max;

  return 0;
}

int main(void)
{
  int a[3] = {1,10,0};
  int b[6] = {1,10,0,-1,1000,0};
  int r, max;

  r = max_array(&max, a, 3);
  printf("return: %d; max: %d\n", r, max);

  r = max_array(&max, b, 6);
  printf("return: %d; max: %d\n", r, max);

  return r;
}






