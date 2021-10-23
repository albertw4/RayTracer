#ifndef PLANE_H
#define PLANE_H
#include "Primitive.h"
#include "Intersection.h"

struct Intersection;

using namespace std;

class Plane : Primitive
{
	Point point;
	Vector normal;
	double distance;

public:
	Plane(Point p, Vector v);
	virtual vector<Intersection> intersections(Ray& ray) ;
};

#endif