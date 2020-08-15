#pragma once

#include <memory>
#include "GameObjects.h"
#include <math.h>
#include "Options.h"
class EnemySpawner
{
private:
	std::shared_ptr<GameObjects> gameObjects;
	Vector2 threshold;
	Vector2Int mapSize;
	int maxNumber;
	double timer;
	double timeToSpawn;
	Sprite* sprite;

public:
	EnemySpawner(std::shared_ptr<GameObjects> gameObjects, Vector2Int mapSize, double timeToSpawn);

	void Process(double delta);
	void SetTimeToSpawn(double timeToSpawn);

private:
	void SpawnEnemies();
	Vector2 GetRandomPosition();

};