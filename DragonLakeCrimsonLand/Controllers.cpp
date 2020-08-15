#include "Controllers.h"

void Controllers::KeyPressProcess(FRKey k)
{
	for (size_t i = 0; i < controllers.size(); i++)
	{
		controllers[i]->KeyPressProcess(k);
	}
}

void Controllers::KeyReleaseProcess(FRKey k)
{
	for (size_t i = 0; i < controllers.size(); i++)
	{
		controllers[i]->KeyReleaseProcess(k);
	}
}

void Controllers::MousePressProcess(FRMouseButton button, bool isReleased)
{
	for (size_t i = 0; i < controllers.size(); i++)
	{
		controllers[i]->MousePressProcess(button, isReleased);
	}
}

void Controllers::MouseMoveProcess(int x, int y, int xrelative, int yrelative)
{
	for (size_t i = 0; i < controllers.size(); i++)
	{
		controllers[i]->MouseMoveProcess(x,y,xrelative,yrelative);
	}
}

void Controllers::Process(double delta)
{
	for (size_t i = 0; i < controllers.size(); i++)
	{
		controllers[i]->Process(delta);
	}
}

void Controllers::AddController(std::shared_ptr<UnitController> unitController)
{
	controllers.push_back(unitController);
}

void Controllers::RemoveControllerAt(int index)
{
}

