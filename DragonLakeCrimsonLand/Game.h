#pragma once

#include "Framework.h"
#include "Map.h"
#include <memory>
#include "Options.h"

class Game : public Framework
{
private:
	std::shared_ptr<Map> map;

	double prevDelta;
	const double fps = 60;

public:
	virtual void PreInit(int& width, int& height, bool& fullscreen) override;
	virtual bool Init() override;
	virtual void Close() override;
	virtual bool Tick() override;

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) override;

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) override;

	virtual void onKeyPressed(FRKey k) override;

	virtual void onKeyReleased(FRKey k) override;

private:
	double GetDeltaTime();

};