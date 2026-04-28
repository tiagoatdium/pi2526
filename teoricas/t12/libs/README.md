# Listas, stacks, queues, ficheiros objecto e bibliotecas

Este pequeno projecto serve para mostrar a separação entre ficheiros `.h`, ficheiros `.c`, ficheiros objecto `.o`, bibliotecas estáticas `.a`, bibliotecas dinâmicas `.so` e o `Makefile`.

## Ficheiros

- `list.h`: interface do módulo das listas ligadas.
- `list.c`: implementação das listas ligadas.
- `stack.h`: interface do módulo das stacks.
- `stack.c`: implementação das stacks usando listas ligadas.
- `queue.h`: interface do módulo das queues.
- `queue.c`: implementação das queues usando listas ligadas.
- `main.c`: programa de teste.
- `Makefile`: regras para compilar o projecto.

## Compilar tudo

```bash
make
```

Isto gera:

```text
build/main.o
build/list.o
build/stack.o
build/queue.o
build/list.pic.o
build/stack.pic.o
build/queue.pic.o
libestruturas.a
libestruturas.so
programa_static
programa_shared
```

## Executar

Executar o programa ligado com a biblioteca estática:

```bash
make run-static
```

Executar o programa ligado com a biblioteca dinâmica:

```bash
make run-shared
```

O alvo `make run` chama `make run-static`.

## Biblioteca estática (static)

A biblioteca estática é criada com:

```bash
ar rcs libestruturas.a build/list.o build/stack.o build/queue.o
```

Depois o programa pode ser ligado assim:

```bash
gcc -Wall -Wextra -pedantic -std=c99 -g -o programa_static build/main.o libestruturas.a
```

Neste caso, o código necessário da biblioteca é copiado para dentro do executável.

## Biblioteca dinâmica (shared)

A biblioteca dinâmica é criada com objectos compilados com `-fPIC`:

```bash
gcc -Wall -Wextra -pedantic -std=c99 -g -fPIC -c list.c -o build/list.pic.o
gcc -Wall -Wextra -pedantic -std=c99 -g -fPIC -c stack.c -o build/stack.pic.o
gcc -Wall -Wextra -pedantic -std=c99 -g -fPIC -c queue.c -o build/queue.pic.o
gcc -shared -o libestruturas.so build/list.pic.o build/stack.pic.o build/queue.pic.o
```

Depois o programa pode ser ligado assim:

```bash
gcc -Wall -Wextra -pedantic -std=c99 -g -o programa_shared build/main.o -L. -lestruturas -Wl,-rpath,'$ORIGIN'
```

Neste caso, o executável depende da biblioteca `.so` em tempo de execução.

## Limpar ficheiros gerados

```bash
make clean
```
