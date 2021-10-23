#include "Vector.h"
#include <math.h>



void Vector::setVec(const Point& p)
{
	this->x = p.x;
	this->y = p.y;
	this->z = p.z;
}

Vector Vector::operator+(const Vector& v)
{
	Vector temp;
	temp.x = this->x + v.x;
	temp.y = this->y + v.y;
	temp.z = this->z + v.z;
	return temp;
}

double Vector::operator*(const Vector& v)
{
	return (this->x * v.x + this->y * v.y + this->z * v.z);
}

Vector Vector::scale(int s)
{
	Vector temp;
	temp.x = this->x * s;
	temp.y = this->y * s;
	temp.z = this->z * s;
	return temp;
}

Vector Vector::scale(double s)
{
	Vector temp;
	temp.x = this->x * s;
	temp.y = this->y * s;
	temp.z = this->z * s;
	return temp;
}

void Vector::length_scale(double s)
{

	if(this->x != 0.0) {
		this->x = s;
	}
	else{
		this->x = 0.0;
	}

	if (this->y != 0.0) {
		this->y = s;
	}
	else {
		this->y = 0.0;
	}

	if (this->z != 0.0) {
		this->z = s;
	}
	else {
		this->z = 0.0;
	}

}

void Vector::normalize()
{
	double length = this->length();
	this->x /= length;
	this->y /= length;
	this->z /= length;
}

double Vector::length()
{
	double temp = sqrt(x * x + y * y + z * z);
	return abs(temp);
}

Vector& Vector::operator=(const Vector& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

Vector Vector::operator-(const Point& p)
{
	Vector temp;
	temp.x = this->x - p.x;
	temp.y = this->y - p.y;
	temp.z = this->z - p.z;
	return temp;
}

Vector Vector::crossProc(const Vector& v1, const Vector& v2)
{
	Vector temp;
	temp.x = v1.y * v2.z - v1.z * v2.y;
	temp.y = v1.z * v2.x - v1.x * v2.z;
	temp.z = v1.x * v2.y - v1.y * v2.x;
	if (temp.x == -0.0) { temp.x = 0.0; }
	if (temp.y == -0.0) { temp.y = 0.0; }
	if (temp.z == -0.0) { temp.z = 0.0; }

	return temp;
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
	out << v.x << ", " << v.y << ", " << v.z << std::endl;
	return out;
}
