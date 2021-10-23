#ifndef POINT_H
#define POINT_H

#include "Vector.h"

struct Vector;

struct Point
{
	double x, y, z;

	Vector getVec(const Point& p);

	Vector operator - (const Point& p);

	Point operator + (const Vector& v);

	friend std::ostream& operator << (std::ostream& out, const Point& p);

};

#endif
