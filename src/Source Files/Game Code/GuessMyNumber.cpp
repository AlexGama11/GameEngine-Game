#include "GuessMyNumber.h"

int GuessMyNumber::PlayGMN()
{
	// generates random numbers
	srand(static_cast<unsigned int>(time(0)));
	int guessNumber = rand() % 100 + 1;
	successMessage += std::to_string(tries);
	triesMessage += std::to_string(tries);

	while ((tries >= 0) && (numberGuessed == false))
	{
		Utility::Log("Guess the number, you can't go to the next world until you do!");
		Utility::Log(triesMessage);
		std::cin >> guess;

		if (guess > guessNumber)
		{
			if (guess > guessNumber && guess < guessNumber + 6)
			{
				Utility::Log("You were close! Have another try!");
				++tries;
			}

			else
			{
				Utility::Log("Your number is too high!", Utility::Severity::Warning);
				--tries;
			}
			
		}

		else if (guess < guessNumber)
		{
			if (guess < guessNumber && guess > guessNumber - 6)
			{
				Utility::Log("You were close! Have another try!");
				++tries;
			}

			else
			{
				Utility::Log("Your number is too low!", Utility::Severity::Warning);
				--tries;
			}
			
		}

		else
		{
			Utility::Log(successMessage, Utility::Severity::Success);
			numberGuessed = true;
			return 0;
		}

		if (tries == 0)
		{
			Utility::Log("You Lost! Better luck next time!", Utility::Severity::Failure);
			tries = 5;
		}

	}
    return 0;
}

bool GuessMyNumber::IsNumberGuessed()
{
	return numberGuessed;
}
