#include "Save.h"

bool Save::SaveFile(const std::string* savetext)
{	

	// Create and open a text file
	std::ofstream saveFile("../gamefiles/saves/saveFile.txt");

	for (int i = 0; i < 100; i++)
	{
		saveFile << savetext[i] << "\n";
	}

	//closes the file
	saveFile.close();

	return true;
}

bool Save::LoadFile(std::string* savetext)
{

	// Read from the text file
	std::ifstream saveFile("../gamefiles/saves/saveFile.txt");

	if (!saveFile)
	{
		// Create and open a text file
		std::fstream saveFile("../gamefiles/saves/saveFile.txt");

		while (!saveFile.eof())
		{
			std::getline(saveFile, savetext[count++]);
		}

		// Close the file
		saveFile.close();
	}

	while (!saveFile.eof())
	{
		std::getline(saveFile, savetext[count++]);
	}

	return true;
}