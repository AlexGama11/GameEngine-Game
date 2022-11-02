#include "Screen.h"


Screen* Screen::Instance()
{
	static Screen* screen = new Screen;
	return screen;
}

bool Screen::Initialize(int width, int height, int posX, int posY, bool isVSync)
{

	//initializes
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		Utility::Log("SDL did not initialize!", Utility::Severity::Failure);
		return false;
	}

	//makes window
	window = SDL_CreateWindow("Alex's Game Engine",
		posX,
		posY,
		width, 
		height,
		SDL_WINDOW_RESIZABLE);

	//if no window
	if (!window)
	{
		Utility::Log("Game engine window could not be created!", Utility::Severity::Failure);
		return false;
	}

	// makes renderer
	// if VSYNC is added, movement should be made faster

	if (isVSync)
	{
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED  | SDL_RENDERER_PRESENTVSYNC);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	//if no renderer
	if (!renderer)
	{
		Utility::Log("Renderer could not be created!", Utility::Severity::Failure);
		return false;
	}

	srand(static_cast<unsigned int>(time(0)));
	int IconVersion = rand() % 100 + 1;

	//Sets Game Engine Icon.
	if (IconVersion % 2 == 0)
	{
		SDL_Surface* icon = IMG_Load("../assets/ShirouIconCaladbolg.png");

		SDL_SetWindowIcon(window, icon);
	}

	else if (IconVersion % 2 == 1)
	{
		SDL_Surface* icon = IMG_Load("../assets/ShirouIconExcalibur.png");

		SDL_SetWindowIcon(window, icon);
	}

	Utility::Log("Screen created successfully!", Utility::Severity::Success);

    return true;
}

void Screen::ClearBuffer()
{

	//Clears the Screen
	SDL_RenderClear(renderer);

}

void Screen::SwapBuffer()
{
	//Swaps the Frame buffer
	SDL_RenderPresent(renderer);
}

void Screen::Shutdown()
{
	//shutdown game
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit;

}

SDL_Renderer* Screen::GetRenderer()
{
	return renderer;
}
