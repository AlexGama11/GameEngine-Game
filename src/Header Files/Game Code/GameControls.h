#pragma once
#include <iostream>
#include "Input.h"
#include "Music.h"

class GameControls
{

public:
	int Controls();

	bool GetSettingsStatus();
	bool GetUBWStatus();
	bool GetStartStatus();

private:

	bool settings{ false };
	bool ubw{ false };
	bool start{ true };

};