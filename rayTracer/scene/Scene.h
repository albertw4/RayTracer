#ifndef SCENE_H
#define SCENE_H
#include "Camera.h"
#include "primitive/Primitive.h"
#include "primitive/Intersection.h"
#include "primitive/Sphere.h"
#include "primitive/Plane.h"
#include <vector>
#include <iterator>
#include <optional>
#include <functional>
#include <string>
#include <iostream>

class Scene
{
	Camera camera;
	vector<Sphere*> spheres;
	vector<Plane*> planes;
	vector<string> names;

public:
	Scene(string fileName);

	
};

#endif