#include "UnitController.h"

UnitController::UnitController()
{

}

UnitController::UnitController(std::shared_ptr<GameObjects> gameObjects)
{
	SetGameObjects(gameObjects);
}

void UnitController::SetGameObjects(std::shared_ptr<GameObjects> gameObjects)
{
	if (gameObjects == nullptr) return;
	if (this->gameObjects == gameObjects) return;
	this->gameObjects = gameObjects;
}
