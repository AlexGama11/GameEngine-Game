#include "Game.h"

int Game::Initializer()
{
	

	//get a random number, this will set the music
	srand(static_cast<unsigned int>(time(0)));
	int BgAudio = rand() % 100 + 1;

	/*std::cout << "The Music Number is: " << BgAudio << std::endl;*/

	if (BgAudio <= 32)
	{
		musicSelected = "../gamefiles/audio/pressgardenact2.mp3";
	}

	else if (BgAudio > 32 && BgAudio <= 64)
	{
		musicSelected = "../gamefiles/audio/the-hot-wind-is-blowing-extended.mp3";
	}

	else if (BgAudio > 64 && BgAudio < 96)
	{
		musicSelected = "../gamefiles/audio/one-winged-angel-music.mp3";
	}

	else if (BgAudio >= 96)
	{
		musicSelected = "../gamefiles/audio/coracao-nao-tem-idade-vou-beijar.mp3";
		Utility::Log("Congratulations! You just got the Easter Egg Music! It's a 4% Chance!", Utility::Severity::Success);
	}

	// initializes the screen
	Screen::Instance()->Initialize();

	swords.Load("../gamefiles/assets/Ubw.png");
	swords.SetSourceDimension(1, 1, 1280, 720);
	swords.SetTextureDimension(1280, 720);
	swords.IsAnimated(false);

	menu.Load("../gamefiles/assets/BGMenu.png");
	menu.SetSourceDimension(1, 1, 1280, 720);
	menu.SetTextureDimension(1280, 720);
	menu.IsAnimated(false);

	options.Load("../gamefiles/assets/OptionsMenu.png");
	options.SetSourceDimension(1, 1, 1280, 720);
	options.SetTextureDimension(1280, 720);
	options.IsAnimated(false);
	
	player.PlayerStart();

	bgMusic.Initialize();
	bgMusic.Load(musicSelected);
	bgMusic.SetVolume(v);
	bgMusic.Play(Music::Loop::Ongoing);

	/*sfx.Load("../gamefiles/audio/button.wav");
	sfx.SetVolume(v);*/

	startText.Initialize();
	startText.Load("../gamefiles/fonts/SEGA_Skip-B.ttf");
	startText.SetSize(1200, 100);
	startText.SetColor(144, 115, 182);
	startText.SetString("Press Enter to Start The Game, and U to return from it. To access the options menu, click O");

	optionsText.Initialize();
	optionsText.Load("../gamefiles/fonts/SEGA_Skip-B.ttf");
	optionsText.SetSize(1200, 100);
	optionsText.SetColor(144, 115, 182);
	optionsText.SetString("Press P to exit the options menu, N to change your name, and the arrow or W and S keys to change the volume");

	volumeText.Initialize();
	volumeText.Load("../gamefiles/fonts/SEGA_Skip-B.ttf");
	volumeText.SetSize(600, 100);
	volumeText.SetColor(144, 115, 182);

	playerName.Initialize();
	playerName.Load("../gamefiles/fonts/SEGA_Skip-B.ttf");
	playerName.SetSize(600, 100);
	playerName.SetColor(144, 115, 182);

	return 0;
}

int Game::GameRunning()
{
	//refreshes the screen
	Screen::Instance()->ClearBuffer();

	//returns pointer to class
	Input::Instance()->Update();

	////closes window
	isGameRunning = !(Input::Instance()->IsWindowClosed());

	std::string savedata[100];

	gameControls.Controls();

	if (gameControls.GetSettingsStatus())
	{
		options.Render(0, 0);
		optionsText.Render(40, 40);
		std::string volumeString = std::to_string(v);
		volumeText.SetString("Current Volume: " + volumeString);
		volumeText.Render(40, 120);
		save.LoadFile(savedata);
		gamerName = savedata[2];
		playerName.SetString("Player Name: " + gamerName);
		playerName.Render(40, 260);


		if (Input::Instance()->IsKeyPressed(HM_KEY_DOWN) == true || Input::Instance()->IsKeyPressed(HM_KEY_S) == true && !isSoundPlayed)
		{
			v -= 0.01;
			std::string volumeString = std::to_string(v);
			volumeText.SetString("Current Volume: " + volumeString);
			bgMusic.SetVolume(v);
			/*sfx.SetVolume(v);
			sfx.Play()*/;
			std::cout << "Music Volume:" << v << std::endl;
			isSoundPlayed = true;
		}

		if (Input::Instance()->IsKeyPressed(HM_KEY_UP) == true || Input::Instance()->IsKeyPressed(HM_KEY_W) == true && !isSoundPlayed)
		{
			v += 0.01;
			std::string volumeString = std::to_string(v);
			volumeText.SetString("Current Volume: " + volumeString);
			bgMusic.SetVolume(v);
			/*sfx.SetVolume(v);
			sfx.Play();*/
			std::cout << "Music Volume:" << v << std::endl;
			isSoundPlayed = true;
		}

		if (Input::Instance()->IsKeyPressed(HM_KEY_N) == true && !isSoundPlayed)
		{
			/*sfx.Play();*/
			std::cout << "What is your new name?" << std::endl;
			std::cin >> gamerName;
			std::cin.get();
			while (std::cin.fail())
			{
				std::cout << "Your name cannot be used within the game!" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> gamerName;
			}

			savedata[2] = gamerName;
			save.SaveFile(savedata);
			playerName.SetString("Player Name: " + gamerName);
			playerName.Render(40, 260);
			isSoundPlayed = true;
		}
	}

	if (gameControls.GetUBWStatus())
	{
		//new bg
		swords.Render(0, 0);
		player.PlayerRender();
		player.PlayerMove();
		gmn.PlayGMN();
		
		while (!gmn.IsNumberGuessed())
		{
			if (Input::Instance()->IsKeyPressed(HM_KEY_U) == true && gameControls.GetSettingsStatus() == false && !isSoundPlayed)
			{
				Utility::Log("You can't leave!", Utility::Severity::Warning);
			}
		}
		
		
	}

	if (gameControls.GetStartStatus())
	{
		//base bg
		menu.Render(0, 0);
		startText.Render(40, 40);
	}

	if (v < 0)
	{
		v = 0.0;
	}

	if (v > 1)
	{
		v = 1.0;
	}

	Screen::Instance()->SwapBuffer();

	return 1;
}

int Game::Shutdown()
{
	swords.Unload();
	menu.Unload();
	startText.Unload();
	optionsText.Unload();
	player.PlayerUnload();
	options.Unload();
	playerName.Unload();
	sfx.Unload();
	isGameRunning = false;
	return 2;
}

int Game::Quit()
{
	Screen::Instance()->Shutdown();
	startText.Shutdown();
	optionsText.Shutdown();
	playerName.Shutdown();
	return 3;
}

bool Game::GetSoundStatus()
{
	return isSoundPlayed;
}

void Game::SetSoundStatus(bool soundStatus)
{
	isSoundPlayed = soundStatus;
}

float Game::GetVolume()
{
	return v;
}

bool Game::GetGameStatus()
{
	return isGameRunning;
}
