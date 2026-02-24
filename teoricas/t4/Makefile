CC      ?= gcc
CFLAGS  ?= -std=c11 -O2 -g -Wall -Wextra -Wpedantic
LDFLAGS ?=

# programas a compilar
ALL := \
  t4_arrays_init0 \
  t4_arrays_init1 \
  t4_arrays_soma_h \
  t4_arrays_soma_v \
 	t4_local_variable_addr \
 	t4_function_compare \
 	t4_array_max \
  t4_matrix0 \
  t4_matrix1

#------------------------------------------------------------------------------
# compilar
.PHONY: all print-all clean

all: $(ALL)

print-all:
	@echo $(ALL)

# caso especial: compilar sem -Wall/-Wextra etc
t1_undefined: t1_undefined.c
	$(CC) -std=c11 -O2 -g $(LDFLAGS) -o $@ $<

# caso genérico
$(ALL):
%: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

# remover executáveis
clean:
	$(RM) -f $(ALL)

#------------------------------------------------------------------------------
#-- formatação e checks 
ALL_INDENT := $(addprefix indent-, $(ALL))
ALL_TIDY := $(addprefix tidy-, $(ALL))
ALL_CHECK := $(addprefix check-, $(ALL))

.PHONY: indent-all tidy-all check-all

## sudo apt install indent // ou equivalente dependendo do sistema operativo
indent-all: $(ALL_INDENT)
$(ALL_INDENT):
indent-%:
	indent -kr -nut -i2 $*.c
	$(RM) -f $*.c~

## sudo apt install clang-tidy // ou equivalente dependendo do sistema operativo
tidy-all: $(ALL_TIDY)
$(ALL_TIDY):
tidy-%:
	clang-tidy $*.c -- $(CFLAGS)

## sudo apt install cppcheck // ou equivalente dependendo do sistema operativo
check-all: $(ALL_CHECK)
$(ALL_CHECK):
check-%:
	cppcheck --enable=warning,style,performance,portability --std=c11 --quiet $*.c


