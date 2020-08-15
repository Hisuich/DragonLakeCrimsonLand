#include "Options.h"

unordered_map<string, int> Options::options =
{
	{"screenWidth", 700},
	{"screenHeight", 500},
	{"mapWidth", 1000},
	{"mapHeight", 1000},
	{"maxEnemy", 10},
	{"maxBullet", 5}
};

unordered_map<string, string> Options::optionsName =
{
	{"-window", "ParseSize"},
	{"-map", "ParseSize"},
	{"-num_enemies", "ParseValue"},
	{"-num_ammo", "ParseValue"}
};

unordered_map<string, vector<string>> Options::paramName =
{
	{"-window", {"screenWidth", "screenHeight"}},
	{"-map", {"mapWidth", "mapHeight"}},
	{"-num_enemies", {"maxEnemy"}},
	{"-num_ammo", {"maxBullet"}}
};

void Options::ParseConsole(int argc, char* argv[])
{
	for (auto i = 0; i < argc; i++)
	{
		string option = string(argv[i]);
		if ((i + 1) < argc)
		{
			if (optionsName.find(option) != optionsName.end())
			{
				if (optionsName.at(option) == "ParseSize")
					ParseSize(option, argv[i + 1]);
				if (optionsName.at(option) == "ParseValue")
					ParseValue(option, argv[i + 1]);
			}
		}
	}
}

void Options::ParseSize(string name, char args[])
{
	if (paramName.find(name) != paramName.end())
	{
		vector<string> params = paramName.at(name);
		if (params.size() < 2) return;
		if (options.find(params[0]) == options.end()) return;
		if (options.find(params[1]) == options.end()) return;

		string arg = string(args);
		string arg1;
		string arg2;

		auto delim = arg.end();
		for (auto i = arg.begin(); i != arg.end(); i++)
		{
			if ((*i) == 'x')
			{
				delim = i;
				break;
			}
		}

		arg1 = arg.substr(0, delim - arg.begin());
		arg2 = arg.substr(delim - arg.begin() + 1);

		try
		{
			int first = std::stoi(arg1);
			options.at(params.at(0)) = first;
		}
		catch (std::invalid_argument ex)
		{
			std::cout << ex.what() << std::endl;
		}
		catch (std::out_of_range ex)
		{
			std::cout << ex.what() << std::endl;
		}

		try
		{
			int second = std::stoi(arg2);
			options.at(params.at(1)) = second;
		}
		catch (std::invalid_argument ex)
		{
			std::cout << ex.what() << std::endl;
		}
		catch (std::out_of_range ex)
		{
			std::cout << ex.what() << std::endl;
		}

	}
}

void Options::ParseValue(string name, char args[])
{
	if (paramName.find(name) != paramName.end())
	{
		vector<string> params = paramName.at(name);
		if (params.size() < 1) return;
		if (options.find(params[0]) == options.end()) return;

		string arg = string(args);

		try
		{
			int value = std::stoi(arg);
			options.at(params.at(0)) = value;
		}
		catch (std::invalid_argument ex)
		{
			std::cout << ex.what() << std::endl;
		}
		catch (std::out_of_range ex)
		{
			std::cout << ex.what() << std::endl;
		}

	}
}
