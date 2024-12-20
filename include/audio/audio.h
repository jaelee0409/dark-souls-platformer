#pragma once

#include <SDL_mixer.h>

class Audio {
    public:
        static bool init();
        static void playSwordSlash();
        static void cleanup();

    private:
        static Mix_Music* bgMusic;
        static Mix_Chunk* swordSlash;
};
