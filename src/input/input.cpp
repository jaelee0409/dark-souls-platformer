#include <SDL.h>
#include "input/input.h"

SDL_Event Input::event;

bool Input::init()
{
    // SDL_Init already initializes input
    return true;
}

void Input::processInput()
{
    // Handle events
    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            // Close the application
            #ifdef _DEBUG
                printf("Application closed...\n");
            #endif
            SDL_Quit();
        }
    }
}

bool Input::keyPressed(SDL_Scancode key)
{
    return SDL_GetKeyboardState(nullptr)[key] != 0;
}
