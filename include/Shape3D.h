#ifndef SHAPE_3D_H
#define SHAPE_3D_H

#include "BasicElements.h"

class Point;

class Shape3D
{
public:
	virtual double volume() = 0;
	virtual double surfaceArea() = 0;
};

class Sphere: public Shape3D
{
public:
	Sphere(const Point& center, double radius):
	center_(center), radius_(radius) {}
	
	virtual double volume();
	virtual double surfaceArea();
	
protected:
	Point center_;
	double radius_;
};

#endif
