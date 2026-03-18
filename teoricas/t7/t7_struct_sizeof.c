#include <stdio.h>

// exemplo 1:
// após o campo 'c' (1 byte), o compilador poderá inserir bytes
// de "padding" antes de 'x', para que o 'int x' fique alinhado
// (ou seja, comece num endereço de memória múltiplo do seu tamanho,
// tipicamente múltiplo de 4 bytes; de forma breve, o alinhamento é
// importante para tornar o acesso à memória mais rápido.)

typedef struct
{
  char c; // 1 byte
  int x;  // 4 bytes
} Ex1;

// exemplo 2:
// além do possível padding antes de 'x', poderá também existir
// padding no fim da struct, para que o tamanho total fique
// alinhado
typedef struct
{
  char c;   // 1 byte
  int x;    // 4 bytes
  char v;   // 1 byte
} Ex2;

// segue-se um exemplo de valores impressos pela seguinte
// função main:
//   
//   sizeof(char) = 1
//   sizeof(int) = 4
//   
//   sizeof(Ex1) = 8
//   sizeof(Ex2) = 12
//   
//   enderecos em Ex1:
//     &e1   = 0x7ffce9e3dd84
//     &e1.c = 0x7ffce9e3dd84
//     &e1.x = 0x7ffce9e3dd88
//   
//   enderecos em Ex2:
//     &e2   = 0x7ffce9e3dd8c
//     &e2.c = 0x7ffce9e3dd8c
//     &e2.x = 0x7ffce9e3dd90
//     &e2.v = 0x7ffce9e3dd94

int main()
{
  Ex1 e1;
  Ex2 e2;

  // tamanhos dos tipos base
  printf("sizeof(char) = %zu\n", sizeof(char));
  printf("sizeof(int) = %zu\n\n", sizeof(int));

  // tamanhos das structs
  printf("sizeof(Ex1) = %zu\n", sizeof(Ex1));
  printf("sizeof(Ex2) = %zu\n\n", sizeof(Ex2));

  // endereços dos campos de Ex1
  printf("enderecos em Ex1:\n");
  printf("  &e1   = %p\n", (void*)&e1);
  printf("  &e1.c = %p\n", (void*)&e1.c);
  printf("  &e1.x = %p\n\n", (void*)&e1.x);

  // endereços dos campos de Ex2
  printf("enderecos em Ex2:\n");
  printf("  &e2   = %p\n", (void*)&e2);
  printf("  &e2.c = %p\n", (void*)&e2.c);
  printf("  &e2.x = %p\n", (void*)&e2.x);
  printf("  &e2.v = %p\n", (void*)&e2.v);

  return 0;
}
