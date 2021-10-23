#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include "geometry/Vector.h"
#include "geometry/Point.h"
#include "scene/Sphere.h"
#include "geometry/Ray.h"
#include "image/PGMOut.h"
#include "tracer/Raytracer.h"

using namespace std;

int main(int argc, char* argv[]) {
    Raytracer tracer;
    PGMOut out;
    int resolution = atoi(argv[1]);
    out.save(tracer.to_raster(resolution));
    return 0;
}