#include "EnemySpawner.h"

EnemySpawner::EnemySpawner(std::shared_ptr<GameObjects> gameObjects, Vector2Int mapSize, double timeToSpawn)
{
	this->gameObjects = gameObjects;

	maxNumber = Options::options.at("maxEnemy");
	int width;
	int height;
	getScreenSize(width, height);
	threshold = Vector2(width/2, height/2);
	this->mapSize = mapSize;
	this->timeToSpawn = timeToSpawn;

	sprite = createSprite("data/cockroach.png");
}

void EnemySpawner::Process(double delta)
{
	timer += delta;
	if (timer >= timeToSpawn)
	{
		timer = 0;
		SpawnEnemies();
	}
}

void EnemySpawner::SetTimeToSpawn(double timeToSpawn)
{
	this->timeToSpawn = timeToSpawn;
}

void EnemySpawner::SpawnEnemies()
{
	if (gameObjects->GetGameObjectCountByType(GameObjectType::Enemy) < maxNumber)
	{
		std::cout << "MaxNumber: " << maxNumber << std::endl;
		int enemiesNumber = rand() % maxNumber + 5;
		for (int i = 0; i < enemiesNumber; i++)
		{
			Vector2 enemyPosition = GetRandomPosition();
			gameObjects->AddGameObject(enemyPosition, sprite, GameObjectType::Enemy);
		}
		maxNumber += rand() % 3;
	}
}

Vector2 EnemySpawner::GetRandomPosition()
{
	Vector2 playerPosition = gameObjects->GetPositionAt(gameObjects->GetFirstGameObjectIndexByType(GameObjectType::Player));
	int enemyWidth;
	int enemyHeight;
	getSpriteSize(sprite, enemyWidth, enemyHeight);
	double x = rand() % (mapSize.x - enemyWidth);
	while (x > (playerPosition.x - threshold.x) && x < (playerPosition.x + threshold.x))
		x = rand() % mapSize.x;

	double y = rand() % (mapSize.y - enemyHeight);
	while (y > (playerPosition.y - threshold.y) && y < (playerPosition.y + threshold.y))
		y = rand() % mapSize.y;

	return Vector2(x, y);
}


