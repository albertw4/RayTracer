#include "Scene.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cctype>


Scene::Scene(string fileName)
{
	std::ifstream f( fileName );

	if (f.is_open())
	{
		string line;
		while (std::getline(f, line))
		{
			cout << line << endl;

			int foundCamera = line.find("camera");
			int foundSphere = line.find("sphere");
			int foundPlane = line.find("plane");

			if (foundCamera != string::npos)
			{
				double x, y, z, x2, y2, z2, w, h;
				vector<double> data;
				double n;
				istringstream ss( line );
				cout << "there is a camera at " << foundCamera << endl;
				while (ss)
				{
					if (isdigit(ss.peek()))
					{
						ss >> n;
						data.push_back(n);
					}
					else {
						ss.ignore();
					}
				}
				x = data[0];
				y = data[1];
				z = data[2];
				x2 = data[3];
				y2 = data[4];
				z2 = data[5];
				w = data[6];
				h = data[7];
				cout << x << ", " << y << ", " << z << ", " << x2 << ", " << y2 << ", " << z2 << ", " << w << ", " << h << endl;
				Camera temp{ Point{x, y ,z}, Point{x2, y2, z2}, w, h };
				camera = temp;
			}

			if (foundSphere != string::npos)
			{
				double x, y, z, r;
				vector<double> data;
				double n;
				istringstream ss(line);
				cout << "there is a sphere at " << foundSphere << endl;
				while (ss)
				{
					if (ss.peek() == '-')
					{
						ss.ignore();
						ss >> n;
						n *= -1;
						data.push_back(n);
					}

					if (isdigit(ss.peek()))
					{
						ss >> n;
						data.push_back(n);
					}
					else {
						ss.ignore();
					}
				}
				x = data[0];
				y = data[1];
				z = data[2];
				r = data[3];
				cout << x << ", " << y << ", " << z << ", " << r << endl;
				Sphere sphere{ Point{x, y, z}, static_cast<int>(r) };
				Sphere* ptr = &sphere;
				spheres.push_back(ptr);
				names.push_back("sphere");
			}

			if (foundPlane != string::npos)
			{
				double x, y, z, x2, y2, z2;
				vector<double> data;
				double n;
				istringstream ss(line);
				cout << "there is a plane at " << foundPlane << endl;
				while (ss)
				{
					if (ss.peek() == '-')
					{
						ss.ignore();
						ss >> n;
						n *= -1;
						data.push_back(n);
					}

					if (isdigit(ss.peek()))
					{
						ss >> n;
						data.push_back(n);
					}
					else {
						ss.ignore();
					}
				}
				x = data[0];
				y = data[1];
				z = data[2];
				x2 = data[3];
				y2 = data[4];
				z2 = data[5];
				cout << x << ", " << y << ", " << z << ", " << x2 << ", " << y2 << ", " << z2 << endl;
				Plane plane{ Point{x, y, z}, Vector{x2, y2, z2} };
				Plane* ptr = &plane;
				planes.push_back(ptr);
				names.push_back("plane");
			}

		}

	}
	else
	{
		cout << fileName << " failed to open\n";
		_Exit(0);
	}
}
