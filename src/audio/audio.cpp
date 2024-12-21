#include <SDL_mixer.h>
#include "audio/audio.h"

Mix_Music *Audio::bgMusic = nullptr;
Mix_Chunk *Audio::swordSlash = nullptr;

bool Audio::init()
{
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
    {
        printf("SDL_mixer could not initialize... SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }

    // Load background music
    bgMusic = Mix_LoadMUS("assets/audio/background_music.mp3");
    if (!bgMusic)
    {
        printf("Failed to load background music... SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }

    // Load sound effect
    swordSlash = Mix_LoadWAV("assets/audio/sword_slash.wav");
    if (!swordSlash)
    {
        printf("Failed to load sword slash sound effect... SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }

    // Play background music in a loop
    Mix_PlayMusic(bgMusic, -1);
    return true;
}

void Audio::playSwordSlash()
{
    Mix_PlayChannel(-1, swordSlash, 0);
}

void Audio::cleanup()
{
    Mix_FreeMusic(bgMusic);
    Mix_FreeChunk(swordSlash);
    Mix_Quit();
}
