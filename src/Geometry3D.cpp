#include "Geometry3D.h"
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

Vector::Vector(const Vector& second_vector)
{
	x_ = second_vector.x_;
	y_ = second_vector.y_;
	z_ = second_vector.z_;
}

Vector::Vector(const Point& point)
{
	x_ = point.x_;
	y_ = point.y_;
	z_ = point.z_;
}

double Vector::norm()
{
	return sqrt(x_ * x_ + y_ * y_ + z_ * z_);
}

double Vector::dot(const Vector& second_vector)
{
	return x_ * second_vector.x_ + y_ * second_vector.y_ + z_ * second_vector.z_;
}

Vector Vector::cross(const Vector& second_vector)
{
	return Vector(y_ * second_vector.z_ - z_ * second_vector.y_,
				  z_ * second_vector.x_ - x_ * second_vector.z_,
				  x_ * second_vector.y_ - y_ * second_vector.x_);
}

Vector Vector::operator -(void)
{
	return Vector(-x_, -y_, -z_);
}

Vector Vector::operator +(const Vector& second_vector)
{
	return Vector(x_ + second_vector.x_, y_ + second_vector.y_, z_ + second_vector.z_);
}

Vector Vector::operator -(const Vector& second_vector)
{
	return Vector(x_ - second_vector.x_, y_ - second_vector.y_, z_ - second_vector.z_);
}

Vector Vector::operator *(double value)
{
	return Vector(x_ * value, y_ * value, z_ * value);
}

Vector Vector::operator /(double value)
{
	if (value == 0)
	{
		cerr << "Error: Divisor can't be 0!" << endl;
		exit(-1);
	}

	return Vector(x_ / value, y_ / value, z_ / value);
}

Vector& Vector::operator *=(double value)
{
	x_ *= value;
	y_ *= value;
	z_ *= value;

	return *this;
}

Vector& Vector::operator /=(double value)
{
	if (value == 0)
	{
		cerr << "Error: Divisor can't be 0!" << endl;
		exit(-1);
	}

	x_ /= value;
	y_ /= value;
	z_ /= value;

	return *this;
}

Point::Point(const Point& second_point)
{
	x_ = second_point.x_;
	y_ = second_point.y_;
	z_ = second_point.z_;
}

Point::Point(const Vector& vector)
{
	x_ = vector.x_;
	y_ = vector.y_;
	z_ = vector.z_;
}

double Point::distanceTo(const Point& point)
{
	double dx = point.x_ - x_;
	double dy = point.y_ - y_;
	double dz = point.z_ - z_;
	return (sqrt(dx * dx + dy * dy + dz * dz));
}

double Point::distanceTo(const LineSegment& lineSegment)
{
	Vector _vector(*this), vector1(lineSegment.endpoint1_), vector2(lineSegment.endpoint2_);
	return (vector1 - _vector).cross(vector2 - vector1).norm() / (vector2 - vector1).norm();
}

double Point::distanceTo(const Plane& plane)
{
	Vector _vector1(*this), _vector2(plane.onePoint_);
	return sqrt(fabs((_vector2 - _vector1).dot(plane.normal_)));
}

double LineSegment::length()
{
	double dx = endpoint2_.x_ - endpoint1_.x_;
	double dy = endpoint2_.y_ - endpoint1_.y_;
	double dz = endpoint2_.z_ - endpoint1_.z_;
	return (sqrt(dx * dx + dy * dy + dz * dz));
}

Vector LineSegment::direction()
{
	Vector vector1(endpoint1_), vector2(endpoint2_);
	Vector direction_(vector2 - vector1);
	direction_ /= direction_.norm();
	return direction_;
}

double Sphere::volume()
{
	return 4.0 / 3 * M_PI * pow(radius_, 3);
}

Vector operator *(double value, Vector vector)
{
	return Vector(value * vector.x_, value * vector.y_, value * vector.z_);
}

ostream& operator <<(ostream& _ostream, Vector vector)
{
	_ostream << vector.x_ << endl << vector.y_ << endl << vector.z_;
	return _ostream;
}

ostream& operator <<(ostream& _ostream, Point point)
{
	_ostream << "(" << point.x_ << ", " << point.y_ << ", " << point.z_ << ")";
	return _ostream;
}