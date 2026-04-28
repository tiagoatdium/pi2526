# Makefile
#
# Este Makefile mostra três ideias diferentes:
#
# 1. compilar ficheiros .c em ficheiros objecto .o;
# 2. juntar vários .o numa biblioteca estática .a;
# 3. juntar vários .o compilados com -fPIC numa biblioteca dinâmica .so.
#
# O programa principal, main.c, é depois ligado de duas formas:
#
# - programa_static: ligado directamente com a biblioteca estática;
# - programa_shared: ligado com a biblioteca dinâmica.

CC = gcc
AR = ar

CFLAGS = -Wall -Wextra -pedantic -std=c99 -g
PICFLAGS = -fPIC

BUILD_DIR = build

LIB_NAME = estruturas
STATIC_LIB = lib$(LIB_NAME).a
SHARED_LIB = lib$(LIB_NAME).so

MAIN_OBJ = $(BUILD_DIR)/main.o

LIB_OBJ = \
  $(BUILD_DIR)/list.o \
  $(BUILD_DIR)/stack.o \
  $(BUILD_DIR)/queue.o

LIB_PIC_OBJ = \
  $(BUILD_DIR)/list.pic.o \
  $(BUILD_DIR)/stack.pic.o \
  $(BUILD_DIR)/queue.pic.o

.PHONY: all clean run run-static run-shared libs

all: programa_static programa_shared

# Constroi apenas as bibliotecas, sem construir os executáveis.
libs: $(STATIC_LIB) $(SHARED_LIB)

# Criamos a directoria build/ antes de colocar lá ficheiros .o.
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# -----------------------------
# Ficheiros objecto normais
# -----------------------------
# Estes .o são usados para a biblioteca estática.

$(BUILD_DIR)/main.o: main.c list.h stack.h queue.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c main.c -o $@

$(BUILD_DIR)/list.o: list.c list.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c list.c -o $@

$(BUILD_DIR)/stack.o: stack.c stack.h list.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c stack.c -o $@

$(BUILD_DIR)/queue.o: queue.c queue.h list.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c queue.c -o $@

# -----------------------------
# Ficheiros objecto para .so
# -----------------------------
# Para construir uma biblioteca dinâmica, os ficheiros objecto devem ser
# compilados como código independente da posição: -fPIC

$(BUILD_DIR)/list.pic.o: list.c list.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(PICFLAGS) -c list.c -o $@

$(BUILD_DIR)/stack.pic.o: stack.c stack.h list.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(PICFLAGS) -c stack.c -o $@

$(BUILD_DIR)/queue.pic.o: queue.c queue.h list.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(PICFLAGS) -c queue.c -o $@

# -----------------------------
# Biblioteca estática
# -----------------------------
# ar junta vários ficheiros .o num arquivo .a.
# Na ligação final, o código necessário é copiado para dentro do executável.

$(STATIC_LIB): $(LIB_OBJ)
	$(AR) rcs $@ $^

# -----------------------------
# Biblioteca dinâmica
# -----------------------------
# A opção -shared cria uma biblioteca .so.
# Na ligação final, o executável fica a depender desta biblioteca.

$(SHARED_LIB): $(LIB_PIC_OBJ)
	$(CC) -shared -o $@ $^

# -----------------------------
# Executáveis
# -----------------------------

# Ligação usando directamente a biblioteca estática.
# Escrevemos $(STATIC_LIB) explicitamente para evitar que o linker escolha a .so.
programa_static: $(MAIN_OBJ) $(STATIC_LIB)
	$(CC) $(CFLAGS) -o $@ $(MAIN_OBJ) $(STATIC_LIB)

# Ligação usando a biblioteca dinâmica.
# -L. diz ao linker para procurar bibliotecas na directoria actual.
# -lestruturas procura uma biblioteca chamada libestruturas.so ou libestruturas.a.
# Como este alvo depende de $(SHARED_LIB), a .so estará disponível.
#
# A opção rpath com $$ORIGIN permite executar o programa sem configurar
# LD_LIBRARY_PATH: o executável procura a .so na mesma directoria onde está.
programa_shared: $(MAIN_OBJ) $(SHARED_LIB)
	$(CC) $(CFLAGS) -o $@ $(MAIN_OBJ) -L. -l$(LIB_NAME) -Wl,-rpath,'$$ORIGIN'

# Alvo antigo, para manter compatibilidade com "make programa".
programa: programa_static

run: run-static

run-static: programa_static
	./programa_static

run-shared: programa_shared
	./programa_shared

clean:
	rm -rf $(BUILD_DIR) $(STATIC_LIB) $(SHARED_LIB) programa programa_static programa_shared
