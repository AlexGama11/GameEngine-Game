#include "Game.h"
#include "Input.h"
#include "Utility.h"

int main(int argc, char* argv[])
{
	Utility::Initialize();

	Game game;
	game.Initializer();

	while (game.GetGameStatus())
	{
		if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE) == true)
		{
			game.Shutdown();
		}

		game.GameRunning();
	}

	// Shuts down the game
	game.Quit();
	return 0;
}