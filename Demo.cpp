#include "Geometry3D.h"
#include <iostream>

using namespace std;

int main(void)
{
	cout << "Hello, 3D!" << endl;
	Point point(1, 2, 3);
	Sphere sphere(point, 12);
	cout << "The volume of sphere with radius 12 is " << sphere.volume() << endl;

	return 0;
}