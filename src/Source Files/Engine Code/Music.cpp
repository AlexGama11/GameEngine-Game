#include "Music.h"

bool Music::Initialize(int frequency, int chunksize)
{
		// audiosys is quality, 2 is 2 channels left and right
		if (Mix_OpenAudio(frequency, AUDIO_S16SYS, 2, chunksize) == -1)
		{
		Utility::Log("Error initializing audio!", Utility::Severity::Failure);
			return false;
		}

	return true;
}

bool Music::Load(const std::string& filename/*, const std : string & tag*/)
{
		music = Mix_LoadMUS(filename.c_str());
		if (!music)
		{
			Utility::Log("Error loading audio!", Utility::Severity::Failure);
			return false;
		}

	return true;
}

bool Music::LoadSFX(const std::string& filename)
{
	sfx = Mix_LoadWAV(filename.c_str());
	if (!sfx)
	{
		Utility::Log("Error loading sfx!", Utility::Severity::Failure);
		return false;
	}

	return true;
}

void Music::Unload(/*const std::string& tag*/)
{
		Mix_FreeMusic(music);
}

void Music::UnloadSFX(const std::string& tag)
{
	Mix_FreeChunk(sfx);
}

void Music::Shutdown()
{
	Mix_CloseAudio();
}

void Music::SetVolume(float volume)
{
	//clamp makes sure that it does not go above 1 or below 0, volumes in sdl are between 1 and 128
	volume = std::clamp(volume, 0.0f, 1.0f);
	Mix_VolumeMusic(static_cast<int>(volume * 128.0f));

}

void Music::SetVolumeSFX(float volume)
{
	volume = std::clamp(volume, 0.0f, 1.0f);
	Mix_VolumeChunk(sfx, static_cast<int>(volume * 128.0f));
}

bool Music::Play(Loop loop)
{
		if (!Mix_PlayingMusic())
		{
			if (Mix_PlayMusic(music, static_cast<int>(loop)) == -1)
			{
				Utility::Log("Error playing audio!", Utility::Severity::Failure);
				return false;
			}
		}
	
	return true;
}

bool Music::PlaySFX(int loop)
{
	if (Mix_PlayChannel(-1, sfx, loop) == -1)
	{
		Utility::Log("Error playing sfx!", Utility::Severity::Failure);
		return false;
	}
	return true;
}

void Music::Pause()
{
		if (!Mix_PausedMusic())
		{
			Mix_PauseMusic();
		}
}

void Music::Resume()
{
	if (Mix_PausedMusic);
	{
		Mix_ResumeMusic();
	}
}

void Music::Stop()
{
	if (Mix_PlayingMusic())
	{
		Mix_HaltMusic();
	}
}