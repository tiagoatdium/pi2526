#include <stdio.h>

// Point: representa um ponto
//
// tem duas coordenadas:
// - x : coordenada horizontal
// - y : coordenada vertical
typedef struct
{
  int x;
  int y;
} Point;


// print_point: imprime um ponto no formato (x, y)
void print_point(Point p)
{
  printf("(%d, %d)\n", p.x, p.y);
}


// move_point: desloca um ponto
//
// - dx : deslocamento na direção x
// - dy : deslocamento na direção y
void move_point(Point *p, int dx, int dy)
{
  p->x = p->x + dx;
  p->y = p->y + dy;
}


// add_points: soma dois pontos
//
// exemplo:
//   (1,2) + (3,4) = (4,6)
Point add_points(Point a, Point b)
{
  Point r;

  r.x = a.x + b.x;
  r.y = a.y + b.y;

  return r;
}


int main()
{
  // criar dois pontos
  Point p1 = {1, 2};
  Point p2 = {3, 4};

  printf("Ponto p1:\n");
  print_point(p1);

  printf("Ponto p2:\n");
  print_point(p2);

  // somar dois pontos
  Point p3 = add_points(p1, p2);

  printf("p1 + p2 = ");
  print_point(p3);

  // mover um ponto
  move_point(&p1, 5, -1);

  printf("p1 depois de mover:\n");
  print_point(p1);

  return 0;
}
