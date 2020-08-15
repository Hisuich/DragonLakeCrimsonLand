#pragma once

#include "Framework.h"
#include "GameObjectType.h"
#include "Vector2.h"
#include "Vector2Int.h"
#include "Controllers.h"
#include "Collisions.h"

#include <vector>

using std::vector;
class GameObjects
{
private:
	vector<Vector2> positions;
	vector<Vector2> offsetPositions;
	vector<Vector2Int> sizes;
	vector<Vector2> velocities;
	vector<Sprite*> sprites;
	vector<GameObjectType> types;
	vector<bool> needDestroy;

	Vector2Int threshold;

public:
	Controllers controllers;
	Collisions collisions;

public:
	GameObjects();

	void AddGameObject(Vector2 position, Sprite* sprite, GameObjectType type);
	void AddGameObject(Vector2 position, Vector2 velocity, Sprite* sprite, GameObjectType type);

	int GetFirstGameObjectIndexByType(GameObjectType type);
	int GetGameObjectCountByType(GameObjectType type);
	Vector2 GetPositionAt(int index);
	Vector2 GetOffsetPositionAt(int index);
	Vector2Int GetSizeAt(int index);
	Vector2& GetLinkPositionAtIndex(int index);
	GameObjectType GetTypeAtIndex(int index);
	bool HasObjectOfType(GameObjectType type);

	void GetInfoByPosition(int index, Vector2& position, Vector2& velocity, Vector2Int& size, GameObjectType& type);

	int GetNumberOfGameObjects();

	void SetVelocityAt(int index, Vector2 velocity);

	void RemoveFirstOf(GameObjectType type);
	void RemoveAtPosition(Vector2 position);
	void NeedRemoveAt(int index);

	void Tick(double delta);

	void Draw();
	void Draw(Vector2 offset);

	void KeyPressProcess(FRKey k);
	void KeyReleaseProcess(FRKey k);

	void MousePressProcess(FRMouseButton button, bool isReleased);
	void MouseMoveProcess(int x, int y, int xrelative, int yrelative);

	void SetThreshold(Vector2Int threshold);

	bool CollisionWithThreshold(int index);
	bool CheckCollision(int indexOne, int indexTwo);
	void Collision(int indexOne, int indexTwo);

private:


	void RemoveAt(int index);
	void RemoveGameObjects();

	void ProcessControllers(double delta);
	void ProcessCollisions();

};