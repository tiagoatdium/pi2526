#include <stdio.h>
#include <limits.h>   // Limites dos tipos inteiros
#include <float.h>    // Limites dos tipos de vírgula flutuante

int main(void)
{
    /*
     * sizeof devolve o número de bytes usados por um tipo ou variável.
     * O valor devolvido é do tipo size_t.
     */

    printf("Tamanhos dos tipos (em bytes):\n\n");

    printf("char:          %zu byte\n",  sizeof(char));
    printf("unsigned char: %zu byte\n",  sizeof(unsigned char));

    printf("short:         %zu bytes\n", sizeof(short));
    printf("int:           %zu bytes\n", sizeof(int));
    printf("unsigned int:  %zu bytes\n", sizeof(unsigned int));
    printf("long:          %zu bytes\n", sizeof(long));
    printf("long long:     %zu bytes\n", sizeof(long long));

    printf("float:         %zu bytes\n", sizeof(float));
    printf("double:        %zu bytes\n", sizeof(double));

    /*
     * Nota sobre %zu:
     *
     * sizeof devolve um valor do tipo size_t.
     * O especificador de formato correcto para imprimir size_t é %zu.
     * Usar outro especificador pode funcionar por acaso,
     * mas não é portável nem correcto segundo o padrão C.
     */

    printf("\n----------------------------------------\n\n");

    /*
     * Valores mínimos e máximos que cada tipo pode armazenar.
     * Estes valores são fornecidos pelos headers <limits.h> e <float.h>.
     */

    printf("Limites dos tipos:\n\n");

    printf("char:          min = %d, max = %d\n", CHAR_MIN,  CHAR_MAX);
    printf("unsigned char: min = 0,  max = %u\n", UCHAR_MAX);

    printf("short:         min = %d, max = %d\n", SHRT_MIN,  SHRT_MAX);
    printf("int:           min = %d, max = %d\n", INT_MIN,   INT_MAX);
    printf("unsigned int:  min = 0,  max = %u\n", UINT_MAX);

    printf("long:          min = %ld, max = %ld\n", LONG_MIN,  LONG_MAX);
    printf("long long:     min = %lld, max = %lld\n", LLONG_MIN, LLONG_MAX);

    printf("\n");

    printf("float:         min = %e, max = %e\n", FLT_MIN, FLT_MAX);
    printf("double:        min = %e, max = %e\n", DBL_MIN, DBL_MAX);

    /*
     * Observações importantes:
     *
     * - Tipos com mais bytes conseguem representar intervalos maiores.
     * - Tipos unsigned não representam valores negativos.
     * - FLT_MIN e DBL_MIN são os menores valores positivos normalizados,
     *   não os valores mais negativos.
     */

    return 0;
}

