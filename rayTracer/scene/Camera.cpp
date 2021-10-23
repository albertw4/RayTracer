#include "Camera.h"

Camera::Camera()
{
	camera_position = { 0,0,0 };
	view_vector = { 0,0,0 };
	up_vector = { 0,0,0 };
	right_vector = { 0,0,0 };
}

Camera::Camera(Point camera_pos, Point viewPoint_center,
	double viewPoint_height, double viewPoint_width)
{
	Vector crossWith{ 0,1,0 };
	camera_position = camera_pos;
	//cout << "camera position is " << camera_position << endl;

	view_vector = viewPoint_center - camera_pos;

	//cout << "view_vector is " << view_vector << endl;
	right_vector = view_vector.crossProc(view_vector, crossWith);
	//cout << "crossprodc is " << right_vector << endl;

	right_vector.length_scale(viewPoint_width / 2);
	//cout << "right_vector is " << right_vector << endl;

	up_vector = right_vector.crossProc(right_vector, view_vector);
	up_vector.length_scale(viewPoint_height / 2);
	//cout << "up_vector is " << up_vector << endl;


	//test
	//camera_position = { 0,0,5 };
	//view_vector = { 0,0,-5 };
	//up_vector = { 0,1,0 };
	//right_vector = { 1,0,0 };
}

Ray Camera::getRay(double viewPoint_horizontal, double viewPoint_vertical)
{
	auto horizontal = right_vector.scale(viewPoint_horizontal);
	auto vertical = up_vector.scale(viewPoint_vertical);
	auto direction = view_vector + horizontal + vertical;
	direction.normalize();
	Ray ray{ direction ,camera_position };
	return ray;
}

Camera& Camera::operator=(const Camera& a)
{
	camera_position = a.camera_position;
	view_vector = a.view_vector;
	up_vector = a.up_vector;
	right_vector = a.right_vector;
	return *this;
}
