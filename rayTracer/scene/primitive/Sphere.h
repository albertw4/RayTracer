#ifndef SPHERE_H
#define SPHERE_H

#include "../../geometry/Point.h"
#include <vector>
#include "../../geometry/Ray.h"
#include "Primitive.h"

using namespace std;

class Sphere : Primitive
{
	Point center;
	int radius;

public:
	vector<int> row;
	Sphere(Point c, int r);
	vector<Intersection> intersections(Ray& ray) override;
};

#endif
