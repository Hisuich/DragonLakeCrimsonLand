#include "PlayerController.h"

PlayerController::PlayerController() : UnitController()
{
	playerSpeed = 3;
	bulletSprite = createSprite("data/bullet.png");
	velocity = Vector2();
	buttonpressed = {false, false, false, false};
	maxBullet = Options::options.at("maxBullet");
}

PlayerController::PlayerController(std::shared_ptr<GameObjects> gameObjects) : UnitController(gameObjects)
{
	playerSpeed = 3;
	bulletSprite = createSprite("data/bullet.png");
	velocity = Vector2();
	buttonpressed = { false, false, false, false };
	maxBullet = Options::options.at("maxBullet");
}

void PlayerController::Process(double delta)
{
	timer += delta;
	playerIndex = gameObjects->GetFirstGameObjectIndexByType(GameObjectType::Player);
	gameObjects->SetVelocityAt(playerIndex, velocity);
}

void PlayerController::KeyPressProcess(FRKey k)
{
	if (k == FRKey::RIGHT)
	{
		velocity = velocity + Vector2(playerSpeed, 0);
		buttonpressed.at(0) = true;
	}
	else if (k == FRKey::LEFT)
	{
		velocity = velocity + Vector2(-playerSpeed, 0);
		buttonpressed.at(1) = true;
	}
	if (k == FRKey::DOWN)
	{
		velocity = velocity + Vector2(0, playerSpeed);
		buttonpressed.at(2) = true;
	}
	else if (k == FRKey::UP)
	{
		velocity = velocity + Vector2(0, -playerSpeed);
		buttonpressed.at(3) = true;
	}
	
	//velocity.Normalize();
	//velocity.Scale(playerSpeed);

}

void PlayerController::KeyReleaseProcess(FRKey k)
{
		if (k == FRKey::RIGHT && buttonpressed.at(0))
		{
			velocity = velocity + Vector2(-playerSpeed, 0);
		}
		else if (k == FRKey::LEFT && buttonpressed.at(1))
		{
			velocity = velocity + Vector2(playerSpeed, 0);
		}
		if (k == FRKey::DOWN && buttonpressed.at(2))
		{
			velocity = velocity + Vector2(0, -playerSpeed);
		}
		else if (k == FRKey::UP && buttonpressed.at(3))
		{
			velocity = velocity + Vector2(0, playerSpeed);
		}

	//velocity.Normalize();
	//velocity.Scale(playerSpeed);
}

void PlayerController::MousePressProcess(FRMouseButton button, bool isReleased)
{
	if (button == FRMouseButton::LEFT && !isReleased)
	{
		Shoot(mousePosition);
	}
}

void PlayerController::MouseMoveProcess(int x, int y, int xrelative, int yrelative)
{
	mousePosition.x = x;
	mousePosition.y = y;
}

void PlayerController::Shoot(Vector2 point)
{
	timer = 0;
	Vector2 playerOffsetPosition = gameObjects->GetOffsetPositionAt(playerIndex);
	Vector2 direction = point - playerOffsetPosition;
	direction.Normalize();

	CreateBullet(direction);
	
}

void PlayerController::CreateBullet(Vector2 direction)
{
	Vector2 playerPosition = gameObjects->GetPositionAt(playerIndex);
	Vector2Int playerSize = gameObjects->GetSizeAt(playerIndex);
	Vector2 bulletVelocity = direction;
	bulletVelocity.Scale(15);

	int halfWidth = playerSize.x / 2;
	int halfHeight = playerSize.y / 2;

	int bulletWidth;
	int bulletHeight;
	getSpriteSize(bulletSprite, bulletWidth, bulletHeight);
	Vector2 bulletSpawnPosition = Vector2();
	bulletSpawnPosition.x = (playerPosition.x) + halfWidth + (halfWidth+bulletWidth+5) * direction.x;
	bulletSpawnPosition.y = (playerPosition.y) + halfHeight + (halfHeight+bulletHeight+5) * direction.y;

	
	CheckBulletInGame();
	gameObjects->AddGameObject(bulletSpawnPosition, bulletVelocity, bulletSprite, GameObjectType::Bullet);
}

void PlayerController::CheckBulletInGame()
{
	int bulletNumber = gameObjects->GetGameObjectCountByType(GameObjectType::Bullet);
	if (bulletNumber >= maxBullet)
		gameObjects->RemoveFirstOf(GameObjectType::Bullet);
}
