#include "Vector2Int.h"

Vector2Int::Vector2Int()
{
	this->x = 0;
	this->y = 0;
}

Vector2Int::Vector2Int(long long x, long long y)
{
	this->x = x;
	this->y = y;
}

Vector2 Vector2Int::GetNormalize()
{
	double magn = GetMagnitude();
	return Vector2(x / magn, y / magn);
}

