#pragma once
#include <SDL.h>
#include <string>
#include <iostream>
#include <fstream>

class Save
{

public:

	bool SaveFile(const std::string* savetext);

	bool LoadFile(std::string* savetext);

private:

	int linenumber{ 0 };
	//std::string savedata[100];
	int count{ 0 };
};