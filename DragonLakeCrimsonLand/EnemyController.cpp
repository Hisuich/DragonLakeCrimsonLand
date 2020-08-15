#include "EnemyController.h"
#include <iostream>

EnemyController::EnemyController() : UnitController()
{
	enemySpeed = 3.0;
}

EnemyController::EnemyController(std::shared_ptr<GameObjects> gameObjects) : UnitController(gameObjects)
{
	enemySpeed = 3.0;
}

void EnemyController::Process(double delta)
{
	SetPoint();
	for (int i = 0; i < gameObjects->GetNumberOfGameObjects(); i++)
	{
		if (gameObjects->GetTypeAtIndex(i) == GameObjectType::Enemy)
		{
			Vector2 enemyPosition = gameObjects->GetPositionAt(i);
			gameObjects->SetVelocityAt(i, GetVelocity(enemyPosition));

		}
	}

}

void EnemyController::KeyPressProcess(FRKey k)
{
}

void EnemyController::KeyReleaseProcess(FRKey k)
{
}

void EnemyController::MousePressProcess(FRMouseButton button, bool isReleased)
{
}

void EnemyController::MouseMoveProcess(int x, int y, int xrelative, int yrelative)
{
}

void EnemyController::SetPoint()
{
	point = gameObjects->GetPositionAt(gameObjects->GetFirstGameObjectIndexByType(GameObjectType::Player));
}

Vector2 EnemyController::GetVelocity(Vector2 enemyPosition)
{
	Vector2 velocity = point - enemyPosition;
	velocity.Normalize();
	velocity.Scale(enemySpeed + (1  / (rand() % 10 + 1)));
	return velocity;
}
