#include "BasicElements.h"
#include <cmath>

Point::Point(const Point& point)
{
	x_ = point.x_;
	y_ = point.y_;
	z_ = point.z_;
}

Point::Point(const Vector3D& vector3D)
{
	x_ = vector3D.x_;
	y_ = vector3D.y_;
	z_ = vector3D.z_;
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
	Vector3D _vector(*this), vector1(lineSegment.endpoint1_), vector2(lineSegment.endpoint2_);
	return (vector1 - _vector).cross(vector2 - vector1).norm() / (vector2 - vector1).norm();
}

double Point::distanceTo(const Plane& plane)
{
	Vector3D _vector1(*this), _vector2(plane.onePoint_);
	return sqrt(fabs((_vector2 - _vector1).dot(plane.normal_)));
}

double LineSegment::length()
{
	double dx = endpoint2_.x_ - endpoint1_.x_;
	double dy = endpoint2_.y_ - endpoint1_.y_;
	double dz = endpoint2_.z_ - endpoint1_.z_;
	return (sqrt(dx * dx + dy * dy + dz * dz));
}

Vector3D LineSegment::direction()
{
	Vector3D vector1(endpoint1_), vector2(endpoint2_);
	Vector3D direction_(vector2 - vector1);
	direction_ /= direction_.norm();
	return direction_;
}

std::ostream& operator <<(std::ostream& _ostream, Point point)
{
	_ostream << "(" << point.x_ << ", " << point.y_ << ", " << point.z_ << ")";
	return _ostream;
}