#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // declaração de variáveis: também poderia ser int a, b, c; int *ap;
  int a;
  int b;
  int c;
  int *ap; // pode-se ler como "a pointer" (não é obrigatório utilizar como
           // sufixo 'p' em variáveis que são apontadores, mas por vezes
           // facilita a leitura de código)

  a = 1;   // inicializar a variável 'a' com o valor 1
  b = 2;   // inicializar a variável 'b' com o valor 2
  
  ap = &a; // inicializar a variável 'ap' com o endereço de memória da variável 'a'
  
  c = *ap; // '*ap' permite aceder ao valor que se encontra no endereço de memória
           // da variável; como ap contém o endereço de memória da variável 'a', 
           // então '*ap' permite ler o valor de 'a'. Seria equivalente a escrever
           // 'c = a;'

  // Uma das coisas que foi "varrida para debaixo do tapete" durante esta primeira aula
  // sobre apontadores foi o '(void*)' que aparece no seguinte printf (para manter a
  // discussão simples e focada na essência do problema).
  //
  // 1. Experimente remover '(void*)' e tente compilar; observe o warning:
  //    -"format '%p' expects argument of type 'void *'"
  //
  // 2. O especificador de formato %p espera receber um argumento do tipo 'void *'
  //    (isto é, um apontador para void).
  //
  // 3. Um 'void*' pode ser visto como um apontador genérico, isto é, um apontador
  //    sem tipo associado, que pode representar o endereço de qualquer variável
  //    (com qualquer tipo).
  //
  // 4. O statement '(void*)ap' converte 'ap' de 'int*' para 'void*'. Esta conversão
  //    explícita  para '(void*)' garante compatibilidade com o formato %p e evita
  //    warnings do compilador. Conversões entre tipos, em C, chamam-se de casts.
  //
  printf("          a=%d b=%d c=%d ap=%p\n", a, b, c, (void*)ap);


  // tente compreender quais os valores impressos no seguinte print antes de executar
  a++; // incrementa 'a'
  b++; // incrementa 'b'
  *ap += 1; // ...
  c++;
  void *apv = (void*)ap; // inicializa a variável apv com uma conversão de ap para void*
                         // na prática ambas as variáveis (apv e ap) contém o mesmo valor;
                         // apenas tem tipos diferentes --- o que mudará alguns comportamentos
                         // particularmente relevantes quando falarmos de arrays (mas deixamos
                         // isso para as aulas seguintes)
                         
  *((int*)apv) += 1; // pode-se ler +/- da seguinte forma: o valor apontado por uma conversão
                     // de apv para int* (recorde que apv é um void*) é incrementado em 1
  
  printf("após inc: a=%d b=%d c=%d ap=%p\n", a, b, c, apv);
  
  return 0;
}
