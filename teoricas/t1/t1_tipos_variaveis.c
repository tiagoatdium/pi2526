#include <stdio.h>

int main(void)
{
    /*
     * Uma variável é um nome associado a uma zona de memória
     * onde é guardado um valor.
     *
     * O tipo da variável diz ao compilador:
     *  - quantos bytes de memória usar
     *  - como interpretar os bits guardados
     */

    /* Tipos inteiros */
    int inteiro = -10; // Número inteiro com sinal
    unsigned int inteiro_u = 10; // Número inteiro sem sinal (>= 0)

    short inteiro_curto = 123; // Inteiro geralmente mais pequeno
    long inteiro_longo = 1000000L; // Inteiro geralmente maior
    long long inteiro_muito_longo = 1234567890123LL; // Inteiro muito grande

    /* Tipos de caracter */
    char letra = 'A'; // Um caracter (internamente um número)

    /* Tipos de vírgula flutuante (números reais) */
    float pi_f = 3.14f; // Precisão simples
    double pi_d = 3.141592653589793; // Precisão dupla

    /*
     * Imprimir os valores das variáveis.
     * Cada tipo tem o seu especificador de formato em printf.
     */

    printf("Inteiros:\n");
    printf("int = %d\n", inteiro);
    printf("unsigned int = %u\n", inteiro_u);
    printf("short = %d\n", inteiro_curto);
    printf("long = %ld\n", inteiro_longo);
    printf("long long = %lld\n", inteiro_muito_longo);

    printf("\nCaracteres:\n");
    printf("char = %c\n", letra);
    printf("char = %d\n", letra);

    printf("\nVirgula flutuante:\n");
    printf("float = %f\n", pi_f);
    printf("double = %.15f\n", pi_d);

    /*
     * Naturalmente, as variáveis podem mudar de valor durante a execução.
     */
    inteiro = inteiro + 1;
    inteiro_u = inteiro_u + 5;

    printf("\nDepois de alterar os valores:\n");
    printf("int = %d\n", inteiro);
    printf("unsigned int = %u\n", inteiro_u);

    return 0;
}

