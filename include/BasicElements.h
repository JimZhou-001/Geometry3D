#ifndef BASIC_ELEMENTS_H
#define BASIC_ELEMENTS_H

#include <iostream>
#include "Vector3D.h"

class LineSegment;
class Plane;

class Point
{
	friend class Vector3D;
	friend class LineSegment;
	friend std::ostream& operator <<(std::ostream& _ostream, Point point);

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0): x_(x), y_(y), z_(z) {}
	Point(const Point& point);
	Point(const Vector3D& vector3D);
	double distanceTo(const Point& point);
	double distanceTo(const LineSegment& lineSegment);
	double distanceTo(const Plane& plane);

protected:
	double x_;
	double y_;
	double z_;
};

class LineSegment
{
	friend class Point;

public:
	LineSegment(const Point& endpoint1, const Point& endpoint2):
	endpoint1_(endpoint1), endpoint2_(endpoint2) {}
	double length();
	Vector3D direction();

protected:
	Point endpoint1_;
	Point endpoint2_;
};

class Plane
{
	friend class Point;

public:
	Plane(const Point& onePoint, const Vector3D& normal):
	onePoint_(onePoint), normal_(normal) {}

protected:
	Point onePoint_;
	Vector3D normal_;
};

std::ostream& operator <<(std::ostream& _ostream, Point point);

#endif
