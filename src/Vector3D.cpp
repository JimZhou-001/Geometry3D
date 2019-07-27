#include "Vector3D.h"
#include "BasicElements.h"
#include <cmath>
#include <cstdlib>

Vector3D::Vector3D(const Vector3D& secondVector3D)
{
	x_ = secondVector3D.x_;
	y_ = secondVector3D.y_;
	z_ = secondVector3D.z_;
}

Vector3D::Vector3D(const Point& point)
{
	x_ = point.x_;
	y_ = point.y_;
	z_ = point.z_;
}

double Vector3D::norm()
{
	return sqrt(x_ * x_ + y_ * y_ + z_ * z_);
}

double Vector3D::dot(const Vector3D& secondVector3D)
{
	return x_ * secondVector3D.x_ + y_ * secondVector3D.y_ + z_ * secondVector3D.z_;
}

Vector3D Vector3D::cross(const Vector3D& secondVector3D)
{
	return Vector3D(y_ * secondVector3D.z_ - z_ * secondVector3D.y_,
				  z_ * secondVector3D.x_ - x_ * secondVector3D.z_,
				  x_ * secondVector3D.y_ - y_ * secondVector3D.x_);
}

Vector3D Vector3D::operator -(void)
{
	return Vector3D(-x_, -y_, -z_);
}

Vector3D Vector3D::operator +(const Vector3D& secondVector3D)
{
	return Vector3D(x_ + secondVector3D.x_, y_ + secondVector3D.y_, z_ + secondVector3D.z_);
}

Vector3D Vector3D::operator -(const Vector3D& secondVector3D)
{
	return Vector3D(x_ - secondVector3D.x_, y_ - secondVector3D.y_, z_ - secondVector3D.z_);
}

Vector3D Vector3D::operator *(double value)
{
	return Vector3D(x_ * value, y_ * value, z_ * value);
}

Vector3D Vector3D::operator /(double value)
{
	if (value == 0)
	{
		std::cerr << "Error: Divisor can't be 0!" << std::endl;
		exit(-1);
	}

	return Vector3D(x_ / value, y_ / value, z_ / value);
}

Vector3D& Vector3D::operator *=(double value)
{
	x_ *= value;
	y_ *= value;
	z_ *= value;

	return *this;
}

Vector3D& Vector3D::operator /=(double value)
{
	if (value == 0)
	{
		std::cerr << "Error: Divisor can't be 0!" << std::endl;
		exit(-1);
	}

	x_ /= value;
	y_ /= value;
	z_ /= value;

	return *this;
}

Vector3D operator *(double value, Vector3D vector3D)
{
	return Vector3D(value * vector3D.x_, value * vector3D.y_, value * vector3D.z_);
}

std::ostream& operator <<(std::ostream& _ostream, Vector3D vector3D)
{
	_ostream << vector3D.x_ << std::endl << vector3D.y_ << std::endl << vector3D.z_;
	return _ostream;
}