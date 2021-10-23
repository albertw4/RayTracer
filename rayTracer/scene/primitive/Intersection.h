#ifndef INTERSECTION_H
#define INTERSECTION_H
#include "Primitive.h"

class Primitive;

struct Intersection
{
	Primitive* primitive;
	double distance;
	Point intersection;
};

#endif