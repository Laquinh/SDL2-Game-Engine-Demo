#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <iostream>

struct Vector2D
{
	float x;
	float y;

	Vector2D();
	Vector2D(float, float);

	Vector2D& add(const Vector2D&);
	Vector2D& substract(const Vector2D&);
	Vector2D& multiply(const Vector2D&);
	Vector2D& divide(const Vector2D&);

	friend Vector2D& operator+(Vector2D, const Vector2D&);
	friend Vector2D& operator-(Vector2D, const Vector2D&);
	friend Vector2D& operator*(Vector2D, const Vector2D&);
	friend Vector2D& operator/(Vector2D, const Vector2D&);

	Vector2D& operator+=(const Vector2D&);
	Vector2D& operator-=(const Vector2D&);
	Vector2D& operator*=(const Vector2D&);
	Vector2D& operator/=(const Vector2D&);

	friend std::ostream& operator<<(std::ostream& stream, const Vector2D& v);
};

#endif