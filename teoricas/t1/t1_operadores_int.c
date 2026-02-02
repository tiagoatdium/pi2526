#include <stdio.h>

int main(void)
{
		/**************************************************************************
		 **************************************************************************
  	 **************************************************************************/

    /*
     * Este programa ilustra os operadores disponíveis para inteiros em C.
     *
     * Um programa imperativo é uma sequência de statements:
     *  - cada statement termina com ';'
     *  - são executados por ordem
     *  - as variáveis vão mudando de valor ao longo do tempo
     */

    int a = 10;
    int b = 3;

    printf("Valores iniciais:\n");
    printf("a = %d, b = %d\n\n", a, b);

    /*
     * Operadores aritméticos
     */

    int soma = a + b;        // soma
    int sub = a - b;         // subtracção
    int mul = a * b;         // multiplicação
    int div = a / b;         // divisão inteira (parte decimal é descartada)
    int mod = a % b;         // resto da divisão

    printf("Operadores aritmeticos:\n");
    printf("a + b = %d\n", soma);
    printf("a - b = %d\n", sub);
    printf("a * b = %d\n", mul);
    printf("a / b = %d\n", div);
    printf("a %% b = %d\n\n", mod);

		/**************************************************************************
		 **************************************************************************
  	 **************************************************************************/

    /*
     * Operadores de comparação
     *
     * O resultado é:
     *  - 1 se a condição for verdadeira
     *  - 0 se a condição for falsa
     */

    printf("Operadores de comparacao:\n");
    printf("a <  b : %d\n", a < b); // 10 < 3 
    printf("a <= b : %d\n", a <= b);
    printf("a >  b : %d\n", a > b);
    printf("a >= b : %d\n", a >= b);
    printf("a == b : %d\n", a == b);
    printf("a != b : %d\n\n", a != b);

		/**************************************************************************
		 **************************************************************************
  	 **************************************************************************/

    /*
     * Operador de atribuicao simples
     */

    int x = 5;
    printf("Atribuicao:\n");
    printf("x = %d\n\n", x);

    /*
     * Operadores de atribuicao composta
     *
     * Estes operadores leem o valor actual da variavel,
     * aplicam a operacao, e guardam o novo valor.
     */

    x += 2;   // x = x + 2
    printf("x += 2  -> %d\n", x);

    x -= 1;   // x = x - 1
    printf("x -= 1  -> %d\n", x);

    x *= 3;   // x = x * 3
    printf("x *= 3  -> %d\n", x);

    x /= 2;   // x = x / 2  (divisao inteira)
    printf("x /= 2  -> %d\n", x);

    x %= 4;   // x = x % 4
    printf("x %%= 4 -> %d\n\n", x);

		/**************************************************************************
		 **************************************************************************
  	 **************************************************************************/

    /*
     * Operadores de incremento e decremento
     */

    int y = 10;

    printf("Incremento e decremento:\n");
    printf("y inicial = %d\n", y);

    y++;      // incremento (pos-incremento)
    printf("y++ -> %d\n", y);

    y--;      // decremento (pos-decremento)
    printf("y-- -> %d\n", y);

    ++y;      // pre-incremento
    printf("++y -> %d\n", y);

    --y;      // pre-decremento
    printf("--y -> %d\n\n", y);

		/**************************************************************************
		 **************************************************************************
  	 **************************************************************************/
    /*
     * Observacao:
     * A diferenca entre pre e pos incremento importa em expressoes,
     * mas aqui mostramos apenas o efeito final na variavel.
     */

    /*
     * Ordem de avaliacao e parenteses
     */

    int r1 = a + b * 2;      // multiplicacao primeiro
    int r2 = (a + b) * 2;    // parenteses alteram a ordem

    printf("Ordem das operacoes:\n");
    printf("a + b * 2     = %d\n", r1);
    printf("(a + b) * 2   = %d\n\n", r2);

    /*
     * Até aqui, este programa mostrou:
     *  - operadores aritmeticos
     *  - operadores de comparacao
     *  - atribuicao simples e composta
     *  - incremento e decremento
     *  - importancia da ordem das operacoes
     */

		/**************************************************************************
		 **************************************************************************
  	 **************************************************************************/
    /*
     * Referenciar a propria variavel numa expressao
     *
     * Comum em programacao imperativa:
     * o novo valor depende do valor antigo.
     */

    int z = 4;

    printf("Referencia a propria variavel:\n");
    printf("z inicial = %d\n", z);

    z = z + 1;          // incrementar z // z += 1
    printf("z = z + 1  -> %d\n", z);

    z = z * 2;          // multiplicar z por 2 // z *= 2
    printf("z = z * 2  -> %d\n", z);

    z = z - 3;          // subtrair 3 // z -= 3
    printf("z = z - 3  -> %d\n", z);

    z = z / 2;          // divisao inteira // z /= 2
    printf("z = z / 2  -> %d\n\n", z);

    /*
     * Pre-incremento e pos-incremento dentro de expressoes
     *
     * Estes exemplos mostram claramente a diferenca entre:
     *   ++x  (incrementa primeiro, depois usa o valor)
     *   x++  (usa o valor primeiro, depois incrementa)
     */

    int w = 5;

    printf("Pre e pos incremento em printf:\n");
    printf("w inicial = %d\n", w);

    printf("++w = %d\n", ++w);  // w e incrementado antes de ser impresso
    printf("w depois de ++w = %d\n\n", w);

    w = 5;  // reset ao valor inicial

    printf("w++ = %d\n", w++);  // w e impresso antes de ser incrementado
    printf("w depois de w++ = %d\n\n", w);

    /*
     * Observacao importante:
     *
     * Nao é boa prática usar a mesma variavel mais do que uma vez
     * na mesma expressao sem uma sequencia bem definida.
     *
     * Exemplos como:
     *   printf("%d %d\n", w++, ++w);
     * podem levar a comportamento indefinido e devem ser, regra geral, evitados.
     */

    return 0;
}




