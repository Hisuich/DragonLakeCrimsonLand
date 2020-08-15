#pragma once

#include "UnitController.h"
#include "GameObjects.h"
#include <memory>

class EnemyController : public UnitController
{
public:
	EnemyController();
	EnemyController(std::shared_ptr<GameObjects> gameObjects);

private:
	Vector2 point;
	double enemySpeed;

public:
	void Process(double delta) override;

	void KeyPressProcess(FRKey k) override;
	void KeyReleaseProcess(FRKey k) override;

	void MousePressProcess(FRMouseButton button, bool isReleased) override;
	void MouseMoveProcess(int x, int y, int xrelative, int yrelative) override;

private:
	void SetPoint();
	Vector2 GetVelocity(Vector2 enemyPosition);
};