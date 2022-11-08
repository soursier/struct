#define _USE_MATH_DEFINES
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
double epsilon = 1.0e-05;
bool isEqual_double(double a, double b) { return fabs(a - b) < epsilon; }

typedef struct _point {
  double x;
  double y;
} point;

typedef struct _line {
  point a;
  point b;
} line;

typedef struct _triangle {
  point a;
  point b;
  point c;
} triangle;

typedef struct _square {
  point a;
  point b;
  point c;
  point d;
} square;

typedef struct _rectangle {
  point a;
  point b;
  point c;
  point d;
} rectangle;

typedef struct circle {
  point a;
  int radius;
} circle;

double getCoordinateDistance(double a, double b) { return fabs(a - b); }
double getDistance(point a, point b) {
  return hypot(getCoordinateDistance(a.x, b.x),
               getCoordinateDistance(a.y, b.y));
}

bool isPerpendiculaire(point angle, point point_droite_1,
                       point point_droite_2) {
  printf("distance hypotenuse, formule = %f\n",
         hypot(getDistance(angle, point_droite_1),
               getDistance(angle, point_droite_2)));

  printf("distance hypotenuse, reelle = %f\n",
         getDistance(point_droite_1, point_droite_2));
  return isEqual_double(hypot(getDistance(angle, point_droite_1),
                              getDistance(angle, point_droite_2)),
                        getDistance(point_droite_1, point_droite_2));
}
bool isRectangle(rectangle rect) {
  if (!(isEqual_double(getDistance(rect.a, rect.b),
                       getDistance(rect.c, rect.d)))) {
    printf("cote differents !");
    return false;
  }

  if (!(isPerpendiculaire(rect.b, rect.a, rect.c))) {
    printf("Pas perpendiculaire\n");
    return false;
  }
  acos(1);
  return true;
}
double getPerimeterRectangle(rectangle rect) {
  return (getDistance(rect.a, rect.b) + getDistance(rect.b, rect.c)) * 2;
}
double getAreaRectangle(rectangle rect) {
  return getDistance(rect.a, rect.b) * getDistance(rect.b, rect.c);
}

bool isCarre(square carre) {
  if (!(isEqual_double(getDistance(carre.a, carre.b),
                       getDistance(carre.c, carre.d))))

  {
    printf("cote differents !");
    return false;
  }

  if (!(isPerpendiculaire(carre.b, carre.a, carre.c))) {
    printf("Pas perpendiculaire\n");
    return false;
  }

  if (!(isEqual_double(getDistance(carre.a, carre.b),
                       getDistance(carre.b, carre.c))))

  {
    printf("cote differents !");
    return false;
  }
  return true;
}
double getPerimeterSquare(square carre) {
  return getDistance(carre.a, carre.b) * 4;
}
double getAreaSquare(square carre) {
  return pow(getDistance(carre.a, carre.b), 2);
}
double getAreaCircle(circle cercle) { return pow(cercle.radius * M_PI, 2); }
int main() {
  point a = {0, 0};
  point b = {1, 0};
  point c = {1, 1};
  point d = {0, 1};
  struct circle test;

  printf("distance en x ab = %f\n", getCoordinateDistance(c.x, b.x));
  printf("distance hypotenuse, formule = %f\n",
         hypot(getDistance(a, b), getDistance(b, c)));
  printf("distance hypotenuse, reelle = %f\n", getDistance(a, c));
  rectangle rect = {a, b, c, d};
  if (isEqual_double(getDistance(rect.a, rect.b),
                     getDistance(rect.c, rect.d))) {
    printf("tout va bien \n");
  } else {
    printf("??\n");
  }
  if (isRectangle(rect)) {
    printf("Perpendiculaire !\n");
  } else {
    printf("Pas rectangle !\n");
  }
  return 0;
}