#include <SDL.h>
#include "graphics/graphics.h"

SDL_Renderer *Graphics::renderer = nullptr;
SDL_Window *Graphics::window = nullptr;

bool Graphics::init()
{
    // Create window
    window = SDL_CreateWindow("Dark Souls Platformer",
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              1280, 720, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
#ifdef _DEBUG
        printf("Window could not be created... SDL_Error: %s\n", SDL_GetError());
#endif
        return false;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
#ifdef _DEBUG
        printf("Renderer could not be created... SDL_Error: %s\n", SDL_GetError());
#endif
        return false;
    }

#ifdef _DEBUG
    printf("Graphics system initialized...\n");
#endif

    return true;
}

void Graphics::clear()
{
#ifdef _DEBUG
    printf("Clearing the renderer...\n");
#endif

    SDL_RenderClear(renderer);
}

void Graphics::present()
{
#ifdef _DEBUG
    printf("Presenting the renderer...\n");
#endif

    SDL_RenderPresent(renderer);
}

void Graphics::cleanup()
{
#ifdef _DEBUG
    printf("Cleaning up graphics resources...\n");
#endif

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
