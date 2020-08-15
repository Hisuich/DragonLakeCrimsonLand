#include "Game.h"
#include "Framework.h"
#include <iostream>
#include <array>

int main(int argc, char *argv[])
{
	Options::ParseConsole(argc, argv);
	return run(new Game);
}