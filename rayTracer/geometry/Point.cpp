#include "Point.h"

Vector Point::getVec(const Point& p)
{
	Vector temp;
	temp.x = p.x - x;
	temp.y = p.y - y;
	temp.z = p.z - z;
	return temp;
}

Vector Point::operator-(const Point& p)
{
	Vector temp;
	temp.x = x - p.x;
	temp.y = y - p.y;
	temp.z = z - p.z;
	return temp;
}

Point Point::operator+(const Vector& v)
{
	Point temp;
	temp.x = this->x + v.x;
	temp.y = this->y + v.y;
	temp.z = this->z + v.z;
	return temp;
}

std::ostream& operator<<(std::ostream& out, const Point& v)
{
	out << v.x << ", " << v.y << ", " << v.z << std::endl;
	return out;
}
