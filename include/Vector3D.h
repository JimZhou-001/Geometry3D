#ifndef Vector_3D_H
#define Vector_3D_H

#include <iostream>

class Point;

class Vector3D
{
	friend class Point;
	friend Vector3D operator *(double value, Vector3D Vector3D);
	friend std::ostream& operator <<(std::ostream& _ostream, Vector3D vector3D);

public:
	Vector3D(double x = 0.0, double y = 0.0, double z = 0.0): x_(x), y_(y), z_(z) {}
	Vector3D(const Vector3D& secondVector3D);
	Vector3D(const Point& point);
	double norm();
	double dot(const Vector3D& secondVector3D);
	Vector3D cross(const Vector3D& secondVector3D);

	Vector3D operator -(void);
	Vector3D operator +(const Vector3D& secondVector3D);
	Vector3D operator -(const Vector3D& secondVector3D);
	Vector3D operator *(double value);
	Vector3D operator /(double value);
	Vector3D& operator *=(double value);
	Vector3D& operator /=(double value);

protected:
	double x_;
	double y_;
	double z_;
};

std::ostream& operator <<(std::ostream& _ostream, Vector3D vector3D);

#endif