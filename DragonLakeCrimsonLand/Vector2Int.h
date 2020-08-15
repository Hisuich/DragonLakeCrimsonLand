#pragma once

#include <math.h>
#include "Vector2.h"
class Vector2Int
{
public:
	long long x;
	long long y;

public:
	Vector2Int();
	Vector2Int(long long x, long long y);

	Vector2 GetNormalize();

	void inline Scale(int value)
	{
		x *= value;
		y *= value;
	}

	void inline Add(Vector2Int addVector)
	{
		x += addVector.x;
		y += addVector.y;
	}

	double inline GetMagnitude()
	{
		return sqrt((x * x) + (y * y));
	}

	double inline GetSqrMagnitude()
	{
		return (x * x) + (y * y);
	}


	Vector2Int operator-(Vector2Int a)
	{
		return Vector2Int(x - a.x, y - a.y);
	}

	Vector2Int operator+(Vector2Int a)
	{
		Add(a);
		return Vector2Int(x + a.x, y + a.y);
	}

	bool operator==(Vector2Int a)
	{
		return x == a.x && y == a.y;
	}
};