#ifndef RAYTRACER_H
#define RAYTRACER_H
#include <vector>

using namespace std;

class Raytracer
{
public:
	vector<vector<int>> to_raster(int res);
};

#endif
