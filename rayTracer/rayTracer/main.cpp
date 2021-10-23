#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include "../geometry/Vector.h"
#include "../geometry/Point.h"
#include "../scene/primitive/Sphere.h"
#include "../geometry/Ray.h"
#include "../image/PGMOut.h"
#include "../tracer/Raytracer.h"
#include "../scene/Scene.h"

using namespace std;

int main(int argc, char* argv[]) {

    Vector v1{ 3, -5,4 };
    Vector v2{ 2,6,5 };
    Vector v3 = v1.crossProc(v1, v2);
    cout << v3 <<endl;

    Scene scene( "planesphere.scene" );
    Raytracer tracer;
    PGMOut out;
    int resolution = 11;
    out.save(tracer.to_raster(resolution));
    return 0;
}