// Inicialização de strings. Algumas notas de seguida:
//
// - Em C, uma string é representada como um array de caracteres
//   terminado pelo carácter nulo \0.
//
// - Uma "string literal" (em C) é uma sequência de caracteres 
//   escrita entre aspas (por exemplo "Hello"), que o compilador
//   armazena em "memória apenas de leitura" (normalmente na secção
//   de dados estáticos do programa) como um array de caracteres
//   terminado pelo carácter nulo: '\0'.

#include <stdio.h>

int main(void)
{

  // //////////////////////////////////////////////////////////////////////////

  // string inicializada com uma cópia da string literal "Ola"
  // - observe o resultado do seguinte printf, onde é impresso sizeof(s1)
  // - sizeof(s1) corresponde ao tamanho em bytes de s1
  // - de notar que um char ocupa 1 byte; O valor 4 é impresso, o que significa 
  //   que é também alocado o espaço correspondente a '\0'

  char s1[] = "Ola";
  printf("s1: %s; sizeof(s1): %zu\n", s1, sizeof(s1));


  // tamanho 4 para haver espaço para o '\0' (ler mais informação acima)
  char s2[4] = "ABC";
  printf("s2: %s; sizeof(s2): %zu\n", s2, sizeof(s2));

  // podemos modificar s2, por exemplo:
  s2[0] = 'a';
  printf("s2 apos modificacao: %s; sizeof(s2): %zu\n", s2, sizeof(s2));

  // exemplo de inicialização explícita (desta forma devemos colocar o '\0') 
  char s3[] = {'o', 'l', 'a', '\0'};
  printf("s3: %s; sizeof(s3): %zu\n", s3, sizeof(s3));

  // podemos declarar mais espaço que o necessário: por vezes é útil 
  char s4[10] = "ABC";
  printf("s4: %s; sizeof(s4): %zu\n", s4, sizeof(s4));

  // //////////////////////////////////////////////////////////////////////////

  // problema comum: esquecer o '\0' quando utilizada a forma de
  // inicialização explícita

  char s5[3] = {'z', 'y', 'x'};

  printf("s5 (undefined behaviour): %s; sizeof(s5): %zu\n\n", s5, sizeof(s5));  

  // declarar 'char *var = "texto";' ou 'char var[] = "texto";' é diferente:
  //   1. char *var = "texto"; declara uma variável chamada var que aponta para
  //      uma string literal (read-only)
  //   2. char var[] = "texto"; declara um array que contém uma cópia de uma
  //      string literal; (read and write)

  // Como tal, da seguinte forma, podemos ler mas não podemos escrever;
  char *c1 = "Constante";

  printf("c1: %s; sizeof(c1): %zu\n", c1, sizeof(c1));

  // remova o comentário da seguinte atribuição e verifique o que acontece:
  // (disclaimer: segmentation fault)
  // c1[0] = 'A';
  printf("primeiro char de c1: %c\n", c1[0]);  

  return 0;
}
