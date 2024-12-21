#pragma once

#include <SDL.h>

class Input
{
public:
    static bool init();
    static void processInput();
    static bool keyPressed(SDL_Scancode key);

private:
    static SDL_Event event;
};
