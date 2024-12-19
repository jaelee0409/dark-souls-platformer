#include "App.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

App::App() : isRunning(true), renderer(nullptr), player(nullptr) {}

App::~App() {
    // delete player;
    // for (auto obj : gameObjects) {
    //     delete obj;
    // }
}

bool App::init() {
    if (!window.init()) {
        return false;
    }

    renderer = new Renderer(window.getRenderer());

    //player = new Player(100, 100, renderer);
    //gameObjects.push_back(player);  // Add player to game objects

    // Create an enemy and add it to the game objects
    //Enemy* enemy = new Enemy(400, 100, renderer);
    //gameObjects.push_back(enemy);

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
            isRunning = false;
        }
        // Handle other events like keypress, etc.
        //player->handleInput(e);
    }
}

void App::run() {
    while (isRunning) {
        handleEvents();

        // Update game state here
        renderer->setDrawColor(0xFF, 0xFF, 0xFF, 0xFF); // Set background color
        SDL_RenderClear(window.getRenderer()); // Clear screen

        // Update each game object
        // for (auto obj : gameObjects) {
        //     obj->update();  // Call update on every object
        // }

        // Render each game object
        // for (auto obj : gameObjects) {
        //     obj->render();  // Call render on every object
        // }

        SDL_RenderPresent(window.getRenderer()); // Update the screen
    }
}