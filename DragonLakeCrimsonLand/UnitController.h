#pragma once

#include "Framework.h"
#include "Vector2.h"
#include "Vector2Int.h"
#include <memory>

class GameObjects;

class UnitController
{
protected:
	std::shared_ptr<GameObjects> gameObjects;

public:
	UnitController();
	UnitController(std::shared_ptr<GameObjects> gameObjects);

public:
	virtual void Process(double delta) = 0;

	void SetGameObjects(std::shared_ptr<GameObjects> gameObjects);

public:
	virtual void KeyPressProcess(FRKey k) = 0;
	virtual void KeyReleaseProcess(FRKey k) = 0;

	virtual void MousePressProcess(FRMouseButton button, bool isReleased) = 0;
	virtual void MouseMoveProcess(int x, int y, int xrelative, int yrelative) = 0;

};