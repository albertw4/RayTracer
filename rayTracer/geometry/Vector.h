#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include "Point.h"

struct Point;

struct Vector
{
	double x, y, z;

public:
	void setVec(const Point& p);
	Vector operator + (const Vector& v);
	double operator * (const Vector& v);
	Vector scale(int s);
	Vector scale(double s);
	void length_scale(double s);
	void normalize();
	double length();
	Vector& operator = (const Vector& v);
	Vector operator - (const Point& p);
	Vector crossProc(const Vector& v1, const Vector& v2);
	friend std::ostream& operator << (std::ostream& out, const Vector& v);
};

#endif
