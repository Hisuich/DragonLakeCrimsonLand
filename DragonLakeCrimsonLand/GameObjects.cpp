#include "GameObjects.h"

GameObjects::GameObjects()
{
}

void GameObjects::AddGameObject(Vector2 position, Sprite* sprite, GameObjectType type)
{
	AddGameObject(position, Vector2(), sprite, type);
}

void GameObjects::AddGameObject(Vector2 position, Vector2 velocity, Sprite* sprite, GameObjectType type)
{
	positions.push_back(position);
	offsetPositions.push_back(position);
	velocities.push_back(velocity);
	sprites.push_back(sprite);
	types.push_back(type);
	needDestroy.push_back(false);
	int width = 0;
	int height = 0;
	getSpriteSize(sprite, width, height);
	sizes.push_back(Vector2Int(width, height));
}

int GameObjects::GetFirstGameObjectIndexByType(GameObjectType type)
{
	for (size_t i = 0; i < types.size(); i++)
	{
		if (types[i] == type)
			return i;
	}
	return 0;
}

int GameObjects::GetGameObjectCountByType(GameObjectType type)
{
	int c = 0;

	for (size_t i = 0; i < types.size(); i++)
	{
		if (types[i] == type)
			c++;
	}

	return c;
}

Vector2 GameObjects::GetPositionAt(int index)
{
	if (index < 0 || index >= positions.size()) return positions[0];
	return positions[index];
}

Vector2 GameObjects::GetOffsetPositionAt(int index)
{
	if (index < 0 || index >= positions.size()) return offsetPositions[0];
	return offsetPositions[index];
}

Vector2Int GameObjects::GetSizeAt(int index)
{
	if (index < 0 || index >= positions.size()) return sizes[0];
	return sizes[index];
}

Vector2& GameObjects::GetLinkPositionAtIndex(int index)
{
	if (index < 0 || index >= positions.size()) return positions[0];
	return positions[index];
}

GameObjectType GameObjects::GetTypeAtIndex(int index)
{
	if (index < 0 || index >= types.size()) return GameObjectType::Enemy;
	return types[index];
}

bool GameObjects::HasObjectOfType(GameObjectType type)
{
	for (size_t i = 0; i < types.size(); i++)
		if (types[i] == type) return true;
	return false;
}

void GameObjects::GetInfoByPosition(int index, Vector2& position, Vector2& velocity, Vector2Int& size, GameObjectType& type)
{
	if (index < 0 || index >= positions.size()) return;
	position = positions[index];
	velocity = velocities[index];
	size = sizes[index];
	type = types[index];
}

int GameObjects::GetNumberOfGameObjects()
{
	return positions.size();
}

void GameObjects::SetVelocityAt(int index, Vector2 velocity)
{
	if (index < 0 || index >= velocities.size()) return;
	velocities[index] = velocity;
}

void GameObjects::RemoveFirstOf(GameObjectType type)
{
	for (size_t i = 0; i < types.size(); i++)
	{
		if (types[i] == type)
		{
			needDestroy[i] = true;
			break;
		}
	}
}

void GameObjects::RemoveAt(int index)
{
	positions.erase(positions.begin()+index);
	offsetPositions.erase(offsetPositions.begin() + index);
	velocities.erase(velocities.begin() + index);
	sprites.erase(sprites.begin() + index);
	sizes.erase(sizes.begin() + index);
	types.erase(types.begin() + index);
	needDestroy.erase(needDestroy.begin() + index);
}

void GameObjects::RemoveGameObjects()
{
	int c = needDestroy.size();
	while (c > 0)
		for (int i = needDestroy.size() - 1; i >= 0; i--)
		{
			c = i;
			if (needDestroy[i])
			{
				RemoveAt(i);
				break;
			}
		}
}

void GameObjects::RemoveAtPosition(Vector2 position)
{
	for (size_t i = 0; i < positions.size(); i++)
	{
		if (positions[i] == position)
		{
			needDestroy[i] = true;
			break;
		}
	}
}

void GameObjects::NeedRemoveAt(int index)
{
	if (index < 0 || index >= needDestroy.size()) return;
	needDestroy[index] = true;
}


void GameObjects::Tick(double delta)
{
	ProcessControllers(delta);

	for (size_t i = 0; i < positions.size(); i++)
	{
		Vector2 velocity = velocities[i];
		velocity.Scale(delta);
		positions[i] = positions[i] + (velocity);
	}
	
	ProcessCollisions();

	RemoveGameObjects();
}

void GameObjects::Draw()
{
	for (size_t i = 0; i < sprites.size(); i++)
	{
		drawSprite(sprites[i], positions[i].x, positions[i].y);
	}
}

void GameObjects::Draw(Vector2 offset)
{
	for (size_t i = 0; i < sprites.size(); i++)
	{
		offsetPositions[i] = positions[i] - offset;
		drawSprite(sprites[i], positions[i].x - offset.x, positions[i].y - offset.y);
	}
}

void GameObjects::ProcessControllers(double delta)
{
	controllers.Process(delta);
}

void GameObjects::ProcessCollisions()
{
	collisions.Process();
}

void GameObjects::KeyPressProcess(FRKey k)
{
	controllers.KeyPressProcess(k);
}

void GameObjects::KeyReleaseProcess(FRKey k)
{
	controllers.KeyReleaseProcess(k);
}

void GameObjects::MousePressProcess(FRMouseButton button, bool isReleased)
{
	controllers.MousePressProcess(button, isReleased);
}

void GameObjects::MouseMoveProcess(int x, int y, int xrelative, int yrelative)
{
	controllers.MouseMoveProcess(x, y, xrelative, yrelative);
}

void GameObjects::SetThreshold(Vector2Int threshold)
{
	this->threshold = threshold;
}

bool GameObjects::CollisionWithThreshold(int index)
{
	if (threshold == Vector2Int(0, 0))
		return false;

	if (positions[index].x < 0)
	{
		positions[index].x = 0;
		return true;
	}
	if (positions[index].y < 0)
	{
		positions[index].y = 0;
		return true;		
	}
	if (positions[index].x + sizes[index].x > threshold.x)
	{
		positions[index].x = threshold.x - sizes[index].x;
		return true;
	}
	if (positions[index].y + sizes[index].y > threshold.y)
	{
		positions[index].y = threshold.y - sizes[index].y;
		return true;
	}

	return false;
}

bool GameObjects::CheckCollision(int indexOne, int indexTwo)
{
	if (positions[indexOne].x + sizes[indexOne].x > positions[indexTwo].x &&
		positions[indexOne].x < positions[indexTwo].x + sizes[indexTwo].x &&
		positions[indexOne].y + sizes[indexOne].y > positions[indexTwo].y &&			
		positions[indexOne].y < positions[indexTwo].y + sizes[indexTwo].y)
		{
			Collision(indexOne, indexTwo);
			return true;
	}
	return false;
}

void GameObjects::Collision(int indexOne, int indexTwo)
{
	double xOffset = (positions[indexOne].x + sizes[indexOne].x) - positions[indexTwo].x;
	if (abs(xOffset) > abs(positions[indexOne].x - (positions[indexTwo].x + sizes[indexTwo].x)))
	{
		xOffset = positions[indexOne].x - (positions[indexTwo].x + sizes[indexTwo].x);
	}

	double yOffset = (positions[indexOne].y + sizes[indexOne].y) - positions[indexTwo].y;
	if (abs(yOffset) > abs(positions[indexOne].y - (positions[indexTwo].y + sizes[indexTwo].y)))
	{
		yOffset = positions[indexOne].y - (positions[indexTwo].y + sizes[indexTwo].y);
	}

	positions[indexOne].x -= xOffset/2;
	positions[indexOne].y -= yOffset/2;
}

