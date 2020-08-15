#pragma once
#include <memory>
#include "GameObjectType.h"
class GameObjects;

class Collisions
{
private:
	std::shared_ptr<GameObjects> gameObjects;


public:
	Collisions();
	Collisions(std::shared_ptr<GameObjects> gameObjects);

	void SetGameObjects(std::shared_ptr<GameObjects> gameObjects);
	void Process();

private:
	void PlayerCollision(int index, GameObjectType type);
	void EnemyCollision(int index, GameObjectType type);
	void BulletCollision(int index, GameObjectType type);

};