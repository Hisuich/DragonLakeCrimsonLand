#pragma once
#include "GameObjects.h"
#include "Controllers.h"
#include "UnitController.h"
#include "PlayerController.h"
#include "EnemyController.h"
#include "Camera.h"
#include <memory>
#include "EnemySpawner.h"
#include "Cursor.h"
#include "Options.h"

class Map
{
private:
	std::shared_ptr<GameObjects> gameObjects;
	Camera camera;
	Vector2Int mapSize;

	Vector2Int backgroundSize;
	Sprite* background;

	int playerIndex;
	std::unique_ptr<EnemySpawner> enemySpawner;

	Cursor cursor;

public:
	Map();


public:
	void Init();
	void Tick(double dt);

	void KeyPressProcess(FRKey k);
	void KeyReleaseProcess(FRKey k);

	void MousePressProcess(FRMouseButton button, bool isReleased);
	void MouseMoveProcess(int x, int y, int xrelative, int yrelative);
private:
	void DrawBackground();
	void SetBackground();
	void CheckEnd();
};