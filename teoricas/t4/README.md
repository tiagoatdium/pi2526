# T4 - Arrays. - Semana 23/02/26

## Parte 1 - 23/02/26

Sumário: Arrays e funções que operam sobre arrays; Modelo de memória de arrays;

1. `t4_arrays_init0.c` - diferentes formas de inicializar um array (estudar e compreender função `print_array`) 
2. `t4_arrays_init0.c` - inicialização de um array com um ciclo for (ordem decrescente e com função)
3. `t4_arrays_soma_h.c` - soma de arrays ({1,2,3} -> 6)
4. `t4_arrays_soma_v.c` - soma de arrays ({1,2,3} + {1,2,3} = {2,4,6})

## Parte 2 - 24/02/26

Sumário: O problema de retornar "address of local variable" (discussão detalhada sobre o porquê de ser inválido); Comparação de funções que operam sobre arrays: tamanho fixo (sem argumento que indica o tamanho do array) e tamanho variável (com argumento que indica o tamanho do array (ou dos arrays)); Função que calcula o máximo de um array e boas práticas de programação (size_t vs int), return de valores por apontador (para que o return corresponda ao código de sucesso/erro 0/-1);

1. `t4_local_variable_addr.c` - "return address of local variable"
2. `t4_function_compare.c` - comparação de funções (verifique o ficheiro, contém notas adicionais; daqui surge o ficheiro `define.c` para que possa realizar um pequeno experimento)
3. `t4_array_max.c` - a história da função max; desenvolvida no decorrer da aula; inicialmente bastante simples; foi-se acrescentando detalhe; falta check por NULL.
4. `t4_matrix0` e `t4_matrix1` - não foram abordados na aula; fica já aqui para os alunos mais interessados.
