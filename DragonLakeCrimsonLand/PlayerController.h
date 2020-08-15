#pragma once

#include "UnitController.h"
#include "GameObjects.h"
#include <vector>
#include <memory>
#include "Options.h"

class PlayerController : public UnitController
{
private:
	Vector2 velocity;
	double playerSpeed;
	Vector2 mousePosition;
	int playerIndex;
	Sprite* bulletSprite;
	double timer;
	const double canShoot = 0.5;
	std::vector<bool> buttonpressed;
	int maxBullet;
	
public:
	PlayerController();
	PlayerController(std::shared_ptr<GameObjects> gameObjects);


public:
	void Process(double delta) override;

public:
	void KeyPressProcess(FRKey k) override;
	void KeyReleaseProcess(FRKey k) override;

	void MousePressProcess(FRMouseButton button, bool isReleased) override;
	void MouseMoveProcess(int x, int y, int xrelative, int yrelative) override;

	void Shoot(Vector2 point);
	void CreateBullet(Vector2 direction);
	void CheckBulletInGame();
};