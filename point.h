#ifndef __POINT__
#define __POINT__

#include "boolean.h"

typedef struct _point Point;

Point *create_point(float x, float y);

bool compare_points(const void* _p1, const void* _p2);

#endif