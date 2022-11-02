#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Utility.h"

class GuessMyNumber
{

public:
	int PlayGMN();

	bool IsNumberGuessed();

private:

	bool numberGuessed{ false };
	int tries{ 5 };
	int guess{ 0 };
	std::string successMessage = "Guessed it! Tries Left: ";
	std::string triesMessage = "Tries = ";
};