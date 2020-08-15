#pragma once
#include <math.h>
#include <iostream>

class Vector2
{
public:
	double x;
	double y;

public:
	Vector2();
	Vector2(double x, double y);

	Vector2 GetNormalize();
	void Normalize();
	
	void Scale(double value);
	
	void Add(Vector2 addVector);

	double GetMagnitude();

	double GetSqrMagnitude();


	Vector2 operator-(Vector2 a);	
	Vector2 operator+(Vector2 a);
	bool operator==(Vector2 a);

};