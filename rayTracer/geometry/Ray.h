#ifndef RAY_H
#define RAY_H

#include "Vector.h"
#include "Point.h"
class Ray
{
	Vector ray_direction;
	Point camera;

public:
	Ray(Vector x, Point y);

	Point getCamera();

	Vector getRayDirection();
};

#endif