#include "Vector2.h"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Vector2::Scale(double value)
{
	this->x *= value;
	this->y *= value;
}

void Vector2::Add(Vector2 addVector) 
{
	x += addVector.x;
	y += addVector.y;
}

Vector2 Vector2::GetNormalize()
{
	double magn = GetMagnitude();
	return Vector2(x / magn, y / magn);
}

void Vector2::Normalize()
{
	double magn = GetMagnitude();
	x /= magn;
	y /= magn;
}

double Vector2::GetMagnitude()
{
	return sqrt((x * x) + (y * y));
}

double Vector2::GetSqrMagnitude()
	{
		return (x * x) + (y * y);
	}

Vector2 Vector2::operator-(Vector2 a)
{
	return Vector2(x - a.x, y - a.y);
}

Vector2 Vector2::operator+(Vector2 a)
{
	Add(a);
	return Vector2(x + a.x, y + a.y);
}

bool Vector2::operator==(Vector2 a)
{
	return fabs(x - a.x) < 0.1 && fabs(y - a.y) < 0.1;
}

