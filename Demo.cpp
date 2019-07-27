#include "Geometry3D.h"
#include <iostream>

using namespace std;

int main(void)
{
	cout << "Hello, 3D!" << endl;
	Point point(1, 2, 3);
	Sphere sphere(point, 12);
	Shape3D* shape3D = &sphere;
	cout << "The volume of sphere with radius 12 is " << shape3D->volume() << endl;
	cout << "The surface area of sphere with radius 12 is " << shape3D->surfaceArea() << endl;

	return 0;
}