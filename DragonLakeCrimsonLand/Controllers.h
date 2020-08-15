#pragma once

#include "UnitController.h"
#include <vector>
#include <memory>

class Controllers
{
private:
	std::vector<std::shared_ptr<UnitController>> controllers;

public: 
	void KeyPressProcess(FRKey k);
	void KeyReleaseProcess(FRKey k);

	void MousePressProcess(FRMouseButton button, bool isReleased);
	void MouseMoveProcess(int x, int y, int xrelative, int yrelative);
	void Process(double delta);

	void AddController(std::shared_ptr<UnitController> unitController);
	void RemoveControllerAt(int index);

};