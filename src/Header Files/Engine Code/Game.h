#pragma once
#include <iostream>
#include "Screen.h"
#include "Texture.h"
#include "Music.h"
#include "Text.h"
#include "Input.h"
#include "Player.h"
#include "GameControls.h"
#include "Save.h"
#include "GuessMyNumber.h"

class Game
{

public:
	int Initializer();
	int GameRunning();
	int Shutdown();
	int Quit();
	bool GetSoundStatus();
	void SetSoundStatus(bool soundStatus);
	float GetVolume();
	bool GetGameStatus();

private:

	// Does not work if put in the header file for some reason, added here.
	Texture swords;
	Texture menu;
	Texture options;
	Texture shirou;
	Music bgMusic;
	Music sfx;
	Text startText;
	Text optionsText;
	Text volumeText;
	Text playerName;
	Player player;
	GameControls gameControls;
	Save save;
	GuessMyNumber gmn;

	bool isGameRunning = true;
	bool isSoundPlayed = false;
	float v = 0.5;
	std::string musicSelected;
	std::string gamerName = "Player 1";

};