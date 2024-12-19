#include "App.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

App::App() : quit(false), renderer(nullptr) {}

App::~App() {}

bool App::init() {
    if (!window.init()) {
        return false;
    }
    renderer = new Renderer(window.getRenderer());

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }
    return true;
}

bool App::loadMedia() {
    // Load media here

    
    return true;
}

void App::handleEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            quit = true;
        }
        // Handle other events like keypress, etc.
    }
}

void App::run() {
    while (!quit) {
        handleEvents();
        // Update game state here
        renderer->setDrawColor(0xFF, 0xFF, 0xFF, 0xFF); // Set background color
        SDL_RenderClear(window.getRenderer()); // Clear screen

        // Render game objects here
        // renderer->render(texture, x, y);

        SDL_RenderPresent(window.getRenderer()); // Update the screen
    }
}