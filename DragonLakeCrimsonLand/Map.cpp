#include "Map.h"

Map::Map()
{
	mapSize = Vector2Int(Options::options.at("mapWidth"), Options::options.at("mapHeight"));
	background = createSprite("data/background.tga");
	cursor = Cursor();
	showCursor(false);
}

void Map::Init()
{
	gameObjects = std::make_shared<GameObjects>();
	gameObjects->AddGameObject(Vector2(mapSize.x/2, mapSize.y/2), Vector2(), createSprite("data/hero.png"), GameObjectType::Player);

	gameObjects->controllers.AddController(std::make_shared<PlayerController>(gameObjects));
	gameObjects->controllers.AddController(std::make_shared<EnemyController>(gameObjects));

	gameObjects->collisions.SetGameObjects(gameObjects);
	gameObjects->SetThreshold(mapSize);

	playerIndex = gameObjects->GetFirstGameObjectIndexByType(GameObjectType::Player);
	camera.SetMapSize(mapSize);

	enemySpawner = std::make_unique<EnemySpawner>(gameObjects, mapSize, 10);
}

void Map::Tick(double delta)
{
	camera.SetLockPosition((gameObjects->GetPositionAt(playerIndex)));
	gameObjects->Tick(delta);
	enemySpawner->Process(delta);

	CheckEnd();

	DrawBackground();
	cursor.Draw();
	gameObjects->Draw(camera.GetOffset());

}

void Map::KeyPressProcess(FRKey k)
{
	gameObjects->KeyPressProcess(k);
}

void Map::KeyReleaseProcess(FRKey k)
{
	gameObjects->KeyReleaseProcess(k);
}

void Map::MousePressProcess(FRMouseButton button, bool isReleased)
{
	gameObjects->MousePressProcess(button, isReleased);
}

void Map::MouseMoveProcess(int x, int y, int xrelative, int yrelative)
{
	gameObjects->MouseMoveProcess(x, y, xrelative, yrelative);
	cursor.SetMousePosition(x, y);
}

void Map::DrawBackground()
{
	int backWidth;
	int backHeight;
	getSpriteSize(background, backWidth, backHeight);

	int x = ceil(mapSize.x / backWidth) + 4;
	int y = ceil(mapSize.y / backHeight) + 4;


	Vector2 offset = camera.GetOffset();

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			drawSprite(background, ((i-2) * backWidth) - offset.x, ((j-2) * backHeight) - offset.y);
}

void Map::SetBackground()
{
	int backWidth;
	int backHeight;
	getSpriteSize(background, backWidth, backHeight);

	backgroundSize = Vector2Int(backWidth, backHeight);
}

void Map::CheckEnd()
{
	if (!(gameObjects->HasObjectOfType(GameObjectType::Player)))
		Init();
}
