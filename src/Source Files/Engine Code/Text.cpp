#include "Text.h"

bool Text::Initialize()
{
	if (TTF_Init() == -1)
	{
		Utility::Log("Error initializing font system!", Utility::Severity::Failure);
		return false;
	}

	return true;
}

bool Text::Load(const std::string& filename)
{
	font = TTF_OpenFont(filename.c_str(), 300);

	if (!font)
	{
		Utility::Log("Error loading font!", Utility::Severity::Failure);
		return false;
	}

	return true;
}

void Text::Unload()
{
	TTF_CloseFont(font);
}

void Text::Shutdown()
{
	TTF_Quit();
}

Text::Text()
{
	font = nullptr;
	texture = nullptr;
	textSize = { 0, 0 };
	color = { 255,255,255 };
}

Text::~Text()
{
	SDL_DestroyTexture(texture);
}

void Text::SetSize(int width, int height)
{
	textSize.x = width;
	textSize.y = height;
}

void Text::SetString(const std::string& setString)
{
	string = setString;
}

void Text::SetColor(Uint8 r, Uint8 g, Uint8 b)
{
	color.r = r;
	color.g = g;
	color.b = b;

}

void Text::Render(int x, int y)
{
	SDL_Rect dst;

	dst.x = x;
	dst.y = y;
	dst.w = textSize.x;
	dst.h = textSize.y;

	CreateText();
	SDL_RenderCopy(Screen::Instance()->GetRenderer(), texture, nullptr, &dst);
}

void Text::CreateText()
{
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, string.c_str(), color);

	SDL_DestroyTexture(texture);
	texture = SDL_CreateTextureFromSurface(Screen::Instance()->GetRenderer(), textSurface);

	SDL_FreeSurface(textSurface);
}
