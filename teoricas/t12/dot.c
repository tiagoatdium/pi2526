#include <stdio.h>
#include <stdlib.h>

// Função auxiliar para exportar em formato Graphviz (.dot).
// Cada nó recebe um identificador numérico único.
// Para filhos NULL, desenhamos pequenos pontos; isso ajuda a ver
// explicitamente onde a árvore termina.

static int writeDOTrec(FILE *out, abin a, int *nextId)
{
  int myId;
  int leftId;
  int rightId;

  myId = (*nextId)++;

  if(a == NULL)
  {
    fprintf(out, "  n%d [shape=point];\n", myId);
    return myId;
  }

  fprintf(out, "  n%d [label=\"%d\"];\n", myId, a->valor);

  leftId = writeDOTrec(out, a->esq, nextId);
  rightId = writeDOTrec(out, a->dir, nextId);

  fprintf(out, "  n%d -> n%d;\n", myId, leftId);
  fprintf(out, "  n%d -> n%d;\n", myId, rightId);

  return myId;
}

// Exporta a árvore para um ficheiro .dot.
// Depois pode ser convertido, por exemplo, para PNG com:
//   dot -Tpng arvore.dot -o arvore.png
void exportDOT(abin a, const char *filename)
{
  FILE *out;
  int nextId = 0;

  out = fopen(filename, "w");
  if(out == NULL)
  { printf("Erro ao abrir o ficheiro %s\n", filename);
    return;
  }

  fprintf(out, "digraph ABin {\n");
  fprintf(out, "  node [shape=circle];\n");
  fprintf(out, "  rankdir=TB;\n"); // TB (default) Top - Bottom

  writeDOTrec(out, a, &nextId);

  fprintf(out, "}\n");
  fclose(out);
}
