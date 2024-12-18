#include "Renderer.h"
#include <SDL.h>

Renderer::Renderer(SDL_Renderer* renderer) : gRenderer(renderer) {}

void Renderer::render(SDL_Texture* texture, int x, int y) {
    SDL_Rect renderQuad = { x, y, 640, 480 }; // Assuming the texture fits the window size
    SDL_RenderCopy(gRenderer, texture, nullptr, &renderQuad);
}

void Renderer::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(gRenderer, r, g, b, a);
}