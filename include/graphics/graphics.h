#pragma once

#include <SDL.h>

class Graphics {
    public:
        static bool init();
        static void clear();
        static void present();
        static void cleanup();

        static SDL_Renderer* renderer;
        static SDL_Window* window;
};
