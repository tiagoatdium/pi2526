#include <stdio.h>

// typedef permite criar um nome alternativo para um tipo de dados,
// podendo ser utilizado, por exemplo, para tornar o código mais
// fácil de interpretar e, dependendo do caso, até mais fácil de
// actualizar

// seguem-se algums exemplos de utilização de typedef
// - no primeiro exemplo, definimos que 'Idade' corresponde a 'int'
//   - isto significa que podemos utilizar 'Idade' para declarar
//     variáveis, passar argumentos e declarar tipos de retorno
//
// - os exemplos seguintes são semelhantes
//
// - considere o seguinte cenário: desenvolvemos um programa (digamos,
//   complexo) que utiliza 'Codigo'. Definido com typedef, se quisermos
//   alterar 'Codigo' de 'unsigned int' para 'unsigned long' (por um
//   motivo qualquer, como por exemplo, passamos a precisar de 'Codigo'(s)
//   com mais dígitos, a tarefa é simplificada: a identificação das
//   funções C que utilizam 'Codigo' é fácil (find) e a alteração
//   de tipo apenas ocorre num sítio (o local onde se encontra presente
//   o statement 'typedef unsigned int Codigo;').

typedef int Idade;
typedef float Salario;
typedef unsigned int Codigo;

// função que usa Salario
Salario aumentar_salario(Salario s, float percentagem)
{
  return s + s * percentagem / 100.0;
}

int main(void)
{
  Idade idade = 30;
  Salario salario = 1000.0;
  Codigo codigo = 12345;

  printf("Codigo: %u\n", codigo);
  printf("Idade: %d\n", idade);
  printf("Salario inicial: %.2f\n", salario);

  salario = aumentar_salario(salario, 10.0);

  printf("Salario apos aumento: %.2f\n", salario);

  return 0;
}
