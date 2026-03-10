# T6 - Strings. - Semana 09/03/26

## Parte 1 - 09/03/26

Sumário: Strings e algoritmos sobre strings.

1. `t6_string_init.c` - inicialização de strings
2. `t6_string_h.c` - listagem com exemplos de funções sobre strings
3. `t6_exemplos_aula.c` - alguns exemplos desenvolvidos em conjunto com os alunos

4. `t6_strlen` - string length
5. `t6_strcpy` - string copy
6. `t6_strncat` - string 'n' concatenate
7. `t6_strncmp` - string 'n' compare
  

## Parte 2 - 10/03/26

Sumário: Resolução de exercício mais complexo; Estruturação na resolução de problemas.

1. `t6_problema.c` - resolução parcial do problema abaixo descrito.

Exercício começado na aula: implemente uma função que dadas duas strings `s1` e `s2`, em que `s1` contém uma frase e `s2` uma palavra, substitui as occurências de `s2` em `s1` pela inversão de `s2`. Alguns exemplos e casos a considerar de seguida:

```
# 1. palavra ocorre no ínicio:
Digite uma frase: rato roeu a rolha
Digite uma palavra: rato
Resultado: otar roeu a rolha

# 2. palavra ocorre algures no meio
Digite uma frase: o rato roeu a rolha
Digite uma palavra: rato
Resultado: o otar roeu a rolha

# 3. palavra ocorre no fim
Digite uma frase: o gato e o rato
Digite uma palavra: rato
Resultado: o gato e o otar

# 4. palavra ocorre dentro de outra palavra e não deve ser substituida
Digite uma frase: o rato correu para a ratoeira
Digite uma palavra: rato
Resultado: o otar correu para a ratoeira

# 5. palavra ocorre várias vezes
Digite uma frase: rato e rato
Digite uma palavra: rato
Resultado: otar e otar
```

Para resolver um problema mais complexo, podemos (devemos) segmentar. Alguns problemas (que resultarão em funções) que podemos identificar após uma interpretação do desafio:

1. é necessário determinar se uma string (`s2`) está contida noutra string (`s1`) num determinado ponto (*offset* desde o início) - função `compara_strings`.

2. é necessário determinar se uma determinada ocorrência (de `s2`) é uma palavra em `s1`; Por exemplo: se `s1` for "a ratoeira e grande" e `s2` "rato", `s2` ocorre em `s1` mas não é uma palavra por si só (pois ocorre dentro do contexto de outra palavra), como tal não deve ser substituida. Daqui podem surgir as seguintes funções:
  - `e_uma_letra` que recebe uma variável com o tipo `char` e retorna 1 ou 0 caso seja uma letra ou não.
  - `e_uma_palavra` que recebe uma string (`s1`), o seu tamanho (o tamanho de `s1` para evitar percorrer a string várias vezes), uma variável que indica o índice a inspeccionar, e o tamanho da palavra em causa (`s2`; não precisa da palavra, o tamanho chega, certo?); retorna 1 ou 0 caso seja uma palavra ou não. Utiliza a função `e_uma_letra` descrita anteriormente.
  
3. é necessário, a dado ponto da execução do programa, escrever o valor invertido (de `s2`). Existem várias estratégias, por exemplo:
 - invertemos a string (`s2`) uma vez e depois copiamos sempre que aplicável;
 - ou também poderiamos fazer a inversão *inplace*, ou seja, directamente em `s1`;

Podemos seguir pela primeira estratégia e implementamos uma função `inverte_string` e outra `copia_string`.

4. Até este ponto, isolamos alguns problemas *pequenos* (`compara_strings`, `e_uma_letra`, `e_uma_palavra`). Falta agora utilizar estas funções para implementar a função principal, a `processa_string`. Algumas intuições para uma versão inicial desta função:
 - Vai percorrendo a string que contém a frase (com um ciclo; questão: vai até ao fim da string denotado pelo '\0' ou pode parar antes? Se sim, quantos caracteres antes?)
   - Verifica se a palavra ocorre na frase (utilizando a função `compara_strings`);
   - Verifica se a ocorrência corresponde a uma palavra (utilizando a função `e_uma_palavra`;
   - Se ambas as verificações forem verdadeiras, então copia a string previamente invertida (ou inverte directamente, como preferir);
   - No caso de haver inversão, pode avançar quantos caracteres?


---

No decorrer da aula, foram implementadas as funções `string_compare`, `e_uma_letra`, e `e_uma_palavra`.

Mas atenção!!! Existe um erro na função `e_uma_palavra` (dica: o típico off-by-one).

**Desafio:**
- Complete o ficheiro `t6_problema.c` começando pela identificação do bug na função `e_uma_palavra`.








