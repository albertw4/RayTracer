#ifndef PRIMITIVE_H
#define PRIMITIVE_H
#include <vector>
#include "../../geometry/Ray.h"
#include "../../geometry/Point.h"
#include "../../geometry/Vector.h"
#include "Intersection.h"
using namespace std;

struct Intersection;
class Primitive
{
public:
	virtual vector<Intersection> intersections(Ray& ray) = 0;

};

#endif