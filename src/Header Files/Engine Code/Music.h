#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <SDL_mixer.h>
#include <assert.h>
#include "Utility.h"

class Music
{

public:
	enum class Loop
	{
		//types of loops
		Once = 1,
	    Ongoing = -1
	};

	// stereo frequency, chunks is how big data chunks are by default
	bool Initialize(int frequency = 44100, int chunkSize = 1024);

    //loading needs a filename, second part is saying that it needs a tag
	bool Load(const std::string& filename/*, const std::string& tag*/);

	bool LoadSFX(const std::string& filename);

    //need to check out tags
	void Unload(/*const std::string& tag = ""*/);

	void UnloadSFX(const std::string& tag = "");

	//shuts down
	void Shutdown();

	//volume
	void SetVolume(float volume);

	void SetVolumeSFX(float volume);

	//player loops once by default
	bool Play(Loop loop = Loop::Once);

	bool PlaySFX(int loop = 0);

	void Pause();

	void Resume();

	void Stop();


private:

	//pointer to music data
	Mix_Music* music{ nullptr };

	//pointer to sound effect data
	Mix_Chunk* sfx{ nullptr };

};

