#pragma once
#include "Framework.h"
#include "Vector2.h"

class Cursor
{
private:
	Sprite* sprite;
	Vector2 mousePosition;

public:
	Cursor();
	void SetMousePosition(int x, int y);
	void Draw();
};