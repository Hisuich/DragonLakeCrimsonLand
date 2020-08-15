#include "Game.h"

void Game::PreInit(int& width, int& height, bool& fullscreen)
{
	width = Options::options.at("screenWidth");
	height = Options::options.at("screenHeight");
	fullscreen = false;
}

bool Game::Init()
{
	prevDelta = getTickCount();
	map = std::make_shared<Map>();
	map->Init();
	return true;
}

void Game::Close()
{
}

bool Game::Tick()
{
	//drawTestBackground();
	map->Tick(GetDeltaTime());
	return false;
}

void Game::onMouseMove(int x, int y, int xrelative, int yrelative)
{
	map->MouseMoveProcess(x, y, xrelative, yrelative);
}

void Game::onMouseButtonClick(FRMouseButton button, bool isReleased)
{
	map->MousePressProcess(button, isReleased);
}

void Game::onKeyPressed(FRKey k)
{
	map->KeyPressProcess(k);
}

void Game::onKeyReleased(FRKey k)
{
	map->KeyReleaseProcess(k);
}

double Game::GetDeltaTime()
{
	double delta = getTickCount() - prevDelta;
	prevDelta = getTickCount();
	delta /= fps;
	return delta;
}
