#ifndef GEOMETRY_ELEMENTS_H
#define GEOMETRY_ELEMENTS_H

#include <iostream>

class Point;

class Vector
{
	friend class Point;
	friend Vector operator *(double value, Vector vector);
	friend std::ostream& operator <<(std::ostream& _ostream, Vector vector);

public:
	Vector(double x = 0.0, double y = 0.0, double z = 0.0): x_(x), y_(y), z_(z) {}
	Vector(const Vector& second_vector);
	Vector(const Point& point);
	double norm();
	double dot(const Vector& second_vector);
	Vector cross(const Vector& second_vector);

	Vector operator -(void);
	Vector operator +(const Vector& second_vector);
	Vector operator -(const Vector& second_vector);
	Vector operator *(double value);
	Vector operator /(double value);
	Vector& operator *=(double value);
	Vector& operator /=(double value);

protected:
	double x_;
	double y_;
	double z_;
};

class LineSegment;
class Plane;

class Point
{
	friend class Vector;
	friend class LineSegment;
	friend std::ostream& operator <<(std::ostream& _ostream, Point point);

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0): x_(x), y_(y), z_(z) {}
	Point(const Point& second_point);
	Point(const Vector& vector);
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
	Vector direction();

protected:
	Point endpoint1_;
	Point endpoint2_;
};

class Plane
{
	friend class Point;

public:
	Plane(const Point& onePoint, const Vector& normal):
	onePoint_(onePoint), normal_(normal) {}

protected:
	Point onePoint_;
	Vector normal_;
};

class Sphere
{
public:
	Sphere(const Point& center, double radius):
	center_(center), radius_(radius) {}
	double volume();
	
protected:
	Point center_;
	double radius_;
};

std::ostream& operator <<(std::ostream& _ostream, Vector vector);

std::ostream& operator <<(std::ostream& _ostream, Point point);

#endif