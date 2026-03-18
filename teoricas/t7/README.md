# T6 - Ordenação e Structs - Semana 16/03/26

## Parte 1 - 16/03/26

Sumário: Revisão do problema da aula anterior; Pesquisa de um elemento num array; Pesquisa de um elemento num array ordenado; Ordenação de arrays; 

1. `t7_quick_quiz.c` - pequeno quiz sobre strings
2. `t7_string_find_and_reverse.c` - proposta de solução para o problema da aula anterior
3. `t7_linear_search.c` - pesquisa linear de um elemento num array (percorre todos os elementos até encontrar o primeiro);
4. `t7_binary_search_sorted_array.c` - pesquisa binária num array ordenado por ordem crescente
5. `t7_bubble_sort.c` - algoritmo simples para ordenar arrays, bubble sort
6. `t7_selection_sort.c` - selection sort
7. `t7_insertion_sort.c` - insertion sort

## Parte 2 - 17/03/26

Sumário: Structs. Nota: os exemplos seguintes foram melhorados (e novos exemplos foram criados) para providenciar mais material de estudo.

1.  `t7_struct0.c` - primeiro exemplo com structs (sem `typedef`)
2.  `t7_typedef.c` - `typedef` - utilização de `typedef` (s/ `struct`)
3.  `t7_struct1.c` - segundo exemplo com structs (c/ `typedef`)
4.  `t7_struct_struct.c` - `struct` que utiliza variáveis declaradas como `struct`. Deste exemplo deriva um exemplo novo que é recomendado estudar, `t7_struct_sizeof.c`, que discute tamanhos de structs
5.  `t7_struct_pointers0.c` - introdução a apontadores para structs
6.  `t7_struct_self.c` - "self-referencing" struct (utiliza apontador para struct)
7.  `t7_struct_pointers1.c` - `typedef Ponto* pPonto;`
8.  `t7_struct_pointers2.c` - `typedef struct { int x; int y;} Ponto, *pPonto;`
9.  `t7_struct_array0.c` - exemplo que percorre um array de alunos e encontra o aluno com melhor nota
10. `t7_struct_array0.c` - iteração do exemplo anterior, agora com apontadores para structs para evitar cópias (desnecessárias) de dados
11. `t7_struct_array_sort0.c` - exemplo que ordena alunos por nota final, usando um array de apontadores para structs e bubble sort.
12. `t7_struct_array_sort1.c` - exemplo que mostra a duplicação de código se quisermos ordernar alunos por diferentes critérios (motiva a necessidade de generalização: "e se a função de ordenação, receber a função de comparação como argumento?").

