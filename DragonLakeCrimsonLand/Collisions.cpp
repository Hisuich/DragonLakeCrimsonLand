#include "Collisions.h"

#include "GameObjects.h"
Collisions::Collisions()
{
}

Collisions::Collisions(std::shared_ptr<GameObjects> gameObjects)
{
	SetGameObjects(gameObjects);
}

void Collisions::SetGameObjects(std::shared_ptr<GameObjects> gameObjects)
{
	this->gameObjects = gameObjects;
}

void Collisions::Process()
{
	int objectsNumber = gameObjects->GetNumberOfGameObjects();
	for (int i = 0; i < objectsNumber; i++)
	{
		if (gameObjects->CollisionWithThreshold(i) && gameObjects->GetTypeAtIndex(i) == GameObjectType::Bullet)
		{

			gameObjects->NeedRemoveAt(i);
		}

		for (int j = 0; j < objectsNumber; j++)
		{
			if (i == j) continue;
			if (gameObjects->CheckCollision(i, j))
			{
				GameObjectType typeOne = gameObjects->GetTypeAtIndex(i);
				GameObjectType typeTwo = gameObjects->GetTypeAtIndex(j);

				switch (typeOne)
				{
				case Player:
					PlayerCollision(i, typeTwo);
					break;
				case Enemy:
					EnemyCollision(i, typeTwo);
					break;
				case Bullet:
					BulletCollision(i,typeTwo);
					break;
				default:
					break;
				}

				switch (typeTwo)
				{
				case Player:
					PlayerCollision(i, typeOne);
					break;
				case Enemy:
					EnemyCollision(i, typeOne);
					break;
				case Bullet:
					BulletCollision(i, typeOne);
					break;
				default:
					break;
				}
			}
		}
	}
}

void Collisions::PlayerCollision(int index, GameObjectType type)
{
	if (type == GameObjectType::Enemy)
		gameObjects->NeedRemoveAt(index);
}

void Collisions::EnemyCollision(int index, GameObjectType type)
{
	if (type == GameObjectType::Bullet)
		gameObjects->NeedRemoveAt(index);
}

void Collisions::BulletCollision(int index, GameObjectType type)
{
	if (type == GameObjectType::Enemy)
		gameObjects->NeedRemoveAt(index);
}
