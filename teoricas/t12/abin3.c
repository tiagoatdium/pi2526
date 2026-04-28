#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// abin3.c
//
// Programa interactivo para árvores binárias de pesquisa (BST).
//
// Funcionalidades:
// - inserir
// - remover
// - procurar
// - rodar à esquerda / à direita num dado nó
// - imprimir no terminal
// - exportar a árvore atual para DOT e PNG
// - exportar comparação "antes vs depois" na vertical
// - converter a BST para array ordenado (inorder)
// - reequilibrar a árvore a partir do array ordenado
// - construir árvore a partir de um array introduzido pelo utilizador
//
// Nota:
// Para gerar PNG, este programa usa o comando externo:
//   dot -Tpng ficheiro.dot -o ficheiro.png
// É preciso ter o Graphviz instalado (sudo apt install graphviz)

typedef struct abin_no {
  int valor;
  struct abin_no *esq;
  struct abin_no *dir;
} *abin;

// ============================================================================
// Operações base
// ============================================================================

abin mkroot(int x, abin e, abin d)
{
  abin new = malloc(sizeof(struct abin_no));
  if(new == NULL)
  { return NULL; }

  new->valor = x;
  new->esq = e;
  new->dir = d;
  return new;
}

abin clone_abin(abin a)
{
  abin r;

  if(a == NULL)
  { return NULL; }

  r = mkroot(a->valor, NULL, NULL);
  if(r == NULL)
  { return NULL; }

  r->esq = clone_abin(a->esq);
  r->dir = clone_abin(a->dir);
  return r;
}

abin fromArrayBalanced(int v[], int N)
{
  abin a;
  abin esq;
  abin dir;
  int meio;

  if(N == 0)
  { return NULL; }

  meio = N / 2;

  esq = fromArrayBalanced(v, meio);
  dir = fromArrayBalanced(v + meio + 1, N - meio - 1);

  a = mkroot(v[meio], esq, dir);
  return a;
}

int size(abin a)
{
  if(a == NULL)
  { return 0; }

  return 1 + size(a->esq) + size(a->dir);
}

int depth(abin a)
{
  int p_esq;
  int p_dir;

  if(a == NULL)
  { return 0; }

  p_esq = depth(a->esq);
  p_dir = depth(a->dir);

  if(p_esq > p_dir)
  { return 1 + p_esq; }
  else
  { return 1 + p_dir; }
}

abin free_abin(abin a)
{
  if(a == NULL)
  { return NULL; }

  free_abin(a->esq);
  free_abin(a->dir);
  free(a);
  return NULL;
}

// ============================================================================
// Procura / inserção / remoção em BST
// ============================================================================

abin search_ex_r(int x, abin a)
{
  abin r;

  if(a == NULL)
  { return NULL; }

  if(a->valor == x)
  { return a; }

  r = search_ex_r(x, a->esq);
  if(r == NULL)
  { return search_ex_r(x, a->dir); }

  return r;
}

abin search_bst_it(int x, abin a)
{
  while(a != NULL && a->valor != x)
  {
    if(x < a->valor)
    { a = a->esq; }
    else
    { a = a->dir; }
  }

  return a;
}

abin insert(int x, abin a)
{
  abin ant = NULL;
  abin aux = a;
  abin new;

  while(aux != NULL)
  {
    ant = aux;

    if(aux->valor == x)
    { return a; }

    if(x < aux->valor)
    { aux = aux->esq; }
    else
    { aux = aux->dir; }
  }

  new = mkroot(x, NULL, NULL);
  if(new == NULL)
  { return a; }

  if(ant == NULL)
  { a = new; }
  else if(x < ant->valor)
  { ant->esq = new; }
  else
  { ant->dir = new; }

  return a;
}

int min_bst(abin a)
{
  while(a->esq != NULL)
  { a = a->esq; }

  return a->valor;
}

abin remove_bst(int x, abin a)
{
  int m;
  abin aux;

  if(a == NULL)
  { return NULL; }

  if(x < a->valor)
  {
    a->esq = remove_bst(x, a->esq);
    return a;
  }

  if(x > a->valor)
  {
    a->dir = remove_bst(x, a->dir);
    return a;
  }

  if(a->esq == NULL && a->dir == NULL)
  {
    free(a);
    return NULL;
  }

  if(a->esq == NULL)
  {
    aux = a->dir;
    free(a);
    return aux;
  }

  if(a->dir == NULL)
  {
    aux = a->esq;
    free(a);
    return aux;
  }

  m = min_bst(a->dir);
  a->valor = m;
  a->dir = remove_bst(m, a->dir);
  return a;
}

// ============================================================================
// Rotações locais
// ============================================================================

abin rotateLeftRoot(abin a)
{
  abin b;

  if(a == NULL || a->dir == NULL)
  { return a; }

  b = a->dir;
  a->dir = b->esq;
  b->esq = a;
  return b;
}

abin rotateRightRoot(abin a)
{
  abin b;

  if(a == NULL || a->esq == NULL)
  { return a; }

  b = a->esq;
  a->esq = b->dir;
  b->dir = a;
  return b;
}

abin rotateLeftAt(int x, abin a)
{
  if(a == NULL)
  { return NULL; }

  if(x < a->valor)
  {
    a->esq = rotateLeftAt(x, a->esq);
    return a;
  }

  if(x > a->valor)
  {
    a->dir = rotateLeftAt(x, a->dir);
    return a;
  }

  return rotateLeftRoot(a);
}

abin rotateRightAt(int x, abin a)
{
  if(a == NULL)
  { return NULL; }

  if(x < a->valor)
  {
    a->esq = rotateRightAt(x, a->esq);
    return a;
  }

  if(x > a->valor)
  {
    a->dir = rotateRightAt(x, a->dir);
    return a;
  }

  return rotateRightRoot(a);
}

int canRotateLeftAt(int x, abin a)
{
  abin r = search_bst_it(x, a);
  return (r != NULL && r->dir != NULL);
}

int canRotateRightAt(int x, abin a)
{
  abin r = search_bst_it(x, a);
  return (r != NULL && r->esq != NULL);
}

// ============================================================================
// Conversão árvore <-> array ordenado
// ============================================================================

void toArraySortedAux(abin a, int v[], int *i)
{
  if(a == NULL)
  { return; }

  toArraySortedAux(a->esq, v, i);
  v[*i] = a->valor;
  (*i)++;
  toArraySortedAux(a->dir, v, i);
}

int *toArraySorted(abin a, int *N)
{
  int *v;
  int i = 0;

  *N = size(a);
  if(*N == 0)
  { return NULL; }

  v = malloc(sizeof(int) * (*N));
  if(v == NULL)
  {
    *N = 0;
    return NULL;
  }

  toArraySortedAux(a, v, &i);
  return v;
}

abin rebalance_bst(abin a)
{
  int N;
  int *v;
  abin r;

  v = toArraySorted(a, &N);
  if(N == 0)
  { return NULL; }

  r = fromArrayBalanced(v, N);
  free(v);
  return r;
}

abin fromArrayInsert(int v[], int N)
{
  abin a = NULL;
  int i;

  for(i = 0; i < N; i++)
  { a = insert(v[i], a); }

  return a;
}

void printArray(int v[], int N)
{
  int i;

  printf("[");
  for(i = 0; i < N; i++)
  {
    printf("%d", v[i]);
    if(i + 1 < N)
    { printf(", "); }
  }
  printf("]\n");
}

// ============================================================================
// Impressão simples no terminal
// ============================================================================

void imprimeArvoreAux(abin a, int espacos)
{
  int i;

  if(a == NULL)
  { return; }

  imprimeArvoreAux(a->dir, espacos + 4);

  for(i = 0; i < espacos; i++)
  { printf(" "); }
  printf("%d\n", a->valor);

  imprimeArvoreAux(a->esq, espacos + 4);
}

void imprimeArvore(abin a)
{
  if(a == NULL)
  { printf("(arvore vazia)\n"); }
  else
  { imprimeArvoreAux(a, 0); }
}

// ============================================================================
// Exportação DOT / PNG
// ============================================================================

const char *colorForValue(int x)
{
  static const char *palette[] = {
    "#f4cccc",
    "#d9ead3",
    "#cfe2f3",
    "#fff2cc",
    "#d9d2e9",
    "#fce5cd",
    "#d0e0e3",
    "#ead1dc",
    "#d9c2f0",
    "#b6d7a8",
    "#a2c4c9",
    "#f9cb9c"
  };
  long long y = x;
  int n = (int) (sizeof(palette) / sizeof(palette[0]));

  if(y < 0)
  { y = -y; }

  return palette[y % n];
}

static int writeDOTrecColor(FILE *out,
                            abin a,
                            int *nextId,
                            const char *prefix,
                            const char *penColor,
                            const char *shape)
{
  int myId;
  int leftId;
  int rightId;

  myId = (*nextId)++;

  if(a == NULL)
  {
    fprintf(out, "  %s%d [shape=point];\n", prefix, myId);
    return myId;
  }

  fprintf(out,
          "  %s%d [label=\"%d\", shape=%s, style=filled, fillcolor=\"%s\", color=\"%s\", penwidth=2];\n",
          prefix,
          myId,
          a->valor,
          shape,
          colorForValue(a->valor),
          penColor);

  leftId = writeDOTrecColor(out, a->esq, nextId, prefix, penColor, shape);
  rightId = writeDOTrecColor(out, a->dir, nextId, prefix, penColor, shape);

  fprintf(out, "  %s%d -> %s%d [color=\"%s\"];\n", prefix, myId, prefix, leftId, penColor);
  fprintf(out, "  %s%d -> %s%d [color=\"%s\"];\n", prefix, myId, prefix, rightId, penColor);

  return myId;
}

void exportDOTColor(abin a, const char *filename, const char *title)
{
  FILE *out;
  int nextId = 0;

  out = fopen(filename, "w");
  if(out == NULL)
  {
    printf("Erro ao abrir o ficheiro %s\n", filename);
    return;
  }

  fprintf(out, "digraph ABin {\n");
  fprintf(out, "  rankdir=TB;\n");
  fprintf(out, "  labelloc=\"t\";\n");
  fprintf(out, "  label=\"%s\";\n", title);
  fprintf(out, "  node [fontname=\"Helvetica\"];\n");

  writeDOTrecColor(out, a, &nextId, "n", "#555555", "circle");

  fprintf(out, "}\n");
  fclose(out);
}

void exportComparisonDOT(abin before,
                         abin after,
                         const char *filename,
                         const char *titleBefore,
                         const char *titleAfter)
{
  FILE *out;
  int nextBefore = 0;
  int nextAfter = 0;
  int rootBefore;
  int rootAfter;

  out = fopen(filename, "w");
  if(out == NULL)
  {
    printf("Erro ao abrir o ficheiro %s\n", filename);
    return;
  }

  fprintf(out, "digraph Compare {\n");
  fprintf(out, "  rankdir=TB;\n");
  fprintf(out, "  compound=true;\n");
  fprintf(out, "  node [fontname=\"Helvetica\"];\n");

  fprintf(out, "  subgraph cluster_before {\n");
  fprintf(out, "    label=\"%s\";\n", titleBefore);
  fprintf(out, "    color=\"#7aa6ff\";\n");
  rootBefore = writeDOTrecColor(out, before, &nextBefore, "b", "#4a86e8", "circle");
  fprintf(out, "  }\n");

  fprintf(out, "  subgraph cluster_after {\n");
  fprintf(out, "    label=\"%s\";\n", titleAfter);
  fprintf(out, "    color=\"#7fd18b\";\n");
  rootAfter = writeDOTrecColor(out, after, &nextAfter, "a", "#6aa84f", "circle");
  fprintf(out, "  }\n");

  // aresta invisível para forçar a disposição vertical: antes por cima,
  // depois por baixo
  fprintf(out, "  b%d -> a%d [style=invis, weight=100];\n", rootBefore, rootAfter);

  fprintf(out, "}\n");
  fclose(out);
}

void dotToPNG(const char *dotFile, const char *pngFile)
{
  char cmd[512];
  int rc;

  snprintf(cmd, sizeof(cmd), "dot -Tpng \"%s\" -o \"%s\"", dotFile, pngFile);
  rc = system(cmd);

  if(rc != 0)
  {
    printf("Aviso: falhou a execução de: %s\n", cmd);
    printf("Verifique se o Graphviz está instalado e se 'dot' está no PATH.\n");
  }
}

void exportCurrentPNG(abin a, const char *baseName)
{
  char dotFile[256];
  char pngFile[256];

  snprintf(dotFile, sizeof(dotFile), "%s.dot", baseName);
  snprintf(pngFile, sizeof(pngFile), "%s.png", baseName);

  exportDOTColor(a, dotFile, baseName);
  dotToPNG(dotFile, pngFile);

  printf("Gerados: %s e %s\n", dotFile, pngFile);
}

void exportBeforeAfterPNG(abin before,
                          abin after,
                          const char *baseName,
                          const char *titleBefore,
                          const char *titleAfter)
{
  char dotFile[256];
  char pngFile[256];

  snprintf(dotFile, sizeof(dotFile), "%s.dot", baseName);
  snprintf(pngFile, sizeof(pngFile), "%s.png", baseName);

  exportComparisonDOT(before, after, dotFile, titleBefore, titleAfter);
  dotToPNG(dotFile, pngFile);

  printf("Gerados: %s e %s\n", dotFile, pngFile);
}

// ============================================================================
// Utilitários interactivos
// ============================================================================

void clearInputLine(void)
{
  int c;
  do
  {
    c = getchar();
  }
  while(c != '\n' && c != EOF);
}

int readInt(const char *prompt, int *x)
{
  int ok;

  printf("%s", prompt);
  ok = scanf("%d", x);
  if(ok != 1)
  {
    clearInputLine();
    return 0;
  }

  clearInputLine();
  return 1;
}

void mostraEstatisticas(abin a)
{
  int n = size(a);
  int p = depth(a);

  printf("size  = %d\n", n);
  printf("depth = %d\n", p);
}

void mostraMenu(void)
{
  printf("\n========================================\n");
  printf("Menu BST\n");
  printf("1  - Inserir valor\n");
  printf("2  - Remover valor\n");
  printf("3  - Procurar valor\n");
  printf("4  - Imprimir árvore\n");
  printf("5  - Mostrar size/depth\n");
  printf("6  - Exportar árvore atual para PNG\n");
  printf("7  - Reequilibrar (toArraySorted + fromArrayBalanced)\n");
  printf("8  - Mostrar árvore como array ordenado\n");
  printf("9  - Construir BST a partir de array introduzido pelo utilizador\n");
  printf("10 - Construir árvore equilibrada a partir de array ordenado\n");
  printf("11 - Limpar árvore\n");
  printf("12 - Rotação à esquerda num nó\n");
  printf("13 - Rotação à direita num nó\n");
  printf("0  - Sair\n");
  printf("========================================\n");
}

void leArray(int **v, int *N)
{
  int i;

  *v = NULL;
  *N = 0;

  if(!readInt("Quantos elementos? ", N))
  {
    printf("Entrada inválida.\n");
    return;
  }

  if(*N <= 0)
  {
    *N = 0;
    return;
  }

  *v = malloc(sizeof(int) * (*N));
  if(*v == NULL)
  {
    printf("Falha de memória.\n");
    *N = 0;
    return;
  }

  for(i = 0; i < *N; i++)
  {
    char prompt[64];
    snprintf(prompt, sizeof(prompt), "v[%d] = ", i);
    if(!readInt(prompt, &((*v)[i])))
    {
      printf("Entrada inválida.\n");
      free(*v);
      *v = NULL;
      *N = 0;
      return;
    }
  }
}

// ============================================================================
// Programa principal
// ============================================================================

int main(void)
{
  abin a = NULL;
  int opcao;
  int running = 1;
  int opCounter = 1;

  printf("Programa interactivo de árvores binárias de pesquisa\n");
  printf("As imagens PNG são geradas com Graphviz (comando dot).\n");
  printf("As comparações antes/depois são colocadas na vertical.\n");
  printf("Nós com o mesmo valor têm a mesma cor em imagens diferentes.\n");

  while(running)
  {
    mostraMenu();

    if(!readInt("Escolha uma opção: ", &opcao))
    {
      printf("Opção inválida.\n");
      continue;
    }

    switch(opcao)
    {
      case 1:
      {
        int x;
        abin before;
        char base[128];
        char tBefore[128];
        char tAfter[128];

        if(!readInt("Valor a inserir: ", &x))
        {
          printf("Entrada inválida.\n");
          break;
        }

        before = clone_abin(a);
        a = insert(x, a);

        snprintf(base, sizeof(base), "op_%03d_insert_%d", opCounter, x);
        snprintf(tBefore, sizeof(tBefore), "Antes de inserir %d", x);
        snprintf(tAfter, sizeof(tAfter), "Depois de inserir %d", x);
        exportBeforeAfterPNG(before, a, base, tBefore, tAfter);
        before = free_abin(before);

        printf("Inserção concluída.\n");
        mostraEstatisticas(a);
        opCounter++;
        break;
      }

      case 2:
      {
        int x;
        abin before;
        char base[128];
        char tBefore[128];
        char tAfter[128];

        if(!readInt("Valor a remover: ", &x))
        {
          printf("Entrada inválida.\n");
          break;
        }

        before = clone_abin(a);
        a = remove_bst(x, a);

        snprintf(base, sizeof(base), "op_%03d_remove_%d", opCounter, x);
        snprintf(tBefore, sizeof(tBefore), "Antes de remover %d", x);
        snprintf(tAfter, sizeof(tAfter), "Depois de remover %d", x);
        exportBeforeAfterPNG(before, a, base, tBefore, tAfter);
        before = free_abin(before);

        printf("Remoção concluída.\n");
        mostraEstatisticas(a);
        opCounter++;
        break;
      }

      case 3:
      {
        int x;
        abin r;

        if(!readInt("Valor a procurar: ", &x))
        {
          printf("Entrada inválida.\n");
          break;
        }

        r = search_bst_it(x, a);
        if(r == NULL)
        { printf("Valor %d não encontrado.\n", x); }
        else
        { printf("Valor %d encontrado no nó %p.\n", x, (void *) r); }
        break;
      }

      case 4:
      {
        imprimeArvore(a);
        break;
      }

      case 5:
      {
        mostraEstatisticas(a);
        break;
      }

      case 6:
      {
        char base[128];
        snprintf(base, sizeof(base), "arvore_atual_%03d", opCounter);
        exportCurrentPNG(a, base);
        break;
      }

      case 7:
      {
        abin before;
        abin balanced;
        char base[128];

        before = clone_abin(a);
        balanced = rebalance_bst(a);
        a = free_abin(a);
        a = balanced;

        snprintf(base, sizeof(base), "op_%03d_rebalance", opCounter);
        exportBeforeAfterPNG(before,
                             a,
                             base,
                             "Antes do reequilíbrio",
                             "Depois do reequilíbrio");
        before = free_abin(before);

        printf("Reequilíbrio concluído.\n");
        mostraEstatisticas(a);
        opCounter++;
        break;
      }

      case 8:
      {
        int N;
        int *v;

        v = toArraySorted(a, &N);
        printf("Array ordenado: ");
        printArray(v, N);
        free(v);
        break;
      }

      case 9:
      {
        int *v;
        int N;
        abin before;
        char base[128];

        leArray(&v, &N);
        if(N == 0)
        {
          printf("Nenhum valor lido.\n");
          break;
        }

        before = clone_abin(a);
        a = free_abin(a);
        a = fromArrayInsert(v, N);
        free(v);

        snprintf(base, sizeof(base), "op_%03d_from_array_insert", opCounter);
        exportBeforeAfterPNG(before,
                             a,
                             base,
                             "Antes",
                             "Depois de construir por inserções");
        before = free_abin(before);

        printf("Nova BST construída por inserções.\n");
        mostraEstatisticas(a);
        opCounter++;
        break;
      }

      case 10:
      {
        int *v;
        int N;
        abin before;
        char base[128];

        leArray(&v, &N);
        if(N == 0)
        {
          printf("Nenhum valor lido.\n");
          break;
        }

        before = clone_abin(a);
        a = free_abin(a);
        a = fromArrayBalanced(v, N);
        free(v);

        snprintf(base, sizeof(base), "op_%03d_from_array_balanced", opCounter);
        exportBeforeAfterPNG(before,
                             a,
                             base,
                             "Antes",
                             "Depois de construir equilibrada");
        before = free_abin(before);

        printf("Nova árvore equilibrada construída a partir do array.\n");
        printf("Atenção: para ter também propriedade BST, o array deve estar ordenado.\n");
        mostraEstatisticas(a);
        opCounter++;
        break;
      }

      case 11:
      {
        abin before;
        char base[128];

        before = clone_abin(a);
        a = free_abin(a);

        snprintf(base, sizeof(base), "op_%03d_clear", opCounter);
        exportBeforeAfterPNG(before,
                             a,
                             base,
                             "Antes de limpar",
                             "Depois de limpar");
        before = free_abin(before);

        printf("Árvore libertada.\n");
        opCounter++;
        break;
      }

      case 12:
      {
        int x;
        abin before;
        char base[128];
        char tBefore[128];
        char tAfter[128];

        if(!readInt("Rodar à esquerda no nó com valor: ", &x))
        {
          printf("Entrada inválida.\n");
          break;
        }

        before = clone_abin(a);

        if(canRotateLeftAt(x, a))
        {
          a = rotateLeftAt(x, a);
          printf("Rotação à esquerda concluída.\n");
        }
        else
        {
          printf("Não foi possível rodar à esquerda nesse nó.\n");
        }

        snprintf(base, sizeof(base), "op_%03d_rot_left_%d", opCounter, x);
        snprintf(tBefore, sizeof(tBefore), "Antes de rodar à esquerda em %d", x);
        snprintf(tAfter, sizeof(tAfter), "Depois de rodar à esquerda em %d", x);
        exportBeforeAfterPNG(before, a, base, tBefore, tAfter);
        before = free_abin(before);

        mostraEstatisticas(a);
        opCounter++;
        break;
      }

      case 13:
      {
        int x;
        abin before;
        char base[128];
        char tBefore[128];
        char tAfter[128];

        if(!readInt("Rodar à direita no nó com valor: ", &x))
        {
          printf("Entrada inválida.\n");
          break;
        }

        before = clone_abin(a);

        if(canRotateRightAt(x, a))
        {
          a = rotateRightAt(x, a);
          printf("Rotação à direita concluída.\n");
        }
        else
        {
          printf("Não foi possível rodar à direita nesse nó.\n");
        }

        snprintf(base, sizeof(base), "op_%03d_rot_right_%d", opCounter, x);
        snprintf(tBefore, sizeof(tBefore), "Antes de rodar à direita em %d", x);
        snprintf(tAfter, sizeof(tAfter), "Depois de rodar à direita em %d", x);
        exportBeforeAfterPNG(before, a, base, tBefore, tAfter);
        before = free_abin(before);

        mostraEstatisticas(a);
        opCounter++;
        break;
      }

      case 0:
      {
        running = 0;
        break;
      }

      default:
      {
        printf("Opção inválida.\n");
        break;
      }
    }
  }

  a = free_abin(a);
  return 0;
}

