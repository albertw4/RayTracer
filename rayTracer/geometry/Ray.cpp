#include "Ray.h"

Ray::Ray(Vector x, Point y) :
	ray_direction(x), camera(y) {}

Point Ray::getCamera()
{
	return camera;
}

Vector Ray::getRayDirection()
{
	return ray_direction;
}
