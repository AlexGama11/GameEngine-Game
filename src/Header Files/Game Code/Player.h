#pragma once
#include <iostream>
#include "Texture.h"
#include "Input.h"

class Player
{

public:
	int PlayerStart();
	int PlayerRender();
	int PlayerMove();
	int PlayerUnload();

	int GetPlayerX();
	int GetPlayerY();

private:
	Texture player;

	struct PlayerPos
	{
		int x{ 640 };
		int y{ 360 };
	};

	PlayerPos position;

	std::string xAxisString = "Player position on the X axis is: ";
	std::string yAxisString = "Player position on the Y axis is: ";
};

