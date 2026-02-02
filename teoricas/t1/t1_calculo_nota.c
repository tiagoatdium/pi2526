#include <stdio.h>

/*
 * Operadores disponíveis para valores do tipo double:
 *
 * Operadores aritméticos:
 *   +   soma
 *   -   subtracção
 *   *   multiplicação
 *   /   divisão (com resultado em vírgula flutuante)
 *
 * Operadores de comparação (o resultado é verdadeiro ou falso):
 *   <   menor que
 *   <=  menor ou igual a
 *   >   maior que
 *   >=  maior ou igual a
 *   ==  igual a
 *   !=  diferente de
 *
 * Nota:
 *  - Não existe operador % (resto) para double.
 *  - Comparações com == em double podem ser problemáticas
 *    devido a erros de arredondamento. Desafio: perceber porquê
 *    e descobrir como lidar com isso.
 */
 
int main(void)
{
    /*
     * Este programa calcula a nota final de uma UC usando double.
     *
     * Um programa em C é uma sequência de instruções (statements).
     * Cada statement termina com ';' e é executado por ordem.
     */

    /* Notas em escala 0..20 */
    double projeto = 14.5;
    double teste = 11.0;
    double participacao = 18.0;

    /* Pesos (percentagens em forma decimal) */
    double peso_projeto = 0.40;
    double peso_teste = 0.50;
    double peso_participacao = 0.10;

    /*
     * - calcula a expressão
     * - guarda o resultado numa nova variável nota_final
     */
    double nota_final = peso_projeto * projeto
                      + peso_teste * teste
                      + peso_participacao * participacao;

    printf("=== Calculo com double ===\n");
    printf("Nota final: %.2f\n", nota_final);

    /*
     * Decisão baseada no valor calculado.
     */
    if (nota_final >= 9.5) {
        printf("Resultado: APROVADO\n");
    } else {
        printf("Resultado: REPROVADO\n");
    }

    return 0;
}

