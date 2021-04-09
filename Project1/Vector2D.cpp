#include "Vector2D.hpp"

Vector2D::Vector2D():
	x(0),
	y(0)
{
}

Vector2D::Vector2D(float x, float y):
	x(x),
	y(y)
{
}

Vector2D::~Vector2D()
{
}

Vector2D& Vector2D::add(const Vector2D& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

Vector2D& Vector2D::substract(const Vector2D& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

Vector2D& Vector2D::multiply(const Vector2D& v)
{
	x *= v.x;
	y *= v.y;
	return *this;
}

Vector2D& Vector2D::divide(const Vector2D& v)
{
	x /= v.x;
	y /= v.y;
	return *this;
}

Vector2D& Vector2D::operator+=(const Vector2D& v)
{
	return add(v);
}

Vector2D& Vector2D::operator-=(const Vector2D& v)
{
	return substract(v);
}

Vector2D& Vector2D::operator*=(const Vector2D& v)
{
	return multiply(v);
}

Vector2D& Vector2D::operator/=(const Vector2D& v)
{
	return divide(v);
}

Vector2D& Vector2D::operator*=(int)
{
	return (*this = (*this * 1));
}

Vector2D& operator+(Vector2D v1, const Vector2D& v2)
{
	v1.add(v2);
	return v1;
}

Vector2D& operator-(Vector2D v1, const Vector2D& v2)
{
	v1.substract(v2);
	return v1;
}

Vector2D& operator*(Vector2D v1, const Vector2D& v2)
{
	v1.multiply(v2);
	return v1;
}

Vector2D& operator/(Vector2D v1, const Vector2D& v2)
{
	v1.divide(v2);
	return v1;
}

Vector2D& operator*(Vector2D v, int n)
{
	v.x *= n;
	v.y *= n;
	return v;
}

Vector2D& operator*(Vector2D v, double n)
{
	v.x *= n;
	v.y *= n;
	return v;
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& v)
{
	stream << "(" << v.x << ", " << v.y << ")";
	return stream;
}