#include "Sphere.h"
#include <algorithm>
#include <math.h>

Sphere::Sphere(Point c, int r) :
	center(c), radius(r) {}

vector<Intersection> Sphere::intersections(Ray& ray)
{
	vector<Intersection> temp;
    Intersection intersection;

    Vector delta = ray.getCamera() - center;

    double b{ delta * ray.getRayDirection() * 2 };

    double c{ delta * delta - radius * radius };

    // If there is an intersection, the discriminant >= 0, so we emit 1, to indicate full brightness, otherwise
    // 0 to indicate black.
    double discriminant{ b * b - 4 * c };

    double distance;
    double distance1 = (-b + sqrt(discriminant)) / 2;
    double distance2 = (-b - sqrt(discriminant)) / 2;
    if (distance1 > 0 && distance2 > 0)
    {
        //temp.push_back(distance1);
        //temp.push_back(distance2);
        distance = std::min(distance1, distance2);
        //cout <<endl << "both distances positive" << distance1 <<", " << distance2 << endl;
    }

    if (distance1 == 0) 
    { 
        //temp.push_back(distance2);
        distance = distance2;
    }
    if (distance2 == 0) 
    { 
        //temp.push_back(distance1); 
        distance = distance1;
    }
    
    if (discriminant >= 0) {
        //cout << "1 ";
        double brightness = 10 - distance;
        if (brightness < 0) brightness = 0;
        int pixel_brightness = static_cast<int>(brightness * 255);
        row.push_back(pixel_brightness);

        intersection.distance = distance;
        intersection.intersection = ray.getCamera() + ray.getRayDirection().scale(distance);
        intersection.primitive = this;
        temp.push_back(intersection);
    }
    else {
        //cout << "0 ";
        row.push_back(0);
    }

	return temp;
}
