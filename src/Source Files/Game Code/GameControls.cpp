#include "GameControls.h"

int GameControls::Controls()
{
	//Music sfx;
	//Game game;

	//sfx.Load("../gamefiles/audio/button.wav");
	//sfx.SetVolume(game.GetVolume());

	if (Input::Instance()->IsKeyPressed(HM_KEY_RETURN) == true && settings == false /*&& !game.GetSoundStatus()*/)
	{
		/*sfx.Play();
		game.SetSoundStatus(true);*/
		ubw = true;
		start = false;
	}

	else if (Input::Instance()->IsKeyPressed(HM_KEY_U) == true && settings == false /*&& !game.GetSoundStatus()*/)
	{
		/*sfx.Play();
		game.SetSoundStatus(true);*/
		start = true;
		ubw = false;
	}

	else if (Input::Instance()->IsKeyPressed(HM_KEY_O) == true && ubw == false /*&& !game.GetSoundStatus()*/)
	{
		/*sfx.Play();
		game.SetSoundStatus(true);*/
		settings = true;
		start = false;
	}

	else if (Input::Instance()->IsKeyPressed(HM_KEY_P) == true && ubw == false /*&& !game.GetSoundStatus()*/)
	{
		/*sfx.Play();
		game.SetSoundStatus(true);*/
		start = true;
		settings = false;
	}

	//static float time = 0.0f;
	//time += 0.01;
	//if (time > 0.65f)
	//{
	//	game.SetSoundStatus(false);
	//	time = 0.0f;
	//}

	return 0;
}

bool GameControls::GetSettingsStatus()
{
	return settings;
}

bool GameControls::GetUBWStatus()
{
	return ubw;
}

bool GameControls::GetStartStatus()
{
	return start;
}
