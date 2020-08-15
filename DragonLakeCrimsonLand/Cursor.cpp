#include "Cursor.h"

Cursor::Cursor()
{
	sprite = createSprite("data/reticle.png");
}

void Cursor::SetMousePosition(int x, int y)
{
	mousePosition.x = x;
	mousePosition.y = y;
}

void Cursor::Draw()
{
	drawSprite(sprite, mousePosition.x, mousePosition.y);
}
