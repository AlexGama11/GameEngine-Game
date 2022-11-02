#include "Player.h"

int Player::PlayerStart()
{

	player.Load("../gamefiles/assets/ShirouUBW-Sheet.png");
	player.SetSourceDimension(5, 1, 160, 32);
	player.SetTextureDimension(64, 64);
	player.IsAnimated(true);
	player.IsAnimationLooping(true);
	player.SetAnimationSpeed(5.0f);

	return 0;
}

int Player::PlayerRender()
{
	player.Update();
	player.Render(position.x, position.y);
	return 0;
}

int Player::PlayerMove()
{
	if (Input::Instance()->IsKeyPressed(HM_KEY_D) == true)
	{
		position.x += 1;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_A) == true)
	{
		position.x -= 1;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_W) == true)
	{
		position.y -= 1;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_S) == true)
	{
		position.y += 1;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_F) == true)
	{
		//Output player position on the X axis if key is clicked.
		xAxisString += std::to_string(position.x);
		Utility::Log(xAxisString);

		//Output player position on the Y axis if key is clicked.
		yAxisString += std::to_string(position.y);
		Utility::Log(yAxisString);
	}

	if (position.x > 1280)
	{
		position.x = 0;
	}

	if (position.x < 0)
	{
		position.x = 1280;
	}

	if (position.y > 720)
	{
		position.y = 0;
	}

	if (position.y < 0)
	{
		position.y = 720;
	}

	return 0;
}

int Player::PlayerUnload()
{
	player.Unload();
	return 0;
}

int Player::GetPlayerX()
{
	return position.x;
}

int Player::GetPlayerY()
{
	return position.y;
}
