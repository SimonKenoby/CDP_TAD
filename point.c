#include "point.h"
#include <stdlib.h>
#include <assert.h>

typedef struct _point {
   float x;
   float y;
}Point ;

Point *create_point(float x, float y) {
   Point *new_point = malloc(sizeof(Point));
   assert(new_point);
   new_point->x = x;
   new_point->y = y;
   return new_point;
}

bool compare_points(const void* _p1, const void* _p2) {
   Point *p1 = (Point*)_p1;
   Point *p2 = (Point*)_p2;
   return (bool) (p1->x == p2->x && p1->y == p2->y);
}