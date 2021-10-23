#ifndef CAMERA_H
#define CAMERA_H
#include "../geometry/Point.h"
#include "../geometry/Vector.h"
#include "../geometry/Ray.h"


using namespace std;
class Camera
{
	Point camera_position;
	Vector view_vector;
	Vector up_vector;
	Vector right_vector;

public:
	Camera();
	Camera(Point camera_pos, Point viewPoint_center, double viewPoint_height, double viewPoint_width);

	Ray getRay(double viewPoint_horizontal, double viewPoint_vertical);

	Camera& operator = (const Camera& a);

};

#endif