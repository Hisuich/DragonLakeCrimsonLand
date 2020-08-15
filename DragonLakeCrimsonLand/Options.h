#pragma once
#include <unordered_map>
#include <iostream>
#include <string>

using std::unordered_map;
using std::string;
using std::begin;
using std::end;
using std::vector;

class Options
{
public:
	static unordered_map<string, int> options;
	static unordered_map<string, string> optionsName;
	static unordered_map<string, vector<string>> paramName;

public:
	static void ParseConsole(int argc, char* argv[]);

private:
	static void ParseSize(string name, char args[]);
	static void ParseValue(string name, char args[]);
};