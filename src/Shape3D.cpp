#include "Shape3D.h"
#include <cmath>

double Sphere::volume()
{
	return 4.0 / 3 * M_PI * pow(radius_, 3);
}

double Sphere::surfaceArea()
{
	return 4 * M_PI * pow(radius_, 2);
}