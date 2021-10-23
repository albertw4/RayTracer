#include "Plane.h"

Plane::Plane(Point p, Vector v)
{
	normal = v;
	normal.normalize();
	Vector plane_vector;
	plane_vector.setVec(p);
	distance = -(plane_vector * this->normal);
}

vector<Intersection> Plane::intersections(Ray& ray)
{
	vector<Intersection> result;
	Intersection intersection;
	double vd = ray.getRayDirection() * this->normal;
	if (vd != 0)
	{
		Vector zero{ 0,0,0 };
		Vector temp = zero - ray.getCamera();
		distance = -(this->normal * (temp)+this->distance) / vd;
		if (distance > 0)
		{
			intersection.distance = distance;
			intersection.intersection = ray.getCamera() + ray.getRayDirection().scale(distance);
			intersection.primitive = this;
			result.push_back(intersection);
			//result.push_back(distance);
			cout << "Plane distance is " << distance << endl;
		}
	}
	return result;
}
