#pragma once

#include <SDL2/SDL.h>

class Window {
public:
    Window();
    ~Window();

    bool init();
    void close();
    SDL_Window* getWindow() const;
    SDL_Renderer* getRenderer() const;

private:
    SDL_Window* gWindow = nullptr;
    SDL_Renderer* gRenderer = nullptr;
};
