#include "Window.h"
#include <SDL.h>

Window::Window() : gWindow(nullptr), gRenderer(nullptr) {}

Window::~Window() {
    close();
}

bool Window::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    gWindow = SDL_CreateWindow("Dark Souls Platformer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (gWindow == nullptr) {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == nullptr) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    return true;
}

void Window::close() {
    if (gRenderer != nullptr) {
        SDL_DestroyRenderer(gRenderer);
    }
    if (gWindow != nullptr) {
        SDL_DestroyWindow(gWindow);
    }
    SDL_Quit();
}

SDL_Window* Window::getWindow() const {
    return gWindow;
}

SDL_Renderer* Window::getRenderer() const {
    return gRenderer;
}