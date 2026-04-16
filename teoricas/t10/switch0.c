#include <stdio.h>
#include <assert.h>

// ============================================================
//
// Em C, a instrução 'switch' permite escolher entre vários
// caminhos possíveis, consoante o valor de uma expressão.
//
// É particularmente útil quando:
//
// - queremos testar igualdade com vários valores inteiros;
// - queremos escrever código mais legível do que uma longa
//   sequência de if / else if / else;
// - estamos a trabalhar com menus, opções, códigos, dias,
//   meses, comandos, etc.
//
// Forma geral:
//
//   switch(expressao)
//   {
//     case valor1:
//       ...
//       break;
//
//     case valor2:
//       ...
//       break;
//
//     default:
//       ...
//   }
//
// Ideias principais:
//
// - o valor da expressão é comparado com os vários 'case';
//
// - se houver correspondência, executa-se o código desse caso;
//
// - a instrução 'break' é normalmente usada para sair do
//   switch;
//
// - se não houver nenhum caso correspondente, pode executar-se
//   o bloco 'default';
//
// - vários 'case' podem apontar para o mesmo bloco de código.
//


// Lê um inteiro introduzido pelo utilizador.
//
// Usamos assert apenas para simplificar o exemplo e assumir
// que o input tem o formato esperado.
int ler_int(const char mensagem[])
{
  int r;
  int x;

  assert(mensagem != NULL);

  printf("%s", mensagem);
  r = scanf("%d", &x);
  assert(r == 1);

  return x;
}



// Devolve o nome do dia da semana correspondente ao número.
//
// Convenção usada:
//
// - 1 -> segunda
// - 2 -> terca
// - 3 -> quarta
// - 4 -> quinta
// - 5 -> sexta
// - 6 -> sabado
// - 7 -> domingo
//
// Este é um exemplo típico de 'switch':
//
// - vários valores possíveis
// - uma resposta diferente para cada valor
// - um caso por omissão ('default')
const char *nome_dia_semana(int dia)
{
  switch(dia)
  {
    case 1:
      return "segunda";

    case 2:
      return "terca";

    case 3:
      return "quarta";

    case 4:
      return "quinta";

    case 5:
      return "sexta";

    case 6:
      return "sabado";

    case 7:
      return "domingo";

    default:
      return "dia invalido";
  }
}



// Devolve o tipo de dia:
//
// - "dia util"
// - "fim de semana"
// - "dia invalido"
//
// Este exemplo mostra que podemos agrupar vários 'case'
// para o mesmo bloco de código.
const char *tipo_dia(int dia)
{
  switch(dia)
  {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return "dia util";

    case 6:
    case 7:
      return "fim de semana";

    default:
      return "dia invalido";
  }
}



// Devolve o número de dias de um mês, ignorando anos bissextos.
//
// Convenção:
//
// - 1 -> janeiro
// - 2 -> fevereiro
// - ...
// - 12 -> dezembro
//
// Este exemplo mostra outro uso frequente de 'switch':
// vários casos diferentes podem partilhar exatamente a mesma
// resposta.
int dias_do_mes(int mes)
{
  switch(mes)
  {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;

    case 4:
    case 6:
    case 9:
    case 11:
      return 30;

    case 2:
      return 28;

    default:
      return -1;
  }
}



// Imprime uma pequena explicação sobre o papel do 'break'.
//
// Aqui não executamos um exemplo "sem break", porque isso
// poderia confundir numa primeira apresentação. Em vez disso,
// deixamos a ideia registada em texto.
void explicar_break(void)
{
  printf("Sobre 'break':\n");
  printf("- em muitos switches, usamos 'break' para terminar o caso atual;\n");
  printf("- sem 'break', a execucao continua para o caso seguinte;\n");
  printf("- esse comportamento chama-se fall-through.\n");
  printf("\n");
}



// Programa principal.
//
// Sequência da demonstracao:
//
// 1. ler um dia da semana e usar switch para obter o nome;
// 2. usar switch para distinguir dia util / fim de semana;
// 3. ler um mes e usar switch para obter o numero de dias.
int main(void)
{
  int dia;
  int mes;
  int ndias;

  printf("========================================\n");

  explicar_break();

  dia = ler_int("Introduza um dia da semana (1 a 7): ");

  printf("Nome do dia: %s\n", nome_dia_semana(dia));
  printf("Tipo de dia: %s\n", tipo_dia(dia));

  printf("\n");

  mes = ler_int("Introduza um mes (1 a 12): ");
  ndias = dias_do_mes(mes);

  if(ndias == -1)
  {
    printf("Mes invalido.\n");
  }
  else
  {
    printf("O mes %d tem %d dias.\n", mes, ndias);
  }

  return 0;
}
