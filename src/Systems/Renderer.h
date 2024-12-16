#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>

class Renderer {
public:
    Renderer(SDL_Renderer* renderer);
    void render(SDL_Texture* texture, int x, int y);
    void setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

private:
    SDL_Renderer* gRenderer;
};

#endif