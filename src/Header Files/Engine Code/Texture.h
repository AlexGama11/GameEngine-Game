#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Vector.h"
#include "Screen.h"
#include "Utility.h"

class Texture
{

public:

	Texture(int width = 0, int height = 0);

	bool Load(const std::string& filename);
	void Unload();

	void IsAnimated(bool flag);
	void IsAnimationLooping(bool flag);

	void SetTextureDimension(int width, int height);
	void SetSourceDimension(int columns, int rows, int width, int height);
	void SetAnimationSpeed(float animationSpeed);

	void Update();
	void Render(int x = 0, int y = 0);

private:

	int cel;
	float animationSpeed;
	float animationRunningTime;

	bool isAnimated;
	bool isAnimationDead;
	bool isAnimationLooping;
	bool isAnimationLoopFinal;

	SDL_Texture* imgTexture;
	Vector<int> textureDimension;
	Vector<int> celDimension;
	Vector<int> sourceDimension;


};

