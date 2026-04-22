CC      ?= gcc
CFLAGS  ?= -std=c11 -O2 -g -Wall -Wextra -Wpedantic
LDFLAGS ?=

# programas a compilar
ALL := \
  abin0 \
  abin1 \
  abin2 \
  vargs

DOT_FILES := \
  from_array_left.dot \
  from_array_balanced.dot \
  size_depth_balanced.dot \
  size_depth_left.dot \
  print_order.dot

PNG_FILES := \
  from_array_left.png \
  from_array_balanced.png \
  size_depth_balanced.png \
  size_depth_left.png \
  print_order.png
  
#------------------------------------------------------------------------------
# sudo apt install graphviz

$(DOT_FILES): run

run: abin0
	./abin0

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
	$(RM) -f *.dot *.png

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


