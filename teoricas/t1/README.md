# T1 - Introdução - Semana 02/02/26

## Parte 1 - 02/02/26

Sumário: Introdução ao C; Compilação; Função main; Tipos variáveis e as suas características; Operadores (estudar precedência); Programa exemplo (8).

1. `t1_hello.c` - introdução

2. `Makefile` - compilação

3. `t1_hello_annot.c` - header files e documentação

4. `t1_hello_fail.c` - return 0 e != 0 na main

5. `t1_tipos_variaveis.c` - variáveis e alguns tipos (também `printf`)

6. `t1_tamanhos_tipos.c` - tamanhos (bytes) e intervalos

7. `t1_operadores_int.c` - operadores sobre inteiros

8. `t1_calculo_nota.c` - exemplo com doubles; introduz if's

## Parte 2 - 03/02/26

Sumário: Breve revisão da aula anterior; "Undefined Variable"; exemplo calculo nota com ints; Overflows; Condições e `if` statements; Introdução a ciclos while e ciclos for.

9. `t1_undefined.c` - variável sem valor definido

10. `t1_calculo_nota_int.c` - exemplo com ints

11. `t1_condicoes.c` - && (AND) || (OR) ! (NOT)

12. `t1_while.c` - ciclos while

13. `t1_while_break_continue.c` - ciclos while: exemplo com break e continue (usar com precaução)

14. `t1_for.c` - ciclos for (2 exemplos; 1 deles com if else)

15. `t1_overflow.c` - overflows

## Parte E ('E' de extra)

16. `t1_scanf.c` - um primeiro exemplo com `scanf`

17. `t1_mini_calculator.c` - uma mini calculadora

18. `t1_mini_calculator2.c` - seguimento do exemplo anterior; mas com funções (para além da função principal `main`)

## Propostas de exercícios avançados

* Crie uma cópia de `t1_mini_calculator2.c` para um ficheiro à sua escolha e suporte mais operadores (`*` e `/`); Altere o programa para que a execução continue até que o utilizador insira `q` na operação (dica: ciclo while).

* Escreva um programa que permita ao utilizador introduzir vários números inteiros e faça uma análise desses números. Por exemplo:
```
Quantos numeros deseja introduzir? 5

Numero 1: 10
Numero 2: 7
Numero 3: 2
Numero 4: 9
Numero 5: 4

Quantidade de numeros pares: 3
Quantidade de numeros impares: 2
Maior numero: 10
Soma: 32
Média: 6.4
```

* A `Makefile` foi actualizada recentemente (para uma versão mais completa). Explore o que pode ser feito (`indent-*`; `tidy-*`; `check-*`) e instale as ferramentas correspondentes (dica `make TAB TAB` {no terminal, escrever make e depois carregar na tecla TAB duas vezes} para ver as sugestões). Explore de que forma as novas flags de compilação alertam para os problemas existentes e corrija-os.

