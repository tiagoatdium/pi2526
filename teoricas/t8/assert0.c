#include <stdio.h>
#include <assert.h>

//
// Visão geral.
//
// Durante o desenvolvimento de um programa, é muito frequente
// escrever funções que assumem que certas condições são
// verdadeiras.
//
// Alguns exemplos:
//
// - um apontador recebido por uma função não deve ser NULL;
//
// - um índice deve estar dentro dos limites válidos;
//
// - o número de elementos usados num array dinâmico nao deve
//   ultrapassar a sua capacidade;
//
// - uma struct deve estar num estado interno coerente.
//
// Estas condições são, muitas vezes, pressupostos do próprio
// programador: se falharem, isso normalmente significa que há
// um erro na lógica do programa, e não apenas um erro "normal"
// de utilização.
//
// É precisamente aqui que entra a biblioteca <assert.h>.
//
// A macro assert permite escrever verificações que ajudam a:
//
// - detetar erros cedo, durante o desenvolvimento;
//
// - documentar explicitamente os pressupostos de uma função;
//
// - localizar mais rapidamente bugs, porque o programa termina
//   logo no ponto em que uma suposição falha;
//
// - evitar que um erro silencioso se propague e venha a causar
//   comportamentos mais difíceis de diagnosticar.
//
// Assim, asserts (consultar 'man 3 assert') sao especialmente
// úteis durante:
//
// - implementação;
//
// - teste;
//
// - "debugging";
//
// - manutenção e evolução do código.
//
// ------------------------------------------------------------
// Significado de NDEBUG:
//
// NDEBUG significa, tradicionalmente, "No Debug".
//
// Quando NDEBUG está definido antes de incluir <assert.h>,
// a macro assert deixa de verificar a condição e passa,
// na prática, a não fazer nada.
//
// Ou seja, statements do tipo:
//
//   assert(expressão);
//
// passam a ser ignorados quando o programa é compilado com
// NDEBUG "ativo".
//
// Isto demonstra bem o papel dos asserts:
//
// - são uma ferramenta de desenvolvimento e debugging;
//
// - não devem ser usados para tratar erros normais que deverão
//   ser verificados em execução.
//
// De outro modo:
//
// - se uma condição representa um pressuposto interno do
//   programador (pré-condição), faz sentido usar assert;
//
// - se representa um erro possível e esperado em execução
//   (por exemplo, input inválido do utilizador, ficheiro que
//   nao abriu, falha de alocação de memória, etc.), então
//   deve ser tratada com código normal: if, mensagens de
//   erro, valores de retorno, etc.
//
// ------------------------------------------------------------
// Compilação:
//
// Exemplo de como compilar "com asserts":
//
//   gcc -Wall -Wextra -pedantic -std=c99 -o assert0_on assert0.c
//
// Exemplo de como compilar "com asserts desativados":
//
//   gcc -Wall -Wextra -pedantic -std=c99 -DNDEBUG -o assert_off assert0.c
//
// Exemplo de Execução:
//
//   ./assert_on
//   ./assert_off
//
// Nota: ao executar a versão com asserts ativas, a segunda chamada
// à função 'imprimir_elemento' (incorreta; ver função main abaixo)
// fará o programa terminar com mensagem de erro.
//
// Ao executar a versão compilada com -DNDEBUG, os asserts
// deixam de ser avaliados ("desaparecem").




// A seguinte função, devolve o elemento na posição 'indice'.
// Esta função assume que:
// - 'v' aponta para um array válido;
// - 'n' é o número de elementos válidos do array;
// - 'indice' está entre 0 e n - 1.
//
// asserts servem para verificar estas pré-condições
// durante o desenvolvimento de um programa. Ajudam 
// também, a documentar de forma explícita, quais são
// as pré-condições/pressupostos assumidos pelo programador.
//
int obter_elemento(int v[], int n, int indice)
{
  assert(v != NULL);
  assert(n > 0);
  assert(indice >= 0);
  assert(indice < n);

  return v[indice];
}


// A seguinte função imprime um elemento do array.
//
// Esta função existe para tornar o exemplo um pouco
// mais modular e para mostrar que a função 'obter_elemento'
// protege os seus próprios pressupostos com asserts.
//
void imprimir_elemento(int v[], int n, int indice)
{
  int x;

  x = obter_elemento(v, n, indice);
  printf("v[%d] = %d\n", indice, x);
}




//
// Neste exemplo fazemos duas chamadas:
// - uma chamada correta, com índice válido;
// - uma chamada incorreta, com índice fora dos limites.
//
// Se os asserts estiverem ativos, a segunda chamada fará o
// programa terminar imediatamente.
//
// Se o programa for compilado com -DNDEBUG, os asserts deixam 
// de ter efeito ("desaparecem"), e a chamada incorreta poderá
// produzir um resultado incorreto ou um comportamento imprevisível
// (undefined behaviour)
//
int main(void)
{
  int v[5] = {10, 20, 30, 40, 50};

  printf("Chamada correta:\n");
  imprimir_elemento(v, 5, 2);

  printf("\n");
  printf("Chamada incorreta (indice fora dos limites):\n");
  imprimir_elemento(v, 5, 10);

  return 0;
}
