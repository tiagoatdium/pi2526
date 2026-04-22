# T11 - Árvores binárias - Semana 20/04/26

## Parte 1 - 20/04/26

Sumário: Árvores binárias; Declaração da estrutura correspondente; Criar nó (`mkroot`); Inicializar uma árvore com os elementos de um array de forma "simples" (`fromArrayLeft`); Inicializar uma árvore balanceada (`fromArrayBalanced`; útil para pesquisas se array estiver ordenado); Funções para calcular o número de nós (`size`) e profundidade (`depth`); Diferentes tipos de travessias (in order; pre order; post order); Libertar espaço alocado para os nós de uma árvore (`free_abin`); Exportar árvore para ficheiro `.dot` para geração de uma imagem `.png` correspondente ao estado de uma árvore.

1. `abin0.c` - contém as funções apresentadas na aula.
2. `fromArrayBalanced.txt` e `inPrePostOrder.txt` contém algumas notas adicionais.

## Parte 2 - 21/04/26

Sumário: Árvores binárias (Continuação);

1. `abin1.c` - funções sobre árvores que retornam resultados via referências.
2. `abin2.c` - ficheiro base para a próxima aula (27/04).
3. `vargs.c` - funções com argumentos variáveis.


## Notas

Ao executar o comando `make abin0` nesta directoria (`t11`) será gerado o ficheiro executável correspondente. Executar este comando (`make abin0`) invoca o seguinte comando correspondente a uma chamada ao compilador disponível no sistema:
```
gcc -std=c11 -O2 -g -Wall -Wextra -Wpedantic  -o abin0 abin0.c
```

Ao executar o ficheiro executável, através do comando `./abin0`, o output esperado é o seguinte:
```
$ ./abin0 
test_size_depth: arv1: size: 5 (expected value: 5)
test_size_depth: arv2: size: 5 (expected value: 5)
test_size_depth: arv1: depth: 3 (expected value: 3)
test_size_depth: arv2: depth: 5 (expected value: 5)
in_order: 
10 20 30 40 50 60 
pre_order: 
40 20 10 30 60 50 
post_order: 
10 30 20 50 60 40
```

Recomenda-se que defina outros testes alterando para isso a função `main`/implementando novas funções de teste (ver funções `test_*`). Adicionalmente, a execução de `./abin0`, cria os seguintes ficheiros (em consequência das chamadas à função `exportDOT` definida em `dot.c`) --- Note que apesar do ficheiro `dot.c` estar a ser incluído directamente no ficheiro `abin0.c` (através da directiva `#include`) tal poderá não ser considerado boa prática. Na realidade, depende do contexto. Tipicamente, declara-se um ficheiro com extensão `.h` (neste caso poderia ser um ficheiro `dot.h`) que, resumidamente, inclui as assinaturas das funções, `typedef`s, etc. Em tal cenário, a compilação tipicamente ocorre de forma separada. Contudo, neste caso em concreto em que se pretende simplicidade de "deployment", incluir o ficheiro `.c` resolve de forma eficaz o problema. Falaremos disto durante a última aula.

```
$ ls *.dot
from_array_balanced.dot  from_array_left.dot  print_order.dot  size_depth_balanced.dot  size_depth_left.dot 
```

Estes ficheiros podem ser "transformados" em imagens, por exemplo, ficheiros seguindo o formato `PNG` (extensão `.png`). Por exemplo, em sistemas operativos debian-based (Ubuntu por exemplo), pode-se (regra geral) executar o comando `sudo apt install graphviz` para instalar o programa `dot` que permite converter ficheiros `.dot` para ficheiros `.png`. Por exemplo:
```
dot -Tpng from_array_left.dot -o from_array_left.png
dot -Tpng from_array_balanced.dot -o from_array_balanced.png
dot -Tpng size_depth_balanced.dot -o size_depth_balanced.png
dot -Tpng size_depth_left.dot -o size_depth_left.png
dot -Tpng print_order.dot -o print_order.png
```

Alternativamente, o aluno pode tentar correr o comando `make png` (ver `Makefile`, linhas 31 a 35) para executar os mesmos comandos. 











