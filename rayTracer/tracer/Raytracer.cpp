#include "Raytracer.h"
#include "../geometry/Vector.h"
#include "../geometry/Point.h"
#include "../scene/primitive/Sphere.h"
#include "../geometry/Ray.h"
#include "../image/PGMOut.h"
#include "../scene/Camera.h"


vector<vector<int>> Raytracer::to_raster(int res)
{
    int resolution = res;

    cout << "P2\n"; // Magic PBM bytes
    cout << resolution << ' ' << resolution << '\n';
    cout << "255\n"; // This means that 1 should be displayed as white.

    double viewport_scale_factor{ resolution == 1 ? 1 : 2. / resolution };
    double viewport_shift{ 1 - 1. / resolution };

    // The camera is located at (x=0;y=0;z=5).
    Point camera_pos{ 0, 0, 5 };

    // And there is a sphere at (0;0;-5) with radius 1.
    int radius = 1;
    Point old_center{ 0, 0, -5 };
    Point center{ 0, 0,0 };
    Sphere sphere(old_center, radius);

    Camera camera(camera_pos, center, 2.0, 2.0);

    vector<double> distances;
    vector<vector<int>> outPut;

    for (int y_pixel = resolution - 1; y_pixel >= 0 ; --y_pixel)
    {
        double viewport_y_coordinate{ y_pixel * viewport_scale_factor - viewport_shift };

        for (int x_pixel = 0; x_pixel < resolution; ++x_pixel)
        {
            double viewport_x_coordinate{ x_pixel * viewport_scale_factor - viewport_shift };

            Ray rays = camera.getRay(viewport_x_coordinate, viewport_y_coordinate);
            //cout << "camera direction is " << rays.getRayDirection() << ", camera_pos is " << rays.getCamera() << endl;

            sphere.intersections(rays);

        }
        outPut.push_back(sphere.row);
        sphere.row.clear();
    }

	return outPut;
}
