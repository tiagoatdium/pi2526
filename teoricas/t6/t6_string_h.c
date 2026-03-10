#include <stdio.h>
#include <string.h>

int main(void)
{
    //
    // strlen:
    // - consultar 'man 3 strlen'
    // - size_t strlen(const char *s);
    // - calcula o comprimento de uma string (não conta o '\0')
    //
    char s1[] = "ola";
    size_t l1 = strlen(s1);
    printf("strlen(\"%s\") = %zu\n\n", s1, l1);



    //
    // strcpy:
    //  - consultar 'man 3 strcpy'
    //  - char *strcpy(char *dest, const char *src);
    //  - copia uma string para outra
    //
    char copia_s1[20];
    strcpy(copia_s1, s1);
    printf("Depois de strcpy, copia_s1 = \"%s\"\n\n", copia_s1);

    // exemplo com strcpy onde se guarda o valor retornado pela função
    char copia2_s1[10];
    char *p;
    p = strcpy(copia2_s1, s1);
    printf("Depois de strcpy, copia2_s1 = \"%s\"\n", copia2_s1);
    printf("   - p = %p; copia2_s1 = %p; são iguais:%d\n\n", p, copia2_s1, p==copia2_s1);



    //
    // strncpy:
    //  - consultar 'man 3 strncpy'
    //  - nota: """The strncpy() function is similar, except that at
    //             most n bytes of src are  copied. Warning: If there
    //             is no null byte among the first n bytes of src,
    //             the string placed in dest will not be null-terminated."""
    //
    //  - char *strncpy(char *dest, const char *src, size_t n);
    //  - copia no máximo n caracteres

    char copia2[100];
    strncpy(copia2, "bla_ble_bli_blo_blu", 10);
    copia2[10] = '\0'; // para garantir terminação da string
    printf("Depois de strncpy (10 caracteres), copia2 = \"%s\"\n\n", copia2);



    //
    // strcat: 
    //  - consultar 'man 3 strcat'
    //  - char *strcat(char *dest, const char *src);
    //  - concatena duas strings
    //  
    char s2[30] = "bom"; // acrescentar espaço?
    char s3[] = "dia";
    strcat(s2, s3);
    printf("Depois de strcat, s2 = \"%s\"\n\n", s2);



    //
    // strncat:
    //  - consultar 'man 3 strncat'
    //  - char *strncat(char *dest, const char *src, size_t n);
    //  - concatena no máximo n caracteres
    //

    char s4[12 + 100] = "correu bem ";   // 11 + 1
    char s5[]    = "o mini-teste?"; // 13 + 1
    printf("strlen(s4)=%zu strlen(s5)=%zu\n", strlen(s4), strlen(s5));

    strncat(s4, s5, 100);
    printf("Depois de strcat, s4 = \"%s\"\n", s4);
    printf("  strlen(s4)=%zu\n\n", strlen(s4));


    //
    // strcmp: 
    //  - consultar 'man 3 strcmp'
    //  - int strcmp(const char *s1, const char *s2);
    //  - compara duas strings. O resultado:
    //    - 0  -> iguais
    //    - < 0 (um valor negativo) -> s1 < s2
    //    - > 0 (um valor positivo) -> s1 > s2
    // 
    printf("strcmp(\"abc\", \"abc\") = %d\n",   strcmp("abc", "abc"));
    printf("strcmp(\"abc\", \"abz\") = %d\n",   strcmp("abc", "abz"));
    printf("strcmp(\"abz\", \"abc\") = %d\n", strcmp("abz", "abc"));
    printf("strcmp(\"abcef\", \"abc\") = %d\n", strcmp("abcef", "abc"));
    printf("strcmp(\"abc\", \"abcef\") = %d\n\n", strcmp("abc", "abcef"));


    //
    // strncmp:
    //  - consultar 'man 3 strncmp'
    //  - int strncmp(const char *s1, const char *s2, size_t n);
    //  - compara apenas os primeiros n caracteres
    //
    printf("strncmp(\"abcdef\", \"abcXYZ\", 3) = %d\n", strncmp("abcdef", "abcXYZ", 3));
    printf("strncmp(\"abcdef\", \"abcXYZ\", 4) = %d\n\n", strncmp("abcdef", "abcXYZ", 4));



    //
    // strchr:
    //  - consultar 'man 3 strchr' 
    //  - char *strchr(const char *s, int c);
    //  - nota: """The strchr() and strrchr() functions return
    //             a pointer to the matched character or NULL
    //             if the character is not found. The terminating
    //             null byte is considered part of the string, so
    //             that if c is specified as '\0', these functions
    //             return a pointer to the terminator."""
    //  - procura a primeira ocorrência de um carácter, devolve o apontador
    //    para a posição correspondente se existir (ou NULL, caso não exista)
    //
    char s6[] = "o rato roeu...";
    char c = 'a';
    char *p1 = strchr(s6, c); // experimente alterar de 'a' para um char
                              // que não exista na string s6

    if (p1 != NULL)
    { printf("Primeiro '%c' em \"%s\" na posição %ld\n\n", c, s6, p1 - s6); } // note: p1 - s6
    else
    { printf("Char '%c' não foi encontrado em \"%s\"\n\n", c, s6); }



    //
    //
    // strrchr:
    //  - consultar 'man 3 strrchr'
    //  - procura a última ocorrência de um carácter, devolve o apontador
    //    para a posição correspondente se existir (ou NULL, caso não exista)
    //

    char *p2 = strrchr(s6, 'e'); // s6 definida acima como "o rato roeu..."

    if (p2 != NULL)
    { printf("Último 'e' em \"%s\" na posição %ld\n\n", s6, p2 - s6); }
    else
    { printf("Char 'e' não foi encontrado em \"%s\"\n\n", s6); }



     // 
    // strstr (ver também strcasestr)
    // - consultar 'man 3 strstr'
    // - char *strstr(const char *haystack, const char *needle);
    // - nota: """The  strstr()  function  finds  the  first occurrence
    //            of the substring needle in the string haystack. The
    //            terminating null bytes ('\0') are not compared."""
    // - procura uma substring dentro de outra string
    //
    char s7[] = "aula sobre strings";

    char *p3 = strstr(s7, "sobre");

    if (p3 != NULL)
    { printf("\"sobre\" encontrada em \"%s\" na posição %ld\n\n", s7, p3 - s7); }
    else { printf("\"sobre\" não encontrada\n\n"); }



    //
    // strtok:
    // - consultar 'man 3 strtok'
    // - char *strtok(char *str, const char *delim);
    // - notas: """The  strtok()  function  breaks a string into a
    //             sequence of zero or more nonempty tokens. On the
    //             first call to strtok(), the string to be parsed
    //             should be specified in str. In each subsequent
    //             call that should parse the same string, str must
    //             be NULL."""
    // - divide uma string em tokens usando delimitadores
    char s8[] = "azul,verde,vermelho";

    printf("tokens da string %s:\n", s8);
    char *token = strtok(s8, ",");

    while (token != NULL)
    { printf("  %s\n", token);
      token = strtok(NULL, ",");
    }
    printf("\n");


    return 0;
}
