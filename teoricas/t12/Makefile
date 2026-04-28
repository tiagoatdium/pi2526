CC      ?= gcc
CFLAGS  ?= -std=c11 -O2 -g -Wall -Wextra -Wpedantic
LDFLAGS ?=

# programas a compilar
ALL := \
  abin2 \
  abin3

DOT_FILES := \
 remove_leaf_after.dot \
 remove_leaf_before.dot \
 remove_missing_after.dot \
 remove_missing_before.dot \
 remove_one_child_after.dot \
 remove_one_child_before.dot \
 remove_root_after.dot \
 remove_root_before.dot \
 remove_two_children_after.dot \
 remove_two_children_before.dot

PNG_FILES := \
 remove_leaf_after.png \
 remove_leaf_before.png \
 remove_missing_after.png \
 remove_missing_before.png \
 remove_one_child_after.png \
 remove_one_child_before.png \
 remove_root_after.png \
 remove_root_before.png \
 remove_two_children_after.png \
 remove_two_children_before.png


  
#------------------------------------------------------------------------------
# sudo apt install graphviz

$(DOT_FILES): run

run: abin2
	./abin2

$(PNG_FILES):
%.png: %.dot
	dot -Tpng $< -o $@

png: $(PNG_FILES)

#------------------------------------------------------------------------------
# compilar
.PHONY: all print-all clean

all: $(ALL)

print-all:
	@echo $(ALL)

# caso genérico
$(ALL):
%: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

# remover executáveis
clean:
	$(RM) -f $(ALL)
	$(RM) -f $(DOT_FILES) $(PNG_FILES)

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


