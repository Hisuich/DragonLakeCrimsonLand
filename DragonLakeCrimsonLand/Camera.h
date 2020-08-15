#pragma once

#include <memory>
#include "GameObjects.h"
class Camera
{
public:
	Vector2 lockPosition;

private:
	int screenWidth;
	int screenHeight;

	Vector2Int mapSize;

	Vector2Int xThreshold;
	Vector2Int yThreshold;

public:
	Camera();

	void Init(Vector2 position, Vector2Int mapSize);
	void SetLockPosition(Vector2 position);
	void SetMapSize(Vector2Int mapSize);
	Vector2 GetOffset();

private:
	Vector2 SetThreshold();

};