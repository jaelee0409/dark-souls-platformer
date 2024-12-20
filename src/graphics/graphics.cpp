#include <SDL.h>
#include "graphics/graphics.h"

SDL_Renderer* Graphics::renderer = nullptr;
SDL_Window* Graphics::window = nullptr;

bool Graphics::init() {
    // Create window
    window = SDL_CreateWindow("2D Dark Souls Platformer",
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              800, 600, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

void Graphics::clear() {
    SDL_RenderClear(renderer);
}

void Graphics::present() {
    SDL_RenderPresent(renderer);
}

void Graphics::cleanup() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
