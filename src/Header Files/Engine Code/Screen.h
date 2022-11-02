#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Utility.h"

class Screen
{

public:

	static Screen* Instance();

	/**
	- Initialize the screen, by inputting width, height, X position, and the Y position.
	- To make the screen centered, set the X position as a quarter of the screen width and the Y position as a quarter of the screen height.
	- Default screen position is centered, while default screen dimentions are 1280x720.
	- isVSyncOn is set to false by default, set it to true if you want VSYnc.
	*/
	bool Initialize(int width = 1280, int height = 720, int posX = 320, int posY = 180, bool isVSyncOn = false);

	void ClearBuffer();

	void SwapBuffer();

	void Shutdown();

	SDL_Renderer* GetRenderer();

private:

	Screen() {};
	Screen(const Screen&);
	Screen& operator = (const Screen&);


	SDL_Window* window{ nullptr };
	SDL_Renderer* renderer{ nullptr };

};
