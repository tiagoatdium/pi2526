#include <stdio.h>

// man 3 putchar

int main(void)
{
  int i, c;

  putchar('a');
  putchar('\n');

  c = '\n';
  printf("c = '\\n'; c=%d\n", c);

  c = 'a';
  printf("c = 'a';  c=%d\n", c);
  
  c = 'A';
  printf("c = 'A';  c=%d\n", c);
  
  for(i=65; i<65+26; i++)
    putchar(i);
  putchar(10);
 
  printf("%d\n", ' ');
   
  for(i='A'; i<='Z'; i++)
    putchar(i);
  putchar(10);
   
  for(i='A'; i<='Z'; i++)
    putchar(i+32);
  putchar(10);


  #if 0
  //
    
  //

  
  //

  
  //

  
  #endif
  return 0;
}
